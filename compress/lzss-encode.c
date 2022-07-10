#include "lzss-encode.h"

int num_digits (int n) {
    int r = 1;
    if (n < 0) n = (n == INT_MIN) ? INT_MAX: -n;
    while (n > 9) {
        n /= 10;
        r++;
    }
    return r;
}

int encoded_length(int lookback_offset, int length){
    return num_digits(lookback_offset) + num_digits(length) + 4;
}

char* lzss_encode(
    char *data, 
    int data_len, 
    int search_buffer_size,
    int look_ahead_buffer_size
){
    char *encoded_data = malloc(data_len);
    int encoded_data_offset = 0;

    for(int i = 0; i < data_len; i++) {
        int search_buffer_start = 0;

        if (i > search_buffer_size) {
            search_buffer_start = i - search_buffer_size;
        }

        int match_start = search_buffer_start;
        int match_end = search_buffer_start;
        int match_found = 0;
        int prev_match[2] = {match_start, match_end};

        for(int j = search_buffer_start; j < i; j++) {
            int offset = match_end - match_start;

            if (i + offset >= data_len){
                break;
            }

            if (!match_found && data[i + offset] == data[j]) {
                match_start = j;
                match_end = match_start + 1;
                match_found = 1;
            } else if (match_found && data[i + offset] == data[j]) {
                match_end++;
            } else if (match_found && data[i + offset] != data[j]) {
                int lookback_offset = i - match_start;
                int length = offset;

                if(
                    offset > encoded_length(lookback_offset, length) &&
                    prev_match[1] - prev_match[0] < offset
                ){
                    prev_match[0] = match_start;
                    prev_match[1] = match_end;
                }

                match_found = 0;
                match_start = match_end;
                j--;
            } else {
                match_found = 0;
            }
        }
        
        int match_length = prev_match[1] - prev_match[0];

        if(match_length > 0){
            int loopback_offset = i - match_start;
            int chunk_length = encoded_length(loopback_offset, match_length);
            char *encoded_chunk = malloc(chunk_length + 1);

            snprintf(
                encoded_chunk,
                chunk_length,
                "<%d,%d>",
                loopback_offset,
                match_length
            );

            memcpy(
                encoded_data + encoded_data_offset,
                encoded_chunk,
                chunk_length - 1
            );

            encoded_data_offset += match_length;
            i += match_length;
        }else{
            memcpy(
                encoded_data + encoded_data_offset,
                data + i,
                1
            );

            encoded_data_offset++;
        }
    }

    return encoded_data;
}
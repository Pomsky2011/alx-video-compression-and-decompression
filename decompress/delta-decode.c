#include "delta-decode.h"

// TODO: This does not decode properly. Fix it!
char *delta_decode(char *encoded_data, int encoded_data_len){
    char *decoded_result = malloc(sizeof(char) * encoded_data_len);
    char prev_byte_last_bit = 0;

    for(int i = 0; i < encoded_data_len; i++){
        char current_byte = encoded_data[i];

        char first_bit   = current_byte & 128;
		char second_bit  = current_byte & 64;
		char third_bit   = current_byte & 32;
		char fourth_bit  = current_byte & 16;
		char fifth_bit   = current_byte & 8;
		char sixth_bit   = current_byte & 4;
		char seventh_bit = current_byte & 2;
		char eighth_bit  = current_byte & 1;

        char decoded_byte = 0;

        if(i == 0){
			decoded_byte = decoded_byte | first_bit;
        }else if(first_bit != 0){
            decoded_byte = decoded_byte | (~prev_byte_last_bit) & 128;
        }else{
            decoded_byte = decoded_byte | prev_byte_last_bit;
        }

        if(second_bit != 0){
            decoded_byte = decoded_byte | (~decoded_byte & 128);
        }else{
            decoded_byte = decoded_byte | (decoded_byte & 128);
        }

        if(third_bit != 0){
            decoded_byte = decoded_byte | (~decoded_byte & 64);
        }else{
            decoded_byte = decoded_byte | (decoded_byte & 64);
        }

        if(fourth_bit != 0){
            decoded_byte = decoded_byte | (~decoded_byte & 32);
        }else{
            decoded_byte = decoded_byte | (decoded_byte & 32);
        }

        if(fifth_bit != 0){
            decoded_byte = decoded_byte | (~decoded_byte & 16);
        }else{
            decoded_byte = decoded_byte | (decoded_byte & 16);
        }

        if(sixth_bit != 0){
            decoded_byte = decoded_byte | (~decoded_byte & 8);
        }else{
            decoded_byte = decoded_byte | (decoded_byte & 8);
        }

        if(seventh_bit != 0){
            decoded_byte = decoded_byte | (~decoded_byte & 4);
        }else{
            decoded_byte = decoded_byte | (decoded_byte & 4);
        }

        if(eighth_bit != 0){
            decoded_byte = decoded_byte | (~decoded_byte & 2);
        }else{
            decoded_byte = decoded_byte | (decoded_byte & 2);
        }

        prev_byte_last_bit = (decoded_byte & 1) << 7;
		decoded_result[i] = decoded_byte;
    }

    return decoded_result;
}
#include "delta-decode.h"

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

		char first_decoded_bit;

		if(i == 0){
			first_decoded_bit = first_bit;
		}else{
			first_decoded_bit = prev_byte_last_bit ^ first_bit;
		}

		char second_decoded_bit  = (first_decoded_bit >> 1) ^ second_bit;
		char third_decoded_bit   = (second_decoded_bit >> 1) ^ third_bit;
		char fourth_decoded_bit  = (third_decoded_bit >> 1) ^ fourth_bit;
		char fifth_decoded_bit   = (fourth_decoded_bit >> 1) ^ fifth_bit;
		char sixth_decoded_bit   = (fifth_decoded_bit >> 1) ^ sixth_bit;
		char seventh_decoded_bit = (sixth_decoded_bit >> 1) ^ seventh_bit;
		char eighth_decoded_bit  = (seventh_decoded_bit >> 1) ^ eighth_bit;

		char decoded_byte = second_decoded_bit |
			third_decoded_bit |
			fourth_decoded_bit |
			fifth_decoded_bit |
			sixth_decoded_bit |
			seventh_decoded_bit |
			eighth_decoded_bit;

        prev_byte_last_bit = (decoded_byte & 1) << 7;
		decoded_result[i] = decoded_byte;
    }

    return decoded_result;
}

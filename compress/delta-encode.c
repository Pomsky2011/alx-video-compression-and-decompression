#include"delta-encode.h"


char *delta_encode(char *data, int data_len){
	char *encoded_result = malloc(sizeof(char) * data_len);
	char prev_byte_last_bit = 0;

	for(int i = 0; i < data_len; i++){
		char current_byte = data[i];

		char first_bit   = current_byte & 128;
		char second_bit  = current_byte & 64;
		char third_bit   = current_byte & 32;
		char fourth_bit  = current_byte & 16;
		char fifth_bit   = current_byte & 8;
		char sixth_bit   = current_byte & 4;
		char seventh_bit = current_byte & 2;
		char eighth_bit  = current_byte & 1;

		char delta_byte = 0;

		if(i == 0){
			delta_byte = delta_byte | first_bit;
		}else if(first_bit != prev_byte_last_bit){
			delta_byte = delta_byte | 128;
		}

		if(second_bit != first_bit){
			delta_byte = delta_byte | 64;
		}
		if(third_bit != second_bit){
			delta_byte = delta_byte | 32;
		}
		if(fourth_bit != third_bit){
			delta_byte = delta_byte | 16;
		}
		if(fifth_bit != fourth_bit){
			delta_byte = delta_byte | 8;
		}
		if(sixth_bit != fifth_bit){
			delta_byte = delta_byte | 4;
		}
		if(seventh_bit != sixth_bit){
			delta_byte = delta_byte | 2;
		}
		if(eighth_bit != seventh_bit){
			delta_byte = delta_byte | 1;
		}

		prev_byte_last_bit = (current_byte & 1) << 7;
		encoded_result[i] = delta_byte;
	}
	
	return encoded_result;
}

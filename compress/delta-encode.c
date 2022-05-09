#include"delta-encode.h"


char *delta_encode(char *data, int data_len){
	char *encoded_result = malloc(sizeof(char) * data_len);
	char prev_byte_last_bit = 0;

	for(int i = 0; i < data_len; i++){
		char current_byte = data[i];
		char delta_byte;

		if(i == 0){
			delta_byte = (current_byte >> 1) ^ current_byte;
		}else{
			delta_byte = (current_byte >> 1 | prev_byte_last_bit) ^ current_byte;
		}

		prev_byte_last_bit = (current_byte & 1) << 7;
		encoded_result[i] = delta_byte;
	}
	
	return encoded_result;
}

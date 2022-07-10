#include <stdio.h>
#include <stdlib.h>

#include "delta-encode.h"
#include "delta-decode.h"
#include "lzss-encode.h"

void print_binary(char n){
    for(int i = 0; i < 8; i++){
        if(n & 128){
            printf("1");
        }else{
            printf("0");
        }

        n = n << 1;
    }
}

void test_delta(){
    char *data = "AA"; // 01000001 01000001
    int data_len = 2;

    char *encoded_data = delta_encode(data, data_len);
    char *decoded_data = delta_decode(encoded_data, data_len);

    printf("Testing delta encoding...\n\n");

    printf("data:         ");
    print_binary(data[0]);
    print_binary(data[1]);
    printf("\n");

    printf("encoded_data: ");
    print_binary(encoded_data[0]);
    print_binary(encoded_data[1]);
    printf("\n");

    printf("decoded_data: ");
    print_binary(decoded_data[0]);
    print_binary(decoded_data[1]);
    printf("\n\n");
}

void test_lzss(){
    char *data = "I AM SAM. I AM SAM. SAM I AM. \
DO YOU LIKE GREEN EGGS AND HAM? \
NO, I DON'T LIKE GREEN EGGS AND HAM. \
I DON'T LIKE THEM, SAM I AM.";
    char *encoded_data = lzss_encode(data, 130, 130, 10); 

    printf("Testing lzss encoding...\n\n");

    printf("data: %s\n", data);

    printf("encoded data: %s\n", encoded_data);
}

int main(){
    //test_delta();
    test_lzss();
}
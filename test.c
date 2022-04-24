#include <stdio.h>
#include <stdlib.h>

#include "delta-encode.h"
#include "delta-decode.h"

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

int main(){
    char *data = "AA"; // 01000001 01000001
    int data_len = 2;

    char *encoded_data = delta_encode(data, data_len);
    char *decoded_data = delta_decode(encoded_data, data_len);

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
    printf("\n");
}
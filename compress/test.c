#include <stdio.h>
#include <stdlib.h>

#include "delta.h"

int main(){
    char *data = "AA"; // 01000001 01000001
    int data_len = 2;

    char *delta_data = delta_encode(data, data_len);

    printf("data: %x%x\n", data[0], data[1]);
    printf("delta_data: %x%x\n", delta_data[0], delta_data[1]);
}
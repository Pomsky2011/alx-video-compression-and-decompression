#include <stdio.h>
#include <stdlib.h>

/* 
 * Performs delta decoding on an encoded data string
 * @param data: a data string
 * @param data_len: the length of the data string
 * @return: a delta-encoded data string
 *
 * delta encoded:
 * 0111110010000000
 *
 * decoded:
 * 0101011100000000
 *
 * See delta-encode.h for more info on the encoding procedure
 */ 
char *delta_decode(char *encoded_data, int encoded_data_len);
#include <stdio.h>
#include <stdlib.h>

/* 
 * Performs delta encoding on a data string
 * @param data: a data string
 * @param data_len: the length of the data string
 * @return: a delta-encoded data string
 *
 * original:
 * 0101011100000000
 *
 * delta encoded:
 * 0111110010000000
 *
 * First bit is always the same as the original
 * If next bit is same as the previous bit: 0; else: 1
 */ 
char *delta_encode(char *data, int data_len);
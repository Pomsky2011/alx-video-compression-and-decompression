#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*
 * Defines 2 variables: Sliding Window and Search Buffer
 * If same sequence dectected in both Sliding Window and
 * Search Buffer than store a reference (length, offset)
 */

char *lzss_encode(
    char *data,
    int data_len,
    int search_buffer_size,
    int sliding_window_size
);

/*
 * References
 *
 * paxdiablo. “How Do I Determine the Number of Digits of
 * an Integer in C?” Stack Overflow, 19 Mar. 2021,
 * https://stackoverflow.com/questions/1068849/how-do-i-
 * determine-the-number-of-digits-of-an-integer-in-c.
 */
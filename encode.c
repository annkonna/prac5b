#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define MAX_TEXT_SIZE 5000
#define MAX_ENCODE_SIZE 10000
#define MAX_LINE_SIZE 80

void dump_raw_bytes(void *databuf, int size) {
    if (size<0 || size>MAX_ENCODE_SIZE) return;
    
    for (int i=0; i<size; i++) {
        putchar(*(char*)databuf);
        databuf++;
    }
}

void dump_mem(const void *mem , size_t len) {
    const char *buffer = mem; // Cast to char *
    size_t i;

    for (i = 0; i < len; i++) {
        if (i > 0 && i % 8 == 0) {
            printf("\n");
        }
        // the bitwise & is needed because buffer[i] is interpretted as a hex integer
        // value by printf and so if the most-significant bit is 1, it will be
        // sign-extended,  it won't appear for 0s as the format string is 02x.
        printf("%02x ", buffer[i]); // & 0xff);
    }
    
    if (i > 1 && i % 8 != 1) {
        puts("");
    }
}

/* Encode the text in data and copy to databuf.
 *
 * Encodes each line of text in data.
 * Any line with more than MAX_LINE_SIZE characters is invalid.
 * Each chunk consists of an integer identifying the number of characters 
 * followed by the characters in the line. 
 * The final chunk should be an integer containing 0.
 *
 * You may assume that the text 'data' points to is NULL terminated and that
 * the buffer 'encode' is pointing to is large enough to hold the encoded
 * data.  
 *
 */
int encode_text(void *encode, char *text) {
    /* Your implementation should appear here */
    
    return 0;
}

int main(int argc, char *argv[]) {

    void *text = malloc(MAX_TEXT_SIZE);
    void *encode = malloc(MAX_ENCODE_SIZE);

    int c;
    char *temp = (char *)text;
    while ( (c=getchar()) != EOF ) {
        *temp = (unsigned char)c;
        temp++;
    }
    *temp = '\0';

    int ret = encode_text(encode, text);
    if ( ret == -1 ) {
        printf("\n Failed: size overflow.\n");
        return -1;
    }

    dump_mem(encode, MAX_ENCODE_SIZE);
//    dump_raw_bytes(encode, MAX_ENCODE_SIZE);
}

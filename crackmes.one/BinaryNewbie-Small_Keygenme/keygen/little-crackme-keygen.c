/*
 * little-crackme-keygen.c
 * Serial generator for BinaryNewbie's Small Keygenme
 *                      https://crackmes.one/crackme/5e83f7f433c5d4439bb2e059
 * Author: Gabriel Marti
 * Twitter: @H0l3Bl4ck
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *serialgen(unsigned int length, char *charset) {    
    char *serial_string = NULL;
    int sz = strlen(charset);
    if (length) {
        srand(time(NULL));  
        serial_string = malloc(sizeof(char) * (length+1));
        if (serial_string) {            
            for (int n = 0; n < length; n++) {            
                int key = rand() % sz;
                serial_string[n] = charset[key];
            }
            serial_string[length] = '\0';
        }
    }
    return serial_string;
}

int main(int argc, char **argv) {
    char *valid_digits = "257dfDF";      
	printf("Serial generator for BinaryNewbie's Small Keygenme\n");
    printf("Serial: %s\n", serialgen(16, valid_digits));
	return 0;
}

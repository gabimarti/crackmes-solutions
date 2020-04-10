/*
 * Shad3-keygen-M1.c
 * Password generator for Shad3-Keyg3n-M1
 * Author: Gabriel Marti
 * Twitter: @H0l3Bl4ck
 */
#include <stdio.h>
#include <string.h>

/* returns ASCII value sum of pass if length are between 8 and 10 */
int key_value(char *current_pass) {
    int pass_length;
    int counter;
    int value_accumulator;

    value_accumulator = 0;
    pass_length = strlen(current_pass);
    if (pass_length > 7 && pass_length < 11 ) {
      counter = 0;
      while(counter < pass_length) {
        value_accumulator += current_pass[counter];
        counter++;
      }
    }
    return value_accumulator;
}


/* Print password if it's valid */
void show_valid_pass( char *pass, int good_pass ) {
    int result;
    result = key_value(pass);
    if ( result >= good_pass) {
        printf("Valid Password %s value( %d )\n", pass, result);
    }
}


int main(int argc, char **argv)
{
    int good_pass = 1000;
    char c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, first, last;
    char pass[11];
     
    pass[10] = '\0';
    printf("Searching possible valid passwords ...\n\n");
    
    first = 'J';
    last = '~';
       
    for (c1 = first; c1 <= last; c1++) {
        for (c2 = first; c2 <= last; c2++) {
            for (c3 = first; c3 <= last; c3++) {
                for (c4 = first; c4 <= last; c4++) {
                    for (c5 = first; c5 <= last; c5++) {
                        for (c6 = first; c6 <= last; c6++) {
                            for (c7 = first; c7 <= last; c7++) {
                                for (c8 = first; c8 <= last; c8++) {
                                    pass[0] = c1;
                                    pass[1] = c2;
                                    pass[2] = c3;
                                    pass[3] = c4;
                                    pass[4] = c5;
                                    pass[5] = c6;
                                    pass[6] = c7;
                                    pass[7] = c8;
                                    pass[8] = '\0';
                                    show_valid_pass(pass, good_pass);
                                    for (c9 = first; c9 <= last; c9++) {
                                        pass[8] = c9;
                                        pass[9] = '\0';
                                        show_valid_pass(pass, good_pass);
                                        for (c10 = first; c10 <= last; c10++) {
                                            pass[9] = c10;
                                            pass[10] = '\0';
                                            show_valid_pass(pass, good_pass);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

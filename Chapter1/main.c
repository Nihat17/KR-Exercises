#include <stdio.h>
#include <stdlib.h>

#define TABSTOP 8        /* fixed tabstop set to 4 */
#define MAXLINE 1000     /* Size of the input */
#define MAXWIDTH 20        /* WIDTH that each line should have */

int main()
{
    exer1_22();
    return 0;
}

char line[MAXLINE];

void detab(void) {
    extern char line[MAXLINE];

    int c, j, i;
    j = i = 0;

    for(i=0; (c = getchar()) != EOF; ++i)
        if(c == '\t') {
            line[i++] = ' ';

            while(i % TABSTOP != 0)
                line[i++] = ' ';
            --i;
        }

        else
            line[i] = c;

}

void exer1_20() {

    /*
        Write a program detab that replaces tabs in the input with the proper number
        of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
        Should n be a variable or a symbolic parameter?

        Meaning whenever program sees \t, it needs to determine how many spaces should put
        For instance if tab stop is 5, if \t is on 0 it should go to the value which is divisible by 5
        which is 5, if cursor is on 7 it should move to 10 since 10 is the next number divisible by 5
    */


    printf("Exercise 1_20...\n");

    extern char line[MAXLINE];
    detab();
    printf("\nConverted: '%s'", line);
}

void exer1_21() {
    /*
        Write a program entab that replaces strings of blanks by the minimum number
        of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab . When
        either a tab or a single blank would suffice to reach a tab stop, which should be given
        preference?
    */
    printf("Exercise 1.21...\n");

    int input_len = getinput();

    detab_local(input_len);

}

int getinput() {
    extern char line[MAXLINE];
    int c, i;

    for(i = 0; (c = getchar()) != EOF && i < MAXLINE; ++i)
        line[i] = c;
    return i;
}

void detab_local(int len) {
    extern char line[MAXLINE];
    int sp = -1, i;

    int tabs[len];
    char line_n[len];
    for(i = 0; i < len; ++i){
        tabs[i] = 0;
        line_n[i] = 'a';
    }


    for(i = 0; i < len; ++i) {
        if(i != 0 && line[i - 1] == ' ' && i % TABSTOP == 0 && sp != -1) {
            tabs[sp] = 1;
            sp = (line[i] == ' ') ? i : -1;
        }
        if(line[i] == ' ' && sp == -1)
            sp = i;
        else if(line[i] != ' ')
            sp = -1;
    }

    int flag = 0, k = 0;

    for(i = 0; i < len; ++i) {
        if(flag == 1 && i % TABSTOP == 0 && i != len - 1 || flag == 1 && line[i] != ' ')
            flag = 0;

        if(tabs[i] == 1) {
            line_n[k++] = '\\t';
            flag = 1;
        }
        else if(flag == 0)
            line_n[k++] = line[i];

    }
    line_n[k] = '\0';
    printf("\n'%s'", line_n);
}

void exer1_22() {
    printf("Exercise 1.22...\n");

    int input_len = getinput();

    char output[MAXLINE];
    extern char line[MAXLINE];          /* input array */

    int c, i, ptr_i = -1, ptr_k = -1, k = 0, flag = -1;
    int output_counter = 0, flag2 = -1;

    for(i = 0; i < input_len; ++i) {
        if(output_counter < MAXWIDTH) {
            flag2 = 0;
            if(line[i] != '\t'){
                if(line[i] == ' ') {
                    ptr_i = i;
                    ptr_k = k;
                    flag = 1;
                }
                else if(flag == -1 || line[i + 1] == ' ' && output_counter + 1 < MAXWIDTH) {
                    ptr_i = i;
                    ptr_k = k;
                }
                output[k++] = line[i];
                ++output_counter;
            }
            else if(line[i] == '\t') {
                ptr_k = k;
                while(output_counter < MAXWIDTH && k % TABSTOP != 0) {
                    output[k++] = ' ';
                    ++output_counter;
                }

                if(output_counter >= MAXWIDTH) {
                    k = ++ptr_k;
                    output[k] = '\n';
                    while(k % TABSTOP != 0)
                        output[k++] = ' ';
                }
            }
        }
        else {
            k = ++ptr_k;
            output_counter = 0;
            output[k++] = '\n';
            i = ptr_i;
            flag = -1;
        }
    }
    output[k] = '\0';

    printf("\n%s", output);
}

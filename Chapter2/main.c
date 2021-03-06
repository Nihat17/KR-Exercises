#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

#define SIGNED      0
#define UNSIGNED    1

void exer1_2();

int atoi2(char[]);

int lower2(char);

int htoi(char[]);

void exer2_3();

void exer2_4();

void exer2_5();

int main()
{
    exer2_1();
    exer2_3();
    exer2_4();
    return 0;
}

void compute_size(int, int);

void exer2_1() {
    /*
        Write a program to determine the ranges of char , short , int , and long
        variables, both signed and unsigned , by printing appropriate values from standard headers
        and by direct computation.
    */

    printf("Exercise 2.1...\n");

    printf("Range of signed char %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range of unsigned char 0 to %d\n\n", UCHAR_MAX);

    printf("Range of signed short int %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of unsigned short int 0 to %d\n\n", USHRT_MAX);

    printf("Range of signed int %d to %d\n", INT_MIN, INT_MAX);
    printf("Range of unsigned int 0 to %lu\n\n", UINT_MAX);

    printf("Range of signed long int %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of unsigned long int 0 to %lu\n\n", ULONG_MAX);

    printf("Range of float %e to %e\n", FLT_MIN, FLT_MAX);
    printf("Range of double %e to %e\n", DBL_MIN, DBL_MAX);
    printf("Range of long double %e to %e\n", LDBL_MIN, LDBL_MAX);

    printf("\nSize range of char is ");
    compute_size(sizeof(char), SIGNED);

    printf("Size range of signed char is ");
    compute_size(sizeof(char), SIGNED);

    printf("Size range of unsigned char is ");
    compute_size(sizeof(char), UNSIGNED);

    printf("Size range of int is ");
    compute_size(sizeof(int), SIGNED);

    printf("Size range of signed int is ");
    compute_size(sizeof(int), SIGNED);

    printf("Size range of unsigned int is ");
    compute_size(sizeof(int), UNSIGNED);

    printf("Size range of signed short is ");
    compute_size(sizeof(short), SIGNED);

    printf("Size range of unsigned short is ");
    compute_size(sizeof(short), UNSIGNED);
}

void exer2_3() {
    /*
        Write a function htoi(s) , which converts a string of hexadecimal digits
        (including an optional 0x or 0X ) into its equivalent integer value. The allowable digits are 0
        through 9 , a through f , and A through F .
    */

    printf("\nExercise 2.3...\n");
    printf("Decimal value of 0xFee7A9 = %d", htoi("0xFee7A9"));
}

void squeeze(char[], char[]);

void exer2_4() {
    /*
        Write an alternative version of squeeze(s1,s2) that deletes each character in
        s1 that matches any character in the string s2 .
    */

    printf("\nExercise 2.4...\n");

    char s1[] = "hello there";
    char s2[] = "e";

    squeeze(s1, s2);
    printf("Modified string %s\n", s1);
}

int any(char[], char[]);

void exer2_5() {
    /*
        Write the function any(s1,s2) , which returns the first location in a string s1
        where any character from the string s2 occurs, or -1 if s1 contains no characters from s2 .
    */
    printf("Exercise 2.5...\n");

}

int any(char s1[], char s2[]) {
    int i, c;
    for(c = 0; s2[c] != '\0'; ++c)
        for(i = 0; s1[i] != '\0'; ++i)
            if(s[i] == s[c])
                return i;
    return -1;
}

void squeeze(char s1[], char s2[]) {
    int i, j;
    for(int c = 0; s2[c] != '\0'; ++c) {
        for(i = j = 0; s1[i] != '\0'; ++i)
            if(s1[i] != s2[c])
                s1[j++] = s1[i];
        s1[j] = '\0';
    }
}

long long pow(int val, int power);

void compute_size(int n_byte, int state) {

    int n_bits = n_byte * 8;

    if(state == UNSIGNED) {
        printf("0 to %lld\n", pow(2 ,n_bits) - 1);
    }
    else{
        long long val = pow(2, n_bits);
        printf("%lld to %lld\n", -val + val / 2, (val - val / 2) - 1);
    }
}

long long pow(int val, int power) {
    if(power == 0)
        return 1;
    return pow(val, power - 1) * val;
}

/* implementation of atoi function */

int atoi2(char s[]) {
    int i, n;

    n = 0;
    for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

/*
    implementation of lower function
    between each lower and corresponding capital letter difference is 32
*/
int lower2(char c) {
    if(c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    return c;
}

/*
    Write a function htoi(s) , which converts a string of hexadecimal digits
    (including an optional 0x or 0X ) into its equivalent integer value. The allowable digits are 0
    through 9 , a through f , and A through F .
*/
int getStrLen(char[]);

int htoi(char s[]) {

    if(s[0] != '0' && s[1] != 'x' || s[0] != '0' && s[1] != 'X')
        return -1;

    char hex_vals[6];
    int i;

    int output = 0;

    for(i = 0; i < 6; ++i)
        hex_vals[i] = i + 10;

    int power = getStrLen(s) - 3;
    int x = 0;

    for(i = 2; s[i] != '\0'; ++i) {
        if(s[i] >= 'A' && s[i] <= 'Z')
            x = hex_vals[s[i] - 65];
        else if(s[i] >= 'a' && s[i] <= 'z')
            x = hex_vals[s[i] - 97];
        else if(s[i] >= '0' && s[i] <= '9')
            x = s[i] - 48;
        else
            return -1;

        output += x * pow(16, power--);
    }

    return output;
}

int getStrLen(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; ++i)
        ;
    return i;
}

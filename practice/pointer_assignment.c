//Create a program that allocate a 64-bit floating point number to any value of your choosing. 
//Create a function that increments the double (using pointers) by any value of your choosing. 
//For each primitive data type (except char...), use pointers to cast the value to that primitive data type,
// iterate over the 8 bytes without leaving the allocated space, and print the values for the data type

//primitive data types: int, float, bool, long, unsigned int, unsigned long short, unsigned short

#include "stdio.h"  
#include "stdlib.h"
#include <stdbool.h>

void increment(double* value) {
  *value = *value + 10;
}

int main(){

    // float* f_ptr = (float*)malloc(sizeof(float[64]));
    // *f_ptr = 56; 
    double num = 5600.8978;

    float* f = &num;
    float float_1 = *f; //float_1 = value that f is pointing to = num's first 4 bytes
    float float_2 = *(f+1);
    printf("the float values are %f, %f \n", float_1, float_2);

    int* i = (int*)f;
    int int_1 = *i;
    int int_2 = *(i+1);
    printf("the integer values are %d, %d \n", int_1, int_2);

    short* s = &num;
    int loop_s = sizeof(num)/sizeof(short);
    for (int i = 0; i < loop_s; i++) {
        short shorty_1 = *(s+i);
        printf("Shorty number %d is %hd\n", i, shorty_1);
    }

    long* l = &num;
    int loop_l = sizeof(num)/sizeof(long);
    for (int i = 0; i < loop_l; i++) {
        long long_ben = *(l+i);
        printf("%ld Longy number %d is %ld\n",sizeof(long), i, long_ben);
    }
    printf("size of num is %ld\n", sizeof(num));
    printf("%ld", sizeof(num)/sizeof(long));

    bool* b = &num;
    bool loop_b = sizeof(num)/sizeof(bool);
    for (int i = 0; i < loop_b; i++) {
        bool booly = *(b+i);
        printf("Booly number %d is %d\n", i, booly);
    }

    return 0;
}
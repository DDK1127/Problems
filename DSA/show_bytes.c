/* type casting to access and print it by byte representation. */

#include<stdio.h>
typedef unsigned char *byte_pointer;
// unsigned char => 0 to 255, equal 1 bytes, no complenment.

void show_bytes(byte_pointer start, int len){
    for(int i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x){
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x){
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x){
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val){
    int ival = val;
    float fval = (float)val;
    int *pval = &val;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int main(){
    int val = 0x12345678;
    byte_pointer valp = (byte_pointer) &val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);
    show_bytes(valp, 4);
    show_bytes(valp, 5);
    printf("\n");

    test_show_bytes(12345);
    return 0;
}

// Mac Os => [Little endian]

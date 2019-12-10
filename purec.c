//
// Created by nahod on 09.12.2019.
//

#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline") //  Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //  Enable AVX
#pragma GCC target("avx")  //   Enable AVX

#include "purec.h"

int a = 5;
double b = 5.12345;
char c = 'X';

int func_ret_int(int val) {
    printf("get func_ret_int: %d\n", val);
    return val;
}

double func_ret_double(double val) {
    printf("get func_ret_double: %f\n", val);
    return val;
}

char * func_ret_str(char * val) {
    printf("get func_ret_str: %s\n", val);
    return val;
}

char func_many_args(int val1, double val2, char val3, short val4) {
    printf("get func_many_args: int - %d, double - %f, char - %c, short - %d\n", val1, val2, val3, val4);
    return val3;
}

void func_print_globals(){
    printf("global variables: a - %d, b - %f, c - %c\n", a, b, c);
}

double func_struct(test_st_t test_st){
    printf("get by value test_st: val1 - %d, val2 - %f, val3 - %c\n", test_st.val1, test_st.val2, test_st.val3);

    return test_st.val1 + test_st.val2;
}

test_st_t * func_ret_struct(test_st_t *test_st) {
    if (test_st) {
        printf("get by pointer test_st: val1 - %d, val2 - %f, val3 - %c\n", test_st->val1, test_st->val2, test_st->val3);
    } else {
        printf("get by pointer test_st: null pointer\n");
    }

    return test_st;
}

double * func_add_out(const double * left, const double * right, double * result){
    *result = *left + *right;
    return result;
}

void func_add_arrays_out(const double * left, const double * right, double * result, unsigned long long n){
    for(unsigned long long i = 0; i < n; ++i) {
        result[i] = left[i] + right[i];
    }
}

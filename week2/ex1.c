#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int int_var = INT_MAX;
    float float_var = FLT_MAX;
    double double_var = DBL_MAX;
    printf("int: %d, %d\n", sizeof(int_var), int_var);
    printf("float: %d, %f\n", sizeof(float_var), float_var);
    printf("double: %d, %lf\n", sizeof(double_var), double_var);
    return 0;
}
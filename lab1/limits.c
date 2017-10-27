#include <stdio.h>
#include <limits.h>

int main(int argc, char * argv[]) {
    printf("Integer datatype range limits for this Machine:\n");
    printf("Signed short:\t\t %hd to %hd \n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short:\t\t %hu to %hu \n", 0, USHRT_MAX);
    printf("Signed integer:\t\t %d to %d \n", INT_MIN, INT_MAX);
    printf("Unsigned integer:\t %u to %u \n", 0, UINT_MAX);
    printf("Signed long:\t\t %ld to %ld \n", LONG_MIN, LONG_MAX);
    printf("Unsigned long:\t\t %lu to %lu \n", 0, ULONG_MAX);
    return 0;
}

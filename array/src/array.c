// array.c
#include <stdio.h>
#include <stdlib.h>

// Arrays have a fixed size which is unchangable

int main(void) {
    // Creating an array with a fixed size of 10 elements
    int nums[10] = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Accessing and changing array elements : O(1) -> Constant time
    nums[0] = 1;

    // Traversing an array : O(n) -> Linear time
    for (size_t i = 0; i < sizeof(nums)/sizeof(nums[0]); ++i) {
        printf("%d\n",nums[i]);
    }

    return 0;
}
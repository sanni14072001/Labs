#include "sort.h"
#include <stdint.h>
#include <stdio.h>

struct part_res {
    char *ptr;
    int swapCount;
};

void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

part_res partition(char *low, char *high, size_t size, int (*comparator)(const void *, const void *)) {
    char *pivot = high;
    char *i = low;
    int swapCount = 0;
    for (char *j = low; j < high; j = j + size) {
        int res = comparator(j, pivot);
        if (res < 0) {
            swap(i, j);
            swapCount++;
            i = i + size;
        }
    }
    swap(i, high);
    part_res res = {
            i,
            swapCount + 1
    };
    return res;
}


int myQSort(void *base, size_t count, size_t size,
            int (*comparator)(const void *, const void *)) {
    char *low = (char *) base;
    char *high = low + size * (count - 1);
    if (low < high) {
        part_res res = partition(low, high, size, comparator);
        int swapCount = res.swapCount;
        swapCount += myQSort(low, ((res.ptr - low) / size), size, comparator);
        swapCount += myQSort(res.ptr + size, ((high - res.ptr) / size) , size, comparator);
        return swapCount;
    }

    return 0;
}


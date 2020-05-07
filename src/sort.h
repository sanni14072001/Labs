#ifndef LABS_SORT_H
#define LABS_SORT_H

#include <stddef.h>

int myQSort(void *base, size_t count, size_t size,
            int (*comparator)(const void *, const void *));

#endif //LABS_SORT_H

#ifndef LABS_SORT_H
#define LABS_SORT_H

#include <stddef.h>

void my_qsort(void *base, size_t num, size_t size,
              int (*comparator)(const void *, const void *));

#endif //LABS_SORT_H

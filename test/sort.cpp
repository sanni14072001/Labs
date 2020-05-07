#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sort.h"

using testing::ElementsAre;

int comparator(const void *p, const void *q) {
    int l = *(const int *) p;
    int r = *(const int *) q;
    return (l - r);
}

TEST(library, my_qsort) {
    int arr[] = {1, 6, 5, 2, 3, 9, 4, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    my_qsort((void *) arr, size, sizeof(arr[0]), comparator);
    ASSERT_THAT(arr, ElementsAre(1, 2, 3, 4, 5, 6, 7, 8, 9));
}
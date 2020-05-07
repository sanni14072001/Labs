#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sort.h"

using testing::ElementsAre;

int intComparator(const void *p, const void *q) {
    int l = *(const int *) p;
    int r = *(const int *) q;
    return (l - r);
}

int stringComparator(const void *p, const void *q) {
    const char **l = (const char **) p;
    const char **r = (const char **) q;
    return strcmp(*l, *r);
}


TEST(library, myQSort_non_empty_arr) {
    int arr[] = {9, 6, 5, 2, 3, 1, 4, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int swapCount = myQSort((void *) arr, size, sizeof(arr[0]), intComparator);
    ASSERT_THAT(arr, ElementsAre(1, 2, 3, 4, 5, 6, 7, 8, 9));
    ASSERT_THAT(swapCount, 22);
}

TEST(library, myQSort_empty_arr) {
    int arr[] = {};
    int size = sizeof(arr) / sizeof(arr[0]);
    int swapCount = myQSort((void *) arr, size, sizeof(arr[0]), intComparator);
    ASSERT_THAT(0, swapCount);
}

TEST(library, myQSort_two_elements_arr) {
    int arr[] = {6, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int swapCount = myQSort((void *) arr, size, sizeof(arr[0]), intComparator);
    ASSERT_THAT(arr, ElementsAre(3, 6));
    ASSERT_THAT(swapCount, 1);
}

TEST(library, myQSort_string_arr) {
    const char *arr[] = {"z", "zz", "bb", "aa", "ccc"};
    int size = sizeof(arr) / sizeof(arr[0]);
    int swapCount = myQSort((void *) arr, size, sizeof(arr[0]), stringComparator);
    ASSERT_THAT(arr, ElementsAre("aa", "bb", "ccc", "z", "zz"));
    ASSERT_THAT(swapCount, 5);
}
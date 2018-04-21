#include <stdio.h>
#include <stdlib.h>

// Dynamic programming solution to find the length of the longest increasing subsequence of an array
// O(n^2)
int len_longest_inc_subseq(int const* arr, int n)
{
    int* lis = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i) {
        // length of lis of one element
        lis[i] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            // lis[i] = min(lis[j]) + 1, 0 < j < i and arr[j] < arr[i]
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; ++i) {
        if (max < lis[i]) {
            max = lis[i];
        }
    }

    free(lis);

    return max;
}

int main()
{
    int arr[] = { 2, 1, 3, 5, 0, 6, -1, -18, 9 };
    printf("%d\n", len_longest_inc_subseq(arr, 9));

    return 0;
}

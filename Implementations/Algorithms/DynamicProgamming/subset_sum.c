#include <stdbool.h>
#include <stdio.h>

bool subset_sum(int* arr, int n, int sum)
{
    // table[i][j] - subset arr[0..i-1] with sum j
    bool table[n + 1][sum + 1];

    // can't sum empty set to anything
    for (int j = 0; j <= sum; j++) {
        table[0][j] = false;
    }

    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= sum; s++) {
            // either arr has subset with length i-1 that sums up to s, contains element s or
            // has subset with length i-1 of sum s - arr[i-1]
            table[i][s] = table[i - 1][s] || arr[i - 1] == s || table[i - 1][s - arr[i - 1]];
        }
    }

    return table[n][sum];
}

int main(int argc, char* argv[])
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    printf("%d\n", subset_sum(arr, 6, 1));
    printf("%d\n", subset_sum(arr, 6, 3));
    printf("%d\n", subset_sum(arr, 6, 6));
    printf("%d\n", subset_sum(arr, 6, 9));
    printf("%d\n", subset_sum(arr, 6, 10));
    printf("%d\n", subset_sum(arr, 6, 12));
    printf("%d\n", subset_sum(arr, 6, 15));
    printf("%d\n", subset_sum(arr, 6, 21));
    printf("%d\n", subset_sum(arr, 6, 24));

    return 0;
}

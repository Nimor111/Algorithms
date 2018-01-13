#include <stdio.h>

template <typename T>
void merge(T* arr, int low, int high, int middle)
{
    int i, j, k;
    int n1 = middle - low + 1;
    int n2 = high - middle;

    T left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[middle + j + 1];

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < n1) {
        arr[k++] = left[i++];
    }
    while (j < n2) {
        arr[k++] = right[j++];
    }
}

template <typename T>
void merge_sort(T* arr, int low, int high)
{
    if (low < high) {
        int middle = (low + high) / 2;
        merge_sort(arr, low, middle);
        merge_sort(arr, middle + 1, high);
        merge(arr, low, high, middle);
    }
}

int main()
{
    int a[] = { 1, 3, 2, 4 };
    merge_sort<int>(a, 0, 3);
    for (int i = 0; i < 4; ++i)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

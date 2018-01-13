#include <stdio.h>

template <typename T>
void swap(T* a, T* b)
{
    T temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

template <typename T>
int partition(T* arr, int low, int high)
{
    int pivot = arr[high];

    int i = low - 1, j = 0;

    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            printf("SWAPPING\n");
            swap(&arr[++i], &arr[j]);
            printf("SWAPPED\n");
        }
    }
    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

template <typename T>
void quick_sort(T* arr, int low, int high)
{
    if (low < high) {
        int p = partition(arr, low, high);

        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

int main()
{
    int a[] = { 4, 3, 2, 1 };
    quick_sort<int>(a, 0, 3);
    for (int i = 0; i < 4; ++i)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

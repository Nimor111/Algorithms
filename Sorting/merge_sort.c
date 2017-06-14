#include <stdio.h>

void merge(int * arr, int low, int middle, int high)
{
    int i, j, k;
    int n1 = middle - low + 1;
    int n2 = high - middle;

    int L[n1], R[n2]; // temp arrays

    /* copying data to temp arrays */
    for ( i = 0; i < n1; ++i )
        L[i] = arr[low + i];
    for ( j = 0; j < n2; ++j )
        R[j] = arr[middle + 1 + j];

    /* merge the temp arrays back into arr[low..high] */
    i = j = 0; // first and second subarrays
    k = low; // new merged subarray

    while ( i < n1 && j < n2 )
    {
        if ( L[i] < R[j] )
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    /* copy remaining elements */
    while ( i < n1 )
    {
        arr[k] = L[i];
        ++i; ++k;
    }

    while ( j < n2 )
    {
        arr[k] = R[j];
        ++j; ++k;
    }
}

void mergeSort(int * arr, int low, int high)
{
    if ( high > low )
    {
        int middle = (low + high) / 2;
        mergeSort(arr, low, middle);
        mergeSort(arr, middle + 1, high);
        merge(arr, low, middle, high);
    }
}

int main(int argc, char const ** argv)
{
    int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    mergeSort(arr, 0, sizeof(arr) / sizeof(arr[0]));
    int i;
    for ( i = 0; i < sizeof(arr) / sizeof(arr[0]); i++ )
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}

#include <stdio.h>

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Every smaller than pivot is put before it,
 * every higher is after it
 * */
int partition(int * arr, int low, int high)
{
    int pivot = arr[high];

    int i = low - 1, j; // -1 to avoid going out of array

    for (j = low; j < high; j++)
    {
        if ( arr[j] <= pivot )
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quickSort(int * arr, int low, int high)
{
    if ( low < high ) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main(int argc, char const ** argv)
{
    int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    /* printf("%d", sizeof(arr) / sizeof(arr[0])); */
    quickSort(arr, 0, sizeof(arr) / sizeof(arr[0]));
    int i;
    for ( i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}

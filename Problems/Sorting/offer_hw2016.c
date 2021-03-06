/**
 * Return minimum by comparison concatenation of strings,
 * comparison is kinda funky
 */


#include <stdio.h>
#include <string.h>

int compare(char arr1[50], char arr2[50])
{
    int n1 = strlen(arr1);
    int n2 = strlen(arr2);
    int len;
    if ( n1 < n2 ) len = n1;
    else len = n2;
    for (int i = 0; i<len; i++)
    {
        if (arr1[i]<arr2[i])
        {
            return 1;
        }
        if (arr2[i]<arr1[i])
        {
            return 0;
        }
    }
    if (n1<n2)
    {
        for (int i = n1; i<n2; i++)
        {
            if (arr2[i]<arr1[n1 - 1])
            {
                return 0;
            }
            if (arr2[i]>arr1[n1 - 1])
            {
                return 1;
            }
        }
    }
    else if (n1>n2)
    {
        for (int i = n2; i<n1; i++)
        {
            if (arr2[n2 - 1]<arr1[i])
            {
                return 0;
            }
            if (arr2[n2 - 1]>arr1[i])
            {
                return 1;
            }
        }
    }
    return 0;

}

// merge two subarrays of array
// first -> arr[l..m], second -> arr[m+1..r]
void merge(char arr[][50], int left, int right, int middle,
           int(*f)(char[50], char[50]))
{
    int k, i, j;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    char L[n1][50], R[n2][50]; // temp arrays to hold values and then merge into
    // main array

    for ( i = 0; i < n1; i++ )
	strcpy(L[i], arr[left+i]);
    for ( j = 0; j < n2; j++ )
        strcpy(R[j], arr[middle + 1 + j]);

    // let's merge
    k = left; // initial index of merged subarray
    i = j = 0;

    while ( i < n1 && j < n2 )
    {
        if ( f(L[i], R[j]) == 1 )
        {
            strcpy(arr[k], L[i]);
            i++;
        } else {
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }

    // copy remaining elements in both temp arrays
    while ( i < n1 )
    {
        strcpy(arr[k], L[i]);
        k++; i++;
    }
    while ( j < n2 )
    {
        strcpy(arr[k], R[j]);
        k++; j++;
    }
}


void mergeSort(char arr[][50], int left, int right,
                 int(*f)(char[50], char[50]))
{
    if ( left < right )
    {
        int middle = (left + ( right - 1 )) / 2;
        mergeSort(arr, left, middle, f);
        mergeSort(arr, middle + 1, right, f);

        merge(arr, left, right, middle, f);
    }
}


int main(int argc, char const ** argv)
{
    int N; scanf("%d", &N);
    char arr[50000][50];
    int i;
    for ( i = 0; i < N; i++ ) {
        scanf("%50s", arr[i]);
    }
    mergeSort(arr, 0, N, compare);
    for (int i = 1; i < N + 1; i++)
    {
        printf("%s", arr[i]);
    }
    printf("\n");
    return 0;
}

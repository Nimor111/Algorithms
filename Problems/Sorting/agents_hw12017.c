// TODO test with merge sort

#include <stdio.h>
#include <string.h>

#define N 50
#define LEN 1000000

char copyWords[N][LEN];

void swapSymbol(char * a, char * b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void swap(char a[], char b[])
{
    char temp[strlen(a)];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int is_upper(char c)
{
    return (int)c >= 65 && (int)c <= 90;
}

int is_lower(char c)
{
    return !is_upper(c);
}

int is_underscore(char c)
{
    return c == '_';
}

// 1 - c is bigger, 0 - d is bigger , -1 - they are equal
int compare(char c, char d)
{
    if (is_upper(c) && is_upper(d) || is_lower(c) && is_lower(d))
    {
        if ((int)c == (int)d) return -1;
        return (int)c <= (int)d;
    }
    else if (is_upper(c) && is_lower(d))
    {
        return 1;
    }
    else if (is_lower(c) && is_upper(d))
    {
        return 0;
    }
    else if (is_underscore(c) && is_lower(d))
    {
        return 1;
    }
    else if (is_lower(c) && is_underscore(d))
    {
        return 0;
    }
    else if (is_upper(c) && is_underscore(d))
    {
        return 1;
    }
    else if (is_underscore(c) && is_upper(d))
    {
        return 0;
    }
    else if (is_underscore(c) && is_underscore(d))
    {
        return -1;
    }
}

int partitionStr(int low, int high, char word[])
{
    // pivot - we take it as last element in array
    char pivot = word[high];

    int i = low - 1; // smaller element

    for ( unsigned int j = low; j <= high - 1; j++ )
    {
        if ( compare(word[j], pivot) == 1 || compare(word[j], pivot) == -1 )
        {
            i++;
            swapSymbol(&word[j], &word[i]);
        }
    }
    swapSymbol(&word[i+1], &word[high]);
    return i + 1;
}

void quickSortStr(char arr[], int low, int high)
{
    if ( low < high )
    {
        int pi = partitionStr(low, high, arr);

        quickSortStr(arr, low, pi-1);
        quickSortStr(arr, pi + 1, high);
    }
}

void transform(char word[])
{
    quickSortStr(word, 0, strlen(word) - 1);
}

int partition(int low, int high, char words[][LEN], short size)
{
    // pivot - we take it as last element in array
    char pivot[strlen(words[high])];

    for ( int i = 0; i < size; i++ )
    {
        strcpy(copyWords[i], words[i]);
    }

    strcpy(pivot, words[high]);

    int i = low - 1; // smaller element

    for ( int j = low; j <= high - 1; j++ )
    {
        transform(copyWords[j]);
        transform(pivot);
        if ( strcmp(copyWords[j], pivot) < 0 )
        {
            i++;
            swap(words[j], words[i]);
        }
    }
    swap(words[i+1], words[high]);
    return i + 1;
}

void quickSort(char arr[][LEN], int low, int high, short size)
{
    if ( low < high )
    {
        int pi = partition(low, high, arr, size);

        quickSort(arr, low, pi-1, size);
        quickSort(arr, pi + 1, high, size);
    }
}

int main(int argc, char const ** argv)
{
    short n;
    scanf("%d", &n);
    unsigned int i, j;
    char words[n][LEN];

    for ( i = 0; i < n; i++ )
    {
        scanf("%s", &words[i]);
    }

    quickSort(words, 0, n - 1, n);

    for ( i = 0; i < n; i++ )
    {
        if ( i != n + 1 )
            printf("%s\n", words[i]);
        else
            printf("%s", words[i]);
    }

    return 0;
}

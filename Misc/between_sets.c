#include <stdio.h>

// is a factor of b
int isFactor(const int a, const int b)
{
    if (a != 0) return b % a == 0;
    return 0;
}

int numsBetweenSets(int A[10], int B[10], int size1, int size2)
{
    int i, j, count = 0, is_between = 1;

    for ( i = 0; i <= 100; i++ )
    {
        for ( j = 0; j < size1; j++ )
        {
            if (!isFactor(A[j], i)) is_between = 0;
        }

        for ( j = 0; j < size2; j++ )
        {
            if(!isFactor(i, B[j])) is_between = 0;
        }

        if ( is_between ) {
            count += 1;
        } else {
            is_between = 1;
        }
    }

    return count;
}

int main(int argc, char const ** argv)
{
    const int size1 = 2;
    const int size2 = 3;

    int A[] = { 2, 4 };
    int B[] = { 16, 32, 96 };

    printf("%d\n", numsBetweenSets(A, B, size1, size2));

    return 0;
}

#include <stdio.h>
#include <math.h>

/**
 * Helper function for binaryRoot * @params: `x`, `start`, `end`
 * @return: square root of `x`
 * */

double binaryRootHelper(int x, int start, int end)
{
    double answer;
    while ( start <= end )
    {
        double mid = ( start + end ) / 2;
        if ( floor(mid * mid) == x )
            return mid;

        if ( floor(mid * mid) > x )
            end = mid - 1;

        if ( floor(mid * mid) < x )
        {
            start = mid + 1;
            answer = mid;
        }
    }

    return answer;
}

/**
 * Finding square root of `number` using binary search.
 * @params : `number`
 * @return : square root of `number`
 * */

double binaryRoot(int number)
{
    return binaryRootHelper(number, 1, number);
}

int main(int argc, char *argv[])
{
    printf("%.5f\n", binaryRoot(5));
    printf("%.5f\n", binaryRoot(4));
    printf("%.5f\n", binaryRoot(247359));

    return 0;
}

#include <stdio.h>
#include <string.h>

int min2(int x, int y)
{
    return x > y ? y : x;
}

int min(int x, int y, int z)
{
    return min2(min2(x, y), z);
}

// min number of operations required to transform str1 into str2
// operations being:
// n1 - length of first string, n2 - length of second string
// * Insert - table[i][j-1]
// * Remove - table[i-1][j]
// * Replace - table[i-1][j-1]
// O(m*n)
int edit_distance(char const* str1, char const* str2, int n1, int n2)
{
    int table[n1 + 1][n2 + 1];

    for (int i = 0; i <= n1; ++i) {
        for (int j = 0; j <= n2; ++j) {
            if (i == 0) {
                table[i][j] = j;
            } else if (j == 0) {
                table[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                table[i][j] = table[i - 1][j - 1];
            } else {
                table[i][j] = 1 + min(table[i][j - 1],      // Insert
                                      table[i - 1][j],      // Remove
                                      table[i - 1][j - 1]); // Replace
            }
        }
    }

    return table[n1][n2];
}

int main()
{
    char const* str1 = "string123";
    char const* str2 = "String132456";

    printf("%d\n", edit_distance(str1, str2, strlen(str1), strlen(str2)));

    return 0;
}

#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int longest_common_subsequence_len(char const* str1, char const* str2)
{
    int m = strlen(str1);
    int n = strlen(str2);
    int table[m + 1][n + 1];

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            // because first row and col are empty subsequences
            if (i == 0 || j == 0) {
                table[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
            } else {
                table[i][j] = max(table[i][j - 1], table[i - 1][j]);
            }
        }
    }

    return table[m][n];
}

int main()
{
    char const * str1 = "IVANKATA";
    char const * str2 = "JOIVAHJNKATA";

    printf("%d\n", longest_common_subsequence_len(str1, str2));

    return 0;
}

#include <stdio.h>

int max(int a, int b)
{
    return a >= b ? a : b;
}

int knapsack(int const* weights, int* values, int n, int W)
{
    int table[n + 1][W + 1];
    for (int j = 0; j <= W; ++j) {
        table[0][j] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            // if weight of ith item is larger than w, then go up in table, we don't put it in knapsack
            if (weights[i] > w) {
                table[i][w] = table[i - 1][w];
            } else {
                // we put the ith item into the knapsack and see if it brings more value
                table[i][w] = max(values[i] + table[i - 1][w - weights[i]], table[i - 1][w]);
            }
        }
    }

    // max value that can be put into knapsack of capacity W
    return table[n][W];
}

int main(int argc, char* argv[])
{
    int values[] = { 10, 40, 30, 50 };
    int weights[] = { 5, 4, 6, 3 };
    int W = 10;
    printf("%d\n", knapsack(weights, values, 4, W));

    return 0;
}

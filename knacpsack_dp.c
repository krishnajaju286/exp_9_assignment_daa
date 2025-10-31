#include <stdio.h>

// Function to return max of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack using Dynamic Programming
int knapsackDP(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int wt[n], val[n];

    printf("Enter the weights of items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &wt[i]);

    printf("Enter the values of items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &val[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int maxValue = knapsackDP(W, wt, val, n);
    printf("Maximum value in Knapsack (DP): %d\n", maxValue);

    return 0;
}

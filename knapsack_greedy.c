#include <stdio.h>

struct Item {
    int value, weight;
    float ratio;
};

// Function to swap two items
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items by value/weight ratio in descending order
void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

// Greedy solution (approximate for 0/1 knapsack)
int knapsackGreedy(int W, struct Item items[], int n) {
    sortItems(items, n);
    int totalWeight = 0, totalValue = 0;

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= W) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
        }
        // else break; // for fractional knapsack, we would take a fraction
    }

    return totalValue;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];

    printf("Enter the weights of items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &items[i].weight);

    printf("Enter the values of items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &items[i].value);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    int maxValue = knapsackGreedy(W, items, n);
    printf("Total value using Greedy approach: %d\n", maxValue);

    return 0;
}

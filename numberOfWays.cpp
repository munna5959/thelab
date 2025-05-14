#include <iostream>
using namespace std;

// Function to count the number of ways to make change
int coinChange(int A[], int coins, int amount) {
    int C[coins + 1][amount + 1];

    // Initialize base cases
    for (int i = 0; i <= coins; i++) {
        for (int j = 0; j <= amount; j++) {
            if (j == 0)
                C[i][j] = 1; // There is one way to make amount 0 (using no coins)
            else if (i == 0)
                C[i][j] = 0; // No ways to make any amount with 0 coins
            else if (A[i - 1] <= j)
                C[i][j] = C[i - 1][j] + C[i][j - A[i - 1]];
            else
                C[i][j] = C[i - 1][j];
        }
    }

    return C[coins][amount];
}

int main() {
    int A[] = {1, 2, 5}; // Available coin denominations
    int coins = sizeof(A) / sizeof(A[0]);
    int amount = 10; // Target amount

    // Call the function and print result
    cout << "Number of ways to make amount " << amount << " is: " << coinChange(A, coins, amount) << endl;

    return 0;
}

#include <iostream>
using namespace std;

int fibo(int n, int A[]) {
    if (n < 2) {
        return n;
    } else if (A[n] != -1) {
        return A[n];
    } else {
        A[n] = fibo(n - 1, A) + fibo(n - 2, A);
        return A[n];
    }
}

int main() {
    int n = 8;
    int A[100];
    for (int i = 0; i < 9; i++) {
        A[i] = -1;
    }

    int result = fibo(n, A);
    cout << "Fibonacci number " << n << " is: " << result << endl;

    return 0;
}

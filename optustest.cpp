#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n <= 1) {
        cout << n << " is not a prime number.";
        return 0;
    }
    if (n <= 3) {
        cout << n << " is a prime number.";
        return 0;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        cout << n << " is not a prime number.";
        return 0;
    }
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            cout << n << " is not a prime number.";
            return 0;
        }
    }
    cout << n << " is a prime number.";
    return 0;

}
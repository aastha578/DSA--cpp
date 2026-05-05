#include <iostream>
using namespace std;

int main() {
    int n = 8; // number of rows

    for (int i = 0; i < n; i++) {
        // Print numbers decreasing from n-1-i to 0
        for (int j = n - 1 - i; j >= 0; j--) {
            cout << j << " ";
        }
        cout << endl; // move to the next row
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int q[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    // Input queue elements
    for (int i = 0; i < n; i++)
        cin >> q[i];

    // Sort elements using Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (q[j] > q[j + 1]) {
                int temp = q[j];
                q[j] = q[j + 1];
                q[j + 1] = temp;
            }
        }
    }

    cout << "Sorted elements: ";
    for (int i = 0; i < n; i++)
        cout << q[i] << " ";

    return 0;
}

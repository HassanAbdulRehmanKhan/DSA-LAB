#include <iostream>
using namespace std;

int main() {
    int q[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    // Input queue elements
    for (int i = 0; i < n; i++)
        cin >> q[i];

    // Find the minimum element
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (q[j] < q[minIndex])
                minIndex = j;
        }

        int temp = q[i];
        q[i] = q[minIndex];
        q[minIndex] = temp;
    }

    cout << "Sorted elements: ";
    for (int i = 0; i < n; i++)
        cout << q[i] << " ";

    return 0;
}

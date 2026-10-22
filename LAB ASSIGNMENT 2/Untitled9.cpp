#include <iostream>
using namespace std;

int main() {
    int s[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    // Input stack elements
    for (int i = 0; i < n; i++)
        cin >> s[i];

    // Sort elements using Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = s[i];
        int j = i - 1;

        while (j >= 0 && s[j] > key) {
            s[j + 1] = s[j];
            j--;
        }

        s[j + 1] = key;
    }

    cout << "Sorted elements: ";
    for (int i = 0; i < n; i++)
        cout << s[i] << " ";

    return 0;
}

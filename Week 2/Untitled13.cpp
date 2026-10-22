#include <iostream>
using namespace std;

int main() {
    int d = 45;

    // declare pointer and store address of var
    int* ptr = & d;
    *ptr =33;
//	ptr = d;
    // print value and address
    cout << "Value of var: " << d << endl;
    cout << "Address of var: " << &d << endl;
    cout << "Value stored in pointer ptr: " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    return 0;
}

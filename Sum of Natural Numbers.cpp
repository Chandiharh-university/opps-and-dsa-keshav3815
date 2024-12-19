#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 1) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    int sum = n * (n + 1) / 2;  
    cout << "Sum of the first " << n << " natural numbers is: " << sum << endl;

    return 0;
}

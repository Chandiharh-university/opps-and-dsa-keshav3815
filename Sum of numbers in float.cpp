#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;  
    cout << "How many numbers do you want to sum? ";
    cin >> n;

    vector<float> numbers(n);
    float sum = 0.0;

    cout << "Enter " << n << " floating-point numbers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
        sum += numbers[i];  
    }

    cout << "The sum of the entered numbers is: " << sum << endl;

    return 0;
}

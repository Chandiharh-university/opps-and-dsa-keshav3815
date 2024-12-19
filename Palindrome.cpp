 #include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    int start = 0;
    int end = str.length() - 1;
    while (start < end) {
        if (!isalnum(str[start])) {
            start++;
        } else if (!isalnum(str[end])) {
            end--;
        } else if (str[start] != str[end]) {
            return false;   
        } else {
            start++;
            end--;
        }
    }
    return true;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);   

    if (isPalindrome(str)) {
        cout << "\"" << str << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << str << "\" is not a palindrome." << endl;
    }

    return 0;
}

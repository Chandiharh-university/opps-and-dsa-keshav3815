 #include <iostream>
using namespace std;
void passByValue(int value) {
    value += 25;  
    cout << "Inside passByValue function, value = " << value << endl;
}
void passByReference(int &ref) {
    ref += 25;  
    cout << "Inside passByReference function, ref = " << ref << endl;
}
void staticCounter() {
    static int counter = 0; 
    counter++;
    cout << "Static counter value: " << counter << endl;
}

int main() {
    int userValue, userReference;
    cout << "Enter a value for pass by value: ";
    cin >> userValue;
    cout << "Enter a value for pass by reference: ";
    cin >> userReference;
    cout << "Before passByValue function, userValue = " << userValue << endl;
    passByValue(userValue);
    cout << "After passByValue function, userValue = " << userValue << endl;
    cout << "Before passByReference function, userReference = " << userReference << endl;
    passByReference(userReference);
    cout << "After passByReference function, userReference = " << userReference << endl;
    cout << "The memory address of userReference is: " << &userReference << endl;
    cout << "Calling staticCounter multiple times:\n";
    staticCounter();
    staticCounter();
    staticCounter();

    return 0;
}

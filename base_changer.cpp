#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    cout << "Enter your base: ";
    int base;
    cin >> base;

    cout << "Enter your number in your base <= 10: ";
    int num;
    cin >> num;

    cout << "Enter your destination base: ";
    int finalBase;
    cin >> finalBase;

    string finalNum = "";

    while (num > 0) {
        finalNum += num % base;
        num /= base;
    }

    cout << "Your number in base " << base << " is " << finalNum << endl;

    return 0;
}
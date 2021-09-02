#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <math.h>

using namespace std;

int main() {
    map<char, int> hex_to_int = {{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9},{'A',10},{'B',11},{'C',12},{'D',13},{'E',14},{'F',15}};
    map<int,string>  int_to_hex = {{1,"1"},{2,"2"},{3,"3"},{4,"4"},{5,"5"},{6,"6"},{7,"7"},{8,"8"},{9,"9"},{10,"A"},{11,"B"},{12,"C"},{13,"D"},{14,"E"},{15,"F"}};
    cout << "Enter your base: ";
    int base;
    cin >> base;

    cout << "Enter your number in your base <= 16: ";
    string num = string();
    cin >> num;

    cout << "Enter your destination base: ";
    int finalBase;
    cin >> finalBase;

    int curr_exp = 0;
    int tempNum = 0;
    string finalNum = 0;

    while (num != string()) {
        char& tempchar = (num.back());
        tempNum += hex_to_int[tempchar] * int(pow(base,curr_exp));
        num.pop_back();
        curr_exp++;
    }

    cout << "Your number in base 10 is : " << tempNum << endl;

    while (tempNum > 0) {
        int modulo = tempNum % finalBase;
        string cha = int_to_hex[modulo];
        finalNum = cha + finalNum;
        tempNum /= finalBase;
    }

    cout << "Your number in base " << base << " is " << finalNum << endl;

    return 0;
}


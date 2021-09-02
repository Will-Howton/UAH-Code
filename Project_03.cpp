#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    //take all the user input and store it in variables
    double startingBalance;
    cout << "Input the starting balance: ";
    cin >> startingBalance;
    cout << startingBalance<<endl;

    double interestRate;
    double interestRatePercent;
    cout << "Input the interest rate (Ex: 5 for 5%): ";
    cin >> interestRatePercent;
    interestRate = interestRatePercent/100;
    cout << interestRatePercent<<endl;

    double time;
    cout << "Input the number of years";
    cin >> time;
    cout << time<<endl;

    //print out all the values and filler text in the program

    cout << endl;

    cout << fixed << showpoint << setprecision(2) << "For a principle of " << startingBalance << endl;
    cout << setprecision(2) << "at an interest rate of " << interestRate*100 << endl;
    cout << setprecision(2) << "for a period of " << time << endl;
    cout << setprecision(2) << "the final account balance would be:" << endl<<endl;

    //calculate all the interest rates using normal formulas

    double simpInterest = startingBalance * (1 + interestRate * time);
    double compInterestMonthly = startingBalance * pow(1 + interestRate / 12, time * 12);
    double compInterestDaily = startingBalance * pow(1 + interestRate / 365, time * 365);
    double compInterestContinuous = startingBalance * exp(interestRate * time);

    /*calculate the effective interest rate and total interest using the simple interest formula and effective rate*/

    double effectiveInterestRateContinuous = (exp(interestRate * time) - 1) / time;
    double simpInterestEffectiveContinuous = startingBalance * (1 + effectiveInterestRateContinuous * time);

    double effectiveInterestRateDaily = (pow(1+interestRate/365, time*365) - 1) / time;
    double simpInterestEffectiveDaily = startingBalance * (1 + effectiveInterestRateDaily * time);

    double effectiveInterestRateMonthly = (pow(1+interestRate/12, time*12) - 1) / time;
    double simpInterestEffectiveMonthly = startingBalance * (1 + effectiveInterestRateMonthly * time);

    /*print all of the calculated interest rates*/

    cout << "Simple Interest:" << endl;
    cout << setprecision(2) << "\tBalance = $" << simpInterest << endl<<endl;

    cout << "Compounded Monthly:" << endl;
    cout << setprecision(2) << "\tBalance = $" << compInterestMonthly << endl;
    cout << "\tThe Effective Simple Interest Rate: " << effectiveInterestRateMonthly*100 <<"%\n";
    cout << "\tBalance using Simple Interest at the Effect Rate = $" << simpInterestEffectiveMonthly << endl<<endl;

    cout << "Compounded Daily:" << endl;
    cout << setprecision(2) << "\tBalance = $" << compInterestDaily << endl;
    cout << "\tThe Effective Simple Interest Rate: " << effectiveInterestRateDaily*100 <<"%\n";
    cout << "\tBalance using Simple Interest at the Effect Rate = $" << simpInterestEffectiveDaily << endl<<endl;

    cout << "Compounded Monthly:" << endl;
    cout << setprecision(2) << "\tBalance = $" << compInterestContinuous << endl;
    cout << "\tThe Effective Simple Interest Rate: " << effectiveInterestRateContinuous*100 <<"%\n";
    cout << "\tBalance using Simple Interest at the Effect Rate = $" << simpInterestEffectiveContinuous << endl<<endl;
}
//  =============== BEGIN ASSESSMENT HEADER ================
/// @file mathematics.cpp
/// @brief assn6/mathematics
///
/// @author Ryan Ulep [rulep001@ucr.edu]
/// @date May 21, 2015
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment,
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <ios>
#include <iomanip>

using namespace std;

const int OK = 0;
const int DIV_ZERO = 1;
const int SQRT_ERR = 2;

/// @brief acquire the proper number of numeric inputs based on operation string
///The numeric inputs are set into x, y, and z in that order;
///the number of numeric inputs acquired is returned to the caller.
///Not all operations require all three values:
///do not set/assign values to operands that are not used by the operation.
///
/// @param op the operation to be performed such as "division"
/// @param x the first numeric input
/// @param y the second numeric input
/// @param z the third numeric input
/// @return the number of numeric inputs that were acquired

int acquireOperands(const string &op, double &x, double &y, double &z)
{
    int operands = 0;

    if (op == "division" || op == "pythagorean") {
        cout << "Enter your first number: ";
        cin >> x;
        cout << endl << "Enter your second number: ";
        cin >> y;
        operands = 2;
    }

    else if (op == "quadratic") {
        cout << "Enter your first number: ";
        cin >> x;
        cout << endl << "Enter your second number: ";
        cin >> y;
        cout << endl << "Enter your third number: ";
        cin >> z;
        operands = 3;
    }
    cout << endl;

    return operands;
}

///@briefcalculatequotientforprovidedvalues(a/b);returnserrorcode ///
///@paramathedividendoftheequation
///@parambthedivisoroftheequation
///@paramresultreferencetoplacethequotientin
///@returnreturnstheintegerrepresentingthestateofthecalculation
/// using global constants for OK and DIV_ZERO
/// int division(double a,double b,double &result);

int division(double a, double b, double &result) {
    if (b != 0) {
        result = a / b;
        return OK;
    }

    else {
        return DIV_ZERO;
    }
}

/// @briefcalculatecforthepythagoreantheorema^2+b^2=c^2
///
/// @paramathevalueofaintheequation
/// @parambthevalueofbintheequation
/// @paramcreferenceforthehypotenusevalue
/// @returnreturnstheintegerrepresentingthestateofthecalculation
/// using global constant for OK intpythagorean(doublea,doubleb,double&c);

int pythagorean(double a, double b, double &c) {
    c = sqrt(pow(a, 2.0) + pow(b, 2.0));
    return OK;
}

int quadratic (double a,double b,double c,double &quadroot1,double &quadroot2)
{
    if ((2 * a) == 0) {

        return DIV_ZERO;
    }

    else if ((pow(b, 2.0) - 4 * a * c) < 0) {

        return SQRT_ERR;
    }

    else {
        quadroot1 = (-b + sqrt(pow(b, 2.0) - 4 * a * c)) / (2 * a);
        quadroot2 = (-b - sqrt(pow(b, 2.0) - 4 * a * c)) / (2 * a);

        return OK;
    }
}

int main ()
{
    double x = 0;
    double y = 0;
    double z = 0;

    double hypotenuse = 0;
    double quadroot1 = 0;
    double quadroot2 = 0;
    double quotient = 0;
    string op;

    cout << "Please choose an operation: ";
    cin >> op;

    cout << endl;

    while ((op != "division") && (op != "quadratic") && (op != "pythagorean")) {
        cout << "Error: Operation not supported." << endl;
        cout << "Please choose an operation: ";
        cin >> op;
        cout << endl;
    }

    int opRes = acquireOperands(op, x, y, z);

    if (opRes == 3) {
        cout << "Equation: " << x << "x^2 + " << y << "x + ";
        cout << z << " = 0" << endl;

        int quadRes = quadratic(x, y, z, quadroot1, quadroot2);

        if (quadRes == 0) {

            if (quadroot1 == quadroot2) {
                cout << "Result: " << quadroot1 << endl;
            }

            else if (quadroot1 < quadroot2) {
                cout << "Result: " << quadroot1 << ", " << quadroot2 << endl;
            }

            else {
                cout << "Result: " << quadroot2 << ", " << quadroot1 << endl;
            }
        }

        else if (quadRes == 1) {
            cout << "Error: Cannot divide by zero." << endl;
        }

        else {
            cout << "Error: Cannot take square root of a negative number."
            << endl;
        }

    }
    else {
        if (op == "division") {
            cout << "Equation: " << x << " / " << y << endl;

            division(x, y, quotient);

            if (division(x, y, quotient) == 0) {
                cout << "Result: " << quotient << endl;
            }

            else {
                cout << "Error: Cannot divide by zero." << endl;
            }
        }

        else {
            cout << "Equation: sqrt(" << x << "^2 + " << y << "^2)" << endl;

            pythagorean(x, y, hypotenuse);

            cout << "Result: " << hypotenuse << endl;
        }

    }

    return 0;
}

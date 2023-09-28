//I'm not sure I'm using the word "increment" correctly in most of the program, but I'm trying to refer to the position of something in an array
#include <iostream>
using namespace std;

int result = 0; //result of the factorial function
int number = 0; //the number we wish to find the factorial of
char oper; //input to choose the operatot for the math operation
int num1; //number for math operator
int num2; //number for math operator
const int n = 4;
const int m = 4;
int poly1[n] = {};
int poly2[m] = {};
int polyAddedSum[n]; //empty array where we assign the sum of the addition between two arrays
int polySubtSum[n]; //empty array where we assign the sum of the subtraction between two arrays
int polyMultSum[n + m - 1]; //empty array where we assign the sum of both arrays multiplied, where the length is the sum of the length of both arrays

/// <summary>
/// (recursive) function to find the factorial sum of a given number
/// </summary>
/// <param name="n">number we want to find the factorial of</param>
/// <returns>result of the factorial sum</returns>
int factorial(int n) {
    if ((n >= 0) && (n % 1 == 0)) { //checks if the number is less than zero, as well as checking if it's an integer
        if ((n == 1) || (n == 0)) { //checks if our number is equal to zero or one, since 1! and 0! are equal to 0. this is the simplest version of the problem, and thus the base case
            result = 1;
        }
        else {
            result = n * factorial(n - 1); //takes the number and runs the function again to multiply it with the next number until we reach the base case
        }

        return result;
    }
    else {
        cout << "nuh uh (invalid number) \n"; //outputs when the input number is invalid 
        return 0;
    }
}

/// <summary>
/// function to output a givenarray as a polynomial with each increment as its exponent
/// </summary>
/// <param name="poly">the array we want to output</param>
/// <param name="n">length of the array</param>
void polyPrint(int poly[], int n) {
    for (int i = 0; i < n; i++) { 
        if (poly[i] != 0) { //outputs for every increment of the array where the value is not zero 
            cout << poly[i];  
            if (i > 1) 
                cout << "x^" << i; //adds an x-value to the power of the position of the array, convenient since the 
            if (i == 1) 
                cout << "x"; // same as the above but since it's to the power of 1, it can just be written as "x" 
            if ((i != n - 1) && (poly[i + 1] != 0)) 
                cout << " + "; //prints a plus sign so long as the loop isn't at the end of the array, and as long as the next number in trhe array is not zero 
        } 
    }
}

/// <summary>
/// function to add together two polynomials 
/// </summary>
/// <param name="poly1">first array/polynomial</param>
/// <param name="poly2">second array/polynomial</param>
/// <param name="polySum">third array where we assign the sums of the first and second arrays</param>
/// <param name="n">length of the array</param>
void polyAdd(int poly1[], int poly2[], int polySum[], int n) { //only using one parameter for length since the arrays are the same length
    for (int i = 0; i < n; i++) {
        polySum[i] = poly1[i] + poly2[i]; //adds together each number at every instance(exponent) of the array
    }
}

/// <summary>
/// function to subtract two polynomials
/// </summary>
/// <param name="poly1">first array/polynomial</param>
/// <param name="poly2">second array/polynomial</param>
/// <param name="polySum">third array where we assign the sums of the first and second arrays</param>
/// <param name="n">length of the array</param>
void polySubtract(int poly1[], int poly2[], int polySum[], int n) {
    for (int i = 0; i < n; i++) {
        polySum[i] = poly1[i] - poly2[i]; //subtracts each number at every instance(exponent) of the array
    }
}

/// <summary>
/// function to multiply two polynomials
/// </summary>
/// <param name="poly1">first array/polynomial</param>
/// <param name="poly2">second array/polynomial</param>
/// <param name="n">length of first array/polynomial</param>
/// <param name="m">length of second array/polynomial</param>
void polyMultiply(int poly1[], int poly2[], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { //using two for-loops to compare one instance(at a time) of the first array to every instance of the second array
            polyMultSum[i + j] += poly1[i] * poly2[j];
        }
    }
    polyPrint(polyMultSum, n + m - 1); //outputs the result of the multiplication as an array with the length of 
}

void polyDerive(int poly[], int n) {
    for (int i = 0; i < n; i++) {
        poly[i] *= i; //multiplies the number with the exponent, standard derivation rules
        if (poly[i] != 0) { //outputs for every instance of the array where the value is not zero 
            cout << poly[i];
            if (i - 1 > 1) //we use i - 1 due to derivation rules
                cout << "x^" << i - 1; //adds an x-value to the power of the position of the array, convenient since the
            if (i - 1 == 1)
                cout << "x"; // same as the above but since it's to the power of 1, it can just be written as "x"
            if ((i != n - 1) && (poly[i + 1] != 0))
                cout << " + "; //prints a plus sign so long as the loop isn't at the end of the array, and as long as the next number in trhe array is not zero
        }
    }
}

int main() {

    int selectedMenu = 0; //value to determine a switch-case menu to replicate a main-menu 
    int selectedPolyMenu = 0; //value to determine a switch-case menu for the polynomials 
    int selectedOpMenu = 0; //value to determine a switch-case menu for the math operation 
    int selectedPoly = 0; //value to determine the first or second polynomial is selected

    while (selectedMenu == 0) { 
        cout << "1. find factorial of a number \n";
        cout << "2. polynomials \n";
        cout << "3. simple math operations \n";
        cout << "4. Exit \n";
        cin >> selectedMenu; 
         
        switch (selectedMenu) { 
        case 1: //FACTORIAL 
            cout << "what number do you want to factorise? \n";
            cin >> number;
            factorial(number);
            if((factorial(number)) != 0)
                cout << number << "'s factorial is: " << result;

            cout << "\n\n----------------------------------------------------------------------------------------------\n\n";
            selectedMenu = 0; 
            break;

        case 2: //POLYNOMIALS
            selectedPolyMenu = 0; //resets the value to ensure the menu works
            /* makes the user input the polynomials before they can do anything with them
            we don't want to be able to print two arrays that are empty */
            cout << "first polynomial: \n";
            for (int i = 0; i < n; i++)
                cin >> poly1[i];

            cout << "Second polynomial: \n";
            for (int i = 0; i < m; i++)
                cin >> poly2[i];

            while (selectedPolyMenu == 0) {
                cout << "\n1. Print polynomials \n";
                cout << "2. Add polynomials \n";
                cout << "3. Subtract polynomials \n";
                cout << "4. Multiply polynomials \n";
                cout << "5. Derive polynomials \n";
                cout << "6. Go Back \n";
                cin >> selectedPolyMenu;

                switch (selectedPolyMenu) {

                case 1: //PRINT POLYNOMIALS

                    cout << "1. polynomial is: "; polyPrint(poly1, n);
                    cout << "\n2. polynomial is: "; polyPrint(poly2, n);

                    cout << "\n";
                    selectedPolyMenu = 0;
                    break;
                case 2: //ADD POLYNOMIALS
                    polyAdd(poly1, poly2, polyAddedSum, n);
                    cout << "("; polyPrint(poly1, n); cout << ")"; cout << " + "; cout << "("; polyPrint(poly2, n); cout << ")"; cout << " = "; polyPrint(polyAddedSum, n); //clearer way to show the operation in the output

                    cout << "\n";
                    selectedPolyMenu = 0;
                    break;
                case 3: //SUBTRACT POLYNOMIALS
                    polySubtract(poly1, poly2, polySubtSum, n);
                    cout << "("; polyPrint(poly1, n); cout << ")"; cout << " - "; cout << "("; polyPrint(poly2, n); cout << ")"; cout << " = "; polyPrint(polySubtSum, n); //clearer way to show the operation in the output

                    cout << "\n";
                    selectedPolyMenu = 0;
                    break;
                case 4: //MULTIPLY POLYNOMIALS
                    cout << "("; polyPrint(poly1, n); cout << ")"; cout << " * "; cout << "("; polyPrint(poly2, n); cout << ")"; cout << " = "; polyMultiply(poly1, poly2, m, n); //clearer way to show the operation in the output. function is at the end of this line

                    cout << "\n";
                    selectedPolyMenu = 0;
                    break;
                case 5: //DERIVE POLYNOMIALS
                    cout << "choose a polynomial to derive: \n";
                    cout << "1. "; polyPrint(poly1, n);
                    cout << "\n2. "; polyPrint(poly2, m);
                    cout << "\n"; 
                    cin >> selectedPoly;
                    switch (selectedPoly) {
                        case 1:
                            polyDerive(poly1, n);
                            break;

                        case 2:
                            polyDerive(poly2, m);
                            break;

                        default:
                            cout << "invalid input";
                            break;
                    }

                    cout << "\n";
                    selectedPolyMenu = 0;
                    break;
                case 6: //return to main menu

                    selectedMenu = 0;
                    break;
                }

            }

            cout << "\n\n----------------------------------------------------------------------------------------------\n\n";
            selectedMenu = 0;
            break;

        case 3: //MATH OPERATIONS
            cout << "enter an operator: +, -, *, / : \n";
            cin >> oper;
            cout << "enter two numbers \n";
            cin >> num1 >> num2;

            switch (oper) {
            case '+':
                cout << num1 << " + " << num2 << " = " << num1 + num2; //addition
                break;
            case '-':
                cout << num1 << " - " << num2 << " = " << num1 - num2; //subtraction
                break;
            case '*':
                cout << num1 << " * " << num2 << " = " << num1 * num2; //multiplication
                break;
            case '/':
                cout << num1 << " / " << num2 << " = " << num1 / num2; //division
                break;
            default:
                cout << "how"; //I have no idea how someone can reach this case 
                return 0;
                break;

            }

            cout << "\n\n----------------------------------------------------------------------------------------------\n\n";
            selectedMenu = 0;
            break;

        }
    }

    return 0;
}
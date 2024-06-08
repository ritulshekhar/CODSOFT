//Simple Calculator

#include <iostream>
using namespace std;
int main()
{
    int choice;
    cout << "Choose the Operation: " << endl;                   //Choose the Operation needed to perform
    cout << " Addition -> 1 \n Subtraction -> 2 \n Multiplication -> 3 \n Division -> 4 \n";
    cin >> choice;
    int FirstNumber, SecondNumber;                              //Enter values for the numbers
    cout << "Enter First Number: " << endl;
    cin >> FirstNumber;
    cout << "Enter Second Number: " << endl;
    cin >> SecondNumber;
    int Sum, Difference, Product;
    float Quotient;
    switch (choice)
    {
    case 1:
        Sum = FirstNumber + SecondNumber;                       //Addition is being performed
        cout << "After Addition, Sum is: " << Sum << endl;
        break;
    case 2:
        if (FirstNumber > SecondNumber)
        {
            Difference = FirstNumber - SecondNumber;            //Subtraction is being performed
            cout << "After Subtraction, Difference is: " << Difference << endl;
        }
        else
        {
            Difference = SecondNumber - FirstNumber;
            cout << "After Subtraction, Difference is: " << Difference << endl;
        }
        break;
    case 3:
        Product = FirstNumber * SecondNumber;                   //Multiplication is being performed
        cout << "After Multiplication, Product is: " << Product << endl;
        break;
    case 4:
        if (SecondNumber != 0)
        {
            Quotient = static_cast<float>(FirstNumber) / (SecondNumber);        //Division is being performed
            cout << "After Division, Quotient is: " << Quotient << endl;
        }
        else
        {
            cout << "Division by Zero! " << endl;
        }
        break;
    default:
        cout << "Enter valid operation!" << endl;
    }
    return 0;
}
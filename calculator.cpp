#include <iostream>

using namespace std;

void displayMenu() {
    cout << "Simple Calculator\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Exit\n";
    cout << "Choose an option (1-5): ";
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        cout << "Error! Division by zero.\n";
        return 0;
    }
    return a / b;
}

int main() {
    int choice;
    double num1, num2, result;

    do {
        displayMenu();
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting the calculator. Goodbye!\n";
            break;
        }

        if (choice < 1 || choice > 5) {
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;

        switch (choice) {
            case 1:
                result = add(num1, num2);
                cout << "Result: " << num1 << " + " << num2 << " = " << result << "\n";
                break;
            case 2:
                result = subtract(num1, num2);
                cout << "Result: " << num1 << " - " << num2 << " = " << result << "\n";
                break;
            case 3:
                result = multiply(num1, num2);
                cout << "Result: " << num1 << " * " << num2 << " = " << result << "\n";
                break;
            case 4:
                result = divide(num1, num2);
                if (num2 != 0) {
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << "\n";
                }
                break;
        }
    } while (true);

    return 0;
}

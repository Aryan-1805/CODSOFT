#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100;
string titles[MAX_BOOKS];
string authors[MAX_BOOKS];
string ISBNs[MAX_BOOKS];
bool isAvailable[MAX_BOOKS];
int bookCount = 0;

int main() {
    int choice;

    do {
        // Display menu
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Check Out Book\n";
        cout << "4. Return Book\n";
        cout << "5. Calculate Fine\n";
        cout << "6. Exit\n";
        cout << "Choose an option (1-6): ";
        cin >> choice;

        if (choice == 1) {
            // Add Book
            if (bookCount >= MAX_BOOKS) {
                cout << "Library is full. Cannot add more books.\n";
                continue;
            }

            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, titles[bookCount]);
            cout << "Enter book author: ";
            getline(cin, authors[bookCount]);
            cout << "Enter book ISBN: ";
            getline(cin, ISBNs[bookCount]);
            isAvailable[bookCount] = true;
            bookCount++;
            cout << "Book added successfully!\n";

        } else if (choice == 2) {
            string query;
            cout << "Enter title, author, or ISBN to search: ";
            cin.ignore();
            getline(cin, query);

            bool found = false;
            for (int i = 0; i < bookCount; ++i) {
                if (titles[i] == query || authors[i] == query || ISBNs[i] == query) {
                    cout << "Book found: " << titles[i] << " by " << authors[i] << " (ISBN: " << ISBNs[i] << ")";
                    cout << (isAvailable[i] ? " [Available]\n" : " [Checked out]\n");
                    found = true;
                }
            }
            if (!found) {
                cout << "No book found with the given query.\n";
            }

        } else if (choice == 3) {
            // Check Out Book
            string ISBN;
            cout << "Enter ISBN of the book to check out: ";
            cin.ignore();
            getline(cin, ISBN);

            bool found = false;
            for (int i = 0; i < bookCount; ++i) {
                if (ISBNs[i] == ISBN && isAvailable[i]) {
                    isAvailable[i] = false;
                    cout << "Book checked out successfully!\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not available for checkout.\n";
            }

        } else if (choice == 4) {
            // Return Book
            string ISBN;
            cout << "Enter ISBN of the book to return: ";
            cin.ignore();
            getline(cin, ISBN);

            bool found = false;
            for (int i = 0; i < bookCount; ++i) {
                if (ISBNs[i] == ISBN && !isAvailable[i]) {
                    isAvailable[i] = true;
                    cout << "Book returned successfully!\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found or already available.\n";
            }

        } else if (choice == 5) {
            // Calculate Fine
            int daysLate;
            cout << "Enter the number of days the book is late: ";
            cin >> daysLate;

            const int finePerDay = 1; // Assuming a fine of 1 unit per day
            int fine = daysLate * finePerDay;
            cout << "The total fine is: " << fine << " units.\n";

        } else if (choice == 6) {
            // Exit
            cout << "Exiting the library management system. Goodbye!\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

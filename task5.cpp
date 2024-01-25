#include <iostream>
//#include <sstream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int isbn;
    bool checkedOut;

public:
    Book() {}
    Book(const string& title, const string& author, int isbn)
        : title(title), author(author), isbn(isbn), checkedOut(false) {
    }

    const string& getTitle() const {
        return title;
    }

    const string& getAuthor() const {
        return author;
    }

    int getIsbn() const {
        return isbn;
    }

    bool isCheckedOut() const {
        return checkedOut;
    }

    void checkOut() {
        if (checkedOut) {
            cout << "Book is already checked out." << endl;
        }
        else {
            checkedOut = true;
            cout << "Book checked out successfully." << endl;
        }
    }

    void returnBook() {
        if (!checkedOut) {
            cout << "Book is not checked out." << endl;
        }
        else {
            checkedOut = false;
            cout << "Book returned successfully." << endl;
        }
    }
};

class Library {
private:
    static const int MAX_BOOKS = 3;
    Book books[MAX_BOOKS];
    int bookCount;

public:
    Library() : bookCount(0) {}

    void addBook(const string& title, const string& author, int isbn) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount++] = Book(title, author, isbn);
            cout << " Book added " << endl;
        }
        else {
            cout << "Library is full. Cannot add more books." << endl;
        }
    }

    void searchBooks(const string& query) const {
        int resultCount = 0;

        for (int i = 0; i < bookCount; ++i) {
            if (books[i].getTitle().find(query) != books[i].getTitle().length() ||
                books[i].getAuthor().find(query) != books[i].getAuthor().length() ||
                to_string(books[i].getIsbn()).find(query) != to_string(books[i].getIsbn()).length()) {
                cout << "Title: " << books[i].getTitle() << ", Author: " << books[i].getAuthor()
                    << ", ISBN: " << books[i].getIsbn() << ", Checked Out: "
                    << (books[i].isCheckedOut() ? "Yes" : "No") << endl;
                ++resultCount;
            }
        }

        if (!resultCount) {
            cout << "No books found matching the search query." << endl;
        }
    }

    void checkoutBook(int isbn) {
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].getIsbn() == isbn) {
                books[i].checkOut();
                return;
            }
        }

        cout << "Book with ISBN " << isbn << " not found in the database." << endl;
    }

    void returnBook(int isbn) {
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].getIsbn() == isbn) {
                books[i].returnBook();
                return;
            }
        }

        cout << "Book with ISBN " << isbn << " not found in the database." << endl;
    }
};

int main() {
    Library library;
    Library l2;
    string B_N;
    cout << "Enter the book name: ";
    cin >> B_N;
    string A_N;
    cout << "Enter the author name: ";
    cin >> A_N;
    int I_N;
    cout << "Enter the ISBN num: ";
    cin >> I_N;

    library.addBook(B_N, A_N, I_N);
    while (true) {
        cout << "\n===== Library Management System =====" << endl;
        cout << "1. Search for a book" << endl;
        cout << "2. Checkout a book" << endl;
        cout << "3. Return a book" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cin.ignore(); // Clear any previous input from the buffer
            cout << "Enter search for book: ";
            string query;
            getline(cin, query); // Use getline to read the entire line
            library.searchBooks(query);
            break;
        }
        case 2:
        {
            int ISBN;
            cout << "Enter ISBN of the book to checkout: ";
            cin >> ISBN;
            library.checkoutBook(ISBN);
            break;
        }
        case 3: {
            int ISBN;
            cout << "Enter ISBN of the book to return: ";
            cin >> ISBN;
            library.returnBook(ISBN);
            break;
        }
        case 4:
            cout << "Exiting Library Management System. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

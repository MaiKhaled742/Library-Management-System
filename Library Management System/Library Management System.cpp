#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Book
{
	int id;
	string title;
	string author;
	bool isBorrowed;
	int borrowedBy;

};

struct User
{
	int id;
	string name;
};

vector <Book> books;
User currentUser = { 1, "Rana" };

void addBook()
{
	Book b;

	cout << "\nEnter Book ID: ";
	cin >> b.id;
	cin.ignore();

	cout << "\nEnter Book Title: ";
	getline(cin, b.title);

	cout << "\nEnter Author Name: ";
	getline(cin, b.author);

	b.isBorrowed = false;
	b.borrowedBy = -1;

	books.push_back(b);
	cout << "\nBook Added Successfully\n";
}

void viewAvailableBooks()
{
    bool found = false;

    cout << "\n****** Available Books ******\n";

    for (int i = 0; i < books.size(); i++)
    {
        if (!books[i].isBorrowed)
        {
            cout << "ID: " << books[i].id << endl;
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "----------------------\n";

            found = true;
        }
    }

    if (!found)
    {
        cout << "No Available Books.\n";
    }
}

void borrowBook()
{
    int id;

    cout << "\nEnter Book ID to Borrow: ";
    cin >> id;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].id == id)
        {
            if (books[i].isBorrowed)
            {
                cout << "Book is already borrowed.\n";
                return;
            }

            books[i].isBorrowed = true;
            books[i].borrowedBy = currentUser.id;

            cout << "Book Borrowed Successfully!\n";
            return;
        }
    }

    cout << "Book Not Found.\n";
}

void returnBook()
{
    int id;

    cout << "\nEnter Book ID to Return: ";
    cin >> id;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].id == id)
        {
            if (!books[i].isBorrowed)
            {
                cout << "This book is not borrowed.\n";
                return;
            }

            if (books[i].borrowedBy != currentUser.id)
            {
                cout << "You didn't borrow this book.\n";
                return;
            }

            books[i].isBorrowed = false;
            books[i].borrowedBy = -1;

            cout << "Book Returned Successfully!\n";
            return;
        }
    }

    cout << "Book Not Found.\n";
}

void viewMyBorrowedBooks()
{
    bool found = false;

    cout << "\n****** My Borrowed Books ******\n";

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].borrowedBy == currentUser.id)
        {
            cout << "ID: " << books[i].id << endl;
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "----------------------\n";

            found = true;
        }
    }

    if (!found)
    {
        cout << "You have no borrowed books.\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n--------- Library Management System ---------\n";
        cout << "1. View Available Books\n";
        cout << "2. Borrow a Book\n";
        cout << "3. Return a Book\n";
        cout << "4. View My Borrowed Books\n";
        cout << "5. Add a Book to Library\n";
        cout << "6. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            viewAvailableBooks();
            break;

        case 2:
            borrowBook();
            break;

        case 3:
            returnBook();
            break;

        case 4:
            viewMyBorrowedBooks();
            break;

        case 5:
            addBook();
            break;

        case 6:
            cout << "Good Bye!\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 6);

    return 0;
}

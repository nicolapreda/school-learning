#include <iostream>

using namespace std;

//create a struct to store the book information (code, title, author, year of publication, editorial)
struct Book {
    string code;
    string title;
    string author;
    int year;
    string editorial;
};

// add a new book to the library
void addBook(Book *library, int &size) {
    Book newBook;
    cout << "Insert the code of the book: ";
    cin >> newBook.code;
    cout << "Insert the title of the book: ";
    cin >> newBook.title;
    cout << "Insert the author of the book: ";
    cin >> newBook.author;
    cout << "Insert the year of publication of the book: ";
    cin >> newBook.year;
    cout << "Insert the editorial of the book: ";
    cin >> newBook.editorial;
    library[size] = newBook;
    size++;
}

//create a function to show the book library
void showLibrary(Book *library, int size) {
    cout<<"Elenco completo:"<<endl;
    for (int i = 0; i < size; i++) {
        cout << "Title: " << library[i].title << endl;
    }
}

//create a function to search a book by code
void searchBook(Book *library, int size) {
    string code;
    cout << "Insert the code of the book: ";
    cin >> code;
    for (int i = 0; i < size; i++) {
        if (code == library[i].code) {
            cout << "Title: " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "Year of publication: " << library[i].year << endl;
            cout << "Editorial: " << library[i].editorial << endl;
        }
    }
}

// create a function to search a book by title
void searchBookByTitle(Book *library, int size) {
    string title;
    cout << "Insert the title of the book: ";
    cin >> title;
    for (int i = 0; i < size; i++) {
        if (title == library[i].title) {
            cout << "Code: " << library[i].code << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "Year of publication: " << library[i].year << endl;
            cout << "Editorial: " << library[i].editorial << endl;
        }
    }
}

int main(){
    int size = 0;
    Book library[100];
    int choice;
    do {
        cout << "1. Add a book" << endl;
        cout << "2. Show the library" << endl;
        cout << "3. Search a book by code" << endl;
        cout << "4. Search a book by title" << endl;
        cout << "5. Exit" << endl;
        cout << "Insert your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addBook(library, size);
                break;
            case 2:
                showLibrary(library, size);
                break;
            case 3:
                searchBook(library, size);
                break;
            case 4:
                searchBookByTitle(library, size);
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 5);
    return 0;
}
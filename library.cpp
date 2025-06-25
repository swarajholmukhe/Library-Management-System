#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    int id;
    string title, author;
    bool isIssued = false;

    Book(int id, string title, string author) : id(id), title(title), author(author) {}

    void display() const {
        cout << "[" << id << "] \"" << title << "\" by " << author << " - "
             << (isIssued ? "Issued" : "Available") << "\n";
    }
};

class Library {
    vector<Book> books;

public:
    void add(int id, const string& title, const string& author) {
        books.emplace_back(id, title, author);
        cout << "✅ Book added!\n";
    }

    void show() const {
        if (books.empty()) {
            cout << "📚 No books available.\n";
            return;
        }
        for (const auto& book : books) book.display();
    }

    void issue(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                if (!book.isIssued) {
                    book.isIssued = true;
                    cout << "📕 Book issued.\n";
                } else cout << "⚠️ Already issued.\n";
                return;
            }
        }
        cout << "❌ Book not found.\n";
    }

    void ret(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                if (book.isIssued) {
                    book.isIssued = false;
                    cout << "📗 Book returned.\n";
                } else cout << "⚠️ Book wasn't issued.\n";
                return;
            }
        }
        cout << "❌ Book not found.\n";
    }
};

int main() {
    Library lib;
    int ch;

    while (true) {
        cout << "\n📘 Library Menu\n1. Add Book\n2. Show Books\n3. Issue Book\n4. Return Book\n5. Exit\n> ";
        cin >> ch;
        if (ch == 1) {
            int id;
            string title, author;
            cout << "ID: "; cin >> id; cin.ignore();
            cout << "Title: "; getline(cin, title);
            cout << "Author: "; getline(cin, author);
            lib.add(id, title, author);
        } else if (ch == 2) lib.show();
        else if (ch == 3) {
            int id; cout << "ID to issue: "; cin >> id;
            lib.issue(id);
        } else if (ch == 4) {
            int id; cout << "ID to return: "; cin >> id;
            lib.ret(id);
        } else if (ch == 5) break;
        else cout << "❌ Invalid choice.\n";
    }

    cout << "👋 Goodbye!\n";
    return 0;
}

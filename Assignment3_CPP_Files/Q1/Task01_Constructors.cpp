#include <iostream>
#include <string>
#include <stdexcept>

class Book {
    std::string title;
    std::string author;
    int copies;

    static int validateCopies(int count) {
        if (count < 0) throw std::invalid_argument("Number of copies cannot be negative.");
        return count;
    }

public:
    Book() : Book("Untitled", "Unknown", 0) {}

    explicit Book(const std::string& bookTitle)
        : Book(bookTitle, "Unknown", 0) {}

    Book(const std::string& bookTitle, const std::string& bookAuthor, int count)
        : title(bookTitle), author(bookAuthor), copies(validateCopies(count)) {}

    void display() const {
        std::cout << "Title: " << title
                  << "\nAuthor: " << author
                  << "\nCopies: " << copies << "\n\n";
    }
};

int main() {
    try {
        Book emptyBook;
        Book donatedBook("The C++ Programming Language");
        Book fullBook("Clean Code", "Robert C. Martin", 5);

        std::cout << "Default constructor:\n";
        emptyBook.display();

        std::cout << "Title-only constructor:\n";
        donatedBook.display();

        std::cout << "Parameterized constructor:\n";
        fullBook.display();

        std::cout << "Testing negative copies:\n";
        Book invalidBook("Invalid", "Author", -2);
        invalidBook.display();
    } catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
    return 0;
}

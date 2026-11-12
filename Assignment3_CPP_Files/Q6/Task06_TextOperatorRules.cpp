#include <cstring>
#include <iostream>
#include <stdexcept>

class Text {
    char* data;

public:
    Text(const char* value = "") {
        if (!value) value = "";
        data = new char[std::strlen(value) + 1];
        std::strcpy(data, value);
    }

    Text(const Text& other) {
        data = new char[std::strlen(other.data) + 1];
        std::strcpy(data, other.data);
    }

    Text& operator=(const Text& other) {
        if (this != &other) {
            char* replacement = new char[std::strlen(other.data) + 1];
            std::strcpy(replacement, other.data);
            delete[] data;
            data = replacement;
        }
        return *this;
    }

    ~Text() { delete[] data; }

    Text operator+(const Text& other) const {
        std::size_t newLength = std::strlen(data) + std::strlen(other.data);
        char* combined = new char[newLength + 1];
        std::strcpy(combined, data);
        std::strcat(combined, other.data);
        Text result(combined);
        delete[] combined;
        return result;
    }

    bool operator==(const Text& other) const {
        return std::strcmp(data, other.data) == 0;
    }

    bool operator!=(const Text& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& out, const Text& text) {
        return out << text.data;
    }
};

int main() {
    Text first("Hello ");
    Text second("World");
    Text third("!");

    Text message = first + second + third;
    std::cout << "Message: " << message << '\n';

    Text copy;
    copy = message;
    std::cout << "Copied: " << copy << '\n';
    std::cout << std::boolalpha
              << "Equal: " << (copy == message) << '\n';

    copy = copy; // Self-assignment test
    std::cout << "After self-assignment: " << copy << '\n';

    Text empty("");
    std::cout << "Empty text: [" << empty << "]\n";
    std::cout << "Not equal: " << (empty != message) << '\n';
    return 0;
}

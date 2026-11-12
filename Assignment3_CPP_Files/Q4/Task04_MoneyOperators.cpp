#include <iomanip>
#include <iostream>

class Money {
    long long paise;

public:
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p) {}

    Money operator+(const Money& other) const {
        Money result;
        result.paise = paise + other.paise;
        return result;
    }

    bool operator==(const Money& other) const {
        return paise == other.paise;
    }

    Money& operator+=(const Money& other) {
        paise += other.paise;
        return *this;
    }

    Money operator-(const Money& other) const {
        Money result;
        result.paise = paise - other.paise;
        return result;
    }

    bool operator<(const Money& other) const {
        return paise < other.paise;
    }

    friend std::ostream& operator<<(std::ostream& out, const Money& amount) {
        long long absolutePaise = amount.paise < 0 ? -amount.paise : amount.paise;
        if (amount.paise < 0) out << "-";
        out << "Rs " << absolutePaise / 100 << '.'
            << std::setw(2) << std::setfill('0') << absolutePaise % 100
            << std::setfill(' ');
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Money& amount) {
        long long rupees;
        int p;
        if (in >> rupees >> p) amount.paise = rupees * 100 + p;
        return in;
    }
};

int main() {
    Money a(120, 75), b(79, 25);
    Money c = a + b;

    std::cout << c << '\n' << std::boolalpha << (c == Money(200)) << '\n';

    Money x(0, 75), y(0, 50);
    std::cout << "Paise carry: " << x + y << '\n';

    Money smaller(10, 0), larger(5, 0);
    std::cout << "Negative subtraction: " << larger - smaller << '\n';
    return 0;
}

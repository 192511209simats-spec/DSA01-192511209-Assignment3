#include <iostream>
#include <string>

class Prescription {
    int n;
    std::string* medicines;

public:
    explicit Prescription(int count)
        : n(count < 0 ? 0 : count),
          medicines(n > 0 ? new std::string[n] : nullptr) {}

    // Deep-copy constructor
    Prescription(const Prescription& other)
        : n(other.n),
          medicines(n > 0 ? new std::string[n] : nullptr) {
        for (int i = 0; i < n; ++i) medicines[i] = other.medicines[i];
        std::cout << "[Copy constructor called]\n";
    }

    // Deep-copy assignment operator
    Prescription& operator=(const Prescription& other) {
        if (this != &other) {
            std::string* newMedicines =
                other.n > 0 ? new std::string[other.n] : nullptr;

            for (int i = 0; i < other.n; ++i)
                newMedicines[i] = other.medicines[i];

            delete[] medicines;
            medicines = newMedicines;
            n = other.n;
        }
        return *this;
    }

    ~Prescription() {
        delete[] medicines;
    }

    void set(int i, const std::string& medicine) {
        if (i >= 0 && i < n) medicines[i] = medicine;
    }

    std::string get(int i) const {
        return (i >= 0 && i < n) ? medicines[i] : "";
    }

    int size() const { return n; }
};

int main() {
    Prescription p(2);
    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p;
    q.set(1, "Cetirizine");

    Prescription r(1);
    r = p;

    p.set(0, "Ibuprofen");

    std::cout << p.get(0) << ' ' << p.get(1)
              << " | " << q.get(0) << ' ' << q.get(1)
              << " | " << r.get(0) << ' ' << r.get(1) << '\n';
    return 0;
}

#include <cmath>
#include <iostream>
#include <stdexcept>

class Complex {
    double real;
    double imag;

public:
    Complex() : real(0.0), imag(0.0) {}
    Complex(double r) : real(r), imag(0.0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& z) const {
        return Complex(real + z.real, imag + z.imag);
    }

    Complex operator-(const Complex& z) const {
        return Complex(real - z.real, imag - z.imag);
    }

    Complex operator*(const Complex& z) const {
        return Complex(real * z.real - imag * z.imag,
                       real * z.imag + imag * z.real);
    }

    Complex operator/(const Complex& z) const {
        double denominator = z.real * z.real + z.imag * z.imag;
        if (denominator == 0.0)
            throw std::runtime_error("Division by zero impedance");
        return Complex((real * z.real + imag * z.imag) / denominator,
                       (imag * z.real - real * z.imag) / denominator);
    }

    bool operator==(const Complex& z) const {
        const double eps = 1e-9;
        return std::fabs(real - z.real) < eps &&
               std::fabs(imag - z.imag) < eps;
    }

    double magnitude() const {
        return std::sqrt(real * real + imag * imag);
    }

    friend std::ostream& operator<<(std::ostream& out, const Complex& z) {
        out << z.real;
        if (z.imag >= 0) out << " + j" << z.imag;
        else out << " - j" << -z.imag;
        return out;
    }
};

int main() {
    try {
        const double omega = 100.0;
        const double resistance = 10.0;
        const double inductance = 0.1;
        const double capacitance = 0.001;

        Complex zR(resistance, 0.0);
        Complex zL(0.0, omega * inductance);
        Complex zC(0.0, -1.0 / (omega * capacitance));

        Complex series = zR + zL + zC;
        std::cout << "Series impedance: " << series << '\n';
        std::cout << "Series magnitude: " << series.magnitude() << '\n';

        Complex z1(10.0, 5.0), z2(20.0, -5.0);
        Complex parallel = (z1 * z2) / (z1 + z2);
        std::cout << "Parallel impedance: " << parallel << '\n';
        std::cout << "Parallel magnitude: " << parallel.magnitude() << '\n';

        Complex zero(0.0, 0.0);
        Complex invalid = z1 / zero;
        std::cout << invalid << '\n';
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
    return 0;
}

#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:

    Complex() {
        real=0;
        imag=0;
    }

    Complex(double r, double i) {
        real=r;
        imag=i;
    }

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
    Complex operator*(const Complex& other) {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0) {
            out << " + " << c.imag << "i";
        } else {
            out << " - " << -c.imag << "i";
        }
        return out;
    }
};

int main() {
    Complex c1, c2;

    cout << "Enter the first complex number:\n";
    cin >> c1;
    cout << "Enter the second complex number:\n";
    cin >> c2;

    Complex sum = c1 + c2;
    Complex product = c1 * c2;

    cout << "Sum of the two complex numbers: " << sum << endl;
    cout << "Product of the two complex numbers: " << product << endl;

    return 0;
}
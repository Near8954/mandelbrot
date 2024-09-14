class Complex {
public:
    Complex(double r, double i) : real_(r), imag_(i) {
    }

    Complex() : real_(0), imag_(0) {
    }

    Complex operator+(const Complex &c) const;

    Complex operator-(const Complex &c) const;

    Complex operator*(const Complex &c) const;

    double get_imag() const {
        return imag_;
    }

    double get_real() const {
        return real_;
    }

    friend double abs(const Complex &c);

    Complex operator-() const;

private:
    double real_;
    double imag_;
};

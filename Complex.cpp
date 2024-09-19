#include "Complex.h"

#include <cmath>
#include <cmath>
#include <valarray>

Complex Complex::operator+(const Complex &c) const {
    return {real_ + c.real_, imag_ + c.imag_};
}

Complex Complex::operator-(const Complex &c) const {
    return {real_ - c.real_, imag_ - c.imag_};
}

Complex Complex::operator*(const Complex &c) const {
    return {real_ * c.real_ - imag_ * c.imag_, real_ * c.imag_ + imag_ * c.real_};
}

Complex Complex::operator-() const {
    return {-real_, -imag_};
}

double abs(const Complex &c) {
    return sqrtf64(c.real_ * c.real_ + c.imag_ * c.imag_);
}

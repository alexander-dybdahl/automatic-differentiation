#include "../include/forward_ad.hpp"

int main() {
    Dual x(2.0, 1.0); // val = 2, dval = 1 (∂f/∂x)
    Dual y = x * sin(x);

    std::cout << "f(x) = " << y.val << "\n";
    std::cout << "df/dx = " << y.dval << "\n";
    return 0;
}

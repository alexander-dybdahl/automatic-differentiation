#include "../include/reverse_ad.hpp"

int main() {
    auto x1 = Var::make(2.0);
    auto x2 = Var::make(1.0);
    auto y = x1 * sin(x2);

    std::cout << "Function output: " << y->val << "\n";
    y->backward();
    std::cout << "df/dx1 = " << x1->grad << "\n";
    std::cout << "df/dx2 = " << x2->grad << "\n";
    return 0;
}

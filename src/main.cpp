#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <cmath>

struct Var {
    double val;
    double grad = 0.0;

    using GradFunc = std::function<void(double)>;
    std::vector<GradFunc> parents;

    Var(double v) : val(v) {}

    void backward(double seed = 1.0) {
        grad += seed;
        for (auto& fn : parents)
            fn(seed);
    }

    // Binary operations return new Var and store how to backpropagate
    static std::shared_ptr<Var> make(double val) {
        return std::make_shared<Var>(val);
    }

    friend std::shared_ptr<Var> operator+(std::shared_ptr<Var> a, std::shared_ptr<Var> b) {
        auto out = make(a->val + b->val);
        out->parents.push_back([a](double g) { a->backward(g); });
        out->parents.push_back([b](double g) { b->backward(g); });
        return out;
    }

    friend std::shared_ptr<Var> operator*(std::shared_ptr<Var> a, std::shared_ptr<Var> b) {
        auto out = make(a->val * b->val);
        out->parents.push_back([a, b](double g) { a->backward(g * b->val); });
        out->parents.push_back([a, b](double g) { b->backward(g * a->val); });
        return out;
    }

    friend std::shared_ptr<Var> sin(std::shared_ptr<Var> x) {
        auto out = make(std::sin(x->val));
        out->parents.push_back([x](double g) { x->backward(g * std::cos(x->val)); });
        return out;
    }
};

int main() {
    auto x1 = Var::make(2.0);
    auto x2 = Var::make(1.0);

    auto y = x1 * sin(x2);  // f(x1, x2) = x1 * sin(x2)

    std::cout << "Function output: " << y->val << "\n";

    y->backward();  // start backpropagation from the output

    std::cout << "df/dx1 = " << x1->grad << "\n";
    std::cout << "df/dx2 = " << x2->grad << "\n";

    return 0;
}

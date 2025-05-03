#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <memory>
#include <cmath>

struct Var {
    double val;
    double grad = 0.0;
    std::vector<std::function<void(double)>> parents;

    Var(double v) : val(v) {}

    static std::shared_ptr<Var> make(double v) {
        return std::make_shared<Var>(v);
    }

    void backward(double seed = 1.0) {
        grad += seed;
        for (auto& fn : parents)
            fn(seed);
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

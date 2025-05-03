#pragma once
#include <iostream>

struct Dual {
    double val;   // value
    double dval;  // derivative

    Dual(double v, double dv) : val(v), dval(dv) {}

    Dual operator+(const Dual& o) const {
        return Dual(val + o.val, dval + o.dval);
    }

    Dual operator*(const Dual& o) const {
        return Dual(val * o.val, val * o.dval + dval * o.val);
    }

    friend Dual sin(const Dual& x) {
        return Dual(std::sin(x.val), std::cos(x.val) * x.dval);
    }
};

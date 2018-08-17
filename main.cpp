#include <functional>
#include <iostream>

int main(void)
{
    auto factorial = [](auto f) {
        return [f](auto n) { return n ? f(n - 1) * n : 1; };
    };
    auto Y = [](auto y) {
        auto f = [y](auto x)->std::function<int(int)> {
            return y([x](auto n) { return x(x)(n); });
        };
        return f(f);
    };
    std::cout << Y(factorial)(4) << std::endl;
    return 0;
}

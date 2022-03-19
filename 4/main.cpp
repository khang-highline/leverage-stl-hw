#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

bool anyPrime(const std::vector<int>& values);

int main() {
    auto integers = randomIntegers();
    std::cout << "Integers: " << integers << "\n";
    std::cout << "Are there any primes? " << (anyPrime(integers) ? "yes" : "no") << "\n";
}

bool anyPrime(const std::vector<int>& values) {
    // TODO: return true if any of the values are prime numbers
    auto result = false;
    auto found = std::find_if(values.begin(), values.end(), [](int n)
    {
        if (n < 2)
            return false;
        if (n == 2)
            return true;
        if (n % 2== 0)
            return false;
        for (int i = 3; (i * i) <= n; i+=2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    });
    result = found != values.end();
    return result;
}

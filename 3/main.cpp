#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    // TODO: print the average price and price range
    // std::cout << "The average price is: $" << "TODO" << "\n";
    auto average = std::accumulate(cars.begin(), cars.end(), 0.0, [](double result, const Car& a)
    {
        return result + a.price();
    });
    std::cout << "The average price is: $" << average << "\n";

    auto minResult = std::min_element(cars.begin(), cars.end(), [](const Car &a, const Car &b)
    {
        return a.price() < b.price();
    });

    auto maxResult = std::max_element(cars.begin(), cars.end(), [](const Car &a, const Car &b)
    {
        return a.price() < b.price();
    });
    // std::cout << "The range is: $" << "TODO" << "\n";
    std::cout << "The range is: $" << maxResult->price() - minResult->price()  << "\n";
}

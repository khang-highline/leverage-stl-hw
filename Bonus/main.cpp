#include <iostream>
#include <random>
#include <algorithm>
#include <numeric>
#include <string>
#include "Utility.h"
#include "Car.h"

std::vector<int> createElevationMap();
int calculateTrappedWater(const std::vector<int>& myList);
int calculateTrappedWater2(const std::vector<int>& myList);

int main() {
    auto range = createElevationMap();
    std::cout << "Elevation Map: " << range << "\n";

    // TODO: print out the amount of trapped water after it rains
    std::cout << "My own implementation from scratch: " << calculateTrappedWater(range) << "\n";
    std::cout << "Implementation based on available algorithm: " << calculateTrappedWater2(range) << "\n";
}

// Idea: calculate the drops in each breadth (layer) from top to bottom.
// use raw for loop.
int calculateTrappedWater(const std::vector<int>& myList)
{
    int drops = 0;

    int evaluationMax = *std::max_element(myList.begin(), myList.end());

    for (int i = 1; i < evaluationMax + 1; i++)
    {
        std::vector<int> indexes;

        // collect indexes in each breadth
        for (int j = 0; j < myList.size(); j++)
        {
            if ((i <= myList[j]) && (myList[j] < evaluationMax + 1))
                indexes.push_back(j);
        }

        // calculate drops in each breadth
        int tmp = 0;
        for (int j = 0; j < indexes.size() - 1; j++)
        {
            tmp += indexes[j + 1] - indexes[j] - 1;
        }
        drops += tmp;
    }

    return drops;
}

int calculateTrappedWater2(const std::vector<int>& myList)
{
    auto maxIterator = std::max_element(myList.begin(), myList.end());

    std::vector<int> tmpList(myList.size());

    auto maxLambda =  [](auto a, auto b)
    {
        return std::max(a, b);
    };

    std::partial_sum(myList.begin(), maxIterator, tmpList.begin(), maxLambda);
    std::partial_sum(myList.rbegin(), std::make_reverse_iterator(maxIterator), tmpList.rbegin(), maxLambda);

    return std::inner_product(tmpList.begin(), tmpList.end(), myList.begin(), 0, std::plus<int>(), std::minus<int>()); 
}

std::vector<int> createElevationMap() {
    // generate elevation data
    std::mt19937 generator{ std::random_device{}() };
    std::exponential_distribution<> elevationDist{ 0.5 };
    auto elevationCreator = [&generator, &elevationDist]() { 
        return static_cast<int>(elevationDist(generator));
    };
    auto elevationMap = randomVectorOfObjects<int, decltype(elevationCreator)>(elevationCreator);

    // ensure there is only one highest peak
    auto firstMaxPeakIt = std::max_element(elevationMap.begin(), elevationMap.end());
    *firstMaxPeakIt += 1;

    return elevationMap;
}

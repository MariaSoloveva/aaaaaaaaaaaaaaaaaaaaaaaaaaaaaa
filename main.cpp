#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include "Polynomial.hpp"

int main()
{
    std::vector<double> vec = {1, 2, 1};
    std::vector<double> vec1 = {5, 2, 6, 0, 1};
    Polynomial <double>polyOfVec(vec);
    Polynomial <double>poly;
    Polynomial <double>polyOfVec1(vec1);
    std::cout << polyOfVec1(1.)<< std::endl;
    polyOfVec1 /= polyOfVec;
    polyOfVec1 *= polyOfVec;
    polyOfVec1 %= polyOfVec;
    poly = polyOfVec1 % polyOfVec;
    polyOfVec += polyOfVec1;
    polyOfVec -= polyOfVec1;
    polyOfVec1 = polyOfVec + polyOfVec;
    polyOfVec = polyOfVec1 - polyOfVec;
    polyOfVec1 *= polyOfVec;
    poly = polyOfVec * 4.;
    poly = 7. * poly;
    std::cout << (polyOfVec1 == polyOfVec) << std::endl;
    std::cout << (polyOfVec1 != polyOfVec) << std::endl;
    return 0;
}

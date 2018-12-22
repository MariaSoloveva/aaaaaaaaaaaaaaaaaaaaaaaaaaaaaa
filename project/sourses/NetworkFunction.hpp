#ifndef EVOLUTION_NETWORKFUNCTION_HPP_
#define EVOLUTION_NETWORKFUNCTION_HPP_

#include <cmath>

/// @brief Класс сигмоидной функции
class Sigmoid
{
public:
    /// @brief Конструктор по умочанию
    Sigmoid() = default;
    /// @brief Деструктор по умолчанию
    ~Sigmoid() = default;
    /// @brief Функция получения значения функции
    /// @param x значение аргумента
    /// @result значение функции
    double Process(const double x)
    {
        return (1 / (1 + exp(-x)));
    };
    /// @brief Функция получения значения производной функции
    /// @param x значение аргумента
    /// @result значение производной функции
    double Derivative(const double x)
    {
        return Process(x) * (1 - Process(x));
    };
};


#endif  //  EVOLUTION_NETWORKFUNCTION_HPP_



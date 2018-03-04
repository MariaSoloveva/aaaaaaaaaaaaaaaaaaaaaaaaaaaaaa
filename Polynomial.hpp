#pragma once
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

template <class T>
class Polynomial
{
    std::vector<T> Coefficients;
public:
    Polynomial()
    {
        Coefficients.push_back(0);
    }
    ~Polynomial() = default;
    Polynomial(size_t a)
    {
        for(size_t i = 0; i < a; ++i)
            Coefficients.push_back(0);
    }
    Polynomial(const Polynomial& a)
    {
        for(size_t i = 0; i < a.Coefficients.size(); ++i)
            Coefficients.push_back(a.Coefficients[i]);
    }
    Polynomial(const std::vector<T>& coef)
    {
        for (size_t i = 0; i < coef.size(); ++i)
            Coefficients.push_back(coef[i]);
    }

    T& operator[](size_t index)
    {
        return Coefficients[index];
    }
    T operator[](size_t index) const
    {
        return Coefficients[index];
    }

    size_t Degree() const
    {
        return Coefficients.size() - 1;
    }
    Polynomial& operator = (const Polynomial& a)
    {
        Coefficients.clear();
        for(size_t i = 0; i < a.Degree() + 1; ++i)
        {
            Coefficients.push_back(a[i]);
        }
        return *this;
    }
    Polynomial& operator += (const Polynomial& a)
    {
        if(Coefficients.size() > a.Coefficients.size())
        {
            for (size_t i = 1; i < a.Coefficients.size() + 1; ++i)
                Coefficients[Coefficients.size() - i] += a[a.Coefficients.size() - i];
        }
        else
        {
            std::vector<T> pol = a.Coefficients;
            for (size_t i = 1; i < Coefficients.size() + 1; ++i)
                pol[a.Coefficients.size() - i] += Coefficients[Coefficients.size() - i];
            this->Coefficients = pol;
        }
        return *this;
    }
    Polynomial& operator -= (const Polynomial& a)
    {
        if(Coefficients.size() > a.Coefficients.size())
        {
            for (size_t i = 1; i < a.Coefficients.size() + 1; ++i)
                Coefficients[Coefficients.size() - i] -= a[a.Coefficients.size() - i];
        }
        else
        {
            std::vector<T> pol = a.Coefficients;
            for (size_t i = 1; i < Coefficients.size() + 1; ++i)
                pol[a.Coefficients.size() - i] -= Coefficients[Coefficients.size() - i];
            this->Coefficients = pol;
        }
        return *this;
    }
    Polynomial& operator *= (const Polynomial& a)
    {
        std::vector<T> newVec(1);
        for(size_t i = 0; i < this->Degree() + a.Degree(); ++i)
            newVec.push_back(0);
        for(size_t i = 0; i < a.Coefficients.size(); ++i)
            for(size_t j = 0; j < Coefficients.size(); ++j)
                newVec[i + j] += a.Coefficients[i] * Coefficients[j];
        this->Coefficients = newVec;
        return *this;
    }
    Polynomial& operator *= (T c)
    {
        for(size_t i = 0; i < Coefficients.size(); ++i)
            Coefficients[i] *= c;
        return *this;
    }

    Polynomial& operator /= (const Polynomial& a)
    {
        int inner = Degree() - a.Degree() + 1;
        std::vector<T> vec(inner);
        for(size_t i = 0; i < inner; ++i)
        {
            Polynomial pol(a);
            for(size_t j = 0; j < Degree() - a.Degree(); ++j)
                pol.Coefficients.push_back(0);
            pol *= (Coefficients[0] / a.Coefficients[0]);
            vec[i] = Coefficients[0] / a.Coefficients[0];
            *this -= pol;
            for(size_t j = 0; j < Degree() - a.Degree(); ++j)
                pol.Coefficients.erase(pol.Coefficients.begin());
            Coefficients.erase(Coefficients.begin());
        }
        this->Coefficients = vec;
        return *this;
    }
    Polynomial& operator %= (const Polynomial& a)
    {
        int inner = Degree() - a.Degree() + 1;
        std::vector<T> vec(inner);
        for(size_t i = 0; i < inner; ++i)
        {
            Polynomial pol(a);
            for(size_t j = 0; j < Degree() - a.Degree(); ++j)
                pol.Coefficients.push_back(0);
            pol *= (Coefficients[0] / a.Coefficients[0]);
            vec[i] = Coefficients[0] / a.Coefficients[0];
            *this -= pol;
            for(size_t j = 0; j < Degree() - a.Degree(); ++j)
                pol.Coefficients.erase(pol.Coefficients.begin());
            Coefficients.erase(Coefficients.begin());
        }
        return *this;
    }

    T operator()(const T& a) const
    {
        T number = 0;
        for(size_t i = 0 ; i < this->Degree(); ++i)
            number += Coefficients[i] * pow(a, this->Degree());
        return number;
    }

    auto begin() const -> decltype(Coefficients.begin())
    {
        return Coefficients.begin();
    }

    auto end() const -> decltype(Coefficients.end())
    {
        return Coefficients.end();
    }
};

template<class T>
bool operator==(const Polynomial<T>& a, const Polynomial<T>& b)
{
    if (std::distance(a.begin(), a.end()) == std::distance(b.begin(), b.end()))
    {
        int i = 0;
        for (auto curr = a.begin(); curr != a.end(); ++curr, ++i)
            if (*curr != *(b.begin() + i))
                return false;
        return true;
    }
    return false;
}

template<class T>
bool operator!=(const Polynomial<T>& a, const Polynomial<T>& b)
{
    return !(a == b);
}

template<class T>
Polynomial<T> operator+(const Polynomial<T>& a, const Polynomial<T>& b)
{
    Polynomial <T>c(a);
    c += b;
    return c;
}

template<class T>
Polynomial<T> operator-(const Polynomial<T>& a, const Polynomial<T>& b)
{
    Polynomial <T>c(a);
    c -= b;
    return c;
}

template<class T>
Polynomial<T> operator*(const Polynomial<T>& a, const Polynomial<T>& b)
{
    Polynomial <T>c(a);
    c *= b;
    return c;
}

template<class T>
Polynomial<T> operator/(const Polynomial<T>& a, const Polynomial<T>& b)
{
    Polynomial <T>c(a);
    c /= b;
    return c;
}

template<class T>
Polynomial<T> operator%(const Polynomial<T>& a, const Polynomial<T>& b)
{
    Polynomial <T>c(a);
    c %= b;
    return c;
}

template<class T>
Polynomial<T> operator*(const Polynomial<T>& a, T b)
{
    Polynomial <T>c(a);
    c *= b;
    return c;
}
template<class T>
Polynomial<T> operator*(T b, const Polynomial<T>& a)
{
    Polynomial <T>c(a);
    c *= b;
    return c;
}

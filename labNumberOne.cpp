#include <iostream>
#include <math.h>
#include <string>

int main(){
// Вывод числа Пи, округленного до сотых :
    std::cout << "pi = 3.14" << std::endl;
// Вывод чисел 1/13/49 c одним пробелом между ними :
    std::cout << "1 13 49" << std::endl;
// Вывод чисел 1/13/49 разделенные заданым символом :
    std::cout << "Введите знак" << std::endl;
    std::string sign1;
    std::cin >> sign1;
    std::string message = "1" + sign1 + "13"+sign1+"49";
    std::cout << message << std::endl;
// Вывод трех любых чисел с двумя пробелами между ними :
    std::cout << "Введите три любые числа" << std::endl;
    std::string number1;
    std::cin >> number1;
    std::string number2;
    std::cin >> number2;
    std::string number3;
    std::cin >> number3;
    std::string message1 = number1 + "  " + number2 + "  " + number3;
    std::cout << message1 << std::endl;
// Вычисление значения функции1 :
    std::cout << "Введите число а" << std::endl;
    double a = 0;
    std::cin >> a;
    double x = 12 * a * a + 7 * a - 12;
    double y = 3 * x * x * x + 4 * x * x - 11 * x + 1;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
// Определение плотности по объему и массе :
    std::cout << "Введите объем и массу" << std::endl;
    double volume = 0;
    std::cin >> volume;
    double weight = 0;
    std::cin >> weight;
    double dentisy = weight / volume;
    std::cout << dentisy << std::endl;
// Решение функции :
    std::cout << "Введите число а,b" << std::endl;
    double a1 = 0;
    std::cin >> a1;
    double b = 0;
    std::cin >> b;
    double x0 = -b / a1;
    std::cout << x0 << std::endl;
// Длина между двумя точками :
    double x1 = 0;
    std::cin >> x1;
    double y1 = 0;
    std::cin >> y1;
    double x2 = 0;
    std::cin >> x2;
    double y2 = 0;
    std::cin >> y2;
    double s = sqrt((x1-x2) * (x1-x2) +(y1-y2) * (y1-y2));
    std::cout << s << std::endl;
// Нахождение периметра равнобедренной трапеции :
    std::cout << "Введите размеры большего и меньшего оснований и высоты" << std::endl;
    double bigBase = 0;
    std::cin >> bigBase;
    double littleBase = 0;
    std::cin >> littleBase;
    double height = 0;
    std::cin >> height;
    double sum = sqrt(height * height + (bigBase - littleBase) * (bigBase - littleBase) / 4);
    double perimeter = bigBase + littleBase + 2 * sum;
    std::cout << perimeter << std::endl;
// Нахождение площади кольца :
    std::cout << "Введите внутренний и внешний радиус" << std::endl;
    double littleRadius = 0;
    std::cin >> littleRadius;
    double bigRadius = 0;
    std::cin >> bigRadius;
    double square = 3.14 * (bigRadius*bigRadius - littleRadius * littleRadius);
    std::cout << square << std::endl;
// Нахождение площади кольца :
    std::cout << "Введите длину ребра" << std::endl;
    double rib = 0;
    std::cin >> rib;
    double volumeCube = rib * rib * rib;
    double surfaceArea = 6 * rib * rib;
    std::cout << volumeCube << std::endl;
    std::cout << surfaceArea << std::endl;
// Нахождение объема квадрата :
    std::cout << "Введите сторону квадрата, чтобы узнать периметр" << std::endl;
    double side = 0;
    std::cin >> side;
    double area = 4 * side;
    std::cout << area << std::endl;
// Нахождение радиуса окружности :
    std::cout << "Введите радиус окружности, чтобы узнать диаметр" << std::endl;
    double radius = 0;
    std::cin >> radius;
    double deameter = 2 * radius;
    std::cout << deameter << std::endl;
    return 0;
}

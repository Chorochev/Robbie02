/* Класс помошник для действий над векторами */
#ifndef PROJECT_GEOMETRY_VECTORHELPER_H
#define PROJECT_GEOMETRY_VECTORHELPER_H

#include <math.h>
#include <geometry/RobVector.h>

namespace robbiespace
{
    class VectorHelper
    {
    private:
        const double PI = 3.141592653589793238463;

    public:
        VectorHelper();

        // Поворот нормализованного вектора на заданный угол вокруг оси Y
        // vec - вектор для поворота
        // angle - угол 0 - 360 град.
        RobVector RotateY(RobVector vec, double angle);

        // Получение косинуса угла
        // angle - угол 0 - 360 град.
        double GetCos(double angle) { return cos(angle * (PI / 180.0)); };

        // Получение синуса угла
        // angle - угол 0 - 360 град.
        double GetSin(double angle) { return sin(angle * (PI / 180.0)); }
    };

    extern VectorHelper globalVectorHelper;

} // namespace robbiespace

#endif
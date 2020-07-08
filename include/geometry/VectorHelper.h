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

        // Поворот нормализованного вектора на заданный угол вокруг оси X
        // vec - вектор для поворота
        // angle - угол 0 - 360 град.
        RobVector RotateX(RobVector vec, double angle);

        // Получение косинуса угла
        // angle - угол 0 - 360 град.
        inline double GetCos(double angle) { return cos(angle * (PI / 180.0)); };

        // Получение синуса угла
        // angle - угол 0 - 360 град.
        inline double GetSin(double angle) { return sin(angle * (PI / 180.0)); }

        // Проверка нахождения точки в границах нормализованного куба. По умолчанию размер куба от -1 до 1;
        // pVec - координаты точки для проверки
        // size - Размер от 0 до стены куба по оси
        bool IsInNormalRoom(RobVector pVec, float size = 1.0f);
    };

    extern VectorHelper globalVectorHelper;

} // namespace robbiespace

#endif
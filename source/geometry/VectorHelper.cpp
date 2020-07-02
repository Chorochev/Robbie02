#include <geometry/VectorHelper.h>

namespace robbiespace
{

    VectorHelper globalVectorHelper;

    VectorHelper::VectorHelper()
    {
    }

    // Поворот нормализованного вектора на заданный угол вокруг оси Y
    // *vec - вектор для поворота
    // angle - угол 0 - 360 град.
    RobVector VectorHelper::RotateY(RobVector vec, double angle)
    {
        RobVector newVector;
        newVector.X = (vec.X * GetCos(angle)) - (vec.Z * GetSin(angle)); //(vec.X * GetCos(angle)) + (vec.Y * 0) - (vec.Z * GetSin(angle));
        newVector.Y = vec.Y;                                             //(vec.X * 0) +             (vec.Y * 1) + (vec.Z * 0);
        newVector.Z = (vec.X * GetSin(angle)) + (vec.Z * GetCos(angle)); //(vec.X * GetSin(angle)) + (vec.Y * 0) + (vec.Z * GetCos(angle));
        return newVector;
    }

} // namespace robbiespace
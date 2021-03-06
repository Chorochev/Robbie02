#include <math.h>
#include <geometry/RobVector.h>

namespace robbiespace
{
    RobVector::RobVector()
    {
        X = Y = Z = 0.0f;
    }

    RobVector::RobVector(float x, float y, float z)
    {
        SetValue(x, y, z);
    }

    // Установка вектора
    void RobVector::SetValue(float x, float y, float z)
    {
        X = x;
        Y = y;
        Z = z;
    }

    // Установка вектора
    // vec - массив где: X-vec[0], Y-vec[1], Z-vec[2]
    void RobVector::SetValue(float vec[3])
    {
        X = vec[0];
        Y = vec[1];
        Z = vec[2];
    }

    // Перегрузка оператора сложения "+"
    RobVector RobVector::operator+(RobVector op2)
    {
        RobVector tempVector;
        tempVector.X = X + op2.X;
        tempVector.Y = Y + op2.Y;
        tempVector.Z = Z + op2.Z;
        return tempVector;
    }

    // Перегрузка оператора вычитания "-"
    RobVector RobVector::operator-(RobVector op2)
    {
        RobVector tempVector;
        tempVector.X = X - op2.X;
        tempVector.Y = Y - op2.Y;
        tempVector.Z = Z - op2.Z;
        return tempVector;
    }

    // Перегрузка оператора присваивания "="
    RobVector RobVector::operator=(RobVector op2)
    {
        X = op2.X;
        Y = op2.Y;
        Z = op2.Z;
        return *this;
    }

    // Перегрузка оператора присваивания "*"
    RobVector RobVector::operator*(float op2)
    {
        RobVector tempVector;
        tempVector.X = X * op2;
        tempVector.Y = Y * op2;
        tempVector.Z = Z * op2;
        return tempVector;
    }

} // namespace robbiespace
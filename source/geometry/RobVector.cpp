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
        X = x;
        Y = y;
        Z = z;
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
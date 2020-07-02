/* Класс для вектора */
#ifndef PROJECT_GEOMETRY_ROBVECTOR_H
#define PROJECT_GEOMETRY_ROBVECTOR_H

namespace robbiespace
{
    class RobVector
    {

    public:
        float X;
        float Y;
        float Z;
        RobVector();
        RobVector(float x, float y, float z);

        // Перегрузка оператора сложения "+"
        RobVector operator+(RobVector op2);

        // Перегрузка оператора вычитания "-"
        RobVector operator-(RobVector op2);

        // Перегрузка оператора присваивания "="
        RobVector operator=(RobVector op2);

        // Перегрузка оператора присваивания "*"
        RobVector operator*(float op2);
    };

} // namespace robbiespace

#endif
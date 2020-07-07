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

        // Установка вектора
        void SetValue(float x, float y, float z);

        // Установка вектора
        // vec - массив где: X-vec[0], Y-vec[1], Z-vec[2]
        void SetValue(float vec[3]);

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
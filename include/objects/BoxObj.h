/* Класс для прямоугольного объекта */
#ifndef PROJECT_OBJECTS_BOXOBJ_H
#define PROJECT_OBJECTS_BOXOBJ_H

#include <system/Structs.h>
#include <objects/BaseObj.h>

namespace robbiespace
{
    // Класс для прямоугольного объекта
    class BoxObj : public BaseObj
    {
    private:
        // Координаты точек куба по умолчанию
        float defaultBoxPoints[8][3] =
            {{-1.0f, 1.0f, -1.0f},  // Первая точка - [X - лево, Y - вверх, Z - перед]
             {1.0f, 1.0f, -1.0f},   // Вторая точка - [X - право, Y - вверх, Z - перед]
             {1.0f, -1.0f, -1.0f},  // Третья точка - [X - право, Y - низ, Z - перед]
             {-1.0f, -1.0f, -1.0f}, // Четвертая точка - [X - лево, Y - низ, Z - перед]
             {-1.0f, 1.0f, 1.0f},   // Пятая точка - [X - лево, Y - вверх, Z - зад]
             {1.0f, 1.0f, 1.0f},    // Шестая точка - [X - право, Y - вверх, Z - зад]
             {1.0f, -1.0f, 1.0f},   // Седьмая точка - [X - право, Y - низ, Z - зад]
             {-1.0f, -1.0f, 1.0f}}; // Восьмая точка - [X - лево, Y - низ, Z - зад]

        // Получение нового размера с учетом знака
        float GetNewSize(float oldSize, float newSize);

    public:
        // Коструктор коробки
        // id - идентификатор объекта
        BoxObj(int id);

        structSideBox Sides[6]; // Стороны прямоугольного объекта

        // Установка объекта в начальное сосотояние
        void SetDefault();

        // Установка размера
        // x - размер стороны по оси X
        // y - размер стороны по оси Y
        // z - размер стороны по оси Z
        void ChangeSize(float x, float y, float z);

        // Вывод объекта на экран
        void Display();
    };

} // namespace robbiespace

#endif
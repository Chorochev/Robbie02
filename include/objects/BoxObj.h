/* Класс для прямоугольного объекта */
#ifndef PROJECT_OBJECTS_BOXOBJ_H
#define PROJECT_OBJECTS_BOXOBJ_H

#include <system/Enums.h>
#include <objects/BaseObj.h>

namespace robbiespace
{
    // Структура описывающая одну сторону прямоугольного объекта
    struct structSideBox
    {
        eSideBoxObj sideBox; // Тип стороны
        RobVector Point1;    // Первая точка строны
        RobVector Point2;    // Вторая точка стороны
        RobVector Point3;    // Третья точка стороны
        RobVector Point4;    // Четвертая точка стороны
    };

    // Класс для прямоугольного объекта
    class BoxObj : public BaseObj
    {
    private:
    public:
        // Коструктор коробки
        // id - идентификатор объекта
        BoxObj(int id);

        structSideBox Sides[6]; // Стороны прямоугольного объекта

        // Вывод объекта на экран
        void Display();
    };

} // namespace robbiespace

#endif
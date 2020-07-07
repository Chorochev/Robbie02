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
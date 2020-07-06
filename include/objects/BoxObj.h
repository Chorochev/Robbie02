/* Базовый класс для объекта */
#ifndef PROJECT_OBJECTS_BOXOBJ_H
#define PROJECT_OBJECTS_BOXOBJ_H

#include <objects/BaseObj.h>
//#include <geometry/RobVector.h>

namespace robbiespace
{
    class BoxObj : public BaseObj
    {
    private:
        /* data */
    public:
        // Коструктор коробки
        // id - идентификатор объекта
        BoxObj(int id);

        // Вывод объекта на экран
        virtual void Display();
    };

} // namespace robbiespace

#endif
/* Базовый класс для объекта */
#ifndef PROJECT_OBJECTS_BOXOBJ_H
#define PROJECT_OBJECTS_BOXOBJ_H

#include <objects/BaseObj.h>

namespace robbiespace
{
    class BoxObj : public BaseObj
    {
    private:
    public:
        // Коструктор коробки
        // id - идентификатор объекта
        BoxObj(int id);

        // Вывод объекта на экран
        void Display();
    };

} // namespace robbiespace

#endif
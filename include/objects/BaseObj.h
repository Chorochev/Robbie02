/* Базовый класс для объекта */
#ifndef PROJECT_OBJECTS_BASEOBJ_H
#define PROJECT_OBJECTS_BASEOBJ_H

#include <geometry/RobVector.h>

namespace robbiespace
{

    class BaseObj
    {
    private:
        int _baseID; // Идентификатор объекта
    protected:
        RobVector position; // Координаты объекта

    public:
        // Базовый конструктор объекта
        // id - идентификатор объекта
        BaseObj(int id);

        // Получение идентификатора объекта
        inline int GetID() { return _baseID; }
    };

} // namespace robbiespace

#endif
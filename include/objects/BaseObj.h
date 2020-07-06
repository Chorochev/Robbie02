/* Базовый класс для объекта */
#ifndef PROJECT_OBJECTS_BASEOBJ_H
#define PROJECT_OBJECTS_BASEOBJ_H

#include <string>
#include <geometry/RobVector.h>

using namespace std;

namespace robbiespace
{

    class BaseObj
    {
    private:
        int _baseID;  // Идентификатор объекта
        string _name; // Имя объекта
    protected:
        RobVector position; // Координаты объекта

    public:
        // Базовый конструктор объекта
        // id - идентификатор объекта
        // name - имя объекта
        BaseObj(int id, string name);

        // Получение идентификатора объекта
        inline int GetID() { return _baseID; };

        // Получение имени объекта
        inline string GetName() { return _name; };
    };

} // namespace robbiespace

#endif
#include <objects/BaseObj.h>

namespace robbiespace
{
    // Базовый конструктор объекта
    // id - идентификатор объекта
    // name - имя объекта
    BaseObj::BaseObj(int id, string name)
    {
        _baseID = id;
        _name = name + std::to_string(id);
    }
} // namespace robbiespace
/* Вспомогательный класс для объектов */
#ifndef PROJECT_OBJECTS_OBJHELPER_H
#define PROJECT_OBJECTS_OBJHELPER_H

#include <objects/BoxObj.h>
#include <system/Enums.h>

namespace robbiespace
{
    // Вспомогательный класс для объектов
    class ObjHelper
    {
    private:
        int curentObjID; // Текущий идентификатор объекта
    public:
        ObjHelper();

        inline int GetNewID() { return curentObjID++; };

        // Создание стены
        // typeWall - тип стены
        // *box - класс стены
        void GetWall(eSideBoxObj typeWall, BoxObj *box);
    };

    extern ObjHelper globalObjHelper;

} // namespace robbiespace

#endif
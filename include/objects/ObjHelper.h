/* Вспомогательный класс для объектов */
#ifndef PROJECT_OBJECTS_OBJHELPER_H
#define PROJECT_OBJECTS_OBJHELPER_H

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
    };

    extern ObjHelper globalObjHelper;

} // namespace robbiespace

#endif
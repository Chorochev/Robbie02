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
        int curentObjID;          // Текущий идентификатор объекта
        float currentColor[3];    // Текущий цвет
        bool isCurrentColorRED;   // Флаг компонента цвета
        bool isCurrentColorGREEN; // Флаг компонента цвета
        bool isCurrentColorBLUE;  // Флаг компонента цвета

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

    public:
        ObjHelper();

        inline int GetNewID() { return curentObjID++; };

        // Установить следующий цвет
        void SetNextColor();

        // Установка объекта в начальное сосотояние в форме куба с размерами от -1 до 1
        void SetDefaultCube(BoxObj *box);
    };

    extern ObjHelper globalObjHelper;

} // namespace robbiespace

#endif
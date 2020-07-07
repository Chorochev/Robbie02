// Structs.h - Класс для структур
#ifndef PROJECT_SYSTEM_STRUCTS_H
#define PROJECT_SYSTEM_STRUCTS_H

#include <string>
#include <system/Enums.h>
#include <geometry/RobVector.h>

namespace robbiespace
{
    // Структура для клавиши
    struct StructKey
    {
        std::string Name;      // Имя клавиши
        std::string Code;      // Код клавиши
        int Value;             // Значение клавиши
        eKeys TypeKey;         // Тип клавиши
        eDeviceKey TypeDevice; // Тип устройства
        bool IsPress;          // Признак нажатия клавиши
        int MouseX;            // координата мыши по оси X
        int MouseY;            // координата мыши по оси Y
    };

    // Структура описывающая одну сторону прямоугольного объекта
    struct structSideBox
    {
        eSideBoxObj sideBox; // Тип стороны
        RobVector Point1;    // Первая точка строны
        RobVector Point2;    // Вторая точка стороны
        RobVector Point3;    // Третья точка стороны
        RobVector Point4;    // Четвертая точка стороны
    };

} // namespace robbiespace
#endif
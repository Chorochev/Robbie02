// Enums.h - Класс для enums (перечислений)
#ifndef PROJECT_SYSTEM_ENUMS_H
#define PROJECT_SYSTEM_ENUMS_H

namespace robbiespace
{
    // Типы сообщений лога
    enum class LoggerType
    {
        LT_UNKNOWN,
        LT_INFO,
        LT_WARNING,
        LT_ERRORS,
    };

    // Типы клавиш
    enum class eKeys
    {
        Unknown,   // нет нажатых клавиш
        Exit,      // кнопка выхода
        KEY_LEFT,  // Стрелка влево
        KEY_UP,    // Стрелка вверх
        KEY_RIGHT, // Стрелка вправо
        KEY_DOWN,  // Стрелка вниз
        PAGE_UP,   // Вверх
        PAGE_DOWN, // Вниз
        KEY_F1,    // F1
        KEY_F2,    // F2
        KEY_F3,    // F3
        KEY_F4     // F4
    };

    // Типы устройств
    enum class eDeviceKey
    {
        Unknown,      // Неопознанно
        Keyboard,     // Клавиатура
        KeyboardSpec, // Клавиатура (специальные клавиши)
        Mouse         // Мышка
    };

    // Стороны прямоугольного объекта
    enum class eSideBoxObj
    {
        Front, // Передняя сторона
        Back,  // Задняя сторона
        Left,  // левая сторона
        Right, // Правая сторона
        Top,   // Верхняя сторона
        Bottom // Нижняя сторона
    };

} // namespace robbiespace
#endif
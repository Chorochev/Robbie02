// KeyHandler.h - Класс для обработки клавиш
#ifndef PROJECT_EVENTS_KEYHANDLER_H
#define PROJECT_EVENTS_KEYHANDLER_H

#define SIZE_STRUCTKEY_ARRAY 14
#define SIZE_UNKNOWN_STRUCTKEY_ARRAY 3

#include <system/Structs.h>

namespace robbiespace
{
    // Класс для обработки клавиш
    class KeyHandler
    {
    private:
        StructKey keys[SIZE_STRUCTKEY_ARRAY];                // Массив обрабатываемых клавиш
        StructKey unknownKeys[SIZE_UNKNOWN_STRUCTKEY_ARRAY]; // Массив неопознанных обрабатываемых клавиш

        bool mouseIsChangedOX; // Признак изменения координаты мышки по оси X
        bool mouseIsChangedOY; // Признак изменения координаты мышки по оси Y
        int currentMouseOX;    // Текущее положение мышки по оси X
        int currentMouseOY;    // Текущее положение мышки по оси Y
        int oldMouseOX;        // Предыдущее положение мышки по оси X
        int oldMouseOY;        // Предыдущее положение мышки по оси Y

        int MouseWheelDir; // Направление колеса мыши

        // Функция для обработки неизвестной клавиши
        // key - код клавиши
        // x - координата мыши по оси X
        // y - координата мыши по оси Y
        // isPress - признак нажатия клавиши
        // deviceKey - Тип устройства
        void KeyUnknown(int key, int x, int y, bool isPress, eDeviceKey deviceKey);

        // Создание строки из структуры для консоли
        // rKey - структура клавиши
        std::string GetStringStructKey(StructKey rKey);

    public:
        KeyHandler();

        const int sizeUnknownKeys = SIZE_UNKNOWN_STRUCTKEY_ARRAY; // Количество элеметов массива клавиш
        const int sizeKeys = SIZE_STRUCTKEY_ARRAY;                // Количество элеметов массива клавиш

        void SetDefaultKeys(); // Установка клавиш по умолчанию
        void LoadKeyValues();  // Загрузка значений клавиш из файла конфигурации
        void SaveKeyValues();  // Сохранение значений в файл конфигурации

        // Функция для обработки клавиш клавиатуры
        // key - код клавиши
        // x - координата мыши по оси X
        // y - координата мыши по оси Y
        // isPress - признак нажатия клавиши
        // TypeDevice - Тип устройства
        void FunctionKeyboard(int key, int x, int y, bool isPress, eDeviceKey typeDevice);

        // Функция для отслеживания пассивного движения мыши (с нажатой кнопкой)
        // x - координата мыши по оси X
        // y - координата мыши по оси Y
        void MotionFunc(int x, int y);

        // Функция для отслеживания пассивного движения мыши (без нажатия кнопки)
        // x - координата мыши по оси X
        // y - координата мыши по оси Y
        void PassiveMotionFunc(int x, int y);

        void MouseWheel(int button, int dir, int x, int y) { MouseWheelDir = dir; };

        // Получить направление вращения колеса мыши
        int GetDirectionMouseWheel();

        // Получить сдвиг мышки по оси X
        int GetMouseShiftOX();

        // Получить сдвиг мышки по оси Y
        int GetMouseShiftOY();

        // Функция для проверки нажатия клавиши
        // key - тип клавиши
        bool IsKeyPress(eKeys key);

        // Сообщение для консоли
        std::string GetMessageForConsole();
    };

} // namespace robbiespace
#endif
// KeyHandler.h - Класс для обработки клавиш
#ifndef PROJECT_EVENTS_KEYHANDLER_H
#define PROJECT_EVENTS_KEYHANDLER_H

#define SIZE_STRUCTKEY_ARRAY 17
#define SIZE_UNKNOWN_STRUCTKEY_ARRAY 3

#include <GL/freeglut.h>

#include <system/Structs.h>
#include <geometry/RobVector.h>

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

        float currentColorPixel[4]; // Текущий цвет пикселя под мышкой

        // Функция для обработки клавиш
        // key - код клавиши
        // x - координата мыши по оси X
        // y - координата мыши по оси Y
        // isPress - признак нажатия клавиши
        // TypeDevice - Тип устройства
        void FunctionKey(int key, int x, int y, bool isPress, eDeviceKey typeDevice);

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

        // Функция для установки позиции курсора
        // x - координата мыши по оси X
        // y - координата мыши по оси Y
        void SetMousePosition(int x, int y);

    public:
        KeyHandler();

        const int sizeUnknownKeys = SIZE_UNKNOWN_STRUCTKEY_ARRAY; // Количество элеметов массива клавиш
        const int sizeKeys = SIZE_STRUCTKEY_ARRAY;                // Количество элеметов массива клавиш

        RobVector CurrentPositionMouse3D; // Текущая координата 3D под мышкой

        void SetDefaultKeys(); // Установка клавиш по умолчанию
        void LoadKeyValues();  // Загрузка значений клавиш из файла конфигурации
        void SaveKeyValues();  // Сохранение значений в файл конфигурации

        // Функция для обработки клавиш клавиатуры
        // key - код клавиши
        // x - координата мыши по оси X
        // y - координата мыши по оси Y
        // isPress - признак нажатия клавиши
        // TypeDevice - Тип устройства
        inline void FunctionKeyboard(int key, int x, int y, bool isPress, eDeviceKey typeDevice) { FunctionKey(key, x, y, isPress, typeDevice); };

        // Функция для обработки данных с мышки
        void MouseFunc(int button, int state, int x, int y);

        // Функция для отслеживания пассивного движения мыши (с нажатой кнопкой)
        // x - координата мыши по оси X
        // y - координата мыши по оси Y
        inline void MotionFunc(int x, int y) { SetMousePosition(x, y); }

        // Функция для отслеживания пассивного движения мыши (без нажатия кнопки)
        // x - координата мыши по оси X
        // y - координата мыши по оси Y
        inline void PassiveMotionFunc(int x, int y) { SetMousePosition(x, y); }

        // Обработка данных колеса мыши
        void MouseWheel(int button, int dir, int x, int y) { MouseWheelDir = dir; };

        // Получить направление вращения колеса мыши
        int GetDirectionMouseWheel();

        // Получить сдвиг мышки по оси X
        int GetMouseShiftOX();

        // Получить сдвиг мышки по оси Y
        int GetMouseShiftOY();

        // Получение цвета пикселя под координатами мыши
        // screenHeight - высота экрана
        inline void GetColorMousePosition(int screenHeight) { glReadPixels(currentMouseOX, (screenHeight - currentMouseOY), 1, 1, GL_RGB, GL_FLOAT, &currentColorPixel); }

        // Получение 3-х мерных координат мыши
        void FindMousePosition3D();

        // Функция для проверки нажатия клавиши
        // key - тип клавиши
        bool IsKeyPress(eKeys key);

        // Сообщение для консоли
        std::string GetMessageForConsole();
    };

} // namespace robbiespace
#endif
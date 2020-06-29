// KeyHandler.h - Класс для обработки клавиш
#ifndef PROJECT_EVENTS_KEYHANDLER_H
#define PROJECT_EVENTS_KEYHANDLER_H

#define SIZE_STRUCTKEY_ARRAY 2
#define SIZE_UNKNOWN_STRUCTKEY_ARRAY 3

#include <string>

namespace robbiespace
{
    // Типы клавиш
    enum class eKeys
    {
        Unknown, // нет нажатых клавиш
        Exit     // кнопка выхода
    };

    // Структура для клавиши
    struct StructKey
    {
        std::string Name;    // Имя клавиши
        std::string Code;    // Код клавиши
        unsigned char Value; // Значение клавиши
        eKeys TypeKey;       // Тип клавиши
        bool IsPress;        // Признак нажатия клавиши
    };

    // Класс для обработки клавиш
    class KeyHandler
    {
    private:        
        StructKey keys[SIZE_STRUCTKEY_ARRAY];                // Массив обрабатываемых клавиш
        StructKey unknownKeys[SIZE_UNKNOWN_STRUCTKEY_ARRAY]; // Массив неопознанных обрабатываемых клавиш

        // Создание строки из структуры для консоли
        // rKey - структура клавиши
        string GetStringStructKey(StructKey rKey);

    public:
        KeyHandler();

        const int sizeUnknownKeys = SIZE_UNKNOWN_STRUCTKEY_ARRAY; // Количество элеметов массива клавиш
        const int sizeKeys = SIZE_STRUCTKEY_ARRAY;                // Количество элеметов массива клавиш

        void SetDefaultKeys(); // Установка клавиш по умолчанию
        void LoadKeyValues();  // Загрузка значений клавиш из файла конфигурации
        void SaveKeyValues();  // Сохранение значений в файл конфигурации

        // Функция для обработки нажатия клавиш клавиатуры
        // key - код клавиши
        // x - координата мыши по оси X
        // y - координата мыши по оси Y
        // isPress - признак нажатия клавиши
        void FunctionKeyboard(unsigned char key, int x, int y, bool isPress);

        // Функция для проверки нажатия клавиши
        // key - тип клавиши
        bool IsKeyPress(eKeys key);

        // Сообщение для консоли
        string GetMessageForConsole();
    };

} // namespace robbiespace
#endif
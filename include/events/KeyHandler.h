// KeyHandler.h - Класс для обработки клавиш
#ifndef PROJECT_EVENTS_KEYHANDLER_H
#define PROJECT_EVENTS_KEYHANDLER_H

#define SIZE_STRUCTKEY_ARRAY 1

#include <string>

namespace robbiespace
{
    // Типы клавиш
    enum class eKeys
    {
        None, // нет нажатых клавиш
        Exit  // кнопка выхода
    };

    // Структура для клавиши
    struct StructKey
    {
        std::string Name; // Имя клавиши
        char Code;        // Код клавиши
        eKeys TypeKey;    // Тип клавиши
        bool IsPress;     // Признак нажатия клавиши
    };

    // Класс для обработки клавиш
    class KeyHandler
    {
    private:
        StructKey keys[SIZE_STRUCTKEY_ARRAY]; // Массив обрабатываемых клавиш

    public:
        KeyHandler();

        const int sizeKeys = SIZE_STRUCTKEY_ARRAY; // Количество элеметов массива клавиш

        void SetDefaultKeys(); // Установка клавиш по умолчанию
        void LoadKeyValues();  // Загрузка значений клавиш из файла конфигурации
        void SaveKeyValues();  // Сохранение значений в файл конфигурации

        // Функция для обработки нажатия клавиш клавиатуры
        // код клавиши
        // x - координата мыши по оси X
        // y - координата мыши по оси Y
        void FunctionKeyboard(unsigned char key, int x, int y);

        // Функция для проверки нажатия клавиши
        // key - тип клавиши
        bool IsKeyPress(eKeys key);
    };

} // namespace robbiespace
#endif
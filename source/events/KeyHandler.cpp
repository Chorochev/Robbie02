#include <system/Settings.h>
#include <events/KeyHandler.h>

namespace robbiespace
{
    KeyHandler::KeyHandler()
    {
        SetDefaultKeys();
        LoadKeyValues();
    }

    // Установка клавиш по умолчанию
    void KeyHandler::SetDefaultKeys()
    {
        // Exit
        keys[0].Name = "cKeyExit1";
        keys[0].Code = '\x1B';
        keys[0].TypeKey = eKeys::Exit;
        keys[0].IsPress = false;
    }

    // Загрузка значений клавиш из файла конфигурации
    void KeyHandler::LoadKeyValues()
    {
        keys[0].Code = globalSettings.GetSettingOrDefault(keys[0].Name, '\x1B'); // Exit
    }

    // Сохранение значений в файл конфигурации
    void KeyHandler::SaveKeyValues()
    {
        for (size_t i = 0; i < sizeKeys; i++)
        {
            globalSettings.SetValue(keys[i].Name, keys[i].Code);
        }
    }

    // Функция для обработки нажатия клавиш клавиатуры
    // код клавиши
    // x - координата мыши по оси X
    // y - координата мыши по оси Y
    void KeyHandler::FunctionKeyboard(unsigned char key, int x, int y)
    {
        for (size_t i = 0; i < sizeKeys; i++)
        {
            if (keys[i].Code == key)
            {
                keys[i].IsPress = true;
            }
        }
    }

    // Функция для проверки нажатия клавиши
    // key - тип клавиши
    bool KeyHandler::IsKeyPress(eKeys key)
    {
        for (size_t i = 0; i < sizeKeys; i++)
        {
            if (keys[i].TypeKey == key && keys[i].IsPress)
                return true;
        }
        return false;
    }

} // namespace robbiespace

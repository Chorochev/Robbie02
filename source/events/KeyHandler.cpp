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
        keys[0] = {"cKeyExit1", "ESC", '\x1B', eKeys::Exit, false};
        keys[1] = {"cKeyExit2", "ESC", 'q', eKeys::Exit, false};
    }

    // Загрузка значений клавиш из файла конфигурации
    void KeyHandler::LoadKeyValues()
    {
        for (size_t i = 0; i < sizeKeys; i++)
        {
            keys[i].Value = globalSettings.GetSettingOrDefault(keys[i].Name, keys[i].Value);
        }
    }

    // Сохранение значений в файл конфигурации
    void KeyHandler::SaveKeyValues()
    {
        for (size_t i = 0; i < sizeKeys; i++)
        {
            globalSettings.SetValue(keys[i].Name, keys[i].Value);
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
            if (keys[i].Value == key)
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

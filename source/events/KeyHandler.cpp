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

        // Неопознанные клавиши
        unknownKeys[0] = {"cKeyUnknown1", "Unknown1", 0, eKeys::Unknown, false};
        unknownKeys[1] = {"cKeyUnknown2", "Unknown2", 0, eKeys::Unknown, false};
        unknownKeys[2] = {"cKeyUnknown3", "Unknown3", 0, eKeys::Unknown, false};
    }

    // Загрузка значений клавиш из файла конфигурации
    void KeyHandler::LoadKeyValues()
    {
        for (size_t i = 0; i < sizeKeys; i++)
        {
            if (keys[i].TypeKey != eKeys::Unknown)
            {
                keys[i].Value = globalSettings.GetSettingOrDefault(keys[i].Name, keys[i].Value);
            }
        }
    }

    // Сохранение значений в файл конфигурации
    void KeyHandler::SaveKeyValues()
    {
        for (size_t i = 0; i < sizeKeys; i++)
        {
            if (keys[i].TypeKey != eKeys::Unknown)
            {
                globalSettings.SetValue(keys[i].Name, keys[i].Value);
            }
        }
    }

    // Функция для обработки нажатия клавиш клавиатуры
    // код клавиши
    // x - координата мыши по оси X
    // y - координата мыши по оси Y
    // IsPress - признак нажатия клавиши
    void KeyHandler::FunctionKeyboard(unsigned char key, int x, int y, bool isPress)
    {
        bool isUnknown = true; // Флаг определяет нажатие знакомой клавиши
        for (size_t i = 0; i < sizeKeys; i++)
        {
            if (keys[i].Value == key)
            {
                keys[i].IsPress = isPress;
                isUnknown = false;
            }
        }

        if (isUnknown)
        {
            for (size_t i = 0; i < sizeUnknownKeys; i++)
            {
                if (isPress && unknownKeys[i].IsPress && unknownKeys[i].Value == key)
                    return;
            }

            for (size_t i = 0; i < sizeUnknownKeys; i++)
            {
                if (isPress)
                {
                    if (unknownKeys[i].IsPress == false)
                    {
                        unknownKeys[i].Value = key;
                        unknownKeys[i].IsPress = true;
                        return;
                    }
                }
                else
                {
                    if (unknownKeys[i].IsPress && unknownKeys[i].Value == key)
                    {
                        unknownKeys[i].Value = 0;
                        unknownKeys[i].IsPress = false;
                    }
                }
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

    // Сообщение для консоли
    string KeyHandler::GetMessageForConsole()
    {
        string resultStr = "";
        bool isFirst = true;
        for (size_t i = 0; i < sizeKeys; i++)
        {
            if (keys[i].IsPress)
            {
                if (isFirst)
                    isFirst = false;
                else
                    resultStr += ", ";

                resultStr += "[" + keys[i].Code + "=" + GetStringStructKey(unknownKeys[i]) + "]";
            }
        }
        if (isFirst == false)
            resultStr += ";";

        isFirst = true;
        for (size_t i = 0; i < sizeUnknownKeys; i++)
        {
            if (unknownKeys[i].IsPress)
            {
                if (isFirst)
                {
                    resultStr += "[Unknowns:";
                    isFirst = false;
                }
                else
                {
                    resultStr += ",";
                }
                resultStr += GetStringStructKey(unknownKeys[i]);
            }
        }
        if (isFirst == false)
            resultStr += "]";

        return resultStr;
    }

    // Создание строки из структуры для консоли
    string KeyHandler::GetStringStructKey(StructKey rKey)
    {
        string result = "(";
        result += std::to_string(((int)rKey.Value));

        if (rKey.Value < 128)
        {
            char ch = rKey.Value;
            if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            {
                char chAr[2] = {ch, '\0'};
                string strChar = chAr;
                result += ",'" + strChar + "'";
            }
        }
        result += ")";
        return result;
    }

} // namespace robbiespace

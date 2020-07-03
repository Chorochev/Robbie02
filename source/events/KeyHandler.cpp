#include <GL/freeglut.h>

#include <system/Settings.h>
#include <events/KeyHandler.h>

namespace robbiespace
{
    KeyHandler::KeyHandler()
    {
        SetDefaultKeys();
        LoadKeyValues();
        mouseIsChangedOX = false;
        mouseIsChangedOY = false;
        currentMouseOX = 0; // Текущее положение мышки по оси X
        currentMouseOY = 0; // Текущее положение мышки по оси Y
        oldMouseOX = 0;     // Предыдущее положение мышки по оси X
        oldMouseOY = 0;     // Предыдущее положение мышки по оси Y
    }

    // Установка клавиш по умолчанию
    void KeyHandler::SetDefaultKeys()
    {
        keys[0] = {"iKeyExit1", "ESC", '\x1B', eKeys::Exit, eDeviceKey::Keyboard, false, 0, 0};
        keys[1] = {"iKeyExit2", "ESC", 'q', eKeys::Exit, eDeviceKey::Keyboard, false, 0, 0};
        keys[2] = {"iKeyLEFT", "LEFT", GLUT_KEY_LEFT, eKeys::KEY_LEFT, eDeviceKey::KeyboardSpec, false, 0, 0};
        keys[3] = {"iKeyUP", "UP", GLUT_KEY_UP, eKeys::KEY_UP, eDeviceKey::KeyboardSpec, false, 0, 0};
        keys[4] = {"iKeyRIGHT", "RIGHT", GLUT_KEY_RIGHT, eKeys::KEY_RIGHT, eDeviceKey::KeyboardSpec, false, 0, 0};
        keys[5] = {"iKeyDOWN", "DOWN", GLUT_KEY_DOWN, eKeys::KEY_DOWN, eDeviceKey::KeyboardSpec, false, 0, 0};
        keys[6] = {"iKeyPAGE_UP", "PAGE_UP", GLUT_KEY_PAGE_UP, eKeys::PAGE_UP, eDeviceKey::KeyboardSpec, false, 0, 0};
        keys[7] = {"iKeyPAGE_DOWN", "PAGE_DOWN", GLUT_KEY_PAGE_DOWN, eKeys::PAGE_DOWN, eDeviceKey::KeyboardSpec, false, 0, 0};
        keys[8] = {"iKeyKEY_F1", "KEY_F1", GLUT_KEY_F1, eKeys::KEY_F1, eDeviceKey::KeyboardSpec, false, 0, 0};
        keys[9] = {"iKeyKEY_F2", "KEY_F2", GLUT_KEY_F2, eKeys::KEY_F2, eDeviceKey::KeyboardSpec, false, 0, 0};
        keys[10] = {"iKeyKEY_F3", "KEY_F3", GLUT_KEY_F3, eKeys::KEY_F3, eDeviceKey::KeyboardSpec, false, 0, 0};
        keys[11] = {"iKeyKEY_F4", "KEY_F4", GLUT_KEY_F4, eKeys::KEY_F4, eDeviceKey::KeyboardSpec, false, 0, 0};

        // Неопознанные клавиши
        unknownKeys[0] = {"iKeyUnknown1", "Unknown1", 0, eKeys::Unknown, eDeviceKey::Unknown, false, 0, 0};
        unknownKeys[1] = {"iKeyUnknown2", "Unknown2", 0, eKeys::Unknown, eDeviceKey::Unknown, false, 0, 0};
        unknownKeys[2] = {"iKeyUnknown3", "Unknown3", 0, eKeys::Unknown, eDeviceKey::Unknown, false, 0, 0};
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

    // Функция для обработки клавиш клавиатуры
    // key - код клавиши
    // x - координата мыши по оси X
    // y - координата мыши по оси Y
    // isPress - признак нажатия клавиши
    // TypeDevice - Тип устройства
    void KeyHandler::FunctionKeyboard(int key, int x, int y, bool isPress, eDeviceKey typeDevice)
    {
        bool isUnknown = true; // Флаг определяет нажатие знакомой клавиши
        for (size_t i = 0; i < sizeKeys; i++)
        {
            if (keys[i].TypeDevice == typeDevice && keys[i].Value == key)
            {
                keys[i].IsPress = isPress;
                keys[i].MouseX = x;
                keys[i].MouseY = y;
                isUnknown = false;
            }
        }

        if (isUnknown)
        {
            KeyUnknown(key, x, y, isPress, typeDevice);
        }
    }

    // Функция для обработки неизвестной клавиши
    // key - код клавиши
    // x - координата мыши по оси X
    // y - координата мыши по оси Y
    // isPress - признак нажатия клавиши
    // deviceKey - Тип устройства
    void KeyHandler::KeyUnknown(int key, int x, int y, bool isPress, eDeviceKey deviceKey)
    {
        for (size_t i = 0; i < sizeUnknownKeys; i++)
        {
            if (isPress && unknownKeys[i].IsPress && unknownKeys[i].Value == key && unknownKeys[i].TypeDevice == deviceKey)
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
                    unknownKeys[i].MouseX = x;
                    unknownKeys[i].MouseY = y;
                    unknownKeys[i].TypeDevice = deviceKey;
                    return;
                }
            }
            else
            {
                if (unknownKeys[i].IsPress && unknownKeys[i].Value == key)
                {
                    unknownKeys[i].Value = 0;
                    unknownKeys[i].IsPress = false;
                    unknownKeys[i].MouseX = 0;
                    unknownKeys[i].MouseY = 0;
                    unknownKeys[i].TypeDevice = deviceKey;
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

    // Функция для отслеживания пассивного движения мыши (с нажатой кнопкой)
    // x - координата мыши по оси X
    // y - координата мыши по оси Y
    void KeyHandler::MotionFunc(int x, int y)
    {
        mouseIsChangedOX = true;     // Устанавливаем флаг указывающий на изменение координат мышки
        mouseIsChangedOY = true;     // Устанавливаем флаг указывающий на изменение координат мышки
        oldMouseOX = currentMouseOX; // Запоминаем положение мышки по оси X
        oldMouseOY = currentMouseOY; // Запоминаем положение мышки по оси Y

        currentMouseOX = x; // Запоминаем положение мышки по оси X
        currentMouseOY = y; // Запоминаем положение мышки по оси Y
    }


    // Функция для отслеживания пассивного движения мыши (без нажатия кнопки)
    // x - координата мыши по оси X
    // y - координата мыши по оси Y
    void KeyHandler::PassiveMotionFunc(int x, int y)
    {
        mouseIsChangedOX = true;     // Устанавливаем флаг указывающий на изменение координат мышки
        mouseIsChangedOY = true;     // Устанавливаем флаг указывающий на изменение координат мышки
        oldMouseOX = currentMouseOX; // Запоминаем положение мышки по оси X
        oldMouseOY = currentMouseOY; // Запоминаем положение мышки по оси Y

        currentMouseOX = x; // Запоминаем положение мышки по оси X
        currentMouseOY = y; // Запоминаем положение мышки по оси Y
    }

    // Получить сдвиг мышки по оси X
    int KeyHandler::GetMouseShiftOX()
    {
        int result = 0;
        if (mouseIsChangedOX)
        {
            mouseIsChangedOX = false; // Устанавливаем флаг указывающий на то что измененные координаты получены
            result = currentMouseOX - oldMouseOX;
            oldMouseOX = currentMouseOX;
        }
        return result;
    }

    // Получить сдвиг мышки по оси Y
    int KeyHandler::GetMouseShiftOY()
    {
        int result = 0;
        if (mouseIsChangedOY)
        {
            mouseIsChangedOY = false; // Устанавливаем флаг указывающий на то что измененные координаты получены
            result = currentMouseOY - oldMouseOY;
            oldMouseOY = currentMouseOY;
        }
        return result;
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

                resultStr += "[" + keys[i].Code + "=" + GetStringStructKey(keys[i]) + "]";
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
        string result = "Mouse [" + std::to_string(currentMouseOX) + ";" + std::to_string(currentMouseOY) + "] ";
        result += "Keys (";
        result += std::to_string(rKey.Value);

        if (rKey.Value < 128 && rKey.TypeDevice == eDeviceKey::Keyboard)
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

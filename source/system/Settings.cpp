#include <fstream>
#include <system/Settings.h>

#define NAMEFILESETTINGS "settings.conf"

namespace robbiespace
{
    Settings globalSettings;

    // Загрузка настроек из файла
    Settings::Settings()
    {
        LoadFromFile();
    }

    // Запись настроек в файл
    Settings::~Settings()
    {
        SaveToFile();  
    }

    // Получение значения настройки типа int, если нет такого значения то добавляется значение по умолчанию
    int Settings::GetSettingOrDefault(string name, int defaultValue)
    {
        map<string, int>::iterator it;
        it = _listInt.find(name);
        if (it != _listInt.end())
        {
            return it->second;
        }
        else
        {
            _listInt.insert(pair<string, int>(name, defaultValue));
            return defaultValue;
        }
    }

    // Получение значения настройки типа char, если нет такого значения то добавляется значение по умолчанию
    char Settings::GetSettingOrDefault(string name, char defaultValue)
    {
        map<string, char>::iterator it;
        it = _listChar.find(name);
        if (it != _listChar.end())
        {
            return it->second;
        }
        else
        {
            _listChar.insert(pair<string, char>(name, defaultValue));
            return defaultValue;
        }
    }

    // Получение значения настройки типа float, если нет такого значения то добавляется значение по умолчанию
    double Settings::GetSettingOrDefault(string name, float defaultValue)
    {
        map<string, float>::iterator it;
        it = _listFloat.find(name);
        if (it != _listFloat.end())
        {
            return it->second;
        }
        else
        {
            _listFloat.insert(pair<string, float>(name, defaultValue));
            return defaultValue;
        }
    }

    // Получение значения настройки типа double, если нет такого значения то добавляется значение по умолчанию
    double Settings::GetSettingOrDefault(string name, double defaultValue)
    {
        map<string, double>::iterator it;
        it = _listDouble.find(name);
        if (it != _listDouble.end())
        {
            return it->second;
        }
        else
        {
            _listDouble.insert(pair<string, double>(name, defaultValue));
            return defaultValue;
        }
    }

    // Получение значения настройки типа string, если нет такого значения то добавляется значение по умолчанию
    string Settings::GetSettingOrDefault(string name, string defaultValue)
    {
        map<string, string>::iterator it;
        it = _listString.find(name);
        if (it != _listString.end())
        {
            return it->second;
        }
        else
        {
            _listString.insert(pair<string, string>(name, defaultValue));
            return defaultValue;
        }
    }

    // Запись настроек в файл
    void Settings::SaveToFile()
    {
        ofstream out;
        out.open(NAMEFILESETTINGS);
        if (!out)
        {
            return;
        }
        out.precision(16);
        // Записываем настройки типа int
        map<string, int>::iterator itInt = _listInt.begin();
        while (itInt != _listInt.end())
        {
            string name = itInt->first;
            int value = itInt->second;
            out << name << " " << value << std::endl;
            itInt++;
        }
        // Записываем настройки типа char
        map<string, char>::iterator itChar = _listChar.begin();
        while (itChar != _listChar.end())
        {
            string name = itChar->first;
            char value = itChar->second;
            out << name << " " << value << std::endl;
            itChar++;
        }
        // Записываем настройки типа float
        map<string, float>::iterator itFloat = _listFloat.begin();
        while (itFloat != _listFloat.end())
        {
            string name = itFloat->first;
            float value = itFloat->second;
            out << name << " " << value << std::endl;
            itFloat++;
        }
        // Записываем настройки типа double
        map<string, double>::iterator itDouble = _listDouble.begin();
        while (itDouble != _listDouble.end())
        {
            string name = itDouble->first;
            double value = itDouble->second;
            out << name << " " << value << std::endl;
            itDouble++;
        }
        // Записываем настройки типа string
        map<string, string>::iterator itString = _listString.begin();
        while (itString != _listString.end())
        {
            string name = itString->first;
            string value = itString->second;
            out << name << " " << value << std::endl;
            itString++;
        }
        out.close();
    }

    // Загрузка настроек из файла
    void Settings::LoadFromFile()
    {
        ifstream in;
        in.open(NAMEFILESETTINGS);
        if (!in)
        {
            return;
        }
        in.precision(16);
        string nameValue;
        char firstChar;
        int intValue;
        char charValue;
        float floatValue;
        double doubleValue;
        string stringValue;
        string strFalse; // Для незнакомых типов

        while (in)
        {
            in >> nameValue;
            if (nameValue.length() > 0)
            {
                firstChar = nameValue[0];
                switch (firstChar)
                {
                case 'i':
                    in >> intValue;
                    GetSettingOrDefault(nameValue, (int)intValue);
                    break;
                case 'c':
                    in >> charValue;
                    GetSettingOrDefault(nameValue, (char)charValue);
                    break;
                case 'f':
                    in >> floatValue;
                    GetSettingOrDefault(nameValue, (float)floatValue);
                    break;
                case 'd':
                    in >> doubleValue;
                    GetSettingOrDefault(nameValue, (double)doubleValue);
                    break;
                case 's':
                    in >> stringValue;
                    GetSettingOrDefault(nameValue, (string)stringValue);
                    break;

                default:
                    in >> strFalse;
                    break;
                }
            }
        }
        in.close();
    }

    // Изменение параметра настройки типа int
    void Settings::SetValue(string name, int newValue)
    {
        map<string, int>::iterator it;
        it = _listInt.find(name);
        if (it != _listInt.end())
        {
            it->second = newValue;
        }
    }

    // Изменение параметра настройки типа char
    void Settings::SetValue(string name, char newValue)
    {
        map<string, char>::iterator it;
        it = _listChar.find(name);
        if (it != _listChar.end())
        {
            it->second = newValue;
        }
    }

    // Изменение параметра настройки типа float
    void Settings::SetValue(string name, float newValue)
    {
        map<string, float>::iterator it;
        it = _listFloat.find(name);
        if (it != _listFloat.end())
        {
            it->second = newValue;
        }
    }

    // Изменение параметра настройки типа double
    void Settings::SetValue(string name, double newValue)
    {
        map<string, double>::iterator it;
        it = _listDouble.find(name);
        if (it != _listDouble.end())
        {
            it->second = newValue;
        }
    }
    
    // Изменение параметра настройки типа string
    void Settings::SetValue(string name, string newValue)
    {
        map<string, string>::iterator it;
        it = _listString.find(name);
        if (it != _listString.end())
        {
            it->second = newValue;
        }
    }
} // namespace robbiespace
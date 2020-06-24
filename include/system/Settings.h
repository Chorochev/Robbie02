// Settings.h - Класс для глобальных настроек
#ifndef PROJECT_SYSTEM_SETTINGS_H
#define PROJECT_SYSTEM_SETTINGS_H

#include <map>
#include <string>

using namespace std;

namespace robbiespace
{       
    class Settings
    {
        private:        
        map<string, int> _listInt; // Словарь настроек типа int
        map<string, float> _listFloat; // Словарь настроек типа float
        map<string, double> _listDouble; // Словарь настроек типа double
        map<string, string> _listString; // Словарь настроек типа string
        
        public:
        // Загрузка настроек из файла
        Settings();
        // Запись настроек в файл
        ~Settings();
        // Получение значения настройки типа int, если нет такого значения то добавляется значение по умолчанию
        int GetSettingOrDefault(string name, int defaultValue);
        // Получение значения настройки типа float, если нет такого значения то добавляется значение по умолчанию
        double GetSettingOrDefault(string name, float defaultValue);
        // Получение значения настройки типа double, если нет такого значения то добавляется значение по умолчанию
        double GetSettingOrDefault(string name, double defaultValue);
        // Получение значения настройки типа string, если нет такого значения то добавляется значение по умолчанию
        string GetSettingOrDefault(string name, string defaultValue);
        // Запись настроек в файл
        void SaveToFile();
        // Загрузка настроек из файла
        void LoadFromFile();
        // Изменение параметра настройки типа int
        void SetValue(string name, int newValue);
        // Изменение параметра настройки типа float
        void SetValue(string name, float newValue);
        // Изменение параметра настройки типа double
        void SetValue(string name, double newValue);
        // Изменение параметра настройки типа string
        void SetValue(string name, string valnewValueue);
    };

    extern Settings globalSettings;

} // namespace robbiespace

#endif 
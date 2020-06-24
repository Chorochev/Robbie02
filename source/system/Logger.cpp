#include <iostream>
#include <fstream>
#include <filesystem>
#include <ctime>
#include <cstring>
#include <Logger.h>

#define NAMEDIRFORLOGS "logs"

namespace robbiespace
{
    Logger globalLogger;

    // Проверка на наличие директории и фала с логами. Если их нет то создаем. Загрузка сообщений.
    Logger::Logger()
    {
        loadMessages();
        loadErrors();
        if (filesystem::exists(NAMEDIRFORLOGS) == 0)
        {
            filesystem::create_directory(NAMEDIRFORLOGS);
        }
        WriteLog(1);
    }

    // Делает последнюю запись в лог.
    Logger::~Logger()
    {
        WriteLog(2);
    }

    // Получение имени файла для текущей даты
    string Logger::getCurrentFileName()
    {
        std::time_t currentTime = std::time(0); // Текущее время
        struct tm now;
        now = *std::localtime(&currentTime);
        char strPath[80] = NAMEDIRFORLOGS;
        strcat(strPath, "/");
        char strDate[40];
        strftime(strDate, sizeof(strDate), "%d-%m-%Y", &now);
        strcat(strDate, ".logs");
        strcat(strPath, strDate);
        return strPath;
    }
    // Получение текущего времени в текстовом формате
    string Logger::getCurrentTime()
    {
        std::time_t currentTime = std::time(0); // Текущее время
        struct tm now;
        now = *std::localtime(&currentTime);
        char strTime[80];
        strftime(strTime, sizeof(strTime), "%d-%m-%Y %X", &now);
        return strTime;
    }

    // Запись сообщения в лог
    // mess - сообщение
    void Logger::writeMessage(string mess)
    {
        std::cout << mess << std::endl;
        string _path = getCurrentFileName();
        ofstream out;
        out.open(_path, ios::app);
        if (!out)
        {
            return;
        }
        out << mess << std::endl;
        out.close();
    }

    // Создание сообщения для лога
    // type - тип сообщения
    // number - номер сообщения
    // addMessage - добавочное сообщение
    string Logger::createMessage(LoggerType type, int number, string addMessage)
    {
        string result = "";
        result = getCurrentTime();
        // Тип сообщения
        result += " [";
        if (type == LoggerType::LT_UNKNOWN)
            result += "UNKNOWN";
        if (type == LoggerType::LT_INFO)
            result += "INFO";
        if (type == LoggerType::LT_WARNING)
            result += "WARNING";
        if (type == LoggerType::LT_ERRORS)
            result += "ERROR";
        result += "] ";

        // Номер
        result += "[NUM_" + std::to_string(number);
        result += "] ";

        map<int, string>::iterator it;
        it = _messages.find(number);
        if (it != _messages.end())
            result += it->second;
        else
            result += "message not found";
        result += ".";

        if (addMessage.length() > 0)
            result += " " + addMessage;
        result += ".";
        return result;
    }

    // Запись в лог
    // number - номер сообщения
    // addMess - Добавочное сообщение
    void Logger::writeMessage(int number, string addMess)
    {
        LoggerType tMess = LoggerType::LT_UNKNOWN;
        if (number > 0 && number < 1000)
            tMess = LoggerType::LT_INFO;
        if (number >= 1000 && number < 2000)
            tMess = LoggerType::LT_WARNING;
        if (number > 2000)
            tMess = LoggerType::LT_ERRORS;
        string mess = createMessage(tMess, number, addMess);
        writeMessage(mess);
    }

    // Запись в лог
    // number - номер сообщения
    void Logger::WriteLog(int number)
    {
        writeMessage(number, "");
    }

    // Запись в лог
    // number - номер сообщения
    // addMess - Добавочное сообщение
    void Logger::WriteLog(int number, string addMess)
    {
        writeMessage(number, addMess);
    }

    // Загрузка сообщений
    void Logger::loadMessages()
    {
        _messages.insert(pair<int, string>(0, "Unknown message"));
        _messages.insert(pair<int, string>(1, "Start log"));
        _messages.insert(pair<int, string>(2, "End log"));
    }
    
    // Загрузка ошибок
    void Logger::loadErrors()
    {
        _messages.insert(pair<int, string>(2000, "Unknown Error"));
    }

} // namespace robbiespace
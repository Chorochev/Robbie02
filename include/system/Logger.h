// Logger.h - Класс для логирования
#ifndef PROJECT_SYSTEM_LOGGER_H
#define PROJECT_SYSTEM_LOGGER_H

#include <map>
#include <string>

using namespace std;

namespace robbiespace
{
    // Типы сообщений лога
    enum class LoggerType
    {
        LT_UNKNOWN,
        LT_INFO,
        LT_WARNING,
        LT_ERRORS,
    };

    class Logger
    {
    private:
        // Сообщения
        map<int, string> _messages;
        // Загрузка сообщений
        void loadMessages();
        // Загрузка ошибок
        void loadErrors();
        // Получение текущей даты в текстовом формате
        string getCurrentFileName();
        // Получение текущего времени в текстовом формате
        string getCurrentTime();
        // Создание сообщения для лога
        // type - тип сообщения (1-INFO;2-ERROR)
        // number - номер сообщения
        // addMessage - добавочное сообщение
        string createMessage(LoggerType type, int number, string addMessage);
        // Запись сообщения в лог
        // mess - сообщение
        void writeMessage(string mess);
        // Запись в лог
        // number - номер сообщения
        // addMess - Добавочное сообщение
        void writeMessage(int number, string addMess);

    public:
        // Проверка на наличие директории и фала с логами. Если их нет то создаем. Загрузка сообщений.
        Logger();
        // Делает последнюю запись в лог.
        ~Logger();
        // Запись в лог
        // number - номер сообщения
        void WriteLog(int number);
        // Запись в лог
        // number - номер сообщения
        // addMess - Добавочное сообщение
        void WriteLog(int number, string addMess);
    };
    extern Logger globalLogger;

} // namespace robbiespace
#endif
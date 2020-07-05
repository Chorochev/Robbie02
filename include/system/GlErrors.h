// GlErrors.h - Класс для обработки ошибок OpenGL
#ifndef PROJECT_SYSTEM_GLERRORS_H
#define PROJECT_SYSTEM_GLERRORS_H

#include <string>
#include <GL/glut.h>

using namespace std;

namespace robbiespace
{
    class GlErrors
    {
    private:
        int countErrors;  // Количество ошибок
        string textError; // Текст ошибки

        const int numberErrorsForLogs = 3000; // Номера ошибок для лога. Для opengl-ых ошибок номера начинаются с 3000.

        // Создание строки сообщения
        // err - флаг ошибки
        void sreateErrorMessage(GLenum err);

    public:
        GlErrors();

        // Обработчик ошибок
        void ErrorsHandler();

        // Сообщение для консоли
        inline string GetMessageForConsole() { return textError; };
    };

    extern GlErrors globalGlErrors;

} // namespace robbiespace
#endif
#include <sstream>
#include <system/GlErrors.h>
#include <system/Logger.h>

namespace robbiespace
{
    GlErrors globalGlErrors;

    GlErrors::GlErrors()
    {
        countErrors = 0; // Количество ошибок
        textError = "";  // Текст ошибки
        sreateErrorMessage(GL_NO_ERROR);
    }

    // Обработчик ошибок
    void GlErrors::ErrorsHandler()
    {
        GLenum err;
        err = glGetError(); // Берем ошибку из стека ошибок opengl
        if (err != GL_NO_ERROR)
        {
            countErrors++;
            sreateErrorMessage(err);
            int numberError = numberErrorsForLogs + err;
            globalLogger.WriteLog(numberError, textError);
        }
    }

    // Создание строки сообщения
    // err - флаг ошибки
    void GlErrors::sreateErrorMessage(GLenum err)
    {
        stringstream strMessage;
        strMessage << "OpenGL Errors: Count[" << countErrors << "] ";
        if (err != GL_NO_ERROR)
        {
            strMessage << "Code[" << err << "]";

            switch (err)
            {
            case GL_INVALID_VALUE:
                strMessage << ", Text[GL_INVALID_VALUE]";
                break;
            case GL_INVALID_ENUM:
                strMessage << ", Text[GL_INVALID_ENUM]";
                break;
            case GL_INVALID_OPERATION:
                strMessage << ", Text[GL_INVALID_OPERATION]";
                break;

            case GL_STACK_OVERFLOW:
                strMessage << ", Text[GL_STACK_OVERFLOW]";
                break;

            case GL_STACK_UNDERFLOW:
                strMessage << ", Text[GL_STACK_UNDERFLOW]";
                break;

            case GL_OUT_OF_MEMORY:
                strMessage << ", Text[GL_OUT_OF_MEMORY]";
                break;

            default:
                strMessage << ", Text[UNKNOWN]";
                break;
            }
        }
        textError = strMessage.str();
    }
} // namespace robbiespace
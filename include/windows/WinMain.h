/* Класс для основного окна OpenGL */
#ifndef PROJECT_WINDOWS_WINMAIN_H
#define PROJECT_WINDOWS_WINMAIN_H

#include <windows/WinBase.h>

namespace robbiespace
{
    class WinMain : public WinBase
    {

    public:
        WinMain();
        ~WinMain();

        void Create();      // Создание окна
        void DisplayFunc(); // Функция рисования
    };

} // namespace robbiespace
#endif
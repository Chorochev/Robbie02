/* Класс для основного окна OpenGL */
#ifndef PROJECT_WINDOWS_WINMAIN_H
#define PROJECT_WINDOWS_WINMAIN_H

#include <windows/WinBase.h>
#include <geometry/World.h>

namespace robbiespace
{
    class WinMain : public WinBase
    {
    private:
        World *worldScena; // Указатель на класс для сцены

    public:
        WinMain();
        ~WinMain();

        void Create(World *world);                // Создание окна
        void DisplayFunc();                      // Функция рисования
        void ReshapeFunc(int width, int height); //Функция изменения размеров окна
    };

} // namespace robbiespace
#endif
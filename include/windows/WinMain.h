/* Класс для основного окна OpenGL */
#ifndef PROJECT_WINDOWS_WINMAIN_H
#define PROJECT_WINDOWS_WINMAIN_H

#include <string>

#include <windows/WinBase.h>
#include <geometry/World.h>
#include <geometry/Camera.h>
#include <events/KeyHandler.h>

namespace robbiespace
{
    class WinMain : public WinBase
    {

    private:
        World *worldScena; // Указатель на класс для сцены

    public:
        WinMain();
        ~WinMain();

        Camera myCamera = Camera(0.05f, 1.5); // камера вида
        CameraBase *camera;                   // Камера вида
        KeyHandler keyHandler;                // Обработка клавиш

        // Создание окна
        void Create(World *world);

        // Функция рисования
        void DisplayFunc();

        //Функция изменения размеров окна
        // width - Новый размер окна по ширине
        // height - Новый размер окна по высоте
        void ReshapeFunc(int width, int height);

        // Основной таймер
        void MainTimer(int value);

        // Сообщение для консоли
        string GetMessageForConsole();
    };

} // namespace robbiespace
#endif
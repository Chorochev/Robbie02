/* Класс для основного окна OpenGL */
#ifndef PROJECT_WINDOWS_WINMAIN_H
#define PROJECT_WINDOWS_WINMAIN_H

#define DELAY_FOR_TIMER_WINMAIN 30

#include <string>

#include <windows/WinBase.h>
#include <geometry/World.h>
#include <geometry/CameraCustom.h>
#include <geometry/CameraGlut.h>
#include <events/KeyHandler.h>
#include <windows/SubWinTopView.h>

namespace robbiespace
{
    class WinMain : public WinBase
    {

    private:
        World *worldScena; // Указатель на класс для сцены

        int timeFPS;     // текущее число миллисекунд
        int frameFPS;    //  количество кадров в секунду
        int timebaseFPS; // время, когда мы в последний раз вычислили частоту кадров.
        float FPS;       // FPS

        void countFPS(); // Счетчик FPS

        SubWinTopView subWinTopView; // Внутреннее окно для вида сверху

    public:
        WinMain();

        CameraCustom cameraCustom = CameraCustom(0.07f, 1.5); // камера вида
        CameraGlut cameraGlut = CameraGlut(0.07f, 1.5);       // камера вида
        CameraBase *camera;                                   // Камера вида
        KeyHandler keyHandler;                                // Обработка клавиш

        // Создание окна
        void Create(World *world);

        // Создание внутренних окон
        void CreateSubWindows();

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
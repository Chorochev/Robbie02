/* Класс для окна внутри основного окна с видов с верху. */
#ifndef PROJECT_WINDOWS_SUBWINTOPVIEW_H
#define PROJECT_WINDOWS_SUBWINTOPVIEW_H

#define DELAY_FOR_TIMER_SUBWINTOPVIEW 100

#include <windows/WinBase.h>
#include <geometry/World.h>
#include <geometry/CameraCustom.h>

namespace robbiespace
{
    class SubWinTopView : public WinBase
    {
    private:
        World *worldScena;                              // Указатель на класс для сцены
        CameraCustom camera = CameraCustom(0.07f, 1.5); // Класс камеры
    public:
        SubWinTopView();

        // Создание окна
        // idMainWindow - идентификатор главного окна
        // *world - Указатель на класс для сцены
        void Create(int idMainWindow, World *world);

        // Функция рисования
        void DisplayFunc();

        //Функция изменения размеров окна
        // width - Новый размер окна по ширине
        // height - Новый размер окна по высоте
        void ReshapeFunc(int width, int height);

        // Основной таймер
        void MainTimer(int value);
    };

} // namespace robbiespace

#endif
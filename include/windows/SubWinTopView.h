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

        CameraBase *cameraWinMain; // Камера вида основного окна
        KeyHandler *keyHandler;    // Указатель на обработчик клавиш

        // Функция для рисования дополнения
        void Draw();

    public:
        SubWinTopView();

        // Создание окна
        // idMainWindow - идентификатор главного окна
        // *world - Указатель на класс для сцены
        void Create(int idMainWindow, World *world);

        // Функция рисования
        void DisplayFunc();

        // Функция изменения размеров окна
        // width - Новый размер окна по ширине
        // height - Новый размер окна по высоте
        void ReshapeFunc(int width, int height);

        // Изменение размеров и местоположение окна
        // parentWidth - Ширина главного окна
        // parentHeight - Высота главного окна
        void ChangeSizeWindow(int parentWidth, int parentHeight);

        // Изменение размеров окна по ширине
        // newWidth - Ширина окна
        inline void ChangeWidthWindow(int newWidth) { iWindowSizeWidth = newWidth; }

        // Изменение размеров окна по высоте
        // newHeight - Высота окна
        inline void ChangeHeightWindow(int newHeight) { iWindowSizeHeight = newHeight; }

        // Устанока ссылки на камеру основного вида
        // pCameraWinMain - Указатель на камеру главного окна
        inline void SetCameraWinMain(CameraBase *pCameraWinMain) { cameraWinMain = pCameraWinMain; }

        // Устанока ссылки на обработчик клавиш
        // pKeyHandler - Указатель на камеру главного окна
        inline void SetKeyHandler(KeyHandler *pKeyHandler) { keyHandler = pKeyHandler; }

        // Основной таймер
        void MainTimer(int value);
    };

} // namespace robbiespace

#endif
/* Класс для камеры */
#ifndef PROJECT_GEOMETRY_CAMERAGLUT_H
#define PROJECT_GEOMETRY_CAMERAGLUT_H

#include <geometry/CameraBase.h>
#include <geometry/RobVector.h>

namespace robbiespace
{
    class CameraGlut : public CameraBase
    {
    private:
        RobVector vecTranslate;

    public:
        // Инициализация камеры
        // speed_move - Скорость движения камеры
        // shift_angel - Угол поворота камеры
        CameraGlut(float speed_move, double shift_angel);

        // установка камеры
        void LookAt();

        // Сдвинуть камеру вперед или назад по оси X
        // step - размер сдвига камеры
        inline void MoveX(float step) { vecTranslate.X += step; };

        // Сдвинуть камеру вперед или назад по оси Y
        // step - размер сдвига камеры
        inline void MoveY(float step) { vecTranslate.Y += step; };

        // Сдвинуть камеру вперед или назад по оси Z
        // step - размер сдвига камеры
        inline void MoveZ(float step) { vecTranslate.Z += step; };

        // Повернуть камеру вокруг оси Y
        // shiftAngel - угол на который нужно повернуть
        void TurnY(double shiftAngel);

        // Обработка клавиш
        // keyHandler - указатель на обработчик клавиш
        void HandlerKeyPressed(KeyHandler *keyHandler);

        // Сообщение для консоли
        string GetMessageForConsole();
    };
} // namespace robbiespace

#endif
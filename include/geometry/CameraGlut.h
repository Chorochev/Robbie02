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

        // Сдвинуть камеру вперед или назад
        // step - переместить камеру
        void Move(float step);

        // Повернуть камеру вокруг оси Y
        // shiftAngel - угол на который нужно повернуть
        void TurnY(double shiftAngel);

        // Обработка клавиш
        // keyHandler - указатель на обработчик клавиш
        void HandlerKeyPressed(KeyHandler *keyHandler);
    };
} // namespace robbiespace

#endif
/* Класс для камеры */
#ifndef PROJECT_GEOMETRY_CAMERACUSTOM_H
#define PROJECT_GEOMETRY_CAMERACUSTOM_H

#include <geometry/CameraBase.h>
#include <geometry/RobVector.h>

namespace robbiespace
{
    class CameraCustom : public CameraBase
    {
    private:
        void IncCurrentAngel(double addAngel);

    public:
        // Инициализация камеры
        // speed_move - Скорость движения камеры
        // shift_angel - Угол поворота камеры
        CameraCustom(float speed_move, double shift_angel);

        // установка камеры
        void LookAt();

        // Сдвинуть камеру вперед или назад
        // step - переместить камеру
        void Move(float step);

        // Повернуть камеру вокруг оси Y
        // shiftAngel - угол на который нужно повернуть
        void TurnY(double shiftAngel);
    };
} // namespace robbiespace

#endif
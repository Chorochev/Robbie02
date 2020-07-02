/* Класс для камеры */
#ifndef PROJECT_GEOMETRY_CAMERA_H
#define PROJECT_GEOMETRY_CAMERA_H

#include <string>
#include <geometry/RobVector.h>

using namespace std;

namespace robbiespace
{
    class Camera
    {
    private:
        RobVector currentEye;    // Текущее положение камеры
        RobVector currentCenter; // Текущая точка зрения камеры (куда камера смотрит)
        RobVector currentUp;     // Текущий угол поворота камеры

        const float sizeVector = 1.0f; // размер нормализованного вектора
        RobVector rotVector;           // Нормализованный вектор вращения
        double currentAngel;           // Текущий угол камеры (0-360 гр.) - Только для консоли

        // Увеличиваем текущий угол камеры
        // addAngel - добавочный угол
        void IncCurrentAngel(double addAngel);

    public:
        Camera();

        // установка камеры
        void LookAt();

        // Сдвинуть камеру вперед или назад
        // step - переместить камеру
        void Move(float step);

        // Повернуть камеру вокруг оси Y
        // shiftAngel - угол на который нужно повернуть
        void TurnY(double shiftAngel);

        // Сообщение для консоли
        string GetMessageForConsole();
    };

} // namespace robbiespace

#endif
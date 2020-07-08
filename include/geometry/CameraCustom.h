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
        const float limit = 2.0f;

    public:
        // Инициализация камеры
        // speed_move - Скорость движения камеры
        // shift_angel - Угол поворота камеры
        CameraCustom(float speed_move, double shift_angel);

        // установка камеры
        void LookAt();

        // Сдвинуть камеру вперед или назад
        // step - размер сдвига камеры
        void Move(float step);

        // Сдвинуть камеру вперед или назад по оси Y
        // step - размер сдвига камеры
        void MoveY(float step);

        // Повернуть камеру вокруг оси X
        // shiftAngel - угол на который нужно повернуть
        void TurnX(double shiftAngel);

        // Повернуть камеру вокруг оси Y
        // shiftAngel - угол на который нужно повернуть
        void TurnY(double shiftAngel);

        // Установка вида паралельно земли
        void CenterView();

        // Обработка клавиш
        // keyHandler - указатель на обработчик клавиш
        void HandlerKeyPressed(KeyHandler *keyHandler);
    };
} // namespace robbiespace

#endif
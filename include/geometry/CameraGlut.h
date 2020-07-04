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
        const float limit = 2.0f;

    public:
        // Инициализация камеры
        // speed_move - Скорость движения камеры
        // shift_angel - Угол поворота камеры
        CameraGlut(float speed_move, double shift_angel);

        // Установка настроек камеры по умолчанию
        void SetPositionDefault();

        // установка камеры
        void LookAt();

        // Сдвинуть камеру вперед или назад по оси X
        // step - размер сдвига камеры
        void MoveX(float step);

        // Сдвинуть камеру вперед или назад по оси Y
        // step - размер сдвига камеры
        void MoveY(float step);

        // Сдвинуть камеру вперед или назад по оси Z
        // step - размер сдвига камеры
        void MoveZ(float step);

        // Обработка клавиш
        // keyHandler - указатель на обработчик клавиш
        void HandlerKeyPressed(KeyHandler *keyHandler);

        // Сообщение для консоли
        string GetMessageForConsole();
    };
} // namespace robbiespace

#endif
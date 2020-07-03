/* Базовый класс для камеры */
#ifndef PROJECT_GEOMETRY_CAMERABASE_H
#define PROJECT_GEOMETRY_CAMERABASE_H

#include <geometry/RobVector.h>
#include <events/KeyHandler.h>

using namespace std;

namespace robbiespace
{
    class CameraBase
    {
    protected:
        string nameCamera;       // Наименование камеры
        string strConsole;       // Строка для консоли
        RobVector currentEye;    // Текущее положение камеры
        RobVector currentCenter; // Текущая точка зрения камеры (куда камера смотрит)
        RobVector currentUp;     // Текущий угол поворота камеры

        const float sizeVector = 1.0f; // размер нормализованного вектора
        RobVector rotVector;           // Нормализованный вектор вращения
        double currentAngelOX;         // Текущий угол камеры (0-360 гр.) по оси X
        double currentAngelOY;         // Текущий угол камеры (0-360 гр.) по оси Y
        double currentAngelOZ;         // Текущий угол камеры (0-360 гр.) по оси Z

        float speedMove;   // Скорость движения камеры
        double shiftAngel; // Угол поворота камеры

        // Получаем увеличенный текущий угол камеры
        // currentAngel - Текущий угол
        // addAngel - добавочный угол
        double GetShiftAngel(double currentAngel, double addAngel);

    public:
        // Инициализация камеры
        // speed_move - Скорость движения камеры
        // shift_angel - Угол поворота камеры
        CameraBase(float speed_move, double shift_angel);

        // Установка скорости перемещения камеры
        // speed_move - Скорость движения камеры
        inline void SetSpeedMove(float speed_move) { speedMove = speed_move; };

        // Установка угла поворота камеры
        // shift_angel - Угол поворота камеры
        inline void SetShiftAngel(double shift_angel) { shiftAngel = shift_angel; };

        // Установка местоположения камеры
        // newEye - новое местоположение камеры
        inline void SetPositionEye(RobVector newEye) { currentEye = newEye; };

        // Установка точки зрения камеры (куда камера смотрит)
        // newCenter - новая точка зрения камеры
        inline void SetPositionCenter(RobVector newCenter) { currentCenter = newCenter; };

        // Установка угола поворота камеры
        // newUp - новый угол поворота камеры
        inline void SetPositionUp(RobVector newUp) { currentUp = newUp; };

        // установка камеры
        virtual void LookAt(){};

        // Сдвинуть камеру вперед или назад
        // step - размер сдвига камеры
        virtual void Move(float step){};

        // Сдвинуть камеру вперед или назад по оси X
        // step - размер сдвига камеры
        virtual void MoveX(float step){};

        // Сдвинуть камеру вперед или назад по оси Y
        // step - размер сдвига камеры
        virtual void MoveY(float step){};

        // Сдвинуть камеру вперед или назад по оси Z
        // step - размер сдвига камеры
        virtual void MoveZ(float step){};

        // Повернуть камеру вокруг оси X
        // shiftAngel - угол на который нужно повернуть
        virtual void TurnX(double shiftAngel) { currentAngelOX = GetShiftAngel(currentAngelOX, shiftAngel); };

        // Повернуть камеру вокруг оси Y
        // shiftAngel - угол на который нужно повернуть
        virtual void TurnY(double shiftAngel) { currentAngelOY = GetShiftAngel(currentAngelOY, shiftAngel); };

        // Повернуть камеру вокруг оси Z
        // shiftAngel - угол на который нужно повернуть
        virtual void TurnZ(double shiftAngel) { currentAngelOZ = GetShiftAngel(currentAngelOZ, shiftAngel); };

        // Обработка клавиш
        // keyHandler - указатель на обработчик клавиш
        virtual void HandlerKeyPressed(KeyHandler *keyHandler){};

        // Сообщение для консоли
        virtual string GetMessageForConsole();
    };

} // namespace robbiespace

#endif
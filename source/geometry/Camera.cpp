#include <GL/glut.h>
#include <math.h>
#include <geometry/Camera.h>
#include <geometry/VectorHelper.h>

namespace robbiespace
{

    // Инициализация камеры
    // speed_move - Скорость движения камеры
    // shift_angel - Угол поворота камеры
    Camera::Camera(float speed_move, double shift_angel)
    {
        // Текущее положение камеры
        currentEye.Y = 0.25f;
        // Текущая точка зрения камеры (куда камера смотрит)
        currentCenter.Y = 0.25f;
        currentCenter.Z = sizeVector;
        // Текущий угол поворота камеры
        currentUp.Y = 1.0f;
        // Нормализованный вектор вращения
        rotVector.Z = sizeVector;
        // Текущий угол камеры (0-360 гр.)
        currentAngel = 0.0;

        speedMove = speed_move;
        shiftAngel = shift_angel;
    }

    // установка камеры
    void Camera::LookAt()
    {
        // установка камеры
        gluLookAt(currentEye.X, currentEye.Y, currentEye.Z, currentCenter.X, currentCenter.Y, currentCenter.Z, currentUp.X, currentUp.Y, currentUp.Z);
    }

    // Увеличиваем текущий угол камеры
    // addAngel - добавочный угол
    void Camera::IncCurrentAngel(double addAngel)
    {
        double newAngel = currentAngel + addAngel;
        if (newAngel >= 0.0 && newAngel <= 360.0)
            currentAngel = newAngel;
        if (newAngel >= 360.0)
            currentAngel = newAngel - 360.0;
        if (newAngel < 0.0)
            currentAngel = 360.0 - newAngel;
    }

    // Сдвинуть камеру вперед или назад
    // step - переместить камеру
    void Camera::Move(float step)
    {
        // Нормализуем вектор
        RobVector normVec = currentCenter - currentEye;
        // Удлиняем нормализованный вектор
        RobVector addVec = normVec * (1.0 + step);
        // Находим вектор сдвига
        RobVector shiftVec = addVec - normVec;
        // Сдвигаем вектора положения камеры и направление вида на вектор сдвига
        currentEye = currentEye + shiftVec;
        currentCenter = currentCenter + shiftVec;
    }

    // Повернуть камеру вокруг оси Y
    // shiftAngel - угол на который нужно повернуть
    void Camera::TurnY(double shiftAngel)
    {
        // Смещаем текущий угол - только для консоли
        IncCurrentAngel(shiftAngel);
        // Нормализуем вектор
        RobVector normVec = currentCenter - currentEye;
        // Поворачиваем нормализованный вектор на заданный угол
        RobVector newVec = globalVectorHelper.RotateY(normVec, shiftAngel);
        // Возвращаем новый вектор на место
        currentCenter = currentEye + newVec;
    }

    // Обработка клавиш
    // keyHandler - указатель на обработчик клавиш
    void Camera::HandlerKeyPressed(KeyHandler *keyHandler)
    {
        if (keyHandler->IsKeyPress(eKeys::KEY_UP))
        {
            Move(speedMove);
        }

        if (keyHandler->IsKeyPress(eKeys::KEY_DOWN))
        {
            Move(-speedMove);
        }

        if (keyHandler->IsKeyPress(eKeys::KEY_LEFT))
        {
            TurnY(-shiftAngel);
        }

        if (keyHandler->IsKeyPress(eKeys::KEY_RIGHT))
        {
            TurnY(shiftAngel);
        }
    }

    // Сообщение для консоли
    string Camera::GetMessageForConsole()
    {
        string resultStr = "Camera: ";
        resultStr += "angel = " + std::to_string(currentAngel) + " ";
        resultStr += "eye[" + std::to_string(currentEye.X) + ";" + std::to_string(currentEye.Y) + ";" + std::to_string(currentEye.Z) + "] ";
        resultStr += "center[" + std::to_string(currentCenter.X) + ";" + std::to_string(currentCenter.Y) + ";" + std::to_string(currentCenter.Z) + "] ";
        return resultStr;
    }

} // namespace robbiespace
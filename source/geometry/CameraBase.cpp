#include <GL/glut.h>
#include <geometry/CameraBase.h>
#include <geometry/VectorHelper.h>

namespace robbiespace
{

    // Инициализация камеры
    // speed_move - Скорость движения камеры
    // shift_angel - Угол поворота камеры
    CameraBase::CameraBase(float speed_move, double shift_angel)
    {
        nameCamera = "CameraBase";
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
        currentAngelOX = 0.0; // Текущий угол камеры (0-360 гр.) по оси X
        currentAngelOY = 0.0; // Текущий угол камеры (0-360 гр.) по оси Y
        currentAngelOZ = 0.0; // Текущий угол камеры (0-360 гр.) по оси Z

        speedMove = speed_move;
        shiftAngel = shift_angel;

        Zoom = 45.0f; // Зум камеры
    }

    // Получаем увеличенный текущий угол камеры
    // currentAngel - Текущий угол
    // addAngel - добавочный угол
    double CameraBase::GetShiftAngel(double currentAngel, double addAngel)
    {
        double newAngel = currentAngel + addAngel;

        if (newAngel >= 360.0)
        {
            currentAngel = newAngel - 360.0;
        }
        if (newAngel <= 0.0)
        {
            currentAngel = 360.0 + newAngel;
        }
        if (newAngel > 0.0 && newAngel < 360.0)
        {
            currentAngel = newAngel;
        }
        return currentAngel;
    }

    // Сообщение для консоли
    string CameraBase::GetMessageForConsole()
    {
        strConsole = nameCamera;
        strConsole += ": ";
        strConsole += "zoom=[" + std::to_string(Zoom) + "] ";
        strConsole += "angels=[" + std::to_string(currentAngelOX) + ";" + std::to_string(currentAngelOY) + ";" + std::to_string(currentAngelOZ) + "] ";
        strConsole += "eye[" + std::to_string(currentEye.X) + ";" + std::to_string(currentEye.Y) + ";" + std::to_string(currentEye.Z) + "] ";
        strConsole += "center[" + std::to_string(currentCenter.X) + ";" + std::to_string(currentCenter.Y) + ";" + std::to_string(currentCenter.Z) + "] ";
        return strConsole;
    }

} // namespace robbiespace
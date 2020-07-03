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

    // Увеличиваем текущий угол камеры
    // addAngel - добавочный угол
    void CameraBase::IncCurrentAngel(double addAngel)
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
    }

    // Сообщение для консоли
    string CameraBase::GetMessageForConsole()
    {
        string resultStr = "Camera: ";
        resultStr += "angel = " + std::to_string(currentAngel) + " ";
        resultStr += "eye[" + std::to_string(currentEye.X) + ";" + std::to_string(currentEye.Y) + ";" + std::to_string(currentEye.Z) + "] ";
        resultStr += "center[" + std::to_string(currentCenter.X) + ";" + std::to_string(currentCenter.Y) + ";" + std::to_string(currentCenter.Z) + "] ";
        return resultStr;
    }

} // namespace robbiespace
#include <sstream>
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
        speedMove = speed_move;
        shiftAngel = shift_angel;
        SetPositionDefault();
    }

    // Установка настроек камеры по умолчанию
    void CameraBase::SetPositionDefault()
    {
        // Текущее положение камеры
        currentEye.X = 0.0f;
        currentEye.Y = 0.25f;
        currentEye.Z = -1.5f;
        // Текущая точка зрения камеры (куда камера смотрит)
        currentCenter.X = 0.0f;
        currentCenter.Y = 0.25f;
        currentCenter.Z = -2.0 + sizeVector;
        // Текущий угол поворота камеры
        currentUp.X = 0.0f;
        currentUp.Y = 1.0f;
        currentUp.Z = 0.0f;
        // Нормализованный вектор вращения
        rotVector.X = 0.0f;
        rotVector.Y = 0.0f;
        rotVector.Z = sizeVector;
        // Текущий угол камеры (0-360 гр.)
        currentAngelOX = 0.0; // Текущий угол камеры (0-360 гр.) по оси X
        currentAngelOY = 0.0; // Текущий угол камеры (0-360 гр.) по оси Y
        currentAngelOZ = 0.0; // Текущий угол камеры (0-360 гр.) по оси Z

        Zoom = 45.0f; // Зум камеры
    }

    // Получаем увеличенный текущий угол камеры
    // currentAngel - Текущий угол
    // addAngel - добавочный угол
    double CameraBase::GetShiftAngel(double currentAngel, double addAngel)
    {
        if (addAngel == 0.0)
            return currentAngel;

        double limitAngel = 3.0;
        if (addAngel > limitAngel)
            addAngel = limitAngel;
        if (addAngel < -limitAngel)
            addAngel = -limitAngel;

        double newAngel = currentAngel + addAngel;

        if (newAngel >= 360.0)
            currentAngel = newAngel - 360.0;

        if (newAngel <= 0.0)
            currentAngel = 360.0 + newAngel;

        if (newAngel > 0.0 && newAngel < 360.0)
            currentAngel = newAngel;

        return currentAngel;
    }

    // Сообщение для консоли
    string CameraBase::GetMessageForConsole()
    {
        stringstream strMessage;
        strMessage.precision(2);
        strMessage << fixed
                   << nameCamera << ": "
                   << "speedMove=[" << speedMove << "] "
                   << "zoom=[" << Zoom << "] "
                   << "angels=[" << currentAngelOX << ";" << currentAngelOY << ";" << currentAngelOZ << "] "
                   << "eye[" << currentEye.X << ";" << currentEye.Y << ";" << currentEye.Z << "] "
                   << "center[" << currentCenter.X << ";" << currentCenter.Y << ";" << currentCenter.Z << "] ";
        return strMessage.str();
    }

} // namespace robbiespace
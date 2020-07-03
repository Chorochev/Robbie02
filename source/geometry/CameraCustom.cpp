#include <GL/glut.h>
#include <geometry/CameraCustom.h>
#include <geometry/VectorHelper.h>

namespace robbiespace
{
    // Инициализация камеры
    // speed_move - Скорость движения камеры
    // shift_angel - Угол поворота камеры
    CameraCustom::CameraCustom(float speed_move, double shift_angel) : CameraBase(speed_move, shift_angel)
    {
        nameCamera = "CameraCustom";
    }

    // установка камеры
    void CameraCustom::LookAt()
    {
        // установка камеры
        gluLookAt(currentEye.X, currentEye.Y, currentEye.Z, currentCenter.X, currentCenter.Y, currentCenter.Z, currentUp.X, currentUp.Y, currentUp.Z);
    }

    // Сдвинуть камеру вперед или назад
    // step - переместить камеру
    void CameraCustom::Move(float step)
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
    void CameraCustom::TurnY(double shiftAngel)
    {
        // Смещаем текущий угол - только для консоли
        currentAngelOY = GetShiftAngel(currentAngelOY, shiftAngel);
        // Нормализуем вектор
        RobVector normVec = currentCenter - currentEye;
        // Поворачиваем нормализованный вектор на заданный угол
        RobVector newVec = globalVectorHelper.RotateY(normVec, shiftAngel);
        // Возвращаем новый вектор на место
        currentCenter = currentEye + newVec;
    }

    // Обработка клавиш
    // keyHandler - указатель на обработчик клавиш
    void CameraCustom::HandlerKeyPressed(KeyHandler *keyHandler)
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

} // namespace robbiespace
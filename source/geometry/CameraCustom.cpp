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
        RobVector newCurrentEye = currentEye + shiftVec;
        if (globalVectorHelper.IsInNormalRoom(newCurrentEye, limit))
        {
            currentEye = newCurrentEye;
            currentCenter = currentCenter + shiftVec;
        }
    }

    // Сдвинуть камеру вперед или назад по оси Y
    // step - размер сдвига камеры
    void CameraCustom::MoveY(float step)
    {
        // Получаем новый вектор с координатами камеры
        //RobVector normVec = currentEye.Y + step;
        if (step > 0.0f && ((currentEye.Y + step) > limit))
            return;
        if (step < 0.0f && ((currentEye.Y + step) < -limit))
            return;
        currentEye.Y += step;
        currentCenter.Y += step;
    }

    // Повернуть камеру вокруг оси X
    // shiftAngel - угол на который нужно повернуть
    void CameraCustom::TurnX(double shiftAngel)
    {
        // Смещаем текущий угол - только для консоли
        currentAngelOX = GetShiftAngel(currentAngelOX, shiftAngel);
        // Нормализуем вектор
        RobVector normVec = currentCenter - currentEye;
        // Поворачиваем нормализованный вектор на заданный угол
        RobVector newVec = globalVectorHelper.RotateX(normVec, shiftAngel);
        // Возвращаем новый вектор на место
        currentCenter = currentEye + newVec;
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

    // Установка вида паралельно земли
    void CameraCustom::CenterView()
    {
        currentCenter.X = currentEye.X;
        currentCenter.Y = currentEye.Y;
        currentCenter.Z = currentEye.X + sizeVector;
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

        if (keyHandler->IsKeyPress(eKeys::PAGE_UP))
        {
            MoveY(speedMove);
        }

        if (keyHandler->IsKeyPress(eKeys::PAGE_DOWN))
        {
            MoveY(-speedMove);
        }

        if (keyHandler->IsKeyPress(eKeys::KEY_F3))
        {
            CenterView();
        }

        // Обработка движения мышки
        TurnX(keyHandler->GetMouseShiftOY());
        TurnY(keyHandler->GetMouseShiftOX());
    }

} // namespace robbiespace
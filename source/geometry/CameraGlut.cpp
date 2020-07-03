#include <GL/glut.h>
#include <geometry/CameraGlut.h>

namespace robbiespace
{
    // Инициализация камеры
    // speed_move - Скорость движения камеры
    // shift_angel - Угол поворота камеры
    CameraGlut::CameraGlut(float speed_move, double shift_angel) : CameraBase(speed_move, shift_angel)
    {
    }

    // установка камеры
    void CameraGlut::LookAt()
    {
        // установка камеры
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef(currentAngel, 0.0, 1.0, 0.0);                       // Rotate on y
        glTranslatef(vecTranslate.X, vecTranslate.Y, vecTranslate.Z); // Translates the screen left or right,
        gluLookAt(currentEye.X, currentEye.Y, currentEye.Z, currentCenter.X, currentCenter.Y, currentCenter.Z, currentUp.X, currentUp.Y, currentUp.Z);
    }

    // Сдвинуть камеру вперед или назад
    // step - переместить камеру
    void CameraGlut::Move(float step)
    {
        vecTranslate.Z += step;
    }

    // Повернуть камеру вокруг оси Y
    // shiftAngel - угол на который нужно повернуть
    void CameraGlut::TurnY(double shiftAngel)
    {
        // Смещаем текущий угол - только для консоли
        IncCurrentAngel(shiftAngel);
    }

    // Обработка клавиш
    // keyHandler - указатель на обработчик клавиш
    void CameraGlut::HandlerKeyPressed(KeyHandler *keyHandler)
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

#include <sstream>
#include <iostream>
#include <GL/glut.h>
#include <geometry/CameraGlut.h>

namespace robbiespace
{
    // Инициализация камеры
    // speed_move - Скорость движения камеры
    // shift_angel - Угол поворота камеры
    CameraGlut::CameraGlut(float speed_move, double shift_angel) : CameraBase(speed_move, shift_angel)
    {
        nameCamera = "CameraGlut";
    }

    // Установка настроек камеры по умолчанию
    void CameraGlut::SetPositionDefault()
    {
        CameraBase::SetPositionDefault();
        vecTranslate.X = 0.0f;
        vecTranslate.Y = 0.0f;
        vecTranslate.Z = 0.0f;
    }

    // установка камеры
    void CameraGlut::LookAt()
    {
        // установка камеры
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef(currentAngelOX, 1.0, 0.0, 0.0);                     // Rotate on x
        glRotatef(currentAngelOY, 0.0, 1.0, 0.0);                     // Rotate on y
        glTranslatef(vecTranslate.X, vecTranslate.Y, vecTranslate.Z); // Translates the screen left or right,
        gluLookAt(currentEye.X, currentEye.Y, currentEye.Z, currentCenter.X, currentCenter.Y, currentCenter.Z, currentUp.X, currentUp.Y, currentUp.Z);
    }

    // Сдвинуть камеру вперед или назад по оси X
    // step - размер сдвига камеры
    void CameraGlut::MoveX(float step)
    {
        if (step > 0.0f && ((vecTranslate.X + step) > limit))
            return;
        if (step < 0.0f && ((vecTranslate.X + step) < -limit))
            return;
        vecTranslate.X += step;
    };

    // Сдвинуть камеру вперед или назад по оси Y
    // step - размер сдвига камеры
    void CameraGlut::MoveY(float step)
    {
        if (step > 0.0f && ((vecTranslate.Y + step) > limit))
            return;
        if (step < 0.0f && ((vecTranslate.Y + step) < -limit))
            return;
        vecTranslate.Y += step;
    };

    // Сдвинуть камеру вперед или назад по оси Z
    // step - размер сдвига камеры
    void CameraGlut::MoveZ(float step)
    {
        if (step > 0.0f && ((vecTranslate.Z + step) > limit))
            return;
        if (step < 0.0f && ((vecTranslate.Z + step) < -limit))
            return;
        vecTranslate.Z += step;
    };

    // Обработка клавиш
    // keyHandler - указатель на обработчик клавиш
    void CameraGlut::HandlerKeyPressed(KeyHandler *keyHandler)
    {
        if (keyHandler->IsKeyPress(eKeys::KEY_UP))
            MoveZ(speedMove);

        if (keyHandler->IsKeyPress(eKeys::KEY_DOWN))
            MoveZ(-speedMove);

        if (keyHandler->IsKeyPress(eKeys::KEY_LEFT))
            MoveX(speedMove);

        if (keyHandler->IsKeyPress(eKeys::KEY_RIGHT))
            MoveX(-speedMove);

        if (keyHandler->IsKeyPress(eKeys::PAGE_UP))
            MoveY(-speedMove);

        if (keyHandler->IsKeyPress(eKeys::PAGE_DOWN))
            MoveY(speedMove);
        // Обработка движения мышки
        TurnX(keyHandler->GetMouseShiftOY());
        TurnY(keyHandler->GetMouseShiftOX());
    }

    // Сообщение для консоли
    string CameraGlut::GetMessageForConsole()
    {
        string strConsole = CameraBase::GetMessageForConsole();
        stringstream strMessage;
        strMessage.precision(2);
        strMessage << fixed << strConsole << "translate[" << vecTranslate.X << ";" << vecTranslate.Y << ";" << vecTranslate.Z << "] ";
        return strMessage.str();
    }
} // namespace robbiespace

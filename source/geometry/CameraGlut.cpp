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

    // Повернуть камеру вокруг оси Y
    // shiftAngel - угол на который нужно повернуть
    void CameraGlut::TurnY(double shiftAngel)
    {
        // Смещаем текущий угол
        IncCurrentAngel(shiftAngel);
    }

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
    }

    // Сообщение для консоли
    string CameraGlut::GetMessageForConsole()
    {
        strConsole = nameCamera;
        strConsole += ": ";
        strConsole += "angel=" + std::to_string(currentAngel) + " ";
        strConsole += "translate[" + std::to_string(vecTranslate.X) + ";" + std::to_string(vecTranslate.Y) + ";" + std::to_string(vecTranslate.Z) + "] ";
        return strConsole;
    }
} // namespace robbiespace

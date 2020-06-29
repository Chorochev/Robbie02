#include <GL/glut.h>
#include <geometry/Camera.h>

namespace robbiespace
{
    Camera::Camera()
    {
        eyeX = 0.0f;    // Положение камеры по OX
        eyeY = 0.5f;    // Положение камеры по OY
        eyeZ = -1.0f;   // Положение камеры по OZ
        centerX = 0.0f; // Точка зрения (куда камера смотрит) по OX
        centerY = 0.0f; // Точка зрения (куда камера смотрит) по OY
        centerZ = 0.0f; // Точка зрения (куда камера смотрит) по OZ
        upX = 0.0f;     // Угол поворота камеры по OX
        upY = 1.0f;     // Угол поворота камеры по OY
        upZ = 0.0f;     // Угол поворота камеры по OZ

        speed = 0.01f; // Скорость смещения камеры
    }

    // установка камеры
    void Camera::LookAt()
    {
        // установка камеры
        gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
    }

    // Сдвинуть камеру вперед
    void Camera::Forward()
    {
        // eyeX - Положение камеры по OX
        // eyeY - Положение камеры по OY
        eyeZ += speed; // Положение камеры по OZ
        // centerX - Точка зрения (куда камера смотрит) по OX
        // centerY - Точка зрения (куда камера смотрит) по OY
        centerZ += speed; // Точка зрения (куда камера смотрит) по OZ
    }

    // Сдвинуть камеру вперед
    void Camera::Back()
    {
        // eyeX - Положение камеры по OX
        // eyeY - Положение камеры по OY
        eyeZ -= speed; // Положение камеры по OZ
        // centerX - Точка зрения (куда камера смотрит) по OX
        // centerY - Точка зрения (куда камера смотрит) по OY
        centerZ -= speed; // Точка зрения (куда камера смотрит) по OZ
    }

} // namespace robbiespace
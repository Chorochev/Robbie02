/* Класс для камеры */
#ifndef PROJECT_GEOMETRY_CAMERA_H
#define PROJECT_GEOMETRY_CAMERA_H

namespace robbiespace
{
    class Camera
    {
    private:
        float eyeX;    // Положение камеры по OX
        float eyeY;    // Положение камеры по OY
        float eyeZ;    // Положение камеры по OZ
        float centerX; // Точка зрения (куда камера смотрит) по OX
        float centerY; // Точка зрения (куда камера смотрит) по OY
        float centerZ; // Точка зрения (куда камера смотрит) по OZ
        float upX;     // Угол поворота камеры по OX
        float upY;     // Угол поворота камеры по OY
        float upZ;     // Угол поворота камеры по OZ

        float speed; // Скорость смещения камеры
    public:
        Camera();
        // установка камеры
        void LookAt();

        // Сдвинуть камеру вперед
        void Forward();

        // Сдвинуть камеру вперед
        void Back();
    };

} // namespace robbiespace
#endif
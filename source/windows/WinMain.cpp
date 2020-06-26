//#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <windows/WinMain.h>
#include <geometry/World.h>

namespace robbiespace
{
    // Указатель на класс для того что-бы осуществить
    // передачу не статических функций класса в методы glut-а.
    WinMain *winMainPoint;

    WinMain::WinMain() : WinBase("Robbie", "main", 400, 400, 200, 200)
    {
        winMainPoint = this;
    }

    WinMain::~WinMain()
    {
    }

    // Функция рисования
    void WinMain::DisplayFunc()
    {
        ///*
        glutSetWindow(idWindow);
        // очистка буфера цвета и глубины
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // обнуление трансформации
        glLoadIdentity();
        // установка камеры
        gluLookAt(0.0f, 0.5f, -1.0f,
                  0.0f, 0.0f, 0.0f,
                  0.0f, 1.0f, 0.0f);

        glPushMatrix();
        rob_GlobalWorld.Floor();
        glPopMatrix();
        // Переключение буферов
        glutSwapBuffers();
        //*/
    }

    //Функция изменения размеров окна
    void WinMain::ReshapeFunc(int width, int height)
    {
        // предупредим деление на ноль
        // если окно сильно перетянуто будет
        if (height == 0)
            height = 1;

        //screenWidth = width;   // Ширина окна
        //screenHeight = height; // Высота окна

        float ratio = width * 1.0 / height;

        // используем матрицу проекции
        glMatrixMode(GL_PROJECTION);
        // Reset матрицы
        glLoadIdentity();
        // определяем окно просмотра
        glViewport(0, 0, width, height);
        // установить корректную перспективу.
        gluPerspective(45.0f, ratio, 0.1f, 100.0f);
        // вернуться к модели
        glMatrixMode(GL_MODELVIEW);
    }

    /////////////////////////////////////////////////////////////////////////////////////
    // Функции переходники
    /////////////////////////////////////////////////////////////////////////////////////
    // Функция переходник для вызова нестатического метода класса для отрисовки экрана
    void DisplayFuncForWinMain()
    {
        winMainPoint->DisplayFunc();
    }

    // Функция переходник для вызова нестатического метода класса при изменении размеров экрана
    void ReshapeFuncForWinMain(int width, int height)
    {
        winMainPoint->ReshapeFunc(width, height);
    }

    /////////////////////////////////////////////////////////////////////////////////////
    // Функции переходники
    /////////////////////////////////////////////////////////////////////////////////////

    // Создание основного окна
    void WinMain::Create()
    {
        // GLUT_DEPTH - Буфер глубины. Используется для отсечения невидимых линий в 3D пространстве при выводе на плоский экран монитора.
        // GLUT_DOUBLE - Двойная буферизация.
        // GLUT_RGB - Цвет состоит из 3х компонентов цвета RGB.
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
        // Размер окна
        glutInitWindowSize(iWindowSizeWidth, iWindowSizeHeight);
        // Местоположение окна
        glutInitWindowPosition(iWindowPositionX, iWindowPositionY);
        idWindow = glutCreateWindow(sNameWindow.c_str());

        glutDisplayFunc(DisplayFuncForWinMain); // Установка функции для рисования
        glutReshapeFunc(ReshapeFuncForWinMain); // Установка функции в случае изменения размеров окна
        //*/
    }

} // namespace robbiespace
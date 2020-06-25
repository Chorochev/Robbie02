//#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <windows/WinMain.h>

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

        // Переключение буферов
        glutSwapBuffers();
        //*/
    }

    /////////////////////////////////////////////////////////////////////////////////////
    // Функции переходники
    /////////////////////////////////////////////////////////////////////////////////////
    // Функция переходник для вызова нестатического метода класса для отрисовки экрана
    void DisplayFuncForWinMain()
    {
        winMainPoint->DisplayFunc();
    }

    /////////////////////////////////////////////////////////////////////////////////////
    // Функции переходники
    /////////////////////////////////////////////////////////////////////////////////////

    // Создание основного окна
    void WinMain::Create()
    {
        ///*
        glutInitDisplayMode(GLUT_RGBA);
        // Размер окна
        glutInitWindowSize(iWindowSizeWidth, iWindowSizeHeight);
        // Местоположение окна
        glutInitWindowPosition(iWindowPositionX, iWindowPositionY);
        idWindow = glutCreateWindow(sNameWindow.c_str());

        glutDisplayFunc(DisplayFuncForWinMain); // Установка функции для рисования
        //*/
    }

} // namespace robbiespace
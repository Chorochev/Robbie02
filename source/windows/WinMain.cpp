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
        worldScena->Floor();
        glPopMatrix();
        // Переключение буферов
        glutSwapBuffers();
    }

    //Функция изменения размеров окна
    void WinMain::ReshapeFunc(int width, int height)
    {        
        // Если окно окажется сильно сжато
        if (width == 0) width = 1;
        if (height == 0) height = 1;

        iWindowSizeWidth = width;   // Ширина окна
        iWindowSizeHeight = height; // Высота окна

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

    // Функция для обработки данных с клавиатуры, возникает при нажатии клавиши
    // код клавиши
    // x - координата мыши по оси X
    // y - координата мыши по оси Y
    void WinMain::KeyboardFunc(unsigned char key, int x, int y)
    {
        keyHandler.FunctionKeyboard(key, x, y);
    }

    // Основной таймер
    void WinMain::MainTimer(int value)
    {
        if (keyHandler.IsKeyPress(eKeys::Exit))
            CloseWindow();
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

    // Функция переходник для вызова нестатического метода класса при нажатии клавиши
    void KeyboardFuncForWinMain(unsigned char key, int x, int y)
    {
        winMainPoint->KeyboardFunc(key, x, y);
    }

    // Функция переходник для вызова нестатического метода класса при нажатии клавиши
    void MainTimerForWinMain(int value)
    {
        winMainPoint->MainTimer(value);
        glutTimerFunc(40, MainTimerForWinMain, 0);
    }

    /////////////////////////////////////////////////////////////////////////////////////
    // Функции переходники
    /////////////////////////////////////////////////////////////////////////////////////

    // Создание основного окна
    void WinMain::Create(World *world)
    {
        worldScena = world;

        // GLUT_DEPTH - Буфер глубины. Используется для отсечения невидимых линий в 3D пространстве при выводе на плоский экран монитора.
        // GLUT_DOUBLE - Двойная буферизация.
        // GLUT_RGB - Цвет состоит из 3х компонентов цвета RGB.
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
        // Размер окна
        glutInitWindowSize(iWindowSizeWidth, iWindowSizeHeight);
        // Местоположение окна
        glutInitWindowPosition(iWindowPositionX, iWindowPositionY);
        idWindow = glutCreateWindow(sNameWindow.c_str());

        glutDisplayFunc(DisplayFuncForWinMain);   // Установка функции для рисования
        glutReshapeFunc(ReshapeFuncForWinMain);   // Установка функции в случае изменения размеров окна
        glutKeyboardFunc(KeyboardFuncForWinMain); // Установка функции для обработки данных с клавиатуры

        glutTimerFunc(40, MainTimerForWinMain, 0);
    }

} // namespace robbiespace
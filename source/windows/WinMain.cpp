#include <GL/glut.h>
#include <GL/freeglut.h>
#include <windows/WinMain.h>
#include <system/PrintTextHelper.h>

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

    // Сообщение для консоли
    string WinMain::GetMessageForConsole()
    {
        return "Screen[" + std::to_string(iWindowSizeWidth) + ":" + std::to_string(iWindowSizeHeight) + "]";
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
        // gluLookAt(0.0f, 0.5f, -1.0f,
        //           0.0f, 0.0f, 0.0f,
        //           0.0f, 1.0f, 0.0f);
        camera.LookAt();

        glPushMatrix();
        worldScena->Floor();
        glPopMatrix();

        glPushMatrix();
        globalPrintTextHelper.PrintTextOnDisplay(iWindowSizeWidth, iWindowSizeHeight, 1, GetMessageForConsole());
        globalPrintTextHelper.PrintTextOnDisplay(iWindowSizeWidth, iWindowSizeHeight, 2, keyHandler.GetMessageForConsole());
        globalPrintTextHelper.PrintTextOnDisplay(iWindowSizeWidth, iWindowSizeHeight, 3, camera.GetMessageForConsole());
        glPopMatrix();
        // Переключение буферов
        glutSwapBuffers();
    }

    //Функция изменения размеров окна
    void WinMain::ReshapeFunc(int width, int height)
    {
        // Если окно окажется сильно сжато
        if (width == 0)
            width = 1;
        if (height == 0)
            height = 1;

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

    // Основной таймер
    void WinMain::MainTimer(int value)
    {
        if (keyHandler.IsKeyPress(eKeys::Exit))
            CloseWindow();

        if (keyHandler.IsKeyPress(eKeys::KEY_UP))
        {
            camera.Move(speedMoveCamera);
        }

        if (keyHandler.IsKeyPress(eKeys::KEY_DOWN))
        {
            camera.Move(-speedMoveCamera);
        }

        if (keyHandler.IsKeyPress(eKeys::KEY_LEFT))
        {
            camera.TurnY(-shiftAngelCamera);
        }

        if (keyHandler.IsKeyPress(eKeys::KEY_RIGHT))
        {
            camera.TurnY(shiftAngelCamera);
        }

        glutPostRedisplay();
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

    // Установка функции для обработки нажатия клавиши клавиатуры
    void KeyboardFuncForWinMain(unsigned char key, int x, int y)
    {
        winMainPoint->keyHandler.FunctionKeyboard(key, x, y, true, eDeviceKey::Keyboard);
    }

    // Установка функции для обработки отжатия клавиши клавиатуры
    void KeyboardUpFuncForWinMain(unsigned char key, int x, int y)
    {
        winMainPoint->keyHandler.FunctionKeyboard(key, x, y, false, eDeviceKey::Keyboard);
    }

    // Установка функции для обработки нажатия специальных клавиши клавиатуры
    void KeyboardSpecialFuncForWinMain(int key, int x, int y)
    {
        winMainPoint->keyHandler.FunctionKeyboard(key, x, y, true, eDeviceKey::KeyboardSpec);
    }

    // Установка функции для обработки отжатия специальных клавиши клавиатуры
    void KeyboardSpecialUpFuncForWinMain(int key, int x, int y)
    {
        winMainPoint->keyHandler.FunctionKeyboard(key, x, y, false, eDeviceKey::KeyboardSpec);
    }

    // Функция переходник для вызова нестатического метода "таймер" из класса
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

        glutDisplayFunc(DisplayFuncForWinMain);             // Установка функции для рисования
        glutReshapeFunc(ReshapeFuncForWinMain);             // Установка функции в случае изменения размеров окна
        glutKeyboardFunc(KeyboardFuncForWinMain);           // Установка функции для обработки нажатия клавиши клавиатуры
        glutKeyboardUpFunc(KeyboardUpFuncForWinMain);       // Установка функции для обработки отжатия клавиши клавиатуры
        glutSpecialFunc(KeyboardSpecialFuncForWinMain);     // Установка функции для обработки нажатия специальных клавиши клавиатуры
        glutSpecialUpFunc(KeyboardSpecialUpFuncForWinMain); // Установка функции для обработки отжатия специальных клавиши клавиатуры

        glutTimerFunc(40, MainTimerForWinMain, 0);
    }

} // namespace robbiespace
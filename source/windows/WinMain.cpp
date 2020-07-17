#include <sstream>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <windows/WinMain.h>
#include <system/PrintTextHelper.h>
#include <system/GlErrors.h>

namespace robbiespace
{
    // Указатель на класс для того что-бы осуществить
    // передачу не статических функций класса в методы glut-а.
    WinMain *winMainPoint;

    WinMain::WinMain() : WinBase("Robbie", "main", 400, 400, 200, 200)
    {
        winMainPoint = this;
        camera = &cameraCustom;
        //camera = &cameraGlut;
        timeFPS = 0;     // текущее число миллисекунд
        frameFPS = 0;    //  количество кадров в секунду
        timebaseFPS = 0; // время, когда мы в последний раз вычислили частоту кадров.
        FPS = 0;         // FPS
    }
    // Счетчик FPS
    void WinMain::countFPS()
    {
        // Код для вычисления кадров в секунду
        frameFPS++;
        timeFPS = glutGet(GLUT_ELAPSED_TIME);
        if (timeFPS - timebaseFPS > 1000)
        {
            //sprintf(strFPS, "FPS:%4.2f", frameFPS * 1000.0 / (timeFPS - timebaseFPS));
            FPS = (float)frameFPS * 1000.0f / (float)(timeFPS - timebaseFPS);
            timebaseFPS = timeFPS;
            frameFPS = 0;
        }
    }

    // Сообщение для консоли
    string WinMain::GetMessageForConsole()
    {
        stringstream strMessage;
        strMessage.precision(2);
        strMessage << fixed << "Screen[" << iWindowSizeWidth << ":" << iWindowSizeHeight << "] "
                   << "FPS " << FPS;
        return strMessage.str();
    }

    // Функция рисования
    void WinMain::DisplayFunc()
    {
        countFPS();
        glutSetWindow(idWindow);
        // очистка буфера цвета и глубины
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // обнуление трансформации
        glLoadIdentity();
        // установка камеры
        camera->LookAt();

        glPushMatrix();
        //worldScena->Floor();
        //worldScena->FloorCells(8, 8);
        //worldScena->Walls();
        worldScena->WorldScena();
        glPopMatrix();

        glPushMatrix();
        globalPrintTextHelper.PrintTextOnDisplay(iWindowSizeWidth, iWindowSizeHeight, 1, GetMessageForConsole());
        globalPrintTextHelper.PrintTextOnDisplay(iWindowSizeWidth, iWindowSizeHeight, 2, camera->GetMessageForConsole());
        globalPrintTextHelper.PrintTextOnDisplay(iWindowSizeWidth, iWindowSizeHeight, 3, globalGlErrors.GetMessageForConsole());
        globalPrintTextHelper.PrintTextOnDisplay(iWindowSizeWidth, iWindowSizeHeight, 4, keyHandler.GetMessageForConsole());
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
        gluPerspective(camera->Zoom, ratio, 0.1, 100.0);
        // вернуться к модели
        glMatrixMode(GL_MODELVIEW);

        subWinTopView.ChangeSizeWindow(width, height); // Внутреннее окно для вида сверху
    }

    // Основной таймер
    void WinMain::MainTimer(int value)
    {
        globalGlErrors.ErrorsHandler();

        glutSetWindow(idWindow);

        camera->HandlerKeyPressed(&keyHandler);

        worldScena->HandlerKeyPressed(&keyHandler);

        if (keyHandler.IsKeyPress(eKeys::KEY_F1))
            camera = &cameraCustom; // Переключаемся на ручную камеру

        if (keyHandler.IsKeyPress(eKeys::KEY_F2))
            camera = &cameraGlut; // Переключаемся на камеру glut

        int wheelDir = keyHandler.GetDirectionMouseWheel();
        int newZoom = camera->Zoom + (5 * wheelDir);
        if (newZoom >= 5 && newZoom <= 120 && newZoom != camera->Zoom)
        {
            camera->Zoom = newZoom;
            ReshapeFunc(iWindowSizeWidth, iWindowSizeHeight);
        }

        if (keyHandler.IsKeyPress(eKeys::KEY_F4))
            camera->SetPositionDefault();

        keyHandler.GetColorMousePosition(iWindowSizeHeight);
        keyHandler.FindMousePosition3D();

        if (keyHandler.IsKeyPress(eKeys::Exit))
        {
            CloseWindow();
        }
        else
        {
            glutPostRedisplay();
        }
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
        glutTimerFunc(DELAY_FOR_TIMER_WINMAIN, MainTimerForWinMain, 0);
    }

    // Функция переходник для вызова нестатического метода класса при обработки данных с мышки
    void MouseFuncForWinMain(int button, int state, int x, int y)
    {
        winMainPoint->keyHandler.MouseFunc(button, state, x, y);
    }

    // Функция переходник для вызова нестатического метода класса для отслеживания движения мыши (с нажатой кнопкой)
    void MotionFuncForWinMain(int x, int y)
    {
        winMainPoint->keyHandler.MotionFunc(x, y);
    }

    // Функция переходник для вызова нестатического метода класса для отслеживания пассивного движения мыши (без нажатия кнопки)
    void PassiveMotionFuncWinMain(int x, int y)
    {
        winMainPoint->keyHandler.PassiveMotionFunc(x, y);
    }

    void MouseWheelFuncWinMain(int button, int dir, int x, int y)
    {
        winMainPoint->keyHandler.MouseWheel(button, dir, x, y);
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

        // Включаем отсечение. *включать нужно после создания окна.
        glEnable(GL_DEPTH_TEST);
        // Отсечение прорисовки внутренней стороны полигона (со спины)
        //glEnable(GL_CULL_FACE);

        glutDisplayFunc(DisplayFuncForWinMain);             // Установка функции для рисования
        glutReshapeFunc(ReshapeFuncForWinMain);             // Установка функции в случае изменения размеров окна
        glutKeyboardFunc(KeyboardFuncForWinMain);           // Установка функции для обработки нажатия клавиши клавиатуры
        glutKeyboardUpFunc(KeyboardUpFuncForWinMain);       // Установка функции для обработки отжатия клавиши клавиатуры
        glutSpecialFunc(KeyboardSpecialFuncForWinMain);     // Установка функции для обработки нажатия специальных клавиши клавиатуры
        glutSpecialUpFunc(KeyboardSpecialUpFuncForWinMain); // Установка функции для обработки отжатия специальных клавиши клавиатуры

        glutMotionFunc(MotionFuncForWinMain);            // Установка функции для отслеживания активного движения мышки (с нажатой кнопкой)
        glutMouseWheelFunc(MouseWheelFuncWinMain);       // Установка функции для обработки данных с колеса мышки
        glutMouseFunc(MouseFuncForWinMain);              // Установка функции для обработки данных с мышки
        glutPassiveMotionFunc(PassiveMotionFuncWinMain); // Установка функции для отслеживания пассивного движения мыши (без нажатия кнопки)

        //glutEntryFunc(EntryFuncForWindowGeneral);                 // Установка функции для отслеживания выхода курсора за пределы окна

        glutTimerFunc(DELAY_FOR_TIMER_WINMAIN, MainTimerForWinMain, 0);
    }

    // Создание внутренних окон
    void WinMain::CreateSubWindows()
    {
        subWinTopView.Create(idWindow, worldScena); // Окно для вида сверху
    }

} // namespace robbiespace
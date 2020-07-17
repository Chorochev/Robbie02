#include <GL/glut.h>
#include <windows/SubWinTopView.h>

namespace robbiespace
{
    // Указатель на класс для того что-бы осуществить
    // передачу не статических функций класса в методы glut-а.
    SubWinTopView *subWinTopViewPoint;

    SubWinTopView::SubWinTopView() : WinBase("SubWinTopView", "subWTV", 200, 200, 200, 200)
    {
        subWinTopViewPoint = this;

        RobVector posCenter;
        posCenter.SetValue(0.0f, 0.0f, 0.0f); // куда камера смотрит
        camera.SetPositionCenter(posCenter);

        RobVector posEye;
        posEye.SetValue(0.0f, 3.0f, 0.001f); // Месторасположение камеры
        camera.SetPositionEye(posEye);
    }

    // Функция рисования
    void SubWinTopView::DisplayFunc()
    {
        glutSetWindow(idWindow);
        // очистка буфера цвета и глубины
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // обнуление трансформации
        glLoadIdentity();
        // установка камеры
        camera.LookAt();

        glPushMatrix();
        worldScena->WorldScena();
        glPopMatrix();
        // Переключение буферов
        glutSwapBuffers();
    }

    //Функция изменения размеров окна
    // width - Новый размер окна по ширине
    // height - Новый размер окна по высоте
    void SubWinTopView::ReshapeFunc(int width, int height)
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
        gluPerspective(camera.Zoom, ratio, 0.1, 100.0);
        // вернуться к модели
        glMatrixMode(GL_MODELVIEW);
    }

    // Изменение размеров и местоположение окна
    // parentWidth - Ширина главного окна
    // parentHeight - Высота главного окна
    void SubWinTopView::ChangeSizeWindow(int parentWidth, int parentHeight)
    {
        glutSetWindow(idWindow);       
        // Местоположение окна       
        iWindowPositionX = parentWidth - iWindowSizeWidth;// Позиция окна по OX
        iWindowPositionY = 0;// Позиция окна по OY
        glutPositionWindow(iWindowPositionX, iWindowPositionY);
        glutReshapeWindow(iWindowSizeWidth, iWindowSizeHeight);
    }

    // Основной таймер
    void SubWinTopView::MainTimer(int value)
    {
        glutPostRedisplay();
    }

    /////////////////////////////////////////////////////////////////////////////////////
    // Функции переходники
    /////////////////////////////////////////////////////////////////////////////////////
    // Функция переходник для вызова нестатического метода класса для отрисовки экрана
    void DisplayFuncForSubWinTopView()
    {
        subWinTopViewPoint->DisplayFunc();
    }

    // Функция переходник для вызова нестатического метода класса при изменении размеров экрана
    void ReshapeFuncForSubWinTopView(int width, int height)
    {
        subWinTopViewPoint->ReshapeFunc(width, height);
    }

    // Функция переходник для вызова нестатического метода "таймер" из класса
    void MainTimerForSubWinTopView(int value)
    {
        subWinTopViewPoint->MainTimer(value);
        glutTimerFunc(DELAY_FOR_TIMER_SUBWINTOPVIEW, MainTimerForSubWinTopView, 0);
    }
    /////////////////////////////////////////////////////////////////////////////////////
    // Функции переходники
    /////////////////////////////////////////////////////////////////////////////////////

    // Создание окна
    // idMainWindow - идентификатор главного окна
    // *world - Указатель на класс для сцены
    void SubWinTopView::Create(int idMainWindow, World *world)
    {
        worldScena = world;
        idWindow = glutCreateSubWindow(idMainWindow, iWindowPositionX, iWindowPositionY, iWindowSizeWidth, iWindowSizeHeight);
        glutDisplayFunc(DisplayFuncForSubWinTopView);
        glutReshapeFunc(ReshapeFuncForSubWinTopView);
        glutTimerFunc(DELAY_FOR_TIMER_SUBWINTOPVIEW, MainTimerForSubWinTopView, 0);
    }

} // namespace robbiespace

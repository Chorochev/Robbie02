#include <math.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <system/PrintTextHelper.h>

using namespace std;

namespace robbiespace
{
    PrintTextHelper globalPrintTextHelper;

    PrintTextHelper::PrintTextHelper()
    {
    }

    // Вывод строки на экран
    // width - Размер окна по ширине в пикселях
    // height - Размер окна по высоте в пикселях
    // numberRow - Номер строки
    // message - Сообщение
    void PrintTextHelper::PrintTextOnDisplay(int width, int height, int numberRow, string message)
    {

        glMatrixMode(GL_PROJECTION);     // Выбираем режим проекции
        glPushMatrix();                  // Сохраняем предыдущую матрицу проекции
        glLoadIdentity();                // Обнуляем матрицу текущую матрицу
        gluOrtho2D(0, width, height, 0); // Устанавливаем проекцию
        glMatrixMode(GL_MODELVIEW);      // Выбираем режим обзора
        glPushMatrix();                  // Сохраняем предыдущую матрицу
        glLoadIdentity();                // Обнуляем матрицу текущую матрицу

        glColor3f(1.0f, 1.0f, 1.0f);
        int x = 5;
        int y = 20 * numberRow;
        glRasterPos2i(x, y);
        unsigned char pointStr[message.length() + 1];
        std::copy(message.data(), (message.data() + message.length() + 1), pointStr);
        glutBitmapString(GLUT_BITMAP_9_BY_15, pointStr);

        glPopMatrix();               // Возвращаем предыдущую матрицу
        glMatrixMode(GL_PROJECTION); // Выбираем режим проекции
        glPopMatrix();               // Возвращаем предыдущую матрицу
        glMatrixMode(GL_MODELVIEW);  // Возвращаемся в режим обзора
    }

} // namespace robbiespace
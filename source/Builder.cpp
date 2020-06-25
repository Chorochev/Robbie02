#include <GL/glut.h>
#include <GL/freeglut.h>

#include <Builder.h>

namespace robbiespace
{
    Builder::Builder()
    {
    }

    Builder::~Builder()
    {
    }

    // Запуск
    void Builder::Run(int argc, char *argv[])
    {
        glutInit(&argc, argv);
        // Настройки для glut которые позволяют выходить из программы не сразу, что дает возможность отработать деструкторам классов
        glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
        ////////////////////////////////////////////////////////////
        // Главное окно
        winMain.Create();

        ////////////////////////////////////////////////////////////
        // Главный цикл
        glutMainLoop();
    }
} // namespace robbiespace
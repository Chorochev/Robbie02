#include <GL/glut.h>
#include <GL/freeglut.h>

#include <Builder.h>
#include <geometry/World.h>

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
        World worldScena; // класс для сцены
        //worldScena.CreateScena();
        worldScena.CreateTestScena();
        winMain.Create(&worldScena);
        ////////////////////////////////////////////////////////////
        // Окно для вида сверху
        subWinTopView.Create(winMain.GetIdWindow(), &worldScena);
        ////////////////////////////////////////////////////////////
        // Главный цикл
        glutMainLoop();
    }
} // namespace robbiespace
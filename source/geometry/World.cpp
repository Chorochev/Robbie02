#include <GL/glut.h>
#include <geometry/World.h>

namespace robbiespace
{
    World::World()
    {
    }

    // Создание всех объектов сцены
    void World::CreateScena()
    {
        BoxObj box1 = BoxObj(1);
        box1.SetDefault();
        box1.ChangeSize(0.2f, 0.14f, 0.25f);
        box1.position.X = 0.2f;
        box1.position.Y = 0.4f;
        box1.position.Z = 0.3f;
        listObjs.push_back(box1);
    }

    void World::Floor()
    {
        glColor3f(0.4f, 0.4f, 0.4f);
        glBegin(GL_POLYGON);
        glVertex3f(-1.0f, 0.0f, -1.0f);
        glVertex3f(-1.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, 0.0f, -1.0f);
        glEnd();
    }

    // Пол в клеточку
    // rows - количество строк
    // columns - количество столбцов
    void World::FloorCells(int rows, int columns)
    {
        bool changeColor = false;
        float color1[3] = {0.5f, 0.5f, 0.5f};
        float color2[3] = {0.3f, 0.3f, 0.3f};

        float sizeRow = 2.0f / ((float)rows);
        float sizeColumn = 2.0f / ((float)columns);

        float startX = -1.0f;
        float startY = 0.0f;
        float startZ = 1.0f;

        float x = startX;
        float y = startY;
        float z = startZ;

        for (size_t r = 0; r < rows; r++)
        {
            z = startZ - (r * sizeRow);
            for (size_t c = 0; c < columns; c++)
            {
                x = startX + (c * sizeColumn);
                if (changeColor)
                    glColor3fv(color1);
                else
                    glColor3fv(color2);

                glBegin(GL_POLYGON);
                glVertex3f(x, y, z);
                glVertex3f(x + sizeColumn, y, z);
                glVertex3f(x + sizeColumn, y, z - sizeRow);
                glVertex3f(x, y, z - sizeRow);
                glEnd();
                changeColor = !changeColor;
            }
            changeColor = !changeColor;
        }
    }

    // Стены
    void World::Walls()
    {
        glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.3f, 0.0f);
        glVertex3f(-1.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glColor3f(0.0f, 0.0f, 0.3f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, 0.0f, 1.0f);
        glEnd();
    }

    // Прорисовка всей сцены
    void World::WorldScena()
    {
        FloorCells(8, 8);
        Walls();

        list<BoxObj>::iterator ob = listObjs.begin();
        while (ob != listObjs.end())
        {
            int tt = ob->GetID();
            const char *n = ob->GetName().c_str();
            ob->Display();
            ob++;
        }
    }

} // namespace robbiespace
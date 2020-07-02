#include <GL/glut.h>
#include <geometry/World.h>

namespace robbiespace
{
    World::World()
    {
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
        float color1[3] = {0.8f, 0.8f, 0.8f};
        float color2[3] = {0.2f, 0.2f, 0.2f};

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
            z = startZ + (r * sizeRow);
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

} // namespace robbiespace
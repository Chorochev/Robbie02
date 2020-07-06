#include <GL/glut.h>
#include <objects/BoxObj.h>

namespace robbiespace
{
    // Коструктор коробки
    // id - идентификатор объекта
    BoxObj::BoxObj(int id) : BaseObj(id, "box")
    {
    }

    // Вывод объекта на экран
    void BoxObj::Display()
    {
        GLfloat pVerts[] = {-0.5f, -0.5f, 0.5f,
                            0.5f, 0.0f, 0.0f,
                            -0.5f, 0.5f, 0.0f};

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, pVerts);

        glColor3ub(255, 0, 0); // красный
        glDrawArrays(GL_POLYGON, 0, 3);
        //glDrawArrays(GL_TRIANGLES, 0, 3);
    }

} // namespace robbiespace
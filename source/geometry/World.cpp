
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

} // namespace robbiespace
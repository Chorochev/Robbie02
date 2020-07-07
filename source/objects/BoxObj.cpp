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
        glTranslatef(position.X, position.Y, position.Z);
        glColor3f(0.6f, 0.1f, 0.2f);
        for (size_t i = 0; i < 6; i++)
        {
            glBegin(GL_POLYGON);
            glVertex3f(Sides[i].Point1.X, Sides[i].Point1.Y, Sides[i].Point1.Z);
            glVertex3f(Sides[i].Point2.X, Sides[i].Point2.Y, Sides[i].Point2.Z);
            glVertex3f(Sides[i].Point3.X, Sides[i].Point3.Y, Sides[i].Point3.Z);
            glVertex3f(Sides[i].Point4.X, Sides[i].Point4.Y, Sides[i].Point4.Z);
            glEnd();
        }
    }

    // Установка объекта в начальное сосотояние
    void BoxObj::SetDefault()
    {
        // Создаем куб с нулевым центром
        // Устанавливаем стороны
        Sides[0].sideBox == eSideBoxObj::Front;
        Sides[0].Point1.SetValue(defaultBoxPoints[0]);
        Sides[0].Point2.SetValue(defaultBoxPoints[1]);
        Sides[0].Point3.SetValue(defaultBoxPoints[2]);
        Sides[0].Point4.SetValue(defaultBoxPoints[3]);
        Sides[1].sideBox == eSideBoxObj::Right;
        Sides[1].Point1.SetValue(defaultBoxPoints[1]);
        Sides[1].Point2.SetValue(defaultBoxPoints[5]);
        Sides[1].Point3.SetValue(defaultBoxPoints[6]);
        Sides[1].Point4.SetValue(defaultBoxPoints[2]);
        Sides[2].sideBox == eSideBoxObj::Back;
        Sides[2].Point1.SetValue(defaultBoxPoints[5]);
        Sides[2].Point2.SetValue(defaultBoxPoints[4]);
        Sides[2].Point3.SetValue(defaultBoxPoints[7]);
        Sides[2].Point4.SetValue(defaultBoxPoints[6]);
        Sides[3].sideBox == eSideBoxObj::Left;
        Sides[3].Point1.SetValue(defaultBoxPoints[4]);
        Sides[3].Point2.SetValue(defaultBoxPoints[0]);
        Sides[3].Point3.SetValue(defaultBoxPoints[3]);
        Sides[3].Point4.SetValue(defaultBoxPoints[7]);
        Sides[4].sideBox == eSideBoxObj::Top;
        Sides[4].Point1.SetValue(defaultBoxPoints[0]);
        Sides[4].Point2.SetValue(defaultBoxPoints[1]);
        Sides[4].Point3.SetValue(defaultBoxPoints[5]);
        Sides[4].Point4.SetValue(defaultBoxPoints[4]);
        Sides[5].sideBox == eSideBoxObj::Bottom;
        Sides[5].Point1.SetValue(defaultBoxPoints[3]);
        Sides[5].Point2.SetValue(defaultBoxPoints[2]);
        Sides[5].Point3.SetValue(defaultBoxPoints[6]);
        Sides[5].Point4.SetValue(defaultBoxPoints[7]);
    }

    // Получение нового размера с учетом знака
    float BoxObj::GetNewSize(float oldSize, float newSize)
    {
        if (oldSize >= 0.0f)
            return newSize;
        else
            return -newSize;
    }

    // Установка размера
    // x - размер стороны по оси X
    // y - размер стороны по оси Y
    // z - размер стороны по оси Z
    void BoxObj::ChangeSize(float x, float y, float z)
    {
        for (size_t i = 0; i < 6; i++)
        {
            float fp1[3] = {GetNewSize(Sides[i].Point1.X, x), GetNewSize(Sides[i].Point1.Y, y), GetNewSize(Sides[i].Point1.Z, z)};
            Sides[i].Point1.SetValue(fp1);
            float fp2[3] = {GetNewSize(Sides[i].Point2.X, x), GetNewSize(Sides[i].Point2.Y, y), GetNewSize(Sides[i].Point2.Z, z)};
            Sides[i].Point2.SetValue(fp2);
            float fp3[3] = {GetNewSize(Sides[i].Point3.X, x), GetNewSize(Sides[i].Point3.Y, y), GetNewSize(Sides[i].Point3.Z, z)};
            Sides[i].Point3.SetValue(fp3);
            float fp4[3] = {GetNewSize(Sides[i].Point4.X, x), GetNewSize(Sides[i].Point4.Y, y), GetNewSize(Sides[i].Point4.Z, z)};
            Sides[i].Point4.SetValue(fp4);
        }
    }

} // namespace robbiespace
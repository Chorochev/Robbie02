#include <GL/glut.h>
#include <ctime>
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
        for (size_t i = 0; i < 6; i++)
        {
            glColor3f(Sides[i].Color.X, Sides[i].Color.Y, Sides[i].Color.Z);
            glBegin(GL_POLYGON);
            glVertex3f(Sides[i].Point1.X, Sides[i].Point1.Y, Sides[i].Point1.Z);
            glVertex3f(Sides[i].Point2.X, Sides[i].Point2.Y, Sides[i].Point2.Z);
            glVertex3f(Sides[i].Point3.X, Sides[i].Point3.Y, Sides[i].Point3.Z);
            glVertex3f(Sides[i].Point4.X, Sides[i].Point4.Y, Sides[i].Point4.Z);
            glEnd();
        }
    }

    // Получение нового размера с учетом знака
    float BoxObj::GetNewSize(float oldSize, float newSize)
    {
        if (oldSize >= 0.0f && newSize > 0.0f)
            return newSize / 2.0f;
        else
            return -(newSize / 2.0f);
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

    // Сохранение объекта в поток
    void BoxObj::SaveToSteam(ofstream &out)
    {
        out << "Position"
            << " " << position.X << " " << position.Y << " " << position.Z << std::endl;
        for (size_t i = 0; i < 6; i++)
        {
            out << "SideBox"
                << " " << Sides[i].SideBox << std::endl;
            out << "Color"
                << " " << Sides[i].Color.X << " " << Sides[i].Color.Y << " " << Sides[i].Color.Z << std::endl;
            out << "Point1"
                << " " << Sides[i].Point1.X << " " << Sides[i].Point1.Y << " " << Sides[i].Point1.Z << std::endl;
            out << "Point2"
                << " " << Sides[i].Point2.X << " " << Sides[i].Point2.Y << " " << Sides[i].Point2.Z << std::endl;
            out << "Point3"
                << " " << Sides[i].Point3.X << " " << Sides[i].Point3.Y << " " << Sides[i].Point3.Z << std::endl;
            out << "Point4"
                << " " << Sides[i].Point4.X << " " << Sides[i].Point4.Y << " " << Sides[i].Point4.Z << std::endl;
            out << "SideEndBox" << std::endl;
        }
    }

    // Загрузка данных объекта из потока
    void BoxObj::LoadFromSteam(ifstream &in)
    {
        int i = 0;
        string nameValue;
        while (in)
        {
            in >> nameValue;
            if (nameValue.length() > 0)
            {
                if (nameValue.compare("SideBox") == 0)
                {
                    int iSideBox = 0;
                    in >> iSideBox;
                    Sides[i].SideBox = (eSideBoxObj)iSideBox;
                }

                if (nameValue.compare("Color") == 0)
                    in >> Sides[i].Color.X >> Sides[i].Color.Y >> Sides[i].Color.Z;

                if (nameValue.compare("Point1") == 0)
                    in >> Sides[i].Point1.X >> Sides[i].Point1.Y >> Sides[i].Point1.Z;

                if (nameValue.compare("Point2") == 0)
                    in >> Sides[i].Point2.X >> Sides[i].Point2.Y >> Sides[i].Point2.Z;

                if (nameValue.compare("Point3") == 0)
                    in >> Sides[i].Point3.X >> Sides[i].Point3.Y >> Sides[i].Point3.Z;

                if (nameValue.compare("Point4") == 0)
                    in >> Sides[i].Point4.X >> Sides[i].Point4.Y >> Sides[i].Point4.Z;

                if (nameValue.compare("Position") == 0)
                    in >> position.X >> position.Y >> position.Z;

                if (nameValue.compare("SideEndBox") == 0)
                    i++;

                if (nameValue.compare("EndBoxObj") == 0)
                    return;
            }
        }
    }

} // namespace robbiespace
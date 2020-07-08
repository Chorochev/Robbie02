#include <iostream>
#include <fstream>
#include <filesystem>
#include <GL/glut.h>
#include <geometry/World.h>
#include <objects/ObjHelper.h>

//#define NAMEDIRFORSCENE "scena"

namespace robbiespace
{
    World::World()
    {
        isQuickSaveScena = false; // Признак сохранения сцены
        isQuickLoadScena = false; // Признак загрузки сцены
    }

    // Создание всех объектов сцены
    void World::CreateScena()
    {
    }

    // Создание тестовой сцены
    void World::CreateTestScena()
    {
        listObjs.clear();
        BoxObj wallLeft = BoxObj(1);
        globalObjHelper.SetNextColor();
        globalObjHelper.SetDefaultCube(&wallLeft);
        wallLeft.ChangeSize(0.04f, 0.3f, 2.0f);
        wallLeft.position.SetValue(1.02f, 0.15f, 0.0f);
        listObjs.push_back(wallLeft);

        BoxObj wallBack = BoxObj(2);
        globalObjHelper.SetNextColor();
        globalObjHelper.SetDefaultCube(&wallBack);
        wallBack.ChangeSize(2.0f, 0.3f, 0.04f);
        wallBack.position.SetValue(0.0f, 0.15f, 1.02f);
        listObjs.push_back(wallBack);

        BoxObj wallRight = BoxObj(3);
        globalObjHelper.SetNextColor();
        globalObjHelper.SetDefaultCube(&wallRight);
        wallRight.ChangeSize(0.04f, 0.3f, 2.0f);
        wallRight.position.SetValue(-1.02f, 0.15f, 0.0f);
        listObjs.push_back(wallRight);

        BoxObj wallFront = BoxObj(4);
        globalObjHelper.SetNextColor();
        globalObjHelper.SetNextColor();
        globalObjHelper.SetDefaultCube(&wallFront);
        wallFront.ChangeSize(2.0f, 0.3f, 0.04f);
        wallFront.position.SetValue(0.0f, 0.15f, -1.02f);
        listObjs.push_back(wallFront);
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

    // Прорисовка всей сцены
    void World::WorldScena()
    {
        glPushMatrix();
        FloorCells(8, 8);
        glPopMatrix();
        // Walls();

        list<BoxObj>::iterator ob = listObjs.begin();
        while (ob != listObjs.end())
        {
            //int tt = ob->GetID();
            //const char *n = ob->GetName().c_str();
            glPushMatrix();
            ob->Display();
            glPopMatrix();
            ob++;
        }
    }

    // Сохранение сцены
    // Имя для сохранения сцены
    void World::SaveScena(string name)
    {
        if (filesystem::exists("scena") == 0)
        {
            filesystem::create_directory("scena");
        }
        string _path = "scena/" + name + ".scene";
        ofstream out;
        out.open(_path); //, ios::app);
        if (!out)
        {
            return;
        }
        out.precision(16);
        //out << "Test" << std::endl;
        list<BoxObj>::iterator ob = listObjs.begin();
        while (ob != listObjs.end())
        {
            out << "type" << " " << "BoxObj" << ob->GetName() << std::endl;
            out << "id" << " " << ob->GetID() << " " << "name" << ob->GetName() << std::endl;
            ob->SaveToSteam(out);
            ob++;
        }
        out.close();
    }

    // Обработка клавиш
    // keyHandler - указатель на обработчик клавиш
    void World::HandlerKeyPressed(KeyHandler *keyHandler)
    {
        if (keyHandler->IsKeyPress(eKeys::QUICK_SAVE_SCENA))
        {
            if (!isQuickSaveScena)
            {
                SaveScena("quickSaveScena");
                isQuickSaveScena = true;
            }
        }
        else
        {
            isQuickSaveScena = false;
        }
    }

} // namespace robbiespace
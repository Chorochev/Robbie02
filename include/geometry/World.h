// World.h - Класс для всей сцены
#ifndef PROJECT_GEOMETRY_WORLD_H
#define PROJECT_GEOMETRY_WORLD_H

#include <list>
#include <objects/BoxObj.h>

using namespace std;

namespace robbiespace
{
    class World
    {
    private:
        list<BoxObj> listObjs;

    public:
        World();

        // Создание всех объектов сцены
        void CreateScena();

        // Пол
        void Floor();

        // Пол в клеточку
        // rows - количество строк
        // columns - количество столбцов
        void FloorCells(int rows, int columns);

        // Стены
        void Walls();

        // Прорисовка всей сцены
        void WorldScena();
    };

} // namespace robbiespace
#endif
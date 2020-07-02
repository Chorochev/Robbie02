// World.h - Класс для всей сцены
#ifndef PROJECT_GEOMETRY_WORLD_H
#define PROJECT_GEOMETRY_WORLD_H

namespace robbiespace
{
    class World
    {
    private:
        /* data */
    public:
        World();

        // Пол
        void Floor();

        // Пол в клеточку
        // rows - количество строк
        // columns - количество столбцов
        void FloorCells(int rows, int columns);
    };

} // namespace robbiespace
#endif
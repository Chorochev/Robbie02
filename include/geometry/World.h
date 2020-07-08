// World.h - Класс для всей сцены
#ifndef PROJECT_GEOMETRY_WORLD_H
#define PROJECT_GEOMETRY_WORLD_H

#include <list>
#include <string>
#include <objects/BoxObj.h>
#include <events/KeyHandler.h>

using namespace std;

namespace robbiespace
{
    class World
    {
    private:
        list<BoxObj> listObjs;
        bool isQuickSaveScena; // Признак сохранения сцены
        bool isQuickLoadScena; // Признак загрузки сцены
    public:
        World();

        // Создание всех объектов сцены
        void CreateScena();

        // Создание тестовой сцены
        void CreateTestScena();

        // Пол в клеточку
        // rows - количество строк
        // columns - количество столбцов
        void FloorCells(int rows, int columns);

        // Прорисовка всей сцены
        void WorldScena();

        // Сохранение сцены
        // Имя для сохранения сцены
        void SaveScena(string name);

        // Обработка клавиш
        // keyHandler - указатель на обработчик клавиш
        void HandlerKeyPressed(KeyHandler *keyHandler);
    };

} // namespace robbiespace
#endif
/* Класс для прямоугольного объекта */
#ifndef PROJECT_OBJECTS_BOXOBJ_H
#define PROJECT_OBJECTS_BOXOBJ_H

#include <iostream>
#include <fstream>
#include <system/Structs.h>
#include <objects/BaseObj.h>

namespace robbiespace
{
    // Класс для прямоугольного объекта
    class BoxObj : public BaseObj
    {
    private:
        // Получение нового размера с учетом знака
        float GetNewSize(float oldSize, float newSize);

    public:
        // Коструктор коробки
        // id - идентификатор объекта
        BoxObj(int id);

        structSideBox Sides[6]; // Стороны прямоугольного объекта

        // Установка размера
        // x - размер стороны по оси X
        // y - размер стороны по оси Y
        // z - размер стороны по оси Z
        void ChangeSize(float x, float y, float z);

        // Вывод объекта на экран
        void Display();

        // Сохранение объекта в поток
        void SaveToSteam(ofstream &out);

        // Загрузка данных объекта из потока
        void LoadFromSteam(ifstream &in);
    };

} // namespace robbiespace

#endif
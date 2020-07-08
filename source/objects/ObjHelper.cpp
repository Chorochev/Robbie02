#include <objects/ObjHelper.h>

namespace robbiespace
{
    ObjHelper globalObjHelper;

    ObjHelper::ObjHelper()
    {
        curentObjID = 1;
        // Текущий цвет
        currentColor[0] = 0.2f;
        currentColor[1] = 0.2f;
        currentColor[2] = 0.2f;
        isCurrentColorRED = true;    // Флаг компоненты цвета
        isCurrentColorGREEN = false; // Флаг компоненты цвета
        isCurrentColorBLUE = false;  // Флаг компоненты цвета
    }

    // Установить следующий цвет
    void ObjHelper::SetNextColor()
    {
        float shiftCol = 0.2f; // Сдвиг компоненты цвета
        float minCol = 0.2f;   // Минимальное значение компоненты цвета
        float maxCol = 0.8f;   // Максимальное значение компоненты цвета
        // RED
        if (isCurrentColorRED)
        {
            isCurrentColorRED = false;
            isCurrentColorGREEN = true;
            if (currentColor[0] < maxCol)
                currentColor[0] += shiftCol;
            else
                currentColor[0] = minCol;
            return;
        }
        // GREEN
        if (isCurrentColorGREEN)
        {
            isCurrentColorGREEN = false;
            isCurrentColorBLUE = true;
            if (currentColor[1] < maxCol)
                currentColor[1] += shiftCol;
            else
                currentColor[1] = minCol;
            return;
        }
        // BLUE
        if (isCurrentColorBLUE)
        {
            isCurrentColorBLUE = false;
            isCurrentColorRED = true;
            if (currentColor[2] < maxCol)
                currentColor[2] += shiftCol;
            else
                currentColor[2] = minCol;
            return;
        }
    }

    // Установка объекта в начальное сосотояние в форме куба с размерами от -1 до 1
    void ObjHelper::SetDefaultCube(BoxObj *box)
    {
        float ton = 0.1f; // Для оттенков цвета
        // Создаем куб с нулевым центром
        // Устанавливаем стороны
        box->Sides[0].SideBox == eSideBoxObj::Front;
        box->Sides[0].Color.SetValue(currentColor[0] - ton, currentColor[1] - ton, currentColor[2] - ton);
        box->Sides[0].Point1.SetValue(defaultBoxPoints[0]);
        box->Sides[0].Point2.SetValue(defaultBoxPoints[1]);
        box->Sides[0].Point3.SetValue(defaultBoxPoints[2]);
        box->Sides[0].Point4.SetValue(defaultBoxPoints[3]);

        box->Sides[1].SideBox == eSideBoxObj::Right;
        box->Sides[1].Color.SetValue(currentColor[0] + ton, currentColor[1] + ton, currentColor[2] + ton);
        box->Sides[1].Point1.SetValue(defaultBoxPoints[1]);
        box->Sides[1].Point2.SetValue(defaultBoxPoints[5]);
        box->Sides[1].Point3.SetValue(defaultBoxPoints[6]);
        box->Sides[1].Point4.SetValue(defaultBoxPoints[2]);

        box->Sides[2].SideBox == eSideBoxObj::Back;
        box->Sides[2].Color.SetValue(currentColor[0] - ton, currentColor[1] - ton, currentColor[2] - ton);
        box->Sides[2].Point1.SetValue(defaultBoxPoints[5]);
        box->Sides[2].Point2.SetValue(defaultBoxPoints[4]);
        box->Sides[2].Point3.SetValue(defaultBoxPoints[7]);
        box->Sides[2].Point4.SetValue(defaultBoxPoints[6]);

        box->Sides[3].SideBox == eSideBoxObj::Left;
        box->Sides[3].Color.SetValue(currentColor[0] + ton, currentColor[1] + ton, currentColor[2] + ton);
        box->Sides[3].Point1.SetValue(defaultBoxPoints[4]);
        box->Sides[3].Point2.SetValue(defaultBoxPoints[0]);
        box->Sides[3].Point3.SetValue(defaultBoxPoints[3]);
        box->Sides[3].Point4.SetValue(defaultBoxPoints[7]);

        box->Sides[4].SideBox == eSideBoxObj::Top;
        box->Sides[4].Color.SetValue(currentColor[0], currentColor[1], currentColor[2]);
        box->Sides[4].Point1.SetValue(defaultBoxPoints[0]);
        box->Sides[4].Point2.SetValue(defaultBoxPoints[1]);
        box->Sides[4].Point3.SetValue(defaultBoxPoints[5]);
        box->Sides[4].Point4.SetValue(defaultBoxPoints[4]);

        box->Sides[5].SideBox == eSideBoxObj::Bottom;
        box->Sides[5].Color.SetValue(currentColor[0], currentColor[1], currentColor[2]);
        box->Sides[5].Point1.SetValue(defaultBoxPoints[3]);
        box->Sides[5].Point2.SetValue(defaultBoxPoints[2]);
        box->Sides[5].Point3.SetValue(defaultBoxPoints[6]);
        box->Sides[5].Point4.SetValue(defaultBoxPoints[7]);
    }

} // namespace robbiespace
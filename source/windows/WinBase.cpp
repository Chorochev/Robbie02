#include <GL/glut.h>
#include <system/Settings.h>
#include <windows/WinBase.h>

namespace robbiespace
{
    // name - Наименование окна
    // m - Метка для различия настроек
    // width - Ширина окна
    // height - Высота окна
    // posX - Позиция окна по OX
    // posY - Позиция окна по OY
    WinBase::WinBase(string name, string m, int width, int height, int posX, int posY)
    {
        idWindow = 0;
        // Имя окна
        //string strWindowName = "sWindowName";
        strWindowName += m;
        sNameWindow = globalSettings.GetSettingOrDefault(strWindowName, name);
        // Размер окна
        // string strWindowSizeWidth = "iWindowSizeWidth";
        strWindowSizeWidth += m;
        iWindowSizeWidth = globalSettings.GetSettingOrDefault(strWindowSizeWidth, width);
        // string strWindowSizeHeight = "iWindowSizeHeight";
        strWindowSizeHeight += m;
        iWindowSizeHeight = globalSettings.GetSettingOrDefault(strWindowSizeHeight, height);
        // Местоположение окна
        // string strWindowPositionX = "iWindowPositionX";
        strWindowPositionX += m;
        iWindowPositionX = globalSettings.GetSettingOrDefault(strWindowPositionX, posX);
        // string strWindowPositionY = "iWindowPositionY";
        strWindowPositionY += m;
        iWindowPositionY = globalSettings.GetSettingOrDefault(strWindowPositionY, posY);
    }

    WinBase::~WinBase()
    {
        // Сохраняем настройки окна
        globalSettings.SetValue(strWindowName, sNameWindow);
        globalSettings.SetValue(strWindowSizeWidth, iWindowSizeWidth);
        globalSettings.SetValue(strWindowSizeHeight, iWindowSizeHeight);
        globalSettings.SetValue(strWindowPositionX, iWindowPositionX);
        globalSettings.SetValue(strWindowPositionY, iWindowPositionY);
    }

    // Закрыть окно
    void WinBase::CloseWindow()
    {
        glutDestroyWindow(idWindow);
    }

} // namespace robbiespace
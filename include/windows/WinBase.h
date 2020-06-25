/* Базовый класс для окна OpenGL */
#ifndef PROJECT_WINDOWS_WINBASE_H
#define PROJECT_WINDOWS_WINBASE_H

#include <string>

using namespace std;

namespace robbiespace
{
    class WinBase
    {
    private:
        string strWindowName = "sWindowName";             // Наименование ключа для - Имя окна
        string strWindowSizeWidth = "iWindowSizeWidth";   // Наименование ключа для значения - Ширина окна
        string strWindowSizeHeight = "iWindowSizeHeight"; // Наименование ключа для значения - Высота окна
        string strWindowPositionX = "iWindowPositionX";   // Наименование ключа для значения - Позиция окна по OX
        string strWindowPositionY = "iWindowPositionY";   // Наименование ключа для значения - Позиция окна по OY

    protected:
        int idWindow; // Идентификатор окна
        // Наименование окна
        string sNameWindow;
        // Размер окна
        int iWindowSizeWidth;  // Ширина окна
        int iWindowSizeHeight; // Высота окна
        // Местоположение окна
        int iWindowPositionX; // Позиция окна по OX
        int iWindowPositionY; // Позиция окна по OY

    public:
        // name - Наименование окна
        // m - Метка для различия настроек
        // width - Ширина окна
        // height - Высота окна
        // posX - Позиция окна по OX
        // posY - Позиция окна по OY
        WinBase(string name, string m, int width, int height, int posX, int posY);
        ~WinBase();
    };

} // namespace robbiespace

#endif
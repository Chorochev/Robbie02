#ifndef PROJECT_SYSTEM_PRINTTEXTHELPER_H
#define PROJECT_SYSTEM_PRINTTEXTHELPER_H

#include <string>

using namespace std;

namespace robbiespace
{
    class PrintTextHelper
    {

    public:
        PrintTextHelper();

        // Вывод строки на экран
        // width - Размер окна по ширине в пикселях
        // height - Размер окна по высоте в пикселях
        // numberRow - Номер строки
        // message - Сообщение
        void PrintTextOnDisplay(int width, int height, int numberRow, string message);
    };

    extern PrintTextHelper globalPrintTextHelper;

} // namespace robbiespace

#endif
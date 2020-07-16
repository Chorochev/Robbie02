/* Builder.h Сборка всего проекта */
#ifndef PROJECT_BUILDER_H
#define PROJECT_BUILDER_H

#include <windows/WinMain.h>
#include <windows/SubWinTopView.h>

namespace robbiespace
{
    class Builder
    {
    private:
        WinMain winMain;             // Основное окно
        SubWinTopView subWinTopView; // Окно для вида сверху

    public:
        Builder();
        ~Builder();
        // Старт
        void Run(int argc, char *argv[]);
    };

} // namespace robbiespace
#endif
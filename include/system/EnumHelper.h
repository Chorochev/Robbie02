// EnumHelper.h - Класс помошник для enums (перечислений)
#ifndef PROJECT_SYSTEM_ENUMHELPER_H
#define PROJECT_SYSTEM_ENUMHELPER_H

#include <system/Enums.h>

namespace robbiespace
{
    class EnumHelper
    {
   
    public:
        EnumHelper();
        ~EnumHelper();

        // Перевод перечисления eSideBoxObj в тип int
        // side - значение типа eSideBoxObj
        int ConvertToInt(eSideBoxObj side);

        // Перевод перечисления int в тип eSideBoxObj
        // side - значение типа int 
        eSideBoxObj ConvertToSideBoxObj(int side);
    };
   
    
    extern EnumHelper globalEnumHelper;
}
#endif
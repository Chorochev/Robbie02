#include <system/EnumHelper.h>

namespace robbiespace
{
    EnumHelper globalEnumHelper;

    EnumHelper::EnumHelper()
    {
    }

    EnumHelper::~EnumHelper()
    {
    }

    // Перевод перечисления eSideBoxObj в тип int
    // side - значение типа eSideBoxObj
    int EnumHelper::ConvertToInt(eSideBoxObj side)
    {
        switch (side)
        {
        case eSideBoxObj::Front:
            return 1;
            break;
        case eSideBoxObj::Back:
            return 2;
            break;
        case eSideBoxObj::Left:
            return 3;
            break;
        case eSideBoxObj::Right:
            return 4;
            break;
        case eSideBoxObj::Top:
            return 5;
            break;
        case eSideBoxObj::Bottom:
            return 6;
            break;

        default:
            return 0;
            break;
        }
    }

    // Перевод перечисления int в тип eSideBoxObj
    // side - значение типа int
    eSideBoxObj EnumHelper::ConvertToSideBoxObj(int side)
    {
        switch (side)
        {
        case 1:
            return eSideBoxObj::Front;
            break;
        case 2:
            return eSideBoxObj::Back;
            break;
        case 3:
            return eSideBoxObj::Left;
            break;
        case 4:
            return eSideBoxObj::Right;
            break;
        case 5:
            return eSideBoxObj::Top;
            break;
        case 6:
            return eSideBoxObj::Bottom;
            break;

        default:
            return eSideBoxObj::Unknown;
            break;
        }
    }

} // namespace robbiespace
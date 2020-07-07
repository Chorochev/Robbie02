#include <objects/ObjHelper.h>

namespace robbiespace
{
    ObjHelper globalObjHelper;

    ObjHelper::ObjHelper()
    {
        curentObjID = 1;
    }

    // Создание стены
    // typeWall - тип стены
    // *box - класс стены
    void ObjHelper::GetWall(eSideBoxObj typeWall, BoxObj *box)
    {
        box->SetDefault();
        box->ChangeSize(1.0f, 1.0f, 0.1f);
        box->position.SetValue(0.0f, 0.5f, 1.0f);
    }

} // namespace robbiespace
#include <system/Logger.h>


int main(int argc, char *argv[])
{
    try
    {        
       
        return 0;
    }
    catch (...)
    {        
        robbiespace::globalLogger.WriteLog(2000, "function main().");
        return 1;
    }
}

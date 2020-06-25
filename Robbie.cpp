#include <system/Logger.h>
#include <Builder.h>

int main(int argc, char *argv[])
{
    try
    {
        robbiespace::Builder builder;
        builder.Run(argc, argv);
        return 0;
    }
    catch (...)
    {
        robbiespace::globalLogger.WriteLog(2000, "function main().");
        return 1;
    }
}

#pragma once
#include "Walnut/Core/Assert.h"
#include "shellapi.h"

class GeneralUtils
{
public:
    static void OSOpenInShell(const char* path)
    {
        #ifdef _WIN32
            ShellExecuteA(NULL, "open", path, NULL, NULL, SW_SHOWDEFAULT);
        #else
        #if __APPLE__
                const char* open_executable = "open";
        #else
                const char* open_executable = "xdg-open";
        #endif
                char command[256];
                snprintf(command, 256, "%s \"%s\"", open_executable, path);
                system(command);
        #endif
    }
};

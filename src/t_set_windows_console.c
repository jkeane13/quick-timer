#ifdef _WIN32
#include <windows.h>
#endif

void t_set_windows_console(){
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif
}

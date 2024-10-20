#include <cstdlib>

void cls()
{
#ifdef  _WIN32
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
}
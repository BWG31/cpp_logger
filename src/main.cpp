#include "LogManager.hpp"

int main(void)
{
    LogManager log;
    log.error("Hello from Error");
    log.access("Hello from Access");
    return 0;
}
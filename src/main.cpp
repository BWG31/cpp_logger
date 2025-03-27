#include "LogManager.hpp"

int main(void)
{
    LogManager log;
    log.error("Hello from Error => ERROR");
    log.info("Hello from Error => INFO");
    log.debug("Hello from Error => DEBUG");
    log.critical("Hello from Error => CRITICAL");
    log.access("Hello from Access");
    return 0;
}

/*

    Log

    ErrorLog : Log
        Font [LEVELS]
    AccessLog : Log
    
    Logger
    
    ErrorLogger : Logger
        prints to -> error.log & std::cerr
    AccessLogger : Logger
        prints to -> access.log & std::cout

    LogManager{
        ErrorLogger
        AccessLogger
    }

*/
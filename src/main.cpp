#include "LogManager.hpp"

int main(void)
{
    LogManager log;
    log.setLogLevel(ErrorLogEntry::DEBUG);
    log.debug("Hello from Error => DEBUG");
    log.info("Hello from Error => INFO");
    log.error("Hello from Error => ERROR");
    log.critical("Hello from Error => CRITICAL");

    log.access("Hello from Access");
    return 0;
}

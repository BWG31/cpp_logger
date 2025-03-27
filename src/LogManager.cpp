#include "LogManager.hpp"

const char *	LogManager::DEFAULT_ERROR_LOG_PATH = "error.log";
const char *	LogManager::DEFAULT_ACCESS_LOG_PATH = "access.log";

//  ==========| CONSTRUCTORS / DESTRUCTOR |==========
LogManager::LogManager() : m_errorLog(DEFAULT_ERROR_LOG_PATH), \
                            m_accessLog(DEFAULT_ACCESS_LOG_PATH)
{
    //  DEFAULT
}

LogManager::LogManager(const LogManager &other)
{
    if (this != &other)
        *this = other;
}

LogManager::~LogManager()
{
    //  DEFAULT
}

//  =======| OPERATOR OVERLOADS |=======
LogManager &LogManager::operator=(const LogManager &rhs)
{
    m_errorLog = rhs.getErrorLog();
    m_accessLog = rhs.getErrorLog();
    return *this;
}

//  ============| GETTERS |=============
const Logger &LogManager::getErrorLog() const { return m_errorLog; };
const Logger &LogManager::getAccessLog() const { return m_accessLog; };

//  ============| SETTERS |=============
//  ============| METHODS |=============
void LogManager::error(const std::string &msg)
{
    LogEntry entry(msg);
    m_errorLog.log(entry);
    std::cerr << entry;
}

void LogManager::access(const std::string &msg)
{
    LogEntry entry(msg);
    m_accessLog.log(entry);
    std::cout << entry;
}

//  ========| VIRTUAL METHODS |=========
//  ======| EXTERNAL FUNCTIONS |========
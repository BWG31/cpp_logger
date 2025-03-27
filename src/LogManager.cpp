#include "LogManager.hpp"

const char *	LogManager::DEFAULT_ERROR_LOG_PATH = "error.log";
const char *	LogManager::DEFAULT_ACCESS_LOG_PATH = "access.log";

//  ==========| CONSTRUCTORS / DESTRUCTOR |==========
LogManager::LogManager() : m_errorLog(DEFAULT_ERROR_LOG_PATH),
							m_accessLog(DEFAULT_ACCESS_LOG_PATH),
							m_level(ErrorLogEntry::ERROR)
{}

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
void LogManager::setLogLevel(ErrorLogEntry::e_level lvl)
{
	m_level = lvl;
}

//  ============| METHODS |=============
void LogManager::error(const std::string &msg)
{
	if (m_level <= ErrorLogEntry::ERROR)
		logError(msg, ErrorLogEntry::ERROR);
}
void LogManager::debug(const std::string &msg)
{
	if (m_level <= ErrorLogEntry::DEBUG)
		logError(msg, ErrorLogEntry::DEBUG);
}
void LogManager::info(const std::string &msg)
{
	if (m_level <= ErrorLogEntry::INFO)
		logError(msg, ErrorLogEntry::INFO);
}

void LogManager::critical(const std::string &msg)
{
	if (m_level <= ErrorLogEntry::CRITICAL)
		logError(msg, ErrorLogEntry::CRITICAL);
}

void LogManager::access(const std::string &msg)
{
	LogEntry entry(msg);
	m_accessLog.log(entry);
	std::cout << entry;
}

void LogManager::logError(const std::string &msg, ErrorLogEntry::e_level lvl)
{
	ErrorLogEntry entry(msg, lvl);
	m_errorLog.log(entry);
	std::cerr << entry;
}

//  ========| VIRTUAL METHODS |=========
//  ======| EXTERNAL FUNCTIONS |========
#include "Logger.hpp"

//  ==========| CONSTRUCTORS / DESTRUCTOR |==========
Logger::Logger()
{
	// NOT USED
}

Logger::Logger(const char *logfile)
{
	setLogfile(logfile);
}

Logger::Logger(const Logger &other)
{
	if (this != &other)
	*this = other;
}

Logger::~Logger()
{
	closeLogfile();
}

//  =======| OPERATOR OVERLOADS |=======
Logger &Logger::operator=(const Logger &rhs)
{
	setLogfile(rhs.getLogfilePath().c_str());
	return *this;
}

//  ============| GETTERS |=============
const std::string &Logger::getLogfilePath() const { return m_logfilePath; };

//  ============| SETTERS |=============
void Logger::setLogfile(const char *logfile)
{
	closeLogfile();
	m_logfilePath = logfile;
	m_logfile.open(logfile, std::ios::app);
	if (!m_logfile.is_open())
		std::cerr << "Unable to open logfile: " << logfile << std::endl;
}

//  ============| METHODS |=============
void Logger::closeLogfile()
{
	if (m_logfile.is_open())
		m_logfile.close();
}

void Logger::log(LogEntry &entry)
{
	if (!m_logfile.is_open())
		return;
	m_logfile << entry;
}
//  ========| VIRTUAL METHODS |=========
//  ======| EXTERNAL FUNCTIONS |========
#include "Logger.hpp"

//  ==========| CONSTRUCTORS / DESTRUCTOR |==========
Logger::Logger()
{
	// NOT USED
}

Logger::Logger(const char *logfile) : m_logfilePath(logfile)
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
	closeLogfile();
	m_logfilePath = rhs.getLogfilePath();
	setLogfile(m_logfilePath.c_str());
}

//  ============| GETTERS |=============
const std::string &Logger::getLogfilePath() const { return m_logfilePath; };

//  ============| SETTERS |=============
void Logger::setLogfile(const char *logfile)
{
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

//  ========| VIRTUAL METHODS |=========
//  ======| EXTERNAL FUNCTIONS |========
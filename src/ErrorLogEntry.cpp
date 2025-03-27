#include "ErrorLogEntry.hpp"

//	==========| CONSTRUCTORS / DESTRUCTOR |==========
ErrorLogEntry::ErrorLogEntry() : 
	LogEntry("Default Error LogEntry"),
	m_level(ERROR)
{}

ErrorLogEntry::ErrorLogEntry(const std::string &content, e_level lvl) :
	LogEntry(content),
	m_level(lvl)
{}

ErrorLogEntry::ErrorLogEntry(const ErrorLogEntry &other)
{
	if (this != &other)
		*this = other;
}

ErrorLogEntry::~ErrorLogEntry()
{
	//	DEFAULT
}

//	=======| OPERATOR OVERLOADS |=======
ErrorLogEntry &ErrorLogEntry::operator=(const ErrorLogEntry &rhs)
{
	LogEntry::operator=(rhs);
	m_level = rhs.getLevel();
	return *this;
}

//	============| GETTERS |=============
ErrorLogEntry::e_level ErrorLogEntry::getLevel() const { return m_level; };

std::string ErrorLogEntry::getLevelString() const
{
	switch (m_level)
	{
		case DEBUG : return "DEBUG";
		case INFO : return "INFO";
		case ERROR : return "ERROR";
		case CRITICAL : return "CRITICAL";
		default : return "UNKNOWN";
	}
}

//	============| SETTERS |=============
//	============| METHODS |=============
//	========| VIRTUAL METHODS |=========
void ErrorLogEntry::print(std::ostream &os) const
{
	os << "[" << getTimestamp() << "] " \
	<< "[" << getLevelString() << "] " \
	<< getContent() << std::endl;
}

//	======| EXTERNAL FUNCTIONS |========
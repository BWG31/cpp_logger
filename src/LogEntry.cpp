#include "LogEntry.hpp"

//	==========| CONSTRUCTORS / DESTRUCTOR |==========
LogEntry::LogEntry() :
	m_content("Hello World")
{
	updateTimestamp();
}

LogEntry::LogEntry(const std::string &content) :
	m_content(content)
{
	updateTimestamp();
}

LogEntry::LogEntry(const LogEntry &other)
{
	if (this != &other)
		*this = other;
}

LogEntry::~LogEntry()
{
	//	DEFAULT
}

//	=======| OPERATOR OVERLOADS |=======
LogEntry &LogEntry::operator=(const LogEntry &rhs)
{
	m_timestamp = rhs.getTimestamp();
	m_content = rhs.getContent();
	return *this;
}

//	============| GETTERS |=============
const std::string &LogEntry::getTimestamp() const { return m_timestamp; };
const std::string &LogEntry::getContent() const { return m_content; };

//	============| SETTERS |=============
//	============| METHODS |=============
void LogEntry::updateTimestamp()
{
	char		buffer[100];
	time_t		rawTime = time(NULL);
	struct tm	*timeInfo = localtime(&rawTime);

	strftime(buffer, 100, "%d/%b/%Y %X", timeInfo);
	m_timestamp = buffer;
}
//	========| VIRTUAL METHODS |=========
//	======| EXTERNAL FUNCTIONS |========
std::ostream &operator<<(std::ostream &os, const LogEntry &rhs)
{
	os << "[" << rhs.getTimestamp() << "] " \
	<< rhs.getContent() << std::endl;
	return os;
}
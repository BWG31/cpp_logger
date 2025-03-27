#include "LogEntry.hpp"

//	==========| CONSTRUCTORS / DESTRUCTOR |==========
LogEntry::LogEntry() :
	m_content("Default LogEntry")
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
void LogEntry::setContent(const std::string &content) { m_content = content; };

//	============| METHODS |=============
void LogEntry::updateTimestamp()
{
	char		buffer[100];
	time_t		rawTime = time(NULL);
	struct tm	*timeInfo = localtime(&rawTime);

	strftime(buffer, 100, "%d/%b/%Y %X", timeInfo);
	m_timestamp = buffer;
}

void LogEntry::printTimestamp(std::ostream &os) const
{
	const char TS_FONT[] = "\033[3m";
	const char RESET[] = "\033[0m";
	os << '[' << TS_FONT << getTimestamp() << RESET << ']';
}

void LogEntry::printContent(std::ostream &os) const
{
	const char CONTENT_FONT[] = "\033[32m";
	const char RESET[] = "\033[0m";
	os << ' ' << CONTENT_FONT << getContent() << RESET;
}

//	========| VIRTUAL METHODS |=========
void LogEntry::print(std::ostream &os) const
{
	printTimestamp(os);
	printContent(os);
	os << std::endl;
}

//	======| EXTERNAL FUNCTIONS |========
std::ostream &operator<<(std::ostream &os, LogEntry &rhs)
{
	rhs.print(os);
	return os;
}
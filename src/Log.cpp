#include "Log.hpp"

//	==========| CONSTRUCTORS / DESTRUCTOR |==========
Log::Log() :
	m_timestamp("TIME_GOES_HERE"),
	m_content("Hello World")
{}

Log::Log(const std::string &content) :
	m_timestamp("TIME_GOES_HERE"),
	m_content(content)
{}

Log::Log(const Log &other)
{
	if (this != &other)
		*this = other;
}

Log::~Log()
{
	//	DEFAULT
}

//	=======| OPERATOR OVERLOADS |=======
Log &Log::operator=(const Log &rhs)
{
	m_timestamp = rhs.getTimestamp();
	m_content = rhs.getContent();
	return *this;
}

//	============| GETTERS |=============
const std::string &Log::getTimestamp() const { return m_timestamp; };
const std::string &Log::getContent() const { return m_content; };

//	============| SETTERS |=============
//	============| METHODS |=============
//	========| VIRTUAL METHODS |=========
//	======| EXTERNAL FUNCTIONS |========
std::ostream &operator<<(std::ostream &os, const Log &rhs)
{
	os << "[" <<rhs.getTimestamp() << "] " \
	<< rhs.getContent() << std::endl;
	return os;
}
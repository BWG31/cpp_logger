#ifndef LOGENTRY_HPP
# define LOGENTRY_HPP

# include <string>
# include <iomanip>
# include <ctime>

# include "Font.hpp"

class LogEntry
{
	public:
		LogEntry();
		LogEntry(const std::string &content);
		LogEntry(const LogEntry &other);
		~LogEntry();

		LogEntry &operator=(const LogEntry &rhs);

		const std::string &getTimestamp() const;
		const std::string &getContent() const;

		void setContent(const std::string &content);

		void updateTimestamp();
		virtual void print(std::ostream &os) const;
	public:
		std::string m_timestamp;
		std::string m_content;

	protected:
		void printTimestamp(std::ostream &os) const;
		void printContent(std::ostream &os) const;
};

std::ostream &operator<<(std::ostream &os, LogEntry &rhs);

#endif
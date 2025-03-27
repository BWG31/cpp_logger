#ifndef LOGENTRY_HPP
# define LOGENTRY_HPP

# include <string>
# include <iomanip>

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

	private:
		std::string m_timestamp;
		std::string m_content;
};

std::ostream &operator<<(std::ostream &os, const LogEntry &rhs);

#endif
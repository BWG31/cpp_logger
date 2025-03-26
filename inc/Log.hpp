#ifndef LOG_HPP
# define LOG_HPP

# include <string>
# include <iomanip>

class Log
{
	public:
		Log();
		Log(const std::string &content);
		Log(const Log &other);
		~Log();

		Log &operator=(const Log &rhs);

		const std::string &getTimestamp() const;
		const std::string &getContent() const;

	private:
		std::string m_timestamp;
		std::string m_content;
};

std::ostream &operator<<(std::ostream &os, const Log &rhs);

#endif
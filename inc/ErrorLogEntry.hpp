#ifndef ERRORLOGENTRY_HPP
# define ERRORLOGENTRY_HPP

# include "LogEntry.hpp"

class ErrorLogEntry : public LogEntry
{
	public:
		enum e_level {
			DEBUG,
			INFO,
			ERROR,
			CRITICAL
		};

		ErrorLogEntry();
		ErrorLogEntry(const std::string &content, e_level lvl = ERROR);
		ErrorLogEntry(const ErrorLogEntry &other);
		~ErrorLogEntry();

		ErrorLogEntry &operator=(const ErrorLogEntry &rhs);

		e_level		getLevel() const;
		std::string	getLevelString() const;

		virtual void print(std::ostream &os) const;

	private:
		e_level m_level;
	
		void printLevel(std::ostream &os) const;
};

#endif
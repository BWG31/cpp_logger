#ifndef LOGMANAGER_HPP
# define LOGMANAGER_HPP

# include "Logger.hpp"

class LogManager
{
	public:
		LogManager();
		LogManager(const LogManager &other);
		~LogManager();

		LogManager &operator=(const LogManager &rhs);
	
		const Logger &getErrorLog() const;
		const Logger &getAccessLog() const;

		void	setLogLevel(ErrorLogEntry::e_level);

		// ERROR LOG HANDLERS
		void error(const std::string &msg);
		void debug(const std::string &msg);
		void info(const std::string &msg);
		void critical(const std::string &msg);

		// ACCESS LOG HANDLERS
		void access(const std::string &msg);

	private:
		static const char		*DEFAULT_ERROR_LOG_PATH;
		static const char		*DEFAULT_ACCESS_LOG_PATH;

		Logger					m_errorLog;
		Logger					m_accessLog;
		ErrorLogEntry::e_level	m_level;

		void logError(const LogEntry &entry);
};

#endif
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

		void error(const std::string &msg);
		void access(const std::string &msg);

	private:
		static const char *	DEFAULT_ERROR_LOG_PATH;
		static const char *	DEFAULT_ACCESS_LOG_PATH;

		Logger	m_errorLog;
		Logger	m_accessLog;
};

#endif
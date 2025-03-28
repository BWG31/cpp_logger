#ifndef LOGGER_HPP
# define LOGGER_HPP

# include "LogEntry.hpp"
# include "ErrorLogEntry.hpp"

# include <fstream>
# include <iostream>
# include <string>
# include <sys/stat.h>
# include <sys/types.h>
# include <cstring>

class Logger
{
	public:
		Logger();
		Logger(const char *logfile);
		Logger(const Logger &other);
		~Logger();
		
		Logger &operator=(const Logger &rhs);

		const std::string &getLogfilePath() const;

		void setLogfile(const char *logfile);

		void log(LogEntry &entry);
	private:
		std::ofstream	m_logfile;
		std::string		m_logfilePath;
	
		void closeLogfile();
		void createDirectoryPart() const;
};

#endif
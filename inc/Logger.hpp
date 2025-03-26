#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <fstream>
# include <iostream>
# include <string>

class Logger
{
	public:
		Logger(const char *logfile);
		Logger(const Logger &other);
		~Logger();
		
		Logger &operator=(const Logger &rhs);

		const std::string &getLogfilePath() const;
	private:
		std::ofstream	m_logfile;
		std::string		m_logfilePath;
	
		void setLogfile(const char *logfile);
		void closeLogfile();
		Logger();
};

#endif
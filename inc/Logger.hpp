#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <fstream>
# include <iostream>
# include <string>

class Logger
{
	public:
		Logger();
		Logger(const char *logfile);
		Logger(const Logger &other);
		~Logger();
		
		Logger &operator=(const Logger &rhs);
		// void operator<<(const std::string &str);

		const std::string &getLogfilePath() const;

		void setLogfile(const char *logfile);

		void msg(const std::string &msg);
	private:
		std::ofstream	m_logfile;
		std::string		m_logfilePath;
	
		void closeLogfile();
};

#endif
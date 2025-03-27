#ifndef PRINTER_HPP
# define PRINTER_HPP

# include <iostream>
# include <iomanip>
# include <map>
# include <algorithm>
# include <utility>
# include <string>
# include <sstream>

# include "Font.hpp"

class Printer
{
	public:
		Printer();
		Printer(const Printer &other);
		~Printer();

		Printer &operator=(const Printer &rhs);

		const Font	&getFont() const;
		const Font	&getKeyFont() const;
		const Font	&getValueFont() const;

		void setFont(uint32_t code);
		void setKeyFont(u_int32_t code);
		void setValueFont(u_int32_t code);
		void setOutputStream(std::ostream &os);

		template <typename T>
		void print(const T &data) const{
			*(m_os) << m_defaultFont << data << m_resetFont << std::endl;
		};

		template <typename Key, typename Value>
		void print(const std::map<Key, Value> &map) const
		{
			typedef typename std::map<Key, Value>::const_iterator map_iterator;

			*(m_os) << "MAP {";
			for (map_iterator it = map.begin(); it != map.end(); ++it)
			{
				*(m_os) << "\n\t" << m_keyFont << (*it).first \
				<< m_resetFont << ":\t" \
				<< m_valueFont << (*it).second \
				<< m_resetFont;
			}
			*(m_os) << "\n}" << std::endl;
		};

	private:
		const Font	m_resetFont;

		Font	m_defaultFont;
		Font	m_keyFont;
		Font	m_valueFont;

		std::ostream *m_os;
};

#endif
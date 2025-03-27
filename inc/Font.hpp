#ifndef FONT_HPP
# define FONT_HPP

# include <string>
# include <sstream>
# include <iostream>
# include <iomanip>
# include <stdint.h>

enum style {
	RESET 		= 	0,
	BOLD		= 	1 << 0,
	DIM			=	1 << 1,
	ITALIC		=	1 << 2,
	UNDERLINE	=	1 << 3,
	BLINK		=	1 << 4,
};

enum textColor {
	BLACK		=	(0 << 8) | (1 << 11),
	RED			=	(1 << 8) | (1 << 11),
	GREEN		=	(2 << 8) | (1 << 11),
	YELLOW		=	(3 << 8) | (1 << 11),
	BLUE		=	(4 << 8) | (1 << 11),
	MAGENTA		=	(5 << 8) | (1 << 11),
	CYAN		=	(6 << 8) | (1 << 11),
	WHITE		=	(7 << 8) | (1 << 11),
	BRIGHT		=	1 << 12,
};

enum backgroundColor {
	BG_BLACK	=	(0 << 16) | (1 << 19),
	BG_RED		=	(1 << 16) | (1 << 19),
	BG_GREEN	=	(2 << 16) | (1 << 19),
	BG_YELLOW	=	(3 << 16) | (1 << 19),
	BG_BLUE		=	(4 << 16) | (1 << 19),
	BG_MAGENTA	=	(5 << 16) | (1 << 19),
	BG_CYAN		=	(6 << 16) | (1 << 19),
	BG_WHITE	=	(7 << 16) | (1 << 19),
	BG_BRIGHT	=	1 << 20
};

class Font
{
	public:
		Font();
		Font(const Font &other);
		Font(uint32_t code);
		~Font();

		Font &operator=(const Font &rhs);

		const std::string	&getFont() const;
		uint32_t			getCode() const;

		void	setFont(uint32_t code);
	
		void	add(uint32_t code);
		void	remove(uint32_t code);

	private:
		uint32_t					m_code;
		std::string					m_font;

		std::string	extractStyle(uint8_t code) const;
		std::string extractTextColor(uint16_t code) const;
		std::string	extractBackgroundColor(uint32_t code) const;
		void		prune();
};

std::ostream &operator<<(std::ostream &os, const Font &rhs);

template <typename T>
std::string NumberToString (T Number)
{
	std::ostringstream ss;
	ss << Number;
	return ss.str();
}

#endif
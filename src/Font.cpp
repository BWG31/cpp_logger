#include "Font.hpp"

//  ==========| CONSTRUCTORS / DESTRUCTOR |==========
Font::Font()
{
	setFont(RESET);
}

Font::Font(const Font &other)
{
	*this = other;
}

Font::Font(uint32_t code)
{
	setFont(code);
}

Font::~Font() {}

//  =======| OPERATOR OVERLOADS |=======
Font &Font::operator=(const Font &rhs)
{
	m_code = rhs.getCode();
	m_font = rhs.getFont();
	return *this;
}

//  ============| GETTERS |=============

const std::string &Font::getFont() const { return m_font; };

uint32_t Font::getCode() const { return m_code; };

//  ============| SETTERS |=============

void Font::setFont(uint32_t code)
{
	const std::string	DEFAULT = "\033[0m";
	const std::string	ESC = "\033[";
	const int			filterMask = 0x00FFFFFF;

	code &= filterMask;
	m_code = code;
	if (code == RESET)
		m_font = DEFAULT;
	else
	{
		m_font = ESC;
		m_font.append(	extractStyle(code) + \
						extractTextColor(code) + \
						extractBackgroundColor(code) );
		prune();
		m_font.append("m");
	}
}

//  ============| METHODS - PUBLIC |=============

void Font::add(uint32_t code) { setFont(m_code | code); };

void Font::remove(uint32_t code) { setFont(m_code ^ code); };

//  ============| METHODS - PRIVATE |=============

std::string Font::extractStyle(uint8_t code) const
{
	std::string	style;
	const uint8_t styleMask = 0x1F;

	code &= styleMask;
	for (int i = 1; code; ++i, code >>= 1)
	{
		if (code & 1)
			style.append(NumberToString(i).append(";"));
	}
	return style;
}

std::string Font::extractTextColor(uint16_t code) const
{
	std::string textColor;
	const int 	colorSettingsMask = 0x3F00;
	const int	colorMask = 0x700;

	code &= colorSettingsMask;
	if (code)
	{
		(code & BRIGHT) ? textColor += "9" : textColor += "3";
		textColor.append(NumberToString((code & colorMask) >> 8).append(";"));
	}
	return textColor;
}

std::string Font::extractBackgroundColor(uint32_t code) const
{
	std::string backgroundColor;
	const int	backgroundMask = 0x3F0000;
	const int	colorMask = 0x70000;

	code &= backgroundMask;
	if (code)
	{
		(code & BG_BRIGHT) ? backgroundColor += "10" : backgroundColor += "4";
		backgroundColor.append(NumberToString((code & colorMask) >> 16).append(";"));
	}
	return backgroundColor;
}

void Font::prune()
{
	if (m_font[m_font.size() - 1] == ';')
		m_font.erase(m_font.size() - 1);
}

//  ========| VIRTUAL METHODS |=========

//  ======| EXTERNAL FUNCTIONS |========

std::ostream &operator<<(std::ostream &os, const Font &rhs)
{
	os << rhs.getFont();
	return os;
}

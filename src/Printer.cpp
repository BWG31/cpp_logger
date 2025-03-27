#include "Printer.hpp"

//  ==========| CONSTRUCTORS / DESTRUCTOR |==========
Printer::Printer() : m_resetFont(Font(RESET)), \
						m_defaultFont(Font(YELLOW)), \
						m_keyFont(Font(BOLD)), \
						m_valueFont(Font(ITALIC)), \
						m_os(&(std::cout)) {}

Printer::Printer(const Printer &other)
{
	*this = other;
}

Printer::~Printer()
{
	//  DEFAULT
}

//  =======| OPERATOR OVERLOADS |=======
Printer &Printer::operator=(const Printer &rhs)
{
	m_defaultFont = rhs.getFont();
	m_keyFont = rhs.getKeyFont();
	m_valueFont = rhs.getValueFont();
	return *this;
}

//  ============| GETTERS |=============

const Font &Printer::getFont() const { return m_defaultFont; };

const Font &Printer::getKeyFont() const { return m_keyFont; };

const Font &Printer::getValueFont() const { return m_valueFont; };

//  ============| SETTERS |=============

void Printer::setFont(uint32_t code) { m_defaultFont.setFont(code); }

void Printer::setKeyFont(u_int32_t code) { m_keyFont.setFont(code); }

void Printer::setValueFont(u_int32_t code) { m_valueFont.setFont(code); }

void Printer::setOutputStream(std::ostream &os) { m_os = &(os); };

//  ============| METHODS |=============

//  ========| VIRTUAL METHODS |=========

//  ======| EXTERNAL FUNCTIONS |========

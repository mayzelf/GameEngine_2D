#include "title_bar.h"

TitleBar::TitleBar(const int& iconPath, int flags, const std::vector<Dropdown>& dropdowns, const std::string& title)
{
	m_iconPath = iconPath;
	m_title = title;
	m_flags = flags;
	m_dropdowns = dropdowns;
}

// Setters
void TitleBar::setIconPath(const int& iconPath)
{
    m_iconPath = iconPath;
}

void TitleBar::setTitle(const std::string& title)
{
    m_title = title;
}

void TitleBar::setFlags(int flags)
{
    m_flags = flags;
}

void TitleBar::setDropdowns(const std::vector<Dropdown>& dropdowns)
{
    m_dropdowns = dropdowns;
}

// Getters
std::string TitleBar::getIconPath() const
{
    return m_iconPath;
}

std::string TitleBar::getTitle() const
{
    return m_title;
}

int TitleBar::getFlags() const
{
	return m_flags;
}

std::vector<Dropdown> TitleBar::getDropdowns() const
{
    return m_dropdowns;
}

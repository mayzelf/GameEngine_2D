#include "title_bar.h"

TitleBar::TitleBar(const int& iconPath, int flags, const std::vector<Dropdown>& dropdowns, const std::string& title)
{
	m_iconPath = iconPath;
	m_title = title;
	m_flags = flags;
	m_dropdowns = dropdowns;
}

// Setters
void TitleBar::set_icon_path(const int& iconPath)
{
    m_iconPath = iconPath;
}

void TitleBar::set_title(const std::string& title)
{
    m_title = title;
}

void TitleBar::set_flags(int flags)
{
    m_flags = flags;
}

void TitleBar::set_dropdowns(const std::vector<Dropdown>& dropdowns)
{
    m_dropdowns = dropdowns;
}

// Getters
std::string TitleBar::get_icon_path() const
{
    return m_iconPath;
}

std::string TitleBar::get_title() const
{
    return m_title;
}

int TitleBar::get_flags() const
{
	return m_flags;
}

std::vector<Dropdown> TitleBar::get_dropdowns() const
{
    return m_dropdowns;
}

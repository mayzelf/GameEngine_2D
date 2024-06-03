#include "title_bar.h"

TitleBar::TitleBar(const int& icon_path, int flags, const std::vector<Dropdown>& dropdowns, const std::string& title, const glm::vec<2, int>& size)
{
	m_iconPath = icon_path;
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

void TitleBar::set_size(int width, int height)
{
	size = glm::vec<2, int>(width, height);
}

// Getters
int TitleBar::get_icon_path() const
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

glm::vec<2, int> TitleBar::get_size() const
{
	return size;
}

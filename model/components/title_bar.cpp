#include "title_bar.h"

TitleBar::TitleBar(const int& iconPath, int flags, const std::vector<Dropdown>& dropdowns, const std::string& title)
{
	m_iconPath = iconPath;
	m_title = title;
	m_showMinimizeButton = flags & SHOW_MINIMIZE_BUTTON;
	m_showMaximizeButton = flags & SHOW_MAXIMIZE_BUTTON;
	m_showCloseButton = flags & SHOW_CLOSE_BUTTON;
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

void TitleBar::setShowMinimizeButton(bool showMinimizeButton)
{
    m_showMinimizeButton = showMinimizeButton;
}

void TitleBar::setShowMaximizeButton(bool showMaximizeButton)
{
    m_showMaximizeButton = showMaximizeButton;
}

void TitleBar::setShowCloseButton(bool showCloseButton)
{
    m_showCloseButton = showCloseButton;
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

bool TitleBar::getShowMinimizeButton() const
{
    return m_showMinimizeButton;
}

bool TitleBar::getShowMaximizeButton() const
{
    return m_showMaximizeButton;
}

bool TitleBar::getShowCloseButton() const
{
    return m_showCloseButton;
}

std::vector<Dropdown> TitleBar::getDropdowns() const
{
    return m_dropdowns;
}

#include "editor_window.h"

// Default constructor for EditorWindow class
EditorWindow::EditorWindow() : title(""), width(0), height(0)
{
}

// Singleton pattern: Get the single instance of EditorWindow
EditorWindow& EditorWindow::getInstance()
{
	static EditorWindow instance;
	return instance;
}

// Set the title of the EditorWindow
void EditorWindow::setTitle(const std::string& title)
{
	this->title = title;
}

// Set the size of the EditorWindow
void EditorWindow::setSize(int width, int height)
{
	this->width = width;
	this->height = height;
}

void EditorWindow::setMinimumSize(int width, int height)
{
	this->minimumWidth = width;
	this->minimumHeight = height;
}

void EditorWindow::resize(int width, int height)
{
	if(width < minimumWidth)
	{
		width = minimumWidth;
	}else
	{
		this->width = width;
	}
	if (height < minimumHeight)
	{
		height = minimumHeight;
	}
	else
	{
		this->height = height;
	}
}

// Get the title of the EditorWindow
const std::string& EditorWindow::getTitle() const
{
	return title;
}

// Get the width of the EditorWindow
int EditorWindow::getWidth() const
{
	return width;
}

// Get the height of the EditorWindow
int EditorWindow::getHeight() const
{
	return height;
}

int EditorWindow::getMinimumWidth() const
{
	return minimumWidth;
}

int EditorWindow::getMinimumHeight() const
{
	return minimumHeight;
}

void EditorWindow::setTitleBar(const TitleBar& titleBar)
{
	this->titleBar = titleBar;
}

const TitleBar& EditorWindow::getTitleBar() const
{
	return titleBar;
}

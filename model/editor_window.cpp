#include "editor_window.h"


// Default constructor for EditorWindow class
EditorWindow::EditorWindow() : title(""), size(0,0)
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

void EditorWindow::setPosition(int x, int y)
{
	position = glm::vec2(x, y);
}

// Set the size of the EditorWindow
void EditorWindow::setSize(int width, int height)
{
	size = glm::vec2(width, height);
}

void EditorWindow::setMinimumSize(int width, int height)
{
	minimumSize = glm::vec2(width, height);
}

void EditorWindow::resize(int width, int height)
{
	if(width < minimumSize.x)
	{
		width = minimumSize.x;
	}else
	{
		this->size.x = width;
	}
	if (height < minimumSize.y)
	{
		height = minimumSize.y;
	}
	else
	{
		this->size.y = height;
	}
}

void EditorWindow::setFlags(int flags)
{
	this->flags = flags;
}

void EditorWindow::setOriginalSize(int width, int height)
{
	originalSize = glm::vec2(width, height);
}

void EditorWindow::setOriginalPosition(int x, int y)
{
	originalPosition = glm::vec2(x, y);
}

// Get the title of the EditorWindow
const std::string& EditorWindow::getTitle() const
{
	return title;
}

glm::vec<2, int> EditorWindow::getPosition() const
{
	return position;
}

// Get the width of the EditorWindow
glm::vec<2, int> EditorWindow::getSize() const
{
	return size;
}

glm::vec<2, int> EditorWindow::getMinimumSize() const
{
	return minimumSize;
}

glm::vec<2, int> EditorWindow::getOriginalSize() const
{
	return originalSize;
}

glm::vec<2, int> EditorWindow::getOriginalPosition() const
{
	return originalPosition;
}

int EditorWindow::getFlags() const
{
	return flags;
}

void EditorWindow::setTitleBar(const TitleBar& titleBar)
{
	this->titleBar = titleBar;
}

const TitleBar& EditorWindow::getTitleBar() const
{
	return titleBar;
}

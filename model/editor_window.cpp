#include "editor_window.h"


EditorWindow::EditorWindow() : title(""), width(0), height(0)
{
}

EditorWindow& EditorWindow::getInstance()
{
	static EditorWindow instance;
	return instance;
}

void EditorWindow::setTitle(const std::string& title)
{
	this->title = title;
}

void EditorWindow::setSize(int width, int height)
{
	this->width = width;
	this->height = height;
}

const std::string& EditorWindow::getTitle() const
{
	return title;
}

int EditorWindow::getWidth() const
{
	return width;
}

int EditorWindow::getHeight() const
{
	return height;
}
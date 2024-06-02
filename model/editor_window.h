#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H
#include <string>

#include "components/title_bar.h"

#include "glm/vec2.hpp"

enum EditorWindowFlags
{
	WINDOW_MINIMIZED = 1 << 0,  // 1
	WINDOW_MAXIMIZED = 1 << 1,  // 2
};

class EditorWindow
{
public:
	static EditorWindow& getInstance();

	void setTitle(const std::string& title);
	void setSize(int width, int height);
	void setMinimumSize(int width, int height);
	void resize(int width, int height);
	void setFlags(int flags);
	void setOriginalSize(int width, int height);
	void setOriginalPosition(int x, int y);

	const std::string& getTitle() const;
	int getWidth() const;
	int getHeight() const;
	int getMinimumWidth() const;
	int getMinimumHeight() const;
	glm::vec2 getOriginalSize() const;
	glm::vec2 getOriginalPosition() const;
	int getFlags() const;

	//Components
	void setTitleBar(const TitleBar& titleBar);
	const TitleBar& getTitleBar() const;

private:
	std::string title;
	int width;
	int height;
	int minimumWidth;
	int minimumHeight;
	glm::vec2 originalSize;
	glm::vec2 originalPosition;
	int flags;

	//Components
	TitleBar titleBar;

	EditorWindow();
	EditorWindow(const EditorWindow&) = delete;
	EditorWindow& operator = (const EditorWindow&) = delete;

};

#endif
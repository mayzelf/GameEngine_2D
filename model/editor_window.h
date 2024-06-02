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
	glm::vec<2, int> getSize() const;
	glm::vec<2, int> getMinimumSize() const;
	glm::vec<2, int> getOriginalSize() const;
	glm::vec<2, int> getOriginalPosition() const;
	int getFlags() const;

	//Components
	void setTitleBar(const TitleBar& titleBar);
	const TitleBar& getTitleBar() const;

private:
	std::string title;
	glm::vec<2, int> size;
	glm::vec<2, int> minimumSize;
	glm::vec<2, int> originalSize;
	glm::vec<2, int> originalPosition;
	int flags;

	//Components
	TitleBar titleBar;

	EditorWindow();
	EditorWindow(const EditorWindow&) = delete;
	EditorWindow& operator = (const EditorWindow&) = delete;

};

#endif
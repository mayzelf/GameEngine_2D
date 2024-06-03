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
	void setPosition(int x, int y);
	void setSize(int width, int height);
	void setMinimumSize(int width, int height);
	void resize(int width, int height);
	void setFlags(int flags);
	void setOriginalSize(int width, int height);
	void setOriginalPosition(int x, int y);

	const std::string& getTitle() const;
	glm::vec<2, int> getPosition() const;
	glm::vec<2, int> getSize() const;
	glm::vec<2, int> getMinimumSize() const;
	glm::vec<2, int> getOriginalSize() const;
	glm::vec<2, int> getOriginalPosition() const;
	int getFlags() const;

	//Components
	void setTitleBar(const TitleBar& titleBar);
	TitleBar& getTitleBar();

private:
	std::string title;
	glm::vec<2, int> position;
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

class EditorWindowBuilder
{
public:
	EditorWindowBuilder& setTitle(const std::string& title) { m_title = title; return *this; }
	EditorWindowBuilder& setPosition(int x, int y) { m_position = glm::vec2(x, y); return *this; }
	EditorWindowBuilder& setSize(int width, int height) { m_size = glm::vec2(width, height); return *this; }
	EditorWindowBuilder& setMinimumSize(int width, int height) { m_minimumSize = glm::vec2(width, height); return *this; }
	EditorWindowBuilder& setFlags(int flags) { m_flags = flags; return *this; }
	EditorWindowBuilder& setTitleBar(const TitleBar& titleBar) { m_titleBar = titleBar; return *this; }

	EditorWindow& build() {
		EditorWindow& instance = EditorWindow::getInstance();
		instance.setTitle(m_title);
		instance.setPosition(static_cast<int>(m_position.x), static_cast<int>(m_position.y));
		instance.setSize(static_cast<int>(m_size.x), static_cast<int>(m_size.y));
		instance.setMinimumSize(static_cast<int>(m_minimumSize.x), static_cast<int>(m_minimumSize.y));
		instance.setFlags(m_flags);
		instance.setTitleBar(m_titleBar);
		return instance;
	}

private:
	std::string m_title;
	glm::vec2 m_position;
	glm::vec2 m_size;
	glm::vec2 m_minimumSize;
	int m_flags = 0;
	TitleBar m_titleBar;
};


#endif
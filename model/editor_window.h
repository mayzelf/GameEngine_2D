#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H
#include <string>

#include "components/title_bar.h"


class EditorWindow
{
public:
	static EditorWindow& getInstance();

	void setTitle(const std::string& title);
	void setSize(int width, int height);
	void setMinimumSize(int width, int height);
	void resize(int width, int height);

	const std::string& getTitle() const;
	int getWidth() const;
	int getHeight() const;
	int getMinimumWidth() const;
	int getMinimumHeight() const;

	//Components
	void setTitleBar(const TitleBar& titleBar);
	const TitleBar& getTitleBar() const;

private:
	std::string title;
	int width;
	int height;
	int minimumWidth;
	int minimumHeight;

	//Components
	TitleBar titleBar;

	EditorWindow();
	EditorWindow(const EditorWindow&) = delete;
	EditorWindow& operator = (const EditorWindow&) = delete;

};

#endif
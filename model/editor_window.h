#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H
#include <string>


class EditorWindow
{
public:
	static EditorWindow& getInstance();

	void setTitle(const std::string& title);
	void setSize(int width, int height);

	const std::string& getTitle() const;
	int getWidth() const;
	int getHeight() const;

private:
	std::string title;
	int width;
	int height;

	EditorWindow();
	EditorWindow(const EditorWindow&) = delete;
	EditorWindow& operator = (const EditorWindow&) = delete;

};

#endif
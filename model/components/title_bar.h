#ifndef TITLE_BAR_H
#define TITLE_BAR_H
#include <string>
#include <vector>

class Dropdown
{
	public:
	Dropdown(const std::string& name, const std::vector<std::string>& items);

	// Setters
	void setName(const std::string& name);
	void setItems(const std::vector<std::string>& items);

	// Getters
	std::string getName() const;
	std::vector<std::string> getItems() const;
};

enum TitleBarFlags
{
    SHOW_MINIMIZE_BUTTON = 1 << 0,  // 1
    SHOW_MAXIMIZE_BUTTON = 1 << 1,  // 2
    SHOW_CLOSE_BUTTON = 1 << 2   // 4
};

class TitleBar    
{
public:
    TitleBar() = default;
    TitleBar(const std::string& iconPath, int flags, const std::vector<Dropdown>& dropdowns = std::vector<Dropdown>(), const std::string& title = "");

    // Setters
    void setIconPath(const std::string& iconPath);
    void setTitle(const std::string& title);
    void setShowMinimizeButton(bool showMinimizeButton);
    void setShowMaximizeButton(bool showMaximizeButton);
    void setShowCloseButton(bool showCloseButton);
    void setDropdowns(const std::vector<Dropdown>& dropdowns);

    // Getters
    std::string getIconPath() const;
    std::string getTitle() const;
    bool getShowMinimizeButton() const;
    bool getShowMaximizeButton() const;
    bool getShowCloseButton() const;
    std::vector<Dropdown> getDropdowns() const;

private:
    std::string m_iconPath;
    std::string m_title;
    bool m_showMinimizeButton;
    bool m_showMaximizeButton;
    bool m_showCloseButton;
    std::vector<Dropdown> m_dropdowns;
};

class TitleBarBuilder
{
public:
    TitleBarBuilder& setIconPath(const std::string& iconPath) { m_iconPath = iconPath; return *this; }
    TitleBarBuilder& setFlags(int flags) { m_flags = flags; return *this; }
    TitleBarBuilder& setDropdowns(const std::vector<Dropdown>& dropdowns) { m_dropdowns = dropdowns; return *this; }
    TitleBarBuilder& setTitle(const std::string& title) { m_title = title; return *this; }

    TitleBar build() const { return TitleBar(m_iconPath, m_flags, m_dropdowns, m_title); }

private:
    std::string m_iconPath;
    int m_flags = 0;
    std::vector<Dropdown> m_dropdowns;
    std::string m_title;
};


#endif
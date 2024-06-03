#ifndef TITLE_BAR_H
#define TITLE_BAR_H
#include <string>
#include <vector>
#include <glm/vec2.hpp>

class Dropdown
{
	public:
	Dropdown(const std::string& name, const std::vector<std::string>& items);

	// Setters
	void set_name(const std::string& name);
	void set_items(const std::vector<std::string>& items);

	// Getters
	std::string get_name() const;
	std::vector<std::string> get_items() const;
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
    TitleBar(const int& icon_path, int flags, const std::vector<Dropdown>& dropdowns, const std::string& title, const glm::vec<2, int>& size);

    // Setters
    void set_icon_path(const int& iconPath);
    void set_title(const std::string& title);
    void set_flags(int flags);
    void set_dropdowns(const std::vector<Dropdown>& dropdowns);

    // Getters
    int get_icon_path() const;
    std::string get_title() const;
    int get_flags() const;
    std::vector<Dropdown> get_dropdowns() const;

private:
    int m_iconPath;
    std::string m_title;
    int m_flags;
    glm::vec<2, int> size;
    std::vector<Dropdown> m_dropdowns;
};

class TitleBarBuilder
{
public:
    TitleBarBuilder& set_icon_path(const int& iconPath) { m_icon_ = iconPath; return *this; }
    TitleBarBuilder& set_flags(int flags) { m_flags_ = flags; return *this; }
    TitleBarBuilder& set_dropdowns(const std::vector<Dropdown>& dropdowns) { m_dropdowns_ = dropdowns; return *this; }
    TitleBarBuilder& set_title(const std::string& title) { m_title_ = title; return *this; }
    TitleBarBuilder& set_size(const glm::vec<2, int>& size) { size_ = size; return *this; }

    [[nodiscard]] TitleBar build() const { return TitleBar(m_icon_, m_flags_, m_dropdowns_, m_title_ , size_); }

private:
    int m_icon_;
    int m_flags_ = 0;
    glm::vec<2, int> size_;
    std::vector<Dropdown> m_dropdowns_;
    std::string m_title_;
};


#endif

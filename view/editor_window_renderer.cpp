#include "editor_window_renderer.h"


Editor_Window_Renderer::Editor_Window_Renderer(EditorWindow& window, HINSTANCE h_instance) : editor_window_(window),
	sdl_render_handler_(nullptr), h_instance_(h_instance)
{
}

Editor_Window_Renderer::~Editor_Window_Renderer()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void Editor_Window_Renderer::init()
{
    this->sdl_render_handler_ = &Sdl_Render_Handler::getInstance();
    sdl_render_handler_->init(editor_window_);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    // Setup ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplSDL2_InitForOpenGL(sdl_render_handler_->getWindow(), sdl_render_handler_->getGLContext());
    ImGui_ImplOpenGL3_Init();
}

void Editor_Window_Renderer::present() const
{
    // Check if SDL window size matches EditorWindow size
    glm::vec<2, int> windowSize = sdl_render_handler_->getWindowSize();
    if (windowSize.x != editor_window_.getSize().x || windowSize.y != editor_window_.getSize().y)
    {
        // Update SDL window size
        sdl_render_handler_->setWindowSize(editor_window_.getSize().x, editor_window_.getSize().y);
    }

    // Check if SDL window position matches EditorWindow position
    if (const glm::vec<2, int> windowPosition = sdl_render_handler_->getWindowPosition(); windowPosition.x !=
	    editor_window_.getPosition().x || windowPosition.y != editor_window_.getPosition().y)
    {
        // Update SDL window position
        sdl_render_handler_->setWindowPosition(editor_window_.getPosition().x, editor_window_.getPosition().y);
    }

    // Clear screen
    glClearColor(0.2f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
    
    draw_title_bar();
	
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // Swap SDL window buffers
    sdl_render_handler_->swapWindowBuffer();
}

void Editor_Window_Renderer::shutdown() const
{
    
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	sdl_render_handler_->~Sdl_Render_Handler();
}

void Editor_Window_Renderer::draw_title_bar() const
{
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(static_cast<float>(editor_window_.getSize().x), 36.0f));

    if (!editor_window_.getTitleBar().get_icon_path().empty())
    {
	    if (constexpr ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse |
		    ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar |
		    ImGuiWindowFlags_NoScrollbar; ImGui::Begin("editor_window_title", nullptr, window_flags))
        {

            GLuint texture = utils::resources::loadTextureFromResource(h_instance_, IDB_PNG1);
            ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(texture)), ImVec2(20, 20));
            ImGui::SameLine();
            if (!editor_window_.getTitleBar().get_title().empty())
                ImGui::TextUnformatted(editor_window_.getTitleBar().get_title().c_str());


            //Flags
            int right_offset = 25;

            if (editor_window_.getTitleBar().get_flags() & SHOW_CLOSE_BUTTON)
            {
                ImGui::SameLine(ImGui::GetWindowWidth() - right_offset);
                if (ImGui::Button("x"))
                {
                    shutdown();
                }
                right_offset += 20;
                
            }

            if (editor_window_.getTitleBar().get_flags() & SHOW_MAXIMIZE_BUTTON)
            {
                right_offset += 7;
                ImGui::SameLine(ImGui::GetWindowWidth() - right_offset);
                if (ImGui::Button("[]"))
                {
                    if (editor_window_.getFlags() == WINDOW_MAXIMIZED)
                    {
                        // Restore window
                        const glm::vec<2, int> pos = editor_window_.getOriginalPosition();
                        sdl_render_handler_->setWindowPosition(pos.x, pos.y);
                        const glm::vec<2, int> size = editor_window_.getOriginalSize();
                        editor_window_.setSize(size.x, size.y);
                        editor_window_.setFlags(editor_window_.getFlags() & ~WINDOW_MAXIMIZED);


                    }
                    else
                    {
                        // Maximize window
                        const RECT monitorSizeMinusTaskbar = utils::windows::GetMonitorSizeMinusTaskbar();
                        const int mon_width = monitorSizeMinusTaskbar.right - monitorSizeMinusTaskbar.left;
                        const int mon_height = monitorSizeMinusTaskbar.bottom - monitorSizeMinusTaskbar.top;
                        editor_window_.setOriginalSize(editor_window_.getSize().x, editor_window_.getSize().y);
                        glm::vec<2, int> pos = editor_window_.getPosition();
                        editor_window_.setOriginalPosition(pos.x, pos.y);
                        sdl_render_handler_->setWindowPosition(0, 0);
                        editor_window_.setSize(mon_width, mon_height);
                        editor_window_.setFlags(WINDOW_MAXIMIZED);

                    }
                }
                right_offset += 20;
                
            }
            if (editor_window_.getTitleBar().get_flags() & SHOW_MINIMIZE_BUTTON)
            {
                ImGui::SameLine(ImGui::GetWindowWidth() - right_offset);
                if (ImGui::Button("_"))
                {
                    sdl_render_handler_->minimizeWindow();
                }
            }
        }
	}
}



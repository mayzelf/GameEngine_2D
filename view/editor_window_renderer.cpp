#include "editor_window_renderer.h"

Editor_Window_Renderer::Editor_Window_Renderer(EditorWindow& window, HINSTANCE hInstance) : window(nullptr), editorWindow(window), hInstance(hInstance)
{
}

Editor_Window_Renderer::~Editor_Window_Renderer()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Editor_Window_Renderer::init()
{

    SDL_Init(SDL_INIT_VIDEO);

    // Use OpenGL 3.3 core profile
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // Create an SDL window without a title bar
    this->window = SDL_CreateWindow(editorWindow.getTitle().c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, editorWindow.getWidth(), editorWindow.getHeight(), SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);
    gl_context = SDL_GL_CreateContext(this->window);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    // Setup ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplSDL2_InitForOpenGL(this->window, gl_context);
    ImGui_ImplOpenGL3_Init();
}

void Editor_Window_Renderer::present()
{
    // Check if SDL window size matches EditorWindow size
    int sdlWindowWidth, sdlWindowHeight;
    SDL_GetWindowSize(window, &sdlWindowWidth, &sdlWindowHeight);
    if (sdlWindowWidth != editorWindow.getWidth() || sdlWindowHeight != editorWindow.getHeight())
    {
        // Update SDL window size
        SDL_SetWindowSize(window, editorWindow.getWidth(), editorWindow.getHeight());
    }


    // Clear screen
    glClearColor(0.2f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
    
    drawTitleBar();
	
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // Swap SDL window buffers
    SDL_GL_SwapWindow(window);
}

void Editor_Window_Renderer::shutdown()
{
    
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Editor_Window_Renderer::drawTitleBar()
{
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(static_cast<float>(editorWindow.getWidth()), 36.0f));

    if (!editorWindow.getTitleBar().getIconPath().empty())
    {
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar;

        if (ImGui::Begin("editor_window_title", nullptr, window_flags))
        {

            GLuint texture = utils::resources::loadTextureFromResource(hInstance, IDB_PNG1);
            ImGui::Image((void*)(intptr_t)texture, ImVec2(20, 20));
            ImGui::SameLine();
            if (!editorWindow.getTitleBar().getTitle().empty())
                ImGui::Text(editorWindow.getTitleBar().getTitle().c_str());


            //Flags
            ImGui::SameLine(ImGui::GetWindowWidth() - 200);

            if (ImGui::Button("Minimize"))
            {
                SDL_MinimizeWindow(window);
            }
            ImGui::SameLine();
            if (ImGui::Button("Maximize"))
            {
                if (editorWindow.getFlags() == WINDOW_MAXIMIZED)
                {
                    // Restore window
                    const glm::vec2 pos = editorWindow.getOriginalPosition();
                    SDL_SetWindowPosition(window, static_cast<int>(pos.x), static_cast<int>(pos.y));
                    const glm::vec2 size = editorWindow.getOriginalSize();
                    editorWindow.setSize(static_cast<int>(size.x), static_cast<int>(size.y));
                    editorWindow.setFlags(editorWindow.getFlags() & ~WINDOW_MAXIMIZED);


                }
                else
                {
                    // Maximize window
                    const RECT monitorSizeMinusTaskbar = utils::windows::GetMonitorSizeMinusTaskbar();
                    const int mon_width = monitorSizeMinusTaskbar.right - monitorSizeMinusTaskbar.left;
                    const int mon_height = monitorSizeMinusTaskbar.bottom - monitorSizeMinusTaskbar.top;
                    editorWindow.setOriginalSize(editorWindow.getWidth(), editorWindow.getHeight());
                    int x, y;
                    SDL_GetWindowPosition(window, &x, &y);
                    editorWindow.setOriginalPosition(x, y);
                    SDL_SetWindowPosition(window, 0, 0);
                    editorWindow.setSize(mon_width, mon_height);
                    editorWindow.setFlags(WINDOW_MAXIMIZED);

                }
            }
            ImGui::SameLine();
            if (ImGui::Button("Close"))
            {
                shutdown();
            }
        }
    }
}



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
    // Clear screen
    glClearColor(0.2f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();


    ImGui::ShowDemoWindow();
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(static_cast<float>(editorWindow.getWidth()), 30.0f));
    
    if(!editorWindow.getTitleBar().getIconPath().empty())
    {
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar;

        if (ImGui::Begin("editor_window_title", nullptr, window_flags))
        {
            if (!editorWindow.getTitleBar().getIconPath().empty())
            {
                GLuint texture = utils::resources::loadTextureFromResource(hInstance, IDB_PNG1);
                if (texture == 0)
            	{
                    ImGui::Text("Failed");
                }
            	ImGui::Image((void*)(intptr_t)texture, ImVec2(20, 20));
                ImGui::SameLine();
                ImGui::Text(editorWindow.getTitleBar().getTitle().c_str());
            }
        }
    }

	
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



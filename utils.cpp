#include "utils.h"


GLuint utils::resources::loadTexture(const char* path)
{
    int width, height, nrChannels;
    unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);
    if (data)
    {
        GLuint texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);

        // Check the number of channels in the image
        if (nrChannels == 4)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        }
        else if (nrChannels == 3)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        }

        // Set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // Set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
        return texture;
    }
    else
    {
        
        return 0;
    }
}

GLuint utils::resources::loadTextureFromResource(HINSTANCE hInstance, int resourceId)
{
    HRSRC hResource = FindResource(hInstance, MAKEINTRESOURCE(resourceId), L"PNG");
    if (hResource == NULL)
    {
        SDL_Log("Failed to find the resource");
        return 0;
    }

    HGLOBAL hMemory = LoadResource(hInstance, hResource);
    if (hMemory == NULL)
    {
        SDL_Log("Failed to load the resource");
        return 0;
    }

    DWORD dwSize = SizeofResource(hInstance, hResource);
    if (dwSize == 0)
    {
        SDL_Log("Failed to get the size of the resource");
        return 0;
    }

    void* pData = LockResource(hMemory);
    if (pData == NULL)
    {
        SDL_Log("Failed to lock the resource");
        return 0;
    }

    int width, height, nrChannels;
    unsigned char* data = stbi_load_from_memory((stbi_uc*)pData, dwSize, &width, &height, &nrChannels, 0);
    if (data == NULL)
    {
        SDL_Log("Failed to load the image data");
        return 0;
    }

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    if (nrChannels == 4)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }
    else if (nrChannels == 3)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(data);
    return texture;
}

RECT utils::windows::GetMonitorSizeMinusTaskbar()
{
    // Get the handle of the primary monitor
    HMONITOR hMonitor = MonitorFromWindow(NULL, MONITOR_DEFAULTTOPRIMARY);

    // Get monitor information
    MONITORINFO monitorInfo;
    monitorInfo.cbSize = sizeof(MONITORINFO);
    GetMonitorInfo(hMonitor, &monitorInfo);

    // Get the taskbar size
    APPBARDATA appBarData;
    appBarData.cbSize = sizeof(APPBARDATA);
    SHAppBarMessage(ABM_GETTASKBARPOS, &appBarData);
    RECT taskbarRect = appBarData.rc;

    // Calculate the monitor size minus the taskbar
    RECT monitorRect = monitorInfo.rcMonitor;
    monitorRect.bottom -= taskbarRect.bottom - taskbarRect.top;

    // Return the monitor size minus the taskbar
    return monitorRect;
}





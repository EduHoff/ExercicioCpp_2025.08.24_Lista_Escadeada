#ifndef UTIL_CROSSPLATFORM_H
#define UTIL_CROSSPLATFORM_H

#ifdef _WIN32
#include <windows.h>
#endif

// Clear screen function
void Clear() {
    #ifdef _WIN32
        system("cls");
    #elif __linux__ || __unix__ || __APPLE__
        system("clear");
    #else
        printf("Unsupported operating system for clearing the screen.\n");
    #endif
}

// Pause function
void Pause() {
    #ifdef _WIN32
        system("pause");
    #else
        // Prompt the user to press Enter
        printf("Press Enter to continue...");
        while(getchar() != '\n'); // Clear buffer
        getchar();
    #endif
}

#endif // UTIL_CROSSPLATFORM_H

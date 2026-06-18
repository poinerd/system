#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h> // Native Windows System API

// Custom helper function to move the cursor to any exact (X, Y) coordinate on Windows
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



// Custom helper to change the text color in the Windows terminal
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    std::srand(std::time(nullptr));

    // Get handle to console and hide the flashing cursor underline
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Hide cursor
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    const int width = 80;
    const int height = 25;

    std::vector<int> rain_drop_y(width);
    for (int i = 0; i < width; ++i) {
        rain_drop_y[i] = std::rand() % height - height;
    }

    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ#$@&*%";

    // Clear the screen once at startup
    system("cls");
    system("mkdir hey");

    while (true) {
        for (int x = 0; x < width; ++x) {
            int current_y = rain_drop_y[x];
            // 1. Draw the leading edge (Bright White)
            if (current_y >= 0 && current_y < height) {
                char random_char = characters[std::rand() % characters.length()];
                gotoxy(x, current_y);
                setColor(15); // 15 = Foreground White
                std::cout << random_char;
            }

            // 2. Draw the fading trail (Bright Green)
            int tail_y = current_y - 1;
            if (tail_y >= 0 && tail_y < height) {
                char random_char = characters[std::rand() % characters.length()];
                gotoxy(x, tail_y);
                setColor(10); // 10 = Foreground Light Green
                std::cout << random_char;
            }

            // 3. Erase old character trails to keep the screen clean
            int clear_y = current_y - 6;
            if (clear_y >= 0 && clear_y < height) {
                gotoxy(x, clear_y);
                std::cout << ' ';
            }

            rain_drop_y[x]++;

            if (rain_drop_y[x] - 6 >= height) {
                rain_drop_y[x] = 0;
            }
        }

        // Native Windows sleep command (50 milliseconds)
        Sleep(50);
    }

    // This is the function that voices the stuff

    return 0;
}
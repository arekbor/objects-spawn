#include <iostream>
#include <list>
#include "raylib.h"
#include "object.h"

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 900
#define WINDOW_TITLE "Objects demo"

void MainLoop();

Container _objectContainer;

int main(void) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    SetWindowMonitor(1);
    InitAudioDevice();

    while (!WindowShouldClose()) {
        MainLoop();
    }
    
    CloseAudioDevice();
    CloseWindow();
    return 0;
}

void MainLoop() {
    Vector2 mousePos = GetMousePosition();
    if (IsKeyPressed(KEY_LEFT_SHIFT)) {
        _objectContainer.AddObjectToNearestEdge(mousePos);
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        _objectContainer.AddObject(mousePos);
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && IsKeyDown(KEY_DELETE)) {
        _objectContainer.RemoveObject(mousePos);
    }

    BeginDrawing();
        ClearBackground(BLACK);
        _objectContainer.DrawAllObjects();
    EndDrawing();
}
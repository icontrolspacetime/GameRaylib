#include <raylib.h>
#include "ball.h"

int main() 
{
    const Color darkGreen = {20, 160, 133, 255};
    
    constexpr int screenWidth = 1280;
    constexpr int screenHeight = 720;
    Vector2 myPos = { 400, 400 };

    Camera2D camera = { 0 };
camera.target = myPos;
camera.offset = { 640, 360 };
camera.zoom = 1.0f;



    Ball ball;
    
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    InitAudioDevice();                              
    Sound testSound = LoadSound("Assets/sfx/test.wav");
    TraceLog(LOG_INFO, "Current working directory: %s", GetWorkingDirectory());
    while (!WindowShouldClose())
    {
        ball.Update();
        if (IsKeyDown(KEY_D)) myPos.x += 200.0f * GetFrameTime();
        if (IsKeyDown(KEY_A)) myPos.x -= 200.0f * GetFrameTime();
        if (IsKeyDown(KEY_S)) myPos.y += 200.0f * GetFrameTime();
        if (IsKeyDown(KEY_W)) myPos.y -= 200.0f * GetFrameTime();
        
        if (IsKeyPressed(KEY_SPACE)) PlaySound(testSound);
        BeginDrawing();
            ClearBackground(darkGreen);
            // then in the loop:
            camera.target = myPos;
            BeginMode2D(camera);
            DrawCircle(myPos.x, myPos.y, 40, BLUE);
            EndMode2D();
            DrawText("This text stays fixed", 10, 10, 20, WHITE);
            if (testSound.frameCount == 0) DrawText("Sound failed to load!", 10, 50, 20, RED);
            
            ball.Draw();
            DrawRectangle(100, 100, 50, 50, RED);
            DrawCircle(640,360,30,Fade(VIOLET,0.5f));
            DrawCircleV(myPos, 30, GREEN);  
        EndDrawing();
        
    }
    UnloadSound(testSound);     
    CloseAudioDevice();    
    CloseWindow();
}
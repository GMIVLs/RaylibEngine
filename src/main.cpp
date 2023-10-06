/*******************************************************************************************
 *
 *   raylib [core] example - Basic window
 * *   Welcome to raylib!
 *
 *   To test examples, just press F6 and execute raylib_compile_execute script
 *   Note that compiled executable is placed in the same folder as .c file
 *
 *   You can find all basic examples on C:\raylib\raylib\examples folder or
 *   raylib official webpage: www.raylib.com
 *
 *   Enjoy using raylib. :)
 *
 *   This example has been created using raylib 1.0 (www.raylib.com)
 *   raylib is licensed under an unmodified zlib/libpng license (View raylib.h
 *for details)
 *
 *   Copyright (c) 2014 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/
#include <raylib.h>

int main() {
  // Initialization parameters
  const int screenWidth = 800;
  const int screenHeight = 600;

  // Initialize the window
  InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
  // Set target frames per second
  SetTargetFPS(60);

  // Get a random integer number between -8 and 5 (both included)
  int randValue = GetRandomValue(0, 10);
  int framesCounter = 0;

  // Colors
  Color rayWhite = {245, 245, 245, 255};
  Color lightGray = {200, 200, 200, 255};
  Color lightGreen = {10, 111, 121, 255};

  // Main game loop
  while (!WindowShouldClose()) { // Continue until window close button or ESC
                                 // key is pressed
    // Start drawing
    BeginDrawing();
    {
      DrawText("Every 2 seconds a new random value is generated:", 130, 100, 20,
               lightGray);
      DrawText(TextFormat("%i", randValue), 360, 180, 80, lightGreen);
    }

    framesCounter++;
    // Every two seconds (120 frames) a new random value is generated
    if (((framesCounter / 120) % 2) == 1) {
      randValue = GetRandomValue(0, 10);
      framesCounter = 0;
    }
    //---

    // Clear the background to white
    ClearBackground(rayWhite);

    // Draw the "Hello, World!" text
    DrawText("Hello, World!", 10, 10, 20, lightGray);

    // End drawing
    EndDrawing();
  }

  // Cleanup and close the window
  CloseWindow();

  return 0;
}

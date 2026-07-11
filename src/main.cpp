#include <Shirag.hpp>

#include <iostream>
#include <raylib.h>
#include <string>

int main() {
  Shirag::Discord discord;
  discord.init(1438202642198167643);
  discord.setActivityState("Writing bad game ideas");
  discord.setActivityDetails("Important work");
  discord.updateActivity();

  Shirag::Window window("Bad game ideas simulator", 2560, 1440);
  InitAudioDevice();

  SetTargetFPS(60);

  Texture2D paperbin = LoadTexture("./PaperBin.png");
  Sound buu = LoadSound("./1.wav");

  const int width = 1800;
  const int height = 100;
  Rectangle inputBox = {GetScreenWidth() / 2.0 - width / 2.0,
                        GetScreenHeight() / 2.0 - height / 2.0, width, height};

  std::string textInput = "";
  bool throwAwayAnimation = false;
  double lastTime = 0;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);

    int keyPress = GetCharPressed();

    if ((keyPress >= 32) && (keyPress <= 125)) {
      textInput += (char)keyPress;
    }

    if (IsKeyPressed(KEY_BACKSPACE) && textInput.size() > 0) {
      textInput.erase(textInput.end() - 1);
    } else if (IsKeyPressed(KEY_ENTER) && textInput.size() > 0) {
      throwAwayAnimation = true;
    }

    Shirag::Drawing::drawRectWithOutline(inputBox, 5, GRAY, BLACK);
    Shirag::Drawing::drawTextCenterRect(
        {inputBox.x + 10, inputBox.y, inputBox.width - 10, inputBox.height},
        textInput, 40, BLACK, false, true);

    if (throwAwayAnimation) {
      DrawTexture(paperbin, GetScreenWidth() / 2.0 - paperbin.width / 2.0,
                  GetScreenHeight() / 2.0 + 200, WHITE);

      if (!IsSoundPlaying(buu))
        PlaySound(buu);

      if (GetTime() != lastTime) {
        textInput.erase(textInput.end() - 1);
        lastTime = GetTime();
      }

      if (textInput.size() == 0)
        throwAwayAnimation = false;
    }

    EndDrawing();

    discord.runCallbacks();
  }

  return 0;
}
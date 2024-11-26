#include "Input.h"

namespace Input {
    bool KeysLast[KeyCode::TotalKeys];
    bool KeysDown[KeyCode::TotalKeys];

    void Init() {
        Reset();
    }

    void HandleKeyDown(SDL_Event& event) {
        int keyCode = event.key.keysym.sym;
        if (keyCode >= KeyCode::TotalKeys) return;

        KeysDown[keyCode] = true;
    }

    void HandleKeyUp(SDL_Event& event) {
        int keyCode = event.key.keysym.sym;
        if (keyCode >= KeyCode::TotalKeys) return;

        KeysDown[keyCode] = false;
    }

    bool GetKey(int keyCode) {
        return KeysDown[keyCode];
    }

    bool GetKeyDown(int keyCode) {
        return KeysDown[keyCode] && !KeysLast[keyCode];
    }

    bool GetKeyUp(int keyCode) {
        return !KeysDown[keyCode] && KeysLast[keyCode];
    }

    int GetAxisRaw(std::string axis) {
        int result = 0;
        // cant use a switch statement so gotta use this
        if (axis == "Horizontal") {
            if (GetKey(KeyCode::A)) result -= 1;
            if (GetKey(KeyCode::D)) result += 1;
        }
        else if (axis == "Vertical") {
            if (GetKey(KeyCode::W) || GetKey(KeyCode::Space)) result -= 1;
            if (GetKey(KeyCode::S)) result += 1;
        }
        
        return result;
    }

    void Reset() {
        memset(KeysDown, 0, sizeof(KeysDown));
        memset(KeysLast, 0, sizeof(KeysLast));
    }

    void Update() {
        memcpy(KeysLast, KeysDown, sizeof(KeysDown));
    }
}
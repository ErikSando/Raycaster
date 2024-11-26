#pragma once

#include <string>

#include "SDL2/SDL.h"

enum KeyCode {
    Backspace = 8,
    Tab,
    Enter = 13,
    Escape = 27,
    Space = 32,
    Exclaim,
    DoubleQuote,
    Hashtag,
    Dollar,
    Percent,
    Ampersand,
    Quote,
    LeftParen,
    RightParen,
    Asterisk,
    Plus,
    Comma,
    Minus,
    Period,
    Slash,
    Digit0, Digit1, Digit2, Digit3, Digit4, Digit5, Digit6, Digit7, Digit8, Digit9,
    Colon,
    SemiColon,
    LessThan,
    Equals,
    Greater,
    Question,
    At,
    LeftBracket = 91,
    Backslash,
    RightBracket,
    Caret,
    Underscore,
    Backquote,
    A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    Delete = 127,
    TotalKeys
};

namespace Input {
    void Init();

    void HandleKeyDown(SDL_Event& event);
    void HandleKeyUp(SDL_Event& event);

    bool GetKey(int keyCode);
    bool GetKeyDown(int keyCode);
    bool GetKeyUp(int keyCode);

    int GetAxisRaw(std::string axis);

    void Update();
    void Reset();
};
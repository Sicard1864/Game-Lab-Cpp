// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include "input.hpp"


// -- Constructors ------------------------------------------------------------------------------ //

Input::Input() {
    resetStates();
}

Input::~Input() {
}


// -- Accesors ---------------------------------------------------------------------------------- //

bool Input::isKeyPressed(SDL_Scancode key) const {
    return keyStates[key] == SDL_TRUE;
}

bool Input::isKeyPressed(SDL_KeyCode key) const {
    const Uint8* state = SDL_GetKeyboardState(NULL);
    return state[key] != 0;
}

bool Input::isMouseButtonPressed(Uint8 button) const {
    return mouseStates[button] == SDL_TRUE;
}

int Input::getMouseX() const {
    return mouseX;
}

int Input::getMouseY() const {
    return mouseY;
}

int Input::getMouseRelX() const {
    return mouseRelX;
}

int Input::getMouseRelY() const {
    return mouseRelY;
}

int Input::getMouseWheelX() const {
    return mouseWheelX;
}

int Input::getMouseWheelY() const {
    return mouseWheelY;
}

Direction Input::getDirection() const {
    bool up = isKeyPressed(SDL_SCANCODE_UP) || isKeyPressed(SDL_SCANCODE_W);
    bool down = isKeyPressed(SDL_SCANCODE_DOWN) || isKeyPressed(SDL_SCANCODE_S);
    bool left = isKeyPressed(SDL_SCANCODE_LEFT) || isKeyPressed(SDL_SCANCODE_A);
    bool right = isKeyPressed(SDL_SCANCODE_RIGHT) || isKeyPressed(SDL_SCANCODE_D);

    if (up && left && !down && !right) {
        return Direction::UP_LEFT;
    } else if (up && right && !down && !left) {
        return Direction::UP_RIGHT;
    } else if (down && left && !up && !right) {
        return Direction::DOWN_LEFT;
    } else if (down && right && !up && !left) {
        return Direction::DOWN_RIGHT;
    } else if (up && (right ^ !left) && !down) {
        return Direction::UP;
    } else if (down && (right ^ !left) && !up) {
        return Direction::DOWN;
    } else if (left && (up ^ !down) && !right) {
        return Direction::LEFT;
    } else if (right && (up ^ !down) && !left) {
        return Direction::RIGHT;
    } else {
        return Direction::NONE;
    }
}


// -- Methodes ---------------------------------------------------------------------------------- //

void Input::update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                quitFlag = true;
                break;

            case SDL_KEYDOWN:
                keyStates[event.key.keysym.scancode] = SDL_TRUE;
                break;

            case SDL_KEYUP:
                keyStates[event.key.keysym.scancode] = SDL_FALSE;
                break;

            case SDL_MOUSEMOTION:
                mouseX = event.motion.x;
                mouseY = event.motion.y;
                mouseRelX = event.motion.xrel;
                mouseRelY = event.motion.yrel;
                break;

            case SDL_MOUSEWHEEL:
                mouseWheelX = event.wheel.x;
                mouseWheelY = event.wheel.y;
                break;

            case SDL_MOUSEBUTTONDOWN:
                mouseStates[event.button.button] = SDL_TRUE;
                break;

            case SDL_MOUSEBUTTONUP:
                mouseStates[event.button.button] = SDL_FALSE;
                break;
        }
    }
}

bool Input::quitRequested() const {
    return quitFlag;
}


/* -- Privates Methodes ------------------------------------------------------------------------- */
void Input::resetStates() {
    for (int i = 0; i < SDL_NUM_SCANCODES; ++i) {
        keyStates[i] = SDL_FALSE;
    }

    for (int i = 0; i < 6; ++i) {
        mouseStates[i] = SDL_FALSE;
    }

    mouseX = mouseY = mouseRelX = mouseRelY = mouseWheelX = mouseWheelY = 0;
    quitFlag = false;
}

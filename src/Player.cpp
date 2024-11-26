#include <iostream>

#include "Player.h"
#include "Game.h" // this imports bascially everything

namespace Player {
    namespace Settings {
        int Speed = 60;
        int Sensitivity = 100;
    }

    void Update(const float delta) {
        int movementH = Input::GetAxisRaw("Horizontal");
        int movementV = -Input::GetAxisRaw("Vertical");

        Camera& camera = Game::GetCamera();

        Vector2 v1 = camera.Forward() * movementV;
        Vector2 v2 = camera.Right() * movementH;

        Vector2 direction = (v1 + v2).normalised();

        // line below doesnt work for some reason, the horizontal movement isnt accounted for
        //Vector2 direction = (camera.Forward() * movementV + camera.Right() * movementH).normalised();
        Vector3 direction3(direction.x, direction.y, 0);

        //std::cout << direction << std::endl;

        camera.position += direction3 * Settings::Speed * delta;

        int rotation = 0;

        //if (Input::GetKey(KeyCode::ArrowLeft)) rotation--;
        //if (Input::GetKey(KeyCode::ArowRight)) rotation++;

        if (Input::GetKey(KeyCode::J)) rotation--;
        if (Input::GetKey(KeyCode::K)) rotation++;

        camera.orientation += rotation * (Settings::Sensitivity / 60) * delta;

        if (Input::GetKey(KeyCode::Q)) camera.position.z -= Settings::Speed * delta * 250;
        if (Input::GetKey(KeyCode::E)) camera.position.z += Settings::Speed * delta * 250;
    }
}
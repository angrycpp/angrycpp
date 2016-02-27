#include "../dep/catch/run-tests.hpp"

#include "core/game-core.hpp"
#include "windows/window.hpp"

#include "math/shapes/rect.hpp"
#include "scenes/scene.hpp"
#include "scenes/scenes-manager.hpp"
#include "scenes/scenes-runner.hpp"
#include "input/mouse.hpp"

#include "graphics/color.hpp"

struct empty_scene: public angrycpp::scene {
    virtual void init() override {};
    virtual void update() override {};
    virtual void draw(angrycpp::graphics::renderer &renderer) override {
        int width = 50, height = 50;
        auto mouse = angrycpp::input::mouse::get();

        renderer.begin(angrycpp::color{ 0, 0, 0 });
        if(mouse.button_pressed.left) {
            renderer.draw(
                angrycpp::rect{ mouse.x - width, mouse.y - height, width * 2, height * 2 },
                angrycpp::color{ 255, 255, 255 });
        }
        renderer.end();
    };
    virtual void finish() override {};
};

#undef main
int main(int argc, const char* argv[]) {
    angrycpp::game::core::guard game_guard{};
    angrycpp::window window(640, 640, "Hello world!");

    angrycpp::scenes_manager scenes_manager;
    scenes_manager.scenes.push_back(std::make_unique<empty_scene>());

    angrycpp::scenes_runner{ scenes_manager }.run(angrycpp::graphics::renderer{ window });

    return run_tests(argc, argv);
}
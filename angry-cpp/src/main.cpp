#include "../dep/catch/run-tests.hpp"

#include "core/game-core.hpp"
#include "windows/window.hpp"

#include "scenes/scene.hpp"
#include "scenes/scenes-manager.hpp"
#include "scenes/scenes-runner.hpp"

struct empty_scene: public angrycpp::scene {
    virtual void init() override {};
    virtual void update() override {};
    virtual void draw(angrycpp::graphics::renderer &) override {};
    virtual void finish() override {};
};

#undef main
int main(int argc, const char* argv[]) {
    angrycpp::game::core::guard game_guard{};
    angrycpp::window window(320, 320, "Hello world!");

    angrycpp::scenes_manager scenes_manager;
    scenes_manager.scenes.push_back(std::make_unique<empty_scene>());

    angrycpp::scenes_runner{ scenes_manager }.run(angrycpp::graphics::renderer{});

    return run_tests(argc, argv);
}
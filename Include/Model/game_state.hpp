#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <vector>
#include "Model/entity.hpp"
#include "Model/player.hpp"
//#include "Model/enemy.hpp"
#include "Model/collision_manager.hpp"
#include "View/renderer.hpp"
#include "Controller/event_handler.hpp"

class GameState {
public:
    GameState();
    ~GameState();

    void update(const EventHandler&);
    void render(Renderer& renderer);

    void addEntity(Entity* entity);
    void removeEntity(Entity* entity);

private:
    std::vector<Entity*> entities;
    Player* player;
};

#endif

#include "Model/game_state.hpp"
#include <algorithm>

GameState::GameState() {
    // Initialize player and other entities
    player = new Player(500, 500, 10, 10, 5, 10, 7, 0.95, -0.5);
    entities.push_back(player);
    entities.push_back(new Entity(20, 20, 200, 50, 5, 10));
}

GameState::~GameState() {
    for (auto entity : entities) {
        delete entity;
    }
    entities.clear();
}

void GameState::update(const EventHandler& event) {
    // Update all entities
    for (auto entity : entities) {
        entity->update(event);
    }

    // Check for collisions
    for (size_t i = 0; i < entities.size(); ++i) {
        for (size_t j = i + 1; j < entities.size(); ++j) {
            if (CollisionManager::checkCollision(entities[i]->getRect(), entities[j]->getRect())) {
                std::cout << std::endl << "collition" ;
                // Handle collision between entities[i] and entities[j]
            }
        }
    }
}

void GameState::render(Renderer& renderer) {
    // Render all entities
    for (auto entity : entities) {
        renderer.draw(*entity);
    }
}

void GameState::addEntity(Entity* entity) {
    entities.push_back(entity);
}

void GameState::removeEntity(Entity* entity) {
    entities.erase(std::remove_if(entities.begin(), entities.end(), [&](Entity* e) { return e == entity; }), entities.end());
    delete entity;
}

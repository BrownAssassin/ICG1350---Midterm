#include "Game.h"
#include "GameObject.h"

GameObject::GameObject()
    : position(0.0f, 0.0f, 0.0f), size(1.0f, 1.0f, 1.0f), velocity(0.0f), color(1.0f), rotation(0.0f), texture(), isSolid(false), isDestroyed(false) { }

GameObject::GameObject(glm::vec3 position, glm::vec3 size, Texture* texture, glm::vec3 color, glm::vec3 velocity)
    : position(position), size(size), velocity(velocity), color(color), rotation(0.0f), texture(texture), isSolid(false), isDestroyed(false) { }

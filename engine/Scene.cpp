#include <chrono>
#include <random>
#include "Scene.h"

Scene::Scene()
{
    this->mLastEntityId = 0;
};

Scene::~Scene()
{
};

Entity* Scene::CreateEntity()
{
    auto id = this->mLastEntityId++;
    auto ent = new Entity(id);
    this->mEntities.insert(pair<long, Entity*>(id, ent));

    return ent;
}

Entity* Scene::GetEntity(long id)
{    
    return this->mEntities.find(id)->second;
}

map<long, Entity*> Scene::GetEntities()
{    
    return this->mEntities;
}
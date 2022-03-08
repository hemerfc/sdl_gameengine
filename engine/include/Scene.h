#pragma once

#include <map>
#include "Entity.h"

using namespace std;

class Scene
{
public:	
    Scene();
    ~Scene();
    Entity* CreateEntity();
    Entity* GetEntity(long id);
    map<long, Entity*> GetEntities();
    
private:
    map<long, Entity*> mEntities;
    long mLastEntityId;
};

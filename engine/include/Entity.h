#pragma once

#include <map>

using namespace std;


class BaseComponent;

class Entity
{
public:
    Entity(long id);
    long GetId();
    void AddComponent(BaseComponent* component);
    BaseComponent* GetComponent(int componentType);
    map<int, BaseComponent*> GetComponents();
private:
    long mId;
    map<int, BaseComponent*> pComponents;
};

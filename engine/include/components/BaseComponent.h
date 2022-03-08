#pragma once

class Entity;

class BaseComponent
{
public: 
	virtual int GetComponentType();
	void Attach(Entity* entity);
	Entity* GetEntity();
private:
	Entity* mEntity; 
};
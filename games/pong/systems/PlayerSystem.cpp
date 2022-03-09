#include "systems/PlayerSystem.h"

PlayerSystem::PlayerSystem()
{
}

void PlayerSystem::Update(Scene* scene, float dt)
{
	// for each entity	
    auto entities = scene->GetEntities();
    for (auto ent : entities)
    {
        auto playerComp = (PlayerComponent*)ent.second->GetComponent(PlayerComponent::TYPE);
        
        if(playerComp != nullptr)
        {
            InputComponent* inputComp;
            RectComponent* rectComp;

            try
            {
                inputComp = (InputComponent*)ent.second->GetComponent(InputComponent::TYPE);
                rectComp = (RectComponent*)ent.second->GetComponent(RectComponent::TYPE);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
            if(inputComp != nullptr && rectComp != nullptr)
                this->PlayerLogic(playerComp, inputComp, rectComp, dt);
        }
    }
}

void PlayerSystem::PlayerLogic(PlayerComponent* player, InputComponent* input, RectComponent* rect, float dt)
{	
    auto buttons = input->GetButtons();

    if (buttons.test(static_cast<std::size_t>(InputButtons::UP)))
    {
        rect->mPosition.y -= (dt * 100.0f);
    }

    else if (buttons.test(static_cast<std::size_t>(InputButtons::DOWN)))
    {
        rect->mPosition.y += (dt * 100.0f);
    }

    // limit the player position
    if(rect->mPosition.y < 0)
        rect->mPosition.y = 0;
    else if(rect->mPosition.y + rect->mSize.y > 240)
        rect->mPosition.y = 240 - rect->mSize.y;
}

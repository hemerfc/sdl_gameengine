#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "Components/SpriteComponent.h"

TEST_CASE( "create component", "Prove that component can be created" ){
    auto comp = new SpriteComponent();
    
    REQUIRE( comp->GetComponentType() == SpriteComponent::TYPE );
}


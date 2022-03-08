#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "scene_test.h"
#include "component_test.h"

TEST_CASE( "stupid/1=2", "Prove that one not equals 2" ){
    int one = 1;
    REQUIRE( one != 2 );
}

TEST_CASE( "stupid/1=1", "Prove that one equals 1" ){
    int one = 1;
    REQUIRE( one == 1 );
}

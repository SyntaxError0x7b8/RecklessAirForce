//
// Created by qos on 8/27/25.
//
#define CATCH_CONFIG_MAIN
#include "../src/graphics/hero_graphics_component.h"
#include "catch2/catch_test_macros.hpp"


TEST_CASE("HeroScale" "[HeroGraphicsTest]") {
  auto *hero = new HeroGraphicsComponent(2.3f);
  CHECK(hero->GetScale() == 2.3f);
  delete hero;
}

//
// Created by qos on 8/26/25.
//

#include "catch2/catch_test_macros.hpp"
#include "../sources/graphics/hero_graphics_component.h"
//#include  "../cmake-build-debug/_deps/raylib-src/src/raylib.h"

TEST_CASE("HeroScale" "[HeroGraphicsTest]") {
  auto *hero = new HeroGraphicsComponent(2.3f);
  CHECK(hero->GetScale() == 2.3f);
  delete hero;
}

#include "enemy.h"
#include "environment.h"
#include "environment_type.h"
#include "food.h"
#include "food_type.h"
#include "game.h"
#include "game_options.h"
#include "game_resources.h"
#include "game_view.h"
#include "menu_button.h"
#include "menu.h"
#include "menu_view.h"
#include "player.h"
#include "player_shape.h"
#include <SFML/Graphics.hpp>
#include <cassert>
#include <iostream>
#include "sound_type.h"

/// All tests are called from here, only in debug mode
void test()
{
  test_action_type();
  test_player_shape();
  test_player();
  test_game();
  test_game_options();
  test_enemy();
  test_environment();
  test_individual_type();
  test_food();
  test_food_type();
  test_menu();
  test_menu_button();
#ifndef LOGIC_ONLY
  test_game_view();
  test_game_resources();
  test_sound_type();
#endif // LOGIC_ONLY
}

int main(int argc, char **argv) //!OCLINT tests may be long
{
#ifndef NDEBUG
  test();
#else
  // In release mode, all asserts are removed from the code
  assert(1 == 2);
#endif
#ifdef LOGIC_ONLY
  std::cout << "Compiled with LOGIC_ONLY\n";
#endif

  const std::vector<std::string> args(argv, argv + argc);

  // We've already tested, so the program is done
  if (args.size() > 1 && args[1] == "--test")
    return 0;

#ifndef LOGIC_ONLY


  // Show the menu, quits after (for now)
  if (args.size() > 1 && args[1] == "--menu")
  {
    menu_view v;
    v.exec();
    return 0;
  }

  const game_options options;
  game_view v(options);
  assert(options == v.get_options());
  v.exec();

#endif // LOGIC_ONLY

  return 0;
}

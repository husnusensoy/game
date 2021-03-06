#include "menu_button.h"

menu_button::menu_button(std::string name, float width, float height)
    : m_body{width, height}, m_name{name}
{
}

void test_menu_button()
{
  // buttons can be set to a certain position
  float x = 1.2f;
  float y = 3.4f;
  menu_button m_b("test");
  m_b.set_x(x);
  m_b.set_y(y);
  assert(m_b.get_x() - x < 0.00000001f);
  assert(m_b.get_y() - y < 0.00000001f);
}

#ifndef SHELTER_H
#define SHELTER_H

#include "color.h"
#include <cmath>
class shelter
{
public:
  shelter(const double x = 0.0, const double y = 0.0,
          const double radius = 100.0, const color &c = color(),
          const double speed = 0.1, const double direction =1.0 );
  const color &get_color() const noexcept { return m_color; }
  double get_radius() const noexcept { return m_radius; }
  double get_x() const noexcept { return m_x; }
  double get_y() const noexcept { return m_y; }
  void update_shelter_position();
private:
  color m_color;
  double m_radius;
  double m_x;
  double m_y;
  double m_speed;
  double m_direction;
};

void test_shelter();

/// Get the blueness (from the color) of the shelter
int get_blueness(const shelter &f) noexcept;

/// Get the greenness (from the color) of the shelter
int get_greenness(const shelter &f) noexcept;

/// Get the opaqueness(from the color) of the shelter (0 = transparat, 255 =
/// opaque)
int get_opaqueness(const shelter &f) noexcept;

/// Get the redness (from the color) of the shelter
int get_redness(const shelter &f) noexcept;

#endif // SHELTER_H

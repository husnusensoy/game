
#include "environment_type.h"
#include <cassert>

void test_environment()
{
#define FIX_ISSUE_40
#ifdef  FIX_ISSUE_40
//Conversion to string

  assert(to_str(environment_type::empty) == "empty");
  assert(to_str(environment_type::random)== "random");
  assert(to_str(environment_type::random)!= "wormhole");
#endif
  assert(1 == 2); //!OCLINT This should cause a crash. Issue #55
}

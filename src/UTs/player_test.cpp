#include <gtest/gtest.h>

#include <player.h>


namespace kensington
{
TEST(PlayerTest, CreatePlayer)
{
  ASSERT_NO_THROW(Player u(std::string("Player1")));
}
TEST(PlayerTest, NameIsStored)
{
  Player u(std::string("Player1"));
  ASSERT_STREQ("Player1", u.get_name().c_str());
}
} // namespace kensington

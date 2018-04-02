#include <board.h>
#include <gtest/gtest.h>

namespace kensington
{
  TEST(BoardTest, CreatedEmpty)
  {
    Board b;
    ASSERT_EQ(b.num_nodes(), 0);
    ASSERT_EQ(b.num_edges(), 0);
  }
  TEST(BoardTest, AddNodes)
  {
    Board b;
    b.add_node(Node{});
    ASSERT_EQ(b.num_nodes(), 1);
    ASSERT_EQ(b.num_edges(), 0);
  }
} //namespace kensington

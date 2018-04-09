#include <board.h>
#include <gtest/gtest.h>

namespace kensington
{
  TEST(BoardTest, CreatedEmpty)
  {
    Board b{3,3};
    ASSERT_EQ(b.num_nodes(), 0);
    ASSERT_EQ(b.num_edges(), 0);
  }
  TEST(BoardTest, AddNodes)
  {
    Board b{3,3};
    b.add_node(Node{{0,0}});
    ASSERT_EQ(b.num_nodes(), 1);
    ASSERT_EQ(b.num_edges(), 0);
  }
  TEST(BoardTest, AddDuplicateNode)
  {
    Board b{3,3};
    b.add_node({{0,0}});
    b.add_node({{0,0}});
    ASSERT_EQ(b.num_nodes(), 1);
  }
  TEST(BoardTest, AddNodeAtInvalidPosition)
  {
    Board b{2,2};
    b.add_node({{2,1}});
    b.add_node({{1,2}});
    b.add_node({{2,2}});
    b.add_node({{1,1}});
    ASSERT_EQ(b.num_nodes(), 1);
  }
} //namespace kensington

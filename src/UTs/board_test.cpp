#include <board.h>
#include <edge.h>
#include <node.h>
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
  TEST(BoardTest, AddEdge)
  {
    Board b{3,3};
    Node n1{{0,0}};
    Node n2{{2,2}};
    Edge e1{n1,n2};
    b.add_node(std::move(n1));
    b.add_node(std::move(n2));
    b.add_edge(std::move(e1));
  }
} //namespace kensington

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
    ASSERT_TRUE(b.add_node(Node{{0,0}}));
    ASSERT_EQ(b.num_nodes(), 1);
    ASSERT_EQ(b.num_edges(), 0);
  }
  TEST(BoardTest, AddDuplicateNode)
  {
    Board b{3,3};
    ASSERT_TRUE(b.add_node({{0,0}}));
    ASSERT_FALSE(b.add_node({{0,0}}));
    ASSERT_EQ(b.num_nodes(), 1);
  }
  TEST(BoardTest, AddNodeAtInvalidPosition)
  {
    Board b{2,2};
    ASSERT_FALSE(b.add_node({{2,1}}));
    ASSERT_FALSE(b.add_node({{1,2}}));
    ASSERT_FALSE(b.add_node({{2,2}}));
    ASSERT_TRUE(b.add_node({{1,1}}));
    ASSERT_EQ(b.num_nodes(), 1);
  }
  TEST(BoardTest, AddEdge)
  {
    Board b{3,3};
    Node n1{{0,0}};
    Node n2{{2,2}};
    Edge e1{n1,n2};
    ASSERT_TRUE(b.add_node(std::move(n1)));
    ASSERT_TRUE(b.add_node(std::move(n2)));
    ASSERT_TRUE(b.add_edge(std::move(e1)));
    ASSERT_EQ(b.num_nodes(), 2);
    ASSERT_EQ(b.num_edges(), 1);

  }
  TEST(BoardTest, OccupyEmpty)
  {
    Board b{1,1};
    Node n{{0,0}};
    b.add_node(std::move(n));
    ASSERT_TRUE(b.occupy({0,0}, NodeStatus::RED));
  }
  TEST(BoardTest, AttemptOccupyNotEmpty)
  {
    Board b{1,1};
    Node n{{0,0}};
    b.add_node(std::move(n));
    b.occupy({0,0}, NodeStatus::RED);
    ASSERT_FALSE(b.occupy({0,0}, NodeStatus::BLUE));
    ASSERT_FALSE(b.occupy({0,0}, NodeStatus::RED));
  }
  TEST(BoardTest, AttemptOccupyNonExistent)
  {
    Board b{1,1};
    Node n{{0,0}};
    b.add_node(std::move(n));
    ASSERT_FALSE(b.occupy({1,0}, NodeStatus::RED));
  }
  TEST(BoardTest, RemoveCounter)
  {
    Board b{1,1};
    Node n{{0,0}};
    b.add_node(std::move(n));
    b.occupy({0,0}, NodeStatus::RED);
    ASSERT_TRUE(b.remove({0,0}));
  }
  TEST(BoardTest, AttemptRemoveEmpty)
  {
    Board b{1,1};
    Node n{{0,0}};
    b.add_node(std::move(n));
    ASSERT_FALSE(b.remove({0,0}));
  }
  TEST(BoardTest, AttemptRemoveNonExistent)
  {
    Board b{1,1};
    Node n{{0,0}};
    b.add_node(std::move(n));
    ASSERT_FALSE(b.remove({1,0}));
  }
  TEST(BoardTest, MoveCounter)
  {
    Board b{3,3};
    Node n1{{0,0}};
    Node n2{{2,2}};
    Edge e1{n1,n2};
    b.add_node(std::move(n1));
    b.add_node(std::move(n2));
    b.add_edge(std::move(e1));
    b.occupy({0,0}, NodeStatus::RED);
    ASSERT_TRUE(b.move({0,0}, {2,2}));
  }
} //namespace kensington

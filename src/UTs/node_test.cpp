#include <gtest/gtest.h>

#include <node.h>
namespace kensington
{
TEST(NodeTest, CreatedEmpty)
{
    Node n{{0,0}};
    ASSERT_EQ(NodeStatus::EMPTY, n.status());
}
TEST(NodeTest, PlaceCounterRed)
{
    Node n{{0,0}};
    ASSERT_TRUE(n.occupy(NodeStatus::RED));
    ASSERT_EQ(NodeStatus::RED, n.status());
}
TEST(NodeTest, PlaceCounterBlue)
{
    Node n{{0,0}};
    ASSERT_TRUE(n.occupy(NodeStatus::BLUE));
    ASSERT_EQ(NodeStatus::BLUE, n.status());
}
TEST(NodeTest, RemoveCounter)
{
    Node n{{0,0}};
    ASSERT_TRUE(n.occupy(NodeStatus::RED));
    ASSERT_TRUE(n.free());
    ASSERT_EQ(NodeStatus::EMPTY, n.status());
}
TEST(NodeTest, AlreadyOccupied)
{
    Node n{{0,0}};
    ASSERT_TRUE(n.occupy(NodeStatus::RED));
    ASSERT_FALSE(n.occupy(NodeStatus::BLUE));
    ASSERT_EQ(NodeStatus::RED, n.status());
}
TEST(NodeTest, CallOccupyWithEMPTY)
{
  Node n{{0,0}};
  ASSERT_FALSE(n.occupy(NodeStatus::EMPTY));
}
TEST(NodeTest, Equality)
{
  Node n1{{0,0}};
  Node n2{{0,1}};
  Node n3{{1,0}};
  Node n1_2{{0,0}};
  Node n4{{1,1}};

  ASSERT_EQ(n1, n1_2);
  ASSERT_NE(n1, n2);
  ASSERT_NE(n1, n3);
  ASSERT_NE(n1, n4);
  ASSERT_NE(n2, n3);
  ASSERT_NE(n3, n4);
}
TEST(NodeTest, CheckReportedLocation)
{
  Node n{{1,2}};
  ASSERT_EQ(n.location().first, 1);
  ASSERT_EQ(n.location().second, 2);
}
} // namespace kensington

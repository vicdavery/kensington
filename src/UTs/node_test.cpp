#include <gtest/gtest.h>

#include <node.h>
namespace kensington
{
TEST(NodeTest, CreatedEmpty)
{
    Node n;
    ASSERT_EQ(NodeStatus::EMPTY, n.status());
}
TEST(NodeTest, PlaceCounterRed)
{
    Node n;
    ASSERT_TRUE(n.occupy(NodeStatus::RED));
    ASSERT_EQ(NodeStatus::RED, n.status());
}
TEST(NodeTest, PlaceCounterBlue)
{
    Node n;
    ASSERT_TRUE(n.occupy(NodeStatus::BLUE));
    ASSERT_EQ(NodeStatus::BLUE, n.status());
}
TEST(NodeTest, RemoveCounter)
{
    Node n;
    ASSERT_TRUE(n.occupy(NodeStatus::RED));
    ASSERT_TRUE(n.free());
    ASSERT_EQ(NodeStatus::EMPTY, n.status());
}
TEST(NodeTest, AlreadyOccupied)
{
    Node n;
    ASSERT_TRUE(n.occupy(NodeStatus::RED));
    ASSERT_FALSE(n.occupy(NodeStatus::BLUE));
    ASSERT_EQ(NodeStatus::RED, n.status());
}
TEST(NodeTest, CallOccupyWithEMPTY)
{
  Node n;
  ASSERT_FALSE(n.occupy(NodeStatus::EMPTY));
}
} // namespace kensington
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

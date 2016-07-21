#include <gtest/gtest.h>

#include <node.h>
namespace kensington
{
TEST(NodeTest, CreatedEmpty)
{
    Node n;
    ASSERT_EQ(n.status(), NodeStatus::EMPTY);
}
TEST(NodeTest, PlaceCounterRed)
{
    Node n;
    ASSERT_TRUE(n.occupy(NodeStatus::RED));
    ASSERT_EQ(n.status(), NodeStatus::RED);
}
TEST(NodeTest, PlaceCounterBlue)
{
    Node n;
    ASSERT_TRUE(n.occupy(NodeStatus::BLUE));
    ASSERT_EQ(n.status(), NodeStatus::BLUE);
}
TEST(NodeTest, RemoveCounter)
{
    Node n;
    ASSERT_TRUE(n.occupy(NodeStatus::RED));
    ASSERT_TRUE(n.free());
    ASSERT_EQ(n.status(), NodeStatus::EMPTY);
}
TEST(NodeTest, AlreadyOccupied)
{
    Node n;
    ASSERT_TRUE(n.occupy(NodeStatus::RED));
    ASSERT_FALSE(n.occupy(NodeStatus::BLUE));
    ASSERT_EQ(n.status(), NodeStatus::RED);
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

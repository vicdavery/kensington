#include <edge.h>
#include <gtest/gtest.h>

namespace kensington
{
TEST(EgdeTest, CreateNewEdge)
{
    Node n1;
    Node n2;
    Edge e(n1, n2);
    ASSERT_EQ(e.get_node(0), n1);
    ASSERT_EQ(e.get_node(1), n2);
}


TEST(EdgeTest, CreateEdgeWithDuplicateNode)
{
  Node n1;
  ASSERT_THROW(Edge e(n1, n1), DuplicateNodeException);
}


} // namespace kensington

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#include <edge.h>
#include <gtest/gtest.h>

namespace kensington
{
TEST(EgdeTest, CreateNewEdge)
{
    Node n1;
    Node n2;
    ASSERT_NO_THROW(Edge e(n1, n2));
}


} // namespace kensington

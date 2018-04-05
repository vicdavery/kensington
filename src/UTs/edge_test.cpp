#include <edge.h>
#include <gtest/gtest.h>

namespace kensington
{
TEST(EgdeTest, CreateNewEdge)
{
    Node n1{{0,0}};
    Node n2{{0,1}};
    ASSERT_NO_THROW(Edge e(n1, n2));
}


} // namespace kensington

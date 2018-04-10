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
TEST(EdgeTest, CompareEdges)
{
  Edge e1{{{0,0}},{{1,1}}};
  Edge e2{{{1,1}},{{2,2}}};
  ASSERT_LT(e1,e2);
}


} // namespace kensington

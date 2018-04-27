#include <layout_config_parser.h>

#include <gtest/gtest.h>

namespace kensington
{

  TEST(LayoutConfigParserTest, SingleNode)
  {
    auto config = R"config(
layout {
  grid {"width": 2,"height": 2}
  node {
    location { "x": 0, "y": 0 }
  }
})config";

    LayoutConfigParser p{config};
    ASSERT_EQ(p.width(), 2);
  }
  TEST(LayoutConfigParserTest, TwoNodesAndEdge)
  {
  }
  TEST(LayoutConfigParserTest, MultipleEdgesFromNode)
  {
  }
}


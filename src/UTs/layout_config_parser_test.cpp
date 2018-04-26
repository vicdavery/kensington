#include <layout_config_parser.h>

#include <gtest/gtest.h>

namespace kensington
{

  TEST(LayoutConfigParserTest, SingleNode)
  {
    auto config = R"config(
layout {
  grid {
    x: 2
    y: 2
  }
  node {
    location { x: 0, y: 0 }
  }
})config";

  }
  TEST(LayoutConfigParserTest, TwoNodesAndEdge)
  {
  }
  TEST(LayoutConfigParserTest, MultipleEdgesFromNode)
  {
  }
}


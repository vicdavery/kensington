#ifndef edge_h
#define edge_h

#include "node.h"
#include <utility>
#include <stdexcept>

namespace kensington
{
  class Edge
  {
  public:
    Edge(Node const& n1, Node const& n2) : nodes_(std::move(n1), std::move(n2))
    {
    }

    Node const& get_node(unsigned int num) {
      if (num == 0)
      return std::get<0>(nodes_);
      else if (num == 1)
      return std::get<1>(nodes_);
      else
      throw std::out_of_range("Node number must be either 0 or 1");
    }
  private:
    std::pair<Node const&, Node const&> nodes_;
  };
} // namespace kensington
#endif

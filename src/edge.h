#pragma once

#include "node.h"
#include <utility>
#include <stdexcept>

namespace kensington
{
  /**
  * Represents the connection between two nodes.
  */
  class Edge
  {
  public:
    /** An Edge can only be created by specifying its 2 nodes.
    *   @param n1 The first node.
    *   @param n2 The second node.
    */
    Edge(Node const& n1, Node const& n2) : nodes_(std::move(n1), std::move(n2))
    {
    }

    Node const& get_node(unsigned int num)
    {
      if (num == 0)
      {
        return nodes_.first;
      }
      else if (num == 1)
      {
        return nodes_.second;
      }
      else
      {
        throw std::out_of_range("Node number must be either 0 or 1");
      }
    }
    bool operator<(const Edge& rhs) const
    {
      return nodes_.first.location() < rhs.nodes_.first.location()
        ||
        (nodes_.first.location() == rhs.nodes_.first.location()
        &&
        nodes_.second.location() < rhs.nodes_.second.location());
    }
  private:
    std::pair<Node const&, Node const&> nodes_;
  };
} // namespace kensington

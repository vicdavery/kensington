#include <board.h>

#include <sstream>

namespace kensington
{
  bool Board::add_node(Node&& n)
  {
    if (n.location().first >= width_ || n.location().second >= height_)
      return false;
    if (std::find(std::begin(nodes_), std::end(nodes_), n) == nodes_.end())
    {
      nodes_.push_back(std::move(n));
      return true;
    }
    return false;
  }
  bool Board::add_edge(Edge&& e)
  {
    return edges_.insert(std::move(e)).second;
  }
  bool Board::occupy(Location loc, NodeStatus status)
  {
    auto node = std::find(std::begin(nodes_), std::end(nodes_), loc);
    if (node == nodes_.end())
      return false;
    if (node->status() != NodeStatus::EMPTY)
      return false;
    node->occupy(status);
    return true;
  }
}

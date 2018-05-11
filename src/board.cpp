#include <board.h>

#include <algorithm>
#include <sstream>

namespace kensington
{
  bool Board::add_node(Node&& n)
  {
    if (n.location().first >= width_ || n.location().second >= height_)
    {
      return false;
    }
    if (std::find(std::begin(nodes_), std::end(nodes_), n) == nodes_.end())
    {
      nodes_.push_back(std::move(n));
      return true;
    }
    return false;
  }
  bool Board::add_edge(Edge&& e)
  {
    return edges_.insert(e).second;
  }
  bool Board::occupy(Location loc, NodeStatus status)
  {
    auto node = std::find(std::begin(nodes_), std::end(nodes_), loc);
    if (node == nodes_.end())
    {
      return false;
    }
    if (node->status() != NodeStatus::EMPTY)
    {
      return false;
    }
    node->occupy(status);
    return true;
  }
  bool Board::remove(Location loc)
  {
    auto node = std::find(std::begin(nodes_), std::end(nodes_), loc);
    if (node == nodes_.end())
      return false;
    if (node->status() == NodeStatus::EMPTY)
      return false;
    node->occupy(NodeStatus::EMPTY);
    return true;

  }
  bool Board::move(Location from, Location to)
  {
    auto from_node = std::find(std::begin(nodes_), std::end(nodes_), from);
    if (from_node == nodes_.end())
    {
      return false;
    }
    auto to_node = std::find(std::begin(nodes_), std::end(nodes_), to);
    if (to_node == nodes_.end())
    {
      return false;
    }
    if (from_node->status() == NodeStatus::EMPTY
        || to_node->status() != NodeStatus::EMPTY)
    {
      return false;
    }
    if (edges_.find(Edge{*from_node,*to_node}) == edges_.end())
    {
      return false;
    }

    to_node->occupy(from_node->status());
    from_node->occupy(NodeStatus::EMPTY);
    return true;
  }
} // namespace kensington

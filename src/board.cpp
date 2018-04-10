#include <board.h>

namespace kensington
{
  bool Board::add_node(Node&& n)
  {
    if (n.location().first >= width_ || n.location().second >= height_)
      return false;

    return nodes_.insert(std::move(n)).second;
  }
  bool Board::add_edge(Edge&& e)
  {
    return edges_.insert(std::move(e)).second;
  }
}

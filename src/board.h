#pragma once

#include <node.h>
#include <edge.h>

#include <deque>
#include <set>

namespace kensington
{
  /**
   * Represents the playing board.
   * The Board owns the Nodes and Edges that make up the board.
   */
  class Board
  {
    public:
      Board() = default;
      void add_node(Node&& n) { nodes_.insert(std::move(n)); }
      size_t num_nodes() { return nodes_.size(); }
      size_t num_edges() { return edges_.size(); }

    private:
      std::set<Node> nodes_;
      std::deque<Edge> edges_;
  };
} // namespace kensington

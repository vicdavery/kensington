#pragma once

#include <node.h>
#include <edge.h>

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
      Board(size_t width, size_t height) : width_{width}, height_{height} {};
      bool add_node(Node&& n);
      bool add_edge(Edge&& e);
      size_t num_nodes() { return nodes_.size(); }
      size_t num_edges() { return edges_.size(); }

    private:
      const size_t width_;
      const size_t height_;
      std::set<Node> nodes_;
      std::set<Edge> edges_;
  };
} // namespace kensington

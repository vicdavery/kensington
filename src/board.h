#pragma once

#include <node.h>
#include <edge.h>

#include <deque>
#include <set>
#include <string>

namespace kensington
{
  /**
   * Represents the playing board.
   * The Board owns the Nodes and Edges that make up the board.
   */
  class Board
  {
    public:
      /**
       * Creates a board with specied size. The board will not have nodes on every position, so it
       * represents a virtual playing field.
       */
      Board(size_t width, size_t height) : width_{width}, height_{height} {};
      bool add_node(Node&& n);
      bool add_edge(Edge&& e);
      size_t num_nodes() { return nodes_.size(); }
      size_t num_edges() { return edges_.size(); }

      /// Add a counter onto the board at the specified location.
      bool occupy(Location loc, NodeStatus status);
      /// Remove a counter from the location.
      bool remove(Location loc);
      /// Move a counter along an edge from one node to another.
      bool move(Location from, Location to);

    private:
      /// The width of the board.
      const size_t width_;
      /// The height of the board.
      const size_t height_;
      /// A list of all the nodes on the board.
      std::deque<Node> nodes_;
      /// A set of the edges which describe the board.
      std::set<Edge> edges_;
  };
} // namespace kensington

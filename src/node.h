#ifndef node_h
#define node_h

namespace kensington
{
enum class NodeStatus { EMPTY, RED, BLUE };
/**
* A node is the point on the board where a counter can be placed.
* It has multiple states: empty, red counter or blue counter
*/
class Node
{
    public:
        /// Indicates the current status of the Node.
        NodeStatus const& status() const { return status_; }
        /** Places a counter on the node if it is not already occupied.
        *   @param status The counter to be placed.
        *   @return true if successful, false if already occupied.
        */
        bool occupy(NodeStatus status);
        /** Removes the counter from the node.
        *   @return true if there was a counter there, otherwise false.
        */
        bool free();

    private:
        /// The Node will start in the EMPTY state.
        NodeStatus status_ = NodeStatus::EMPTY;
};
}
#endif

#ifndef node_h
#define node_h

namespace kensington
{
enum class NodeStatus { EMPTY, RED, BLUE };
class Node
{
    public:
        NodeStatus const& status() const { return status_; }
        bool occupy(NodeStatus status);
        bool free();

    private:
        NodeStatus status_ = NodeStatus::EMPTY;
};
}
#endif

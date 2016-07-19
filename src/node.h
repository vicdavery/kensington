
namespace kensington
{
enum class NodeStatus { EMPTY, RED, BLUE };
class Node
{
    public:
        NodeStatus const& status() const { return status_; }
        bool occupy(NodeStatus status);

    private:
        NodeStatus status_ = NodeStatus::EMPTY;
};
}

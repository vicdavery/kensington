#include "node.h"
#include <utility>

namespace kensington
{
class Edge
{
    private:
        std::pair<Node const&, Node const&> nodes_;
};
} // namespace kensington

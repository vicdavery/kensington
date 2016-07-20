#include "node.h"

namespace kensington
{
bool Node::occupy(NodeStatus status)
{
  if (status_ != NodeStatus::EMPTY)
    return false;
  status_ = status;
  return true;
}
bool Node::free()
{
  bool retval = false;
  if (status_ != NodeStatus::EMPTY)
  {
    retval = true;
    status_ = NodeStatus::EMPTY;
  }
  return retval;
}
} // namespace kensington

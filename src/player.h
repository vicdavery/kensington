#ifndef Player_h
#define Player_h

namespace kensington
{
class Player
{
public:
  Player(std::string const& name) : name_(std::move(name)) {}
  std::string const& get_name() { return name_; }
private:
  std::string const name_;
};
} // namespace kensington

#endif

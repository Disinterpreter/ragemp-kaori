#include <iostream>
#include <functional>
#include <map>
#include "../rageinc/rage.hpp"

class CmdHandl { 
	public:
	    CmdHandl() {};
	    virtual void addCommand(const std::u16string &cmd, std::function<void(rage::IPlayer*)> method);
	    virtual void callCommand(const std::u16string &cmd, rage::IPlayer *player);
};

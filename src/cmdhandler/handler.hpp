#include <iostream>
#include <functional>
#include <map>
class CmdHandl { 
	public:
	    CmdHandl() {};
	    virtual void addCommand(const std::u16string &cmd, std::function<void()> method);
	    virtual void callCommand(const std::u16string &cmd);
};

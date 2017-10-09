#include "handler.hpp"
#include <map>
#include <string>
#include <functional>
#include <iostream>
#include <unordered_map>


std::unordered_map<std::u16string, std::function<void(rage::IPlayer*, std::u16string &)>> cmdmap;

void CmdHandl::addCommand(const std::u16string &cmd, std::function<void(rage::IPlayer*, std::u16string &)> method)
{
	cmdmap.insert(std::pair<std::u16string, std::function<void(rage::IPlayer*, std::u16string &)>>(cmd, method));
};

void CmdHandl::callCommand(const std::u16string &cmd, rage::IPlayer *player, std::u16string &args) 
{
	auto search = cmdmap.find(cmd);
	if( search != cmdmap.end())
	{
		search->second(player, args);
	}
}

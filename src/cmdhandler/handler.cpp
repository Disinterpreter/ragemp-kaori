#include "handler.hpp"
#include <map>
#include <string>
#include <functional>
#include <iostream>
#include <unordered_map>


std::unordered_map<std::u16string, std::function<void(rage::IPlayer*)>> cmdmap;

void CmdHandl::addCommand(const std::u16string &cmd, std::function<void(rage::IPlayer*)> method)
{
	cmdmap.insert(std::pair<std::u16string, std::function<void(rage::IPlayer*)>>(cmd, method));
};

void CmdHandl::callCommand(const std::u16string &cmd, rage::IPlayer *player)
{
	auto search = cmdmap.find(cmd);
	if( search != cmdmap.end())
	{
		search->second(player);
	}
}

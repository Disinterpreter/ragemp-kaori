#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include "rageinc/rage.hpp"
#include "cmdhandler/handler.hpp"
#include "utils/utils.hpp"


class EventHandler 
		: public rage::IEventHandler,
		public rage::IPlayerHandler
{
	public:
		virtual rage::IPlayerHandler *GetPlayerHandler() {return this;}

		virtual void OnPlayerJoin(rage::IPlayer *player) { std::cout<<"Hai"<<std::endl; }
		virtual void OnPlayerChat(rage::IPlayer *player, const std::u16string &text);
		virtual void OnPlayerCommand(rage::IPlayer *player, const std::u16string &text);
		
};
void EventHandler::OnPlayerChat(rage::IPlayer *player, const std::u16string &text)
{
	std::string nick = player->GetName();
	std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> convert; 
	std::u16string u16nick = convert.from_bytes(nick);
	std::u16string middle = u": ";
	u16nick.append(middle);
	u16nick.append(text);
	player->OutputChatBox(u16nick);
}
void test(rage::IPlayer *player, std::u16string &args)
{
	player->OutputChatBox(args);
	std::cout<<player->GetName()<<std::endl;
}
void EventHandler::OnPlayerCommand(rage::IPlayer *player, const std::u16string &text)
{
	std::cout<<"cmd was recived"<<std::endl;
	std::u16string args = GetArguments(text);

	std::u16string cmd = GetCommand(text);
	CmdHandl *cmdh = new CmdHandl;
	cmdh->addCommand(u"help", test);
	cmdh->callCommand(cmd,player, args);
}
RAGE_API rage::IPlugin *InitializePlugin(rage::IMultiplayer *mp)
{
	std::cout << "\033[1;32m[OK] \033[0m" << "Gamemode Kaori has been started!" << std::endl;
	mp->AddEventHandler(new EventHandler);
	return new rage::IPlugin;
}

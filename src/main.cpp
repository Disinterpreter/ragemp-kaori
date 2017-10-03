#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include "rageinc/rage.hpp"


class EventHandler 
		: public rage::IEventHandler,
		public rage::IPlayerHandler
{
	public:
		virtual rage::IPlayerHandler *GetPlayerHandler() {return this;}

		virtual void OnPlayerJoin(rage::IPlayer *player) { std::cout<<"Hai"<<std::endl; }
		virtual void OnPlayerChat(rage::IPlayer *player, const std::u16string &text);
		
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
RAGE_API rage::IPlugin *InitializePlugin(rage::IMultiplayer *mp)
{
	std::cout << "Gamemode Kaori has been started!" << std::endl;
	mp->AddEventHandler(new EventHandler);
	return new rage::IPlugin;
}

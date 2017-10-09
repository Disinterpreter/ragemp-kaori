#include <string>

std::u16string GetArguments (const std::u16string &text)
{
	std::u16string _tmp = u"";
	for (int i = 0; i < text.length(); ++i)
	{
		if(text.at(i) == 32)
		{
			for (int k = i+1; k < text.length(); ++k)
			{
				//cout << text.at(k) << endl;
				_tmp.push_back(text.at(k));
			}
			break;
		}
	}
	return _tmp;
}

std::u16string GetCommand (const std::u16string &cmd)
{
	std::u16string _tmp = u"";
	for (int i = 0; i < cmd.length(); ++i)
	{
		if(cmd.at(i) == 32)
		{
			for(int k = 0; k < i ; ++k)
			{
				_tmp.push_back(cmd.at(k));
			}
			break;
		}
		if(cmd.at(i) == cmd.back())
		{
			_tmp = cmd;
		}
	}
	return _tmp;
}

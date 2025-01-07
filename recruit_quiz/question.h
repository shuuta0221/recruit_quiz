#pragma once
#include <string>
#include <vector>

//–â‘è•¶‚ğ‚Ü‚Æ‚ß‚é\‘¢‘Ì
struct Question
{
	std::string s;//–â‘è•¶
	std::string a;//“š‚¦
	std::vector<std::string> b;	//“š‚¦(•¡”‚ ‚éê‡)
};

// –â‘è‚Ì”z—ñ‚ğ•\‚·Œ^
using QuestionList = std::vector<Question>;
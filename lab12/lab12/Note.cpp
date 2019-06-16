#include "Note.h"



Note::Note() : Note("Note","Nothing."){}
Note::Note(std::string name,std::string information) : Item(name), information(information){}
Note::Note(std::string name,std::string information,std::string whereToFind) : Item(name,whereToFind), information(information){}

std::string Note::getInfo()
{
	return "Information: " + information;
}

Note::~Note()
{
}

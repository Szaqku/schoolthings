#include <iostream>
#include "Treasures.h"
#include "Note.h"

int main()
{
	Treasures trs;
	Item* yellowNote = new Note("Yellow Note", "Apples are red.","Black Valley");
	Item* blackNote = new Note("Black Note", "Apples are black.");

	trs.addTreasure(new Note("True Note","Apples are green."));
	trs.addTreasure(yellowNote);
	trs.addTreasure(new Note("False Note","Apples are not yellow."));

	std::cout << "Treasure list contains: " << std::endl;
	trs.printListOfTreasures();

	Item* found = trs.findNextTreasure(yellowNote);
	std::cout << std::endl << "Next to "<<yellowNote->getName()<<" is: \n" << *found << std::endl;

	std::cout << std::endl << "Trying to find element which is not in list: " << std::endl;
	try {
		trs.findNextTreasure(blackNote);
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl << "Trying to delete element which is not in list: " << std::endl;
	try {
		trs.deleteTreasure(blackNote);
	}
	catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl << "Trying to delete element: "<<*yellowNote<<"\n (No confirmation displayed)" << std::endl;
	trs.deleteTreasure(yellowNote);

	std::cout << std::endl<< "List of treasures after delete operation: " << std::endl;
	trs.printListOfTreasures();
}

#include "Story.h"
#include "functions.h"

Story::Story() 
{
	RunSetup();
	// uncomment this and insert title when applicable:
	// Common::Action("SetTitle(Insert Title Here)", true);
	Run();
	SetCurrentLocation(Cottage); // Cottage is the initial location
}

void Story::RunSetup() 
{
	// ----Call location setup functions----
	SetupCottage("Cottage");
	// SetupLocation2("location2");
	// ...

	Common::Action("ShowMenu()", true); // displays title menu
}

void Story::Run()
{
	while (true)
	{
		Location location = this->GetCurrentLocation();
		switch (location)
		{
			case Cottage:
				RunCottage();
				break;
			/*
			case "location2":
				RunLocation2();
				break;
			*/
		}

	}
}

void Story::SetupCottage(string name)
{
	// ----Location Setup----
	Common::Action("CreatePlace(" + name + ", Cottage)", true);

	// ----Character Setup----
	Common::SetUpCharacter("Player", "D", "Peasant", "Spiky", "Brown", "Cottage");

	// ----Items and Placement----

	// ----Interaction Setup----
	Common::Action("EnableIcon(Open_Door, Open, " + name + ".Door, Exit the Cottage, true)", true);
	
	// ----Furniture Config----
	Common::Action("HideFurniture(" + name + ".Chest)", true);
}

void Story::RunCottage()
{
	// ----Cottage Execution Loop----
	Location location = this->GetCurrentLocation();
	while (location == Cottage)
	{
		string input; // stores a single message from Camelot
		getline(cin, input);

		vector<string> inputWords = Common::SplitInput(input); // split camelot message into a vector containing its words
	}
}

void Story::SetCurrentLocation(Location newLocation)
{
	this->CurrentLocation = newLocation;
}

Story::Location Story::GetCurrentLocation()
{
	return this->CurrentLocation;
}
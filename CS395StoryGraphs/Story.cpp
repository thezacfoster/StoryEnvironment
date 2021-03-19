#include "Story.h"
#include "functions.h"

Story::Story() 
{
	playerName = "Player";
	SetCurrentLocation(Cottage); // Cottage is the initial location
	RunSetup();
	// uncomment this and insert title when applicable:
	// Common::Action("SetTitle(Insert Title Here)", true);
	Run();
	
}

void Story::RunSetup() 
{
	// ----Call location setup functions----
	SetupCottage("Cottage");
	SetupCrossroads("Crossroads");

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
			
			case Crossroads:
				RunCrossroads();
				break;
		}
	}
}

void Story::SetupCottage(string name)
{
	// ----Location Setup----
	Common::Action("CreatePlace(" + name + ", Cottage)", true);

	// ----Character Setup----
	Common::SetUpCharacter(playerName, "D", "Peasant", "Spiky", "Black", "9", "brown", "Cottage");

	// ----Items and Placement----

	// ----Interaction Setup----
	Common::Action("EnableIcon(Open_Door, Open, " + name + ".Door, Exit the Cottage, true)", true);
	
	// ----Furniture Config----
	Common::Action("HideFurniture(" + name + ".Chest)", true);
}

void Story::SetupCrossroads(string name)
{
	// ----Location Setup----
	Common::Action("CreatePlace(" + name + ", Bridge)", true);

	// ----Character Setup----
	

	// ----Items and Placement----

	// ----Interaction Setup----
	

	// ----Furniture Config----
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

		// execute common commands
		bool commandWasCommon = Common::CheckCommonKeywords(inputWords, playerName);

		// non-common commands:
		if (!commandWasCommon)
		{
			if (inputWords[1] == "Open_Door")
			{
				Common::Transition(playerName, "Cottage.Door", "Crossroads.NorthEnd");
				SetCurrentLocation(Crossroads);
			}
		}
	}
}

void Story::RunCrossroads()
{
	// ----Crossroads Execution Loop----
	Location location = this->GetCurrentLocation();
	while (location == Crossroads)
	{
		string input; // stores a single message from Camelot
		getline(cin, input);

		vector<string> inputWords = Common::SplitInput(input); // split camelot message into a vector containing its words

		// execute common commands
		bool commandWasCommon = Common::CheckCommonKeywords(inputWords, playerName);

		// non-common commands
		if (!commandWasCommon)
		{
			if (input == "input arrived Player position Crossroads.NorthEnd")
			{
				Common::Transition(playerName, "Crossroads.NorthEnd", "Cottage.Door");
				SetCurrentLocation(Cottage);
			}
		}
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
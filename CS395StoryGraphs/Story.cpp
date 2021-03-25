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
	SetupMarket("Market");
	SetupCamp("Camp");

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
				
			case Market:
				RunMarket();
				break;

			case Camp:
				RunCamp();
				break;
		}
	}
}

void Story::SetupCottage(string name)
{
	// ----Location Setup----
	Common::Action("CreatePlace(" + name + ", Farm)", true);

	// ----Character Setup----
	Common::SetUpCharacter(playerName, "D", "Peasant", "Spiky", "Black", "9", "brown", "Cottage.Door");
	Common::Action("Face(" + playerName + ", Cottage.Exit)", true);

	// ----Items and Placement----
	Common::Action("CreateItem(PlayerCoin, Coin)", true);

	// ----Interaction Setup----
	
	// ----Furniture Config----
	
}

void Story::SetupCrossroads(string name)
{
	// ----Location Setup----
	Common::Action("CreatePlace(" + name + ", CastleCrossroads)", true);

	// ----Character Setup----
	

	// ----Items and Placement----

	// ----Interaction Setup----
	

	// ----Furniture Config----
}

void Story::SetupMarket(string name)
{
	// ----Location Setup----
	Common::Action("CreatePlace(" + name + ", Courtyard)", true);

	// ----Character Setup----
	Common::SetUpCharacter("Merchant", "C", "Merchant", "Ponytail", "Red", "1", "green", name + ".BigStall");
	Common::SetUpCharacter("Guard", "F", "HeavyArmour", "Short_Full", "Black", "10", "brown", name + ".Target");

	// ----Items and Placement----

	// ----Interaction Setup----
	

	// ----Furniture Config----
	Common::Action("HideFurniture(Market.SmallStall)", true);
	
}

void Story::SetupCamp(string name)
{
	// ----Location Setup----
	Common::Action("CreatePlace(" + name + ", Camp)", true);

	// ----Character Setup----
	Common::SetUpCharacter("Bandit", "E", "Bandit", "Spiky", "Brown", "4", "blue", name + ".LeftLog");

	// ----Items and Placement----

	// ----Interaction Setup----

	// ----Furniture Config----
	Common::Action("HideFurniture(Camp.Stall)", true);

}

void Story::RunCottage()
{
	// ----Cottage Execution Loop----
	while (this->GetCurrentLocation() == Cottage)
	{
		string input; // stores a single message from Camelot
		getline(cin, input);

		vector<string> inputWords = Common::SplitInput(input); // split camelot message into a vector containing its words

		// execute common commands
		bool commandWasCommon = Common::CheckCommonKeywords(inputWords, playerName);

		// non-common commands:
		if (inputWords[1] == "arrived" && inputWords[2] == "Player")
		{
			// inputWords[3] should always be "position"

			if (inputWords[4] == "Cottage.Exit")
			{
				Common::Transition(playerName, "Cottage.Exit", "Crossroads.WestEnd");
				SetCurrentLocation(Crossroads);
			}
		}
	}
}

void Story::RunCrossroads()
{
	// ----Crossroads Execution Loop----
	while (this->GetCurrentLocation() == Crossroads)
	{
		string input; // stores a single message from Camelot
		getline(cin, input);

		vector<string> inputWords = Common::SplitInput(input); // split camelot message into a vector containing its words

		// execute common commands
		bool commandWasCommon = Common::CheckCommonKeywords(inputWords, playerName);

		// non-common commands
		if (!commandWasCommon)
		{
			if (inputWords[1] == "arrived" && inputWords[2] == "Player")
			{
				// inputWords[3] should always be "position"

				if (inputWords[4] == "Crossroads.WestEnd")
				{
					Common::Transition(playerName, "Crossroads.WestEnd", "Cottage.Exit");
					SetCurrentLocation(Cottage);
				}

				else if (inputWords[4] == "Crossroads.EastEnd")
				{
					Common::Transition(playerName, "Crossroads.EastEnd", "Camp.Exit");
					SetCurrentLocation(Camp);
				}

				else if (inputWords[4] == "Crossroads.Gate")
				{
					Common::Transition(playerName, "Crossroads.Gate", "Market.Exit");
					SetCurrentLocation(Market);
				}

				else if (inputWords[4] == "Crossroads.WestSign") 
				{
					Common::Action("Enter(Bandit, Crossroads.EastEnd)", true);
					Common::WalkTo("Bandit", "Player");
					Common::Action("DisableInput()", true);
					Common::Rob("Bandit", "PlayerCoin", "Player");
					Common::Action("EnableInput()", true);
					Common::WalkTo("Bandit", "Crossroads.Gate");
					Common::Action("Exit(Bandit, Crossroads.Gate)", true);
					Common::Action("SetPosition(Bandit, Market.Barrel)", true);
				}
			}
		}
	}
}

void Story::RunMarket() 
{
	// ----Market Execution Loop----
	while (this->GetCurrentLocation() == Market)
	{
		string input; // stores a single message from Camelot
		getline(cin, input);

		vector<string> inputWords = Common::SplitInput(input); // split camelot message into a vector containing its words

		// execute common commands
		bool commandWasCommon = Common::CheckCommonKeywords(inputWords, playerName);

		// non-common commands
		if (!commandWasCommon)
		{
			if (inputWords[1] == "arrived" && inputWords[2] == "Player")
			{
				// inputWords[3] should always be "position"

				if (inputWords[4] == "Market.Exit")
				{
					Common::Transition(playerName, "Market.Exit", "Crossroads.Gate");
					SetCurrentLocation(Crossroads);
				}
			}
		}
	}
}

void Story::RunCamp() 
{
	// ----Camp Execution Loop----
	while (this->GetCurrentLocation() == Camp)
	{
		string input; // stores a single message from Camelot
		getline(cin, input);

		vector<string> inputWords = Common::SplitInput(input); // split camelot message into a vector containing its words

		// execute common commands
		bool commandWasCommon = Common::CheckCommonKeywords(inputWords, playerName);

		// non-common commands
		if (!commandWasCommon)
		{
			if (inputWords[1] == "arrived" && inputWords[2] == "Player")
			{
				// inputWords[3] should always be "position"

				if (inputWords[4] == "Camp.Exit")
				{
					Common::Transition(playerName, "Camp.Exit", "Crossroads.EastEnd");
					SetCurrentLocation(Crossroads);
				}
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
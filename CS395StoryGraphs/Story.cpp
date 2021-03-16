#include "Story.h"
#include "functions.h"

Story::Story() 
{
	RunSetup();
	// uncomment this and insert title when applicable:
	// Common::Action("SetTitle(Insert Title Here)", true);
	Run();
	// uncomment this and insert initial location
	// SetCurrentLocation("insert first location name here");
}

void Story::RunSetup() 
{
	// ----Call location setup functions----
	// SetupLocation1("location1");
	// SetupLocation2("location2");
	// ...

	Common::Action("ShowMenu()", true); // displays title menu
}

void Story::Run()
{
	while (true)
	{
		/*
		location = GetLocation();
		switch (location)
		{
			case "location1":
				RunLocation1();
				break;
			case "location2":
				RunLocation2();
				break;
		}
		*/
	}
}

void Story::SetCurrentLocation(string newLocation)
{
	this->CurrentLocation = newLocation;
}

string Story::GetCurrentLocation()
{
	return this->CurrentLocation;
}
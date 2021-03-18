#pragma once
#include <string>

using namespace std;

class Story 
{
public:
	enum Location { Cottage, Market, Camp, Crossroads };

	Story(); // Constructor
	void RunSetup();
	void Run();

	// ----Functions for setting up each location in the story----
	void SetupCottage(string name);
	// void SetupLocation2(string name);
	// ...

	// ----Functions for executing each location in the story----
	void RunCottage();
	// void RunLocation2();
	// ...

	// Other Set/Get functions
	void SetCurrentLocation(Location newLocation);
	Location GetCurrentLocation();


private:
	Location CurrentLocation; // The name of the current location the player is in.

	// ----Variables for each instantiated location----
	// Type1 location1;
	// Type2 location2;
	// ...
};
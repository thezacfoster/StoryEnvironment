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
	void SetupCrossroads(string name);
	void SetupMarket(string name);
	void SetupCamp(string name);

	// ----Functions for executing each location in the story----
	void RunCottage();
	void RunCrossroads();
	void RunMarket();
	void RunCamp();

	// Other Set/Get functions
	void SetCurrentLocation(Location newLocation);
	Location GetCurrentLocation();

	string playerName;
private:
	Location CurrentLocation; // The name of the current location the player is in.

	// ----Variables for each instantiated location----
	// Type1 location1;
	// Type2 location2;
	// ...
};
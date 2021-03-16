#pragma once
#include <string>

using namespace std;

class Story 
{
public:
	Story(); // Constructor
	void RunSetup();
	void Run();

	// ----Functions for setting up each location in the story----
	// bool SetupLocation1(string name);
	// bool SetupLocation2(string name);
	// ...

	// ----Functions for executing each location in the story----
	// void RunLocation1();
	// void RunLocation2();
	// ...

	// Other Set/Get functions
	void SetCurrentLocation(string newLocation);
	string GetCurrentLocation();

private:
	string CurrentLocation; // The name of the current location the player is in.

	// ----Variables for each instantiated location----
	// Type1 location1;
	// Type2 location2;
	// ...
};
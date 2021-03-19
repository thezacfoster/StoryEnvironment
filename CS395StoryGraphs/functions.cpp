#include "functions.h"
#include <sstream>

using namespace std;

// Pauses execution in the experience manager until the given input message is received from Camelot
void Common::WaitFor(string msg)
{
	string i;
	do { getline(cin, i); } while (i != msg); // keep reading until matching msg is received
}

// Sends a given command to Camelot. If waitForSuccess is true, pauses the experience manager's execution until the command succeeds.
void Common::Action(string cmd, bool waitForSuccess)
{
	cout << ("start " + cmd) << endl;
	if (waitForSuccess) WaitFor("succeeded " + cmd);
}

// Manages the entire process of setting up a character, including appearance, clothing, and position.
void Common::SetUpCharacter(string name, string bodyType, string clothing, string hairStyle, string hairColor, string position)
{
	Action("CreateCharacter(" + name + ", " + bodyType + ")", true);
	if (clothing != "") Action("SetClothing(" + name + ", " + clothing + ")", true);
	if (hairStyle != "") Action("SetHairStyle(" + name + ", " + hairStyle + ")", true);
	if (hairColor != "") Action("SetHairColor(" + name + ", " + hairColor + ")", true);
	if (position != "") Action("SetPosition(" + name + ", " + position + ")", true);
}

// Prepares dialog display between two given characters. If walkTo is true, the first character will walk to the second's position.
void Common::SetUpDialog(string firstChar, string secondChar, bool walkTo)
{
	Action("DisableInput()", true);

	if (walkTo == true) Action("WalkTo(" + firstChar + ", " + secondChar + ")", true);

	Action("ShowDialog()", true);
	Action("ClearDialog()", true);

	Action("SetLeft(" + firstChar + ")", true);
	Action("SetRight(" + secondChar + ")", true);
	Action("EnableInput()", true);
}

// Establishes the text and response choices in the current dialog interaction.
void Common::SetUpDialogText(string message, string responseKey1, string response1, string responseKey2, string response2);

// Causes given character to exit one location and enter another, allowing transitions between Camelot Places.
void Common::Transition(string character, string exit, string entrance)
{
	Action("DisableInput()", true);
	Action("Exit(" + character + ", " + exit + ", true)", true);
	Action("Enter(" + character + ", " + entrance + ", true)", true);
	Action("EnableInput()", true);
}

// Establishes player control of the given character when the "Start" button is pressed at the main menu.
void Common::PlayerStart(string playerChar)
{
	Action("SetCameraFocus(" + playerChar + ")", true);
	Action("HideMenu()", true);
	Action("EnableInput()", true);
}

// Causes given character to walk to given location.
void Common::WalkTo(string character, string location)
{
	Action("DisableInput()", true);
	Action("WalkTo(" + character + ", " + location + ")", true);
	Action("EnableInput()", true);
}

// Clears and closes list views, such as inventory screens.
void Common::CloseList()
{
	Action("HideList()", true);
	Action("ClearList()", true);
	Action("EnableInput()", true);
}

// Takes an input string and splits it into a vector containing its words.
vector<string> Common::SplitInput(string input)
{
	vector<string> output; // vector of words to be returned
	string word; // temporarily stores a single word

	// read one word at a time and add to vector
	istringstream inputStream(input);
	while (getline(inputStream, word, ' '))
	{
		output.push_back(word);
	}

	return output;
}

// Checks common keywords for the most frequent commands from Camelot and performs the appropriate action if found. 
// Returns true if the given camelot command was for a common command.
bool Common::CheckCommonKeywords(vector<string> input, string playerName)
{
	bool keywordFound = true; // value to be returned. defaults to true, becomes false if command was not common

	if (input.size() < 2) return false; // vector is invalid if it has less than two words

	// if the command is under the "Selected" keyword
	if (input[1] == "Selected")
	{
		// occurs when the player clicks Start on the main menu
		if (input[2] == "Start")
		{
			cout << "test\n";
			PlayerStart(playerName);
			Action("EnableInput()", true);
		}

		// occurs when the player unpauses the game
		else if (input[2] == "Resume")
		{
			Action("HideMenu()", true);
			Action("EnableInput()", true);
			Action("EnableInput()", true); // need to enable input twice for this to work
		}

		// occurs when the player selects Credits at the menu
		// (fill in later)

		// occurs when the player selects Quit at the menu
		else if (input[2] == "Quit")
			Action("Quit()", true);

		// occurs when dialog ends
		else if (input[2] == "end")
			Action("HideDialog()", true);

		// occurs if the keyword was "Selected" but the option selected was something custom, such as a dialog choice
		else keywordFound = false;
	}

	// if the command is under the "Key" keyword
	else if (input[1] == "Key")
	{
		// occurs if the player presses the inventory key
		if (input[2] == "Inventory")
		{
			Action("ClearList()", true);
			// (fill in later once inventory management is added
		}

		// occurs if the player presses the pause key
		else if (input[2] == "Pause")
		{
			Action("DisableInput()", true);
			Action("ShowMenu()", true);
		}

		else keywordFound = false;
	}

	// if the command is under the "Close" keyword
	else if (input[1] == "Close")
	{
		// occurs when the player closes a narration window
		if (input[2] == "Narration")
			Action("HideNarration()", true);

		// occurs when the player closes an inventory screen. there should not be any other commands under the "Close" keyword
		else CloseList();
	}

	// if the given command is not in this set of common commands
	else keywordFound == false;

	return keywordFound;
}
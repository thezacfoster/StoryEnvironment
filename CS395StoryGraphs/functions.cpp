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

// Clears and closes the narration box.
void Common::CloseNarration()
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
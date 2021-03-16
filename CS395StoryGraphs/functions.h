// File Description: A handful of functions that simplify the execution of common processes in Camelot.

#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace Common
{
	// Pauses execution in the experience manager until the given input message is received from Camelot
	void WaitFor(string msg);

	// Sends a given command to Camelot. If waitForSuccess is true, pauses the experience manager's execution until the command succeeds.
	void Action(string cmd, bool waitForSuccess);

	// Manages the entire process of setting up a character, including appearance, clothing, and position.
	void SetUpCharacter(string name, string bodyType, string clothing, string hairStyle, string hairColor, string position);

	// Prepares dialog display between two given characters. If walkTo is true, the first character will walk to the second's position.
	void SetUpDialog(string firstChar, string secondChar, bool walkTo);

	// Establishes the text and response choices in the current dialog interaction.
	void SetUpDialogText(string message, string responseKey1, string response1, string responseKey2, string response2);

	// Causes given character to exit one location and enter another, allowing transitions between Camelot Places.
	void Transition(string character, string exit, string entrance);

	// Establishes player control of the given character when the "Start" button is pressed at the main menu.
	void PlayerStart(string playerChar);

	// Causes given character to walk to given location.
	void WalkTo(string character, string location);

	// Clears and closes the narration box.
	void CloseNarration();
}
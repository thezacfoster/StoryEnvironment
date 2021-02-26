// File Description: A handful of functions that simplify the execution of common processes in Camelot.

#pragma once
#include <iostream>
#include <string>

using namespace std;

// Pauses execution in the experience manager until the given input message is received from Camelot
void Wait(string msg);

// Sends a given command to Camelot. If waitForSuccess is true, pauses the experience manager's execution until the command succeeds.
void Action(string cmd, bool waitForSuccess);

// Manages the entire process of setting up a character.
void SetUpCharacter(string name, string bodyType, string clothing, string hairStyle, string hairColor, string position)
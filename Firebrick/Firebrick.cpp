#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "Card.h"
#include "Sword.h"
#include "Armour.h"
#include "Spell.h"
#include "Bless.h"
#include "Fireball.h"
#include "Lightning.h"
#include "Minion.h"
#include "Horde.h"
#include "Leech.h"
#include "Trample.h"
#include "Vampire.h"
#include "Wall.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Flag to check for memory leaks

	cout << "Jack Smurthwaite - Firebrick" << endl;

	CGame game;
	game.SeedRandom();											  // Seed the random function
	game.AddPlayers(game.SORCERESS, game.WIZARD);				  // Add players to the game
	game.Shuffle();												  // Ask to shuffle players decks
	game.Play();												  // Play the game
}


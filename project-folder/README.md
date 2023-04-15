This project contains a program to the game "Return of the Snakes"

It counted as an advanced project.

The project contains the following source files:

main.c:
	Contains the entry point main()
	sets up the display, timers and ports that will be used.

functions.c
	Contains the functions that handle the start screen,
	mode select, the interrupts and defines some other useful functions

enemies.c
	Contains the functions that handle the movement of the
	snakes for both gamemodes.

fruit.c
	Contains the functions that handle the generation of the
	fruit in the "collect" gamemode

gameEnd.c
	Contains the functions that are called when the player 
	touches a snake or runs off screen in the "survival" mode, 
	which results in a game end

gameEndless.c
	contains the code for the "survival" gamemode

gameNormal.c
	contains the code for the "normal" gamemode

highscore.c
	Contains the functions that check if your score was high 
	enough to make it onto the leaderboard, and if the score 
	is high enough, you can enter it into the leaderboard 
	along with a 3 letter name

inputs.c
	sets up the buttons to be used as inputs

vectors.S:
	Contains the interrupt handler and the exception handler

stubs.c:
	Contains stubs for functions run during micro controller
	initialization

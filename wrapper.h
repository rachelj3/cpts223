#include "list.h"
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>

typedef struct players
{
	std::string name;
	int points;
}Players;

class Wrapper
{
public:
	/*************************************************************
* Function: Wrapper ()
* Description:  constructs wrapper
* Input parameters: none
* Returns: none
*************************************************************/
	Wrapper();

	/*************************************************************
* Function: ~Wrapper ()
* Description:  destructs wrapper
* Input parameters: none
* Returns: none
*************************************************************/
	~Wrapper();

	/*************************************************************
* Function: playGame ()
* Description:  plays game
* Input parameters: none
* Returns: none
*************************************************************/
	void playGame();

	/*************************************************************
* Function: loadDefFile ()
* Description:  loads in definition files
* Input parameters: none
* Returns: none
*************************************************************/
	void loadDefFile();

	/*************************************************************
* Function: loadSavedGames ()
* Description:  loads in profiles file
* Input parameters: none
* Returns: none
*************************************************************/
	void loadSavedGames();

	/*************************************************************
* Function: insertIntoArray ()
* Description: inserts profile into array
* Input parameters: name, points
* Returns: none
*************************************************************/
	void insertIntoArray(std::string name, int score);

	/*************************************************************
* Function: printMenu ()
* Description:  prints the menu
* Input parameters: none
* Returns: none
*************************************************************/
	void printMenu();

	/*************************************************************
* Function: printRules ()
* Description:  prints rules
* Input parameters: none
* Returns: none
*************************************************************/
	void printRules();

	/*************************************************************
* Function: runGame ()
* Description:  runs the question part of the game
* Input parameters: name, points
* Returns: total points
*************************************************************/
	int runGame(std::string name, int points);

	/*************************************************************
* Function: fetchPoints ()
* Description:  brings back points given name
* Input parameters: name
* Returns: points
*************************************************************/
	int fetchPoints(std::string name);

	/*************************************************************
* Function: dupeChecker()
* Description:  checks for duplicate in array
* Input parameters: checker, array
* Returns: t/f
*************************************************************/
	bool dupeChecker(int checker, int array[]);

	/*************************************************************
* Function:returnRando ()
* Description:  returns random number
* Input parameters: upper bound
* Returns: random number
*************************************************************/
	int returnRando(int bound);

	/*************************************************************
* Function: printDefFile ()
* Description:  prints list to file
* Input parameters: none
* Returns: none
*************************************************************/
	void printDefFile();

	/*************************************************************
* Function: printScoreFile ()
* Description:  prints profiles to file
* Input parameters: none
* Returns: none
*************************************************************/
	void printScoreFile();
	//void insertArray(std::string name, int points);
private:
	List<std::string> linkedList;
	Players savedGames[50];
};

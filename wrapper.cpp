#pragma once
#include "wrapper.h"

/*************************************************************
* Function: Wrapper ()
* Description:  constructs wrapper
* Input parameters: none
* Returns: none
*************************************************************/
Wrapper::Wrapper()
{
	//this->linkedList;
}

/*************************************************************
* Function: ~Wrapper ()
* Description:  destructs wrapper
* Input parameters: none
* Returns: none
*************************************************************/
Wrapper::~Wrapper()
{

}

/*************************************************************
* Function: playGame ()
* Description:  plays game
* Input parameters: none
* Returns: none
*************************************************************/
void Wrapper::playGame()
{
	int gameChoice = 0;
	loadDefFile();
	loadSavedGames();
	std::string addTerm, addDef, delTerm;
	std::string buffer, nameInit, matcher;
	int pointsInit, pointsFinal, index = 0;
	bool dupes;
	while (gameChoice != 6)
	{
		printMenu();
		std::cin >> gameChoice;
		if (gameChoice < 1 || gameChoice > 6)
		{
			system("cls");
			std::cout << "Invalid Choice. Please try again" << std::endl;
			system("pause");
			system("cls");
		}
		else if (gameChoice == 1)
		{
			system("cls");
			printRules();
			system("pause");
			system("cls");
		}
		else if (gameChoice == 2)
		{
			system("cls");
			std::cout << "Enter name:" << std::endl;
			std::getline(std::cin, buffer, '\n');
			std::getline(std::cin, nameInit, '\n');
			pointsFinal = runGame(nameInit, 0); //send off name and zero points to game
			insertIntoArray(nameInit, pointsFinal);
			system("pause");
			system("cls");
		}
		else if (gameChoice == 3)
		{
			system("cls");
			std::cout << "Enter name to pull up points record." << std::endl;
			std::getline(std::cin, buffer, '\n');
			std::getline(std::cin, nameInit, '\n');
			pointsInit = fetchPoints(nameInit);
			pointsFinal = runGame(nameInit, pointsInit);
			index = 0;
			while (this->savedGames[index].name != nameInit)
			{
				++index;
			}
			this->savedGames[index].points = pointsFinal;
			system("pause");
			system("cls");
		}
		else if (gameChoice == 4)
		{
			system("cls");
			//std::cin >> buffer;
			std::cout << "Please enter term to add" << std::endl;
			//std::cin >> buffer;
			std::getline(std::cin, buffer, '\n');
			std::getline(std::cin, addTerm, '\n');
			dupes = this->linkedList.findDuplicate(addTerm);
			if (dupes == false)
			{
				//std::cin >> buffer;
				std::cout << "Please enter definition to add" << std::endl;
				//std::cin >> buffer;
				std::getline(std::cin, addDef, '\n');
				system("pause");
				system("cls");
				this->linkedList.insert(addTerm, addDef);
				std::cout << "Successfully inserted" << std::endl;
			}
			else
			{
				std::cout << "That is a duplicate. Return to main menu" << std::endl;
			}
			system("pause");
			system("cls");
		}
		else if (gameChoice == 5)
		{
			system("cls");
			std::getline(std::cin, buffer, '\n');
			std::cout << "Please enter term to delete" << std::endl;
			//std::cin >> buffer;
			std::getline(std::cin, delTerm, '\n');
			
			dupes = this->linkedList.findDuplicate(delTerm);
			if (dupes == true)
			{
				//std::cin >> buffer;
				system("pause");
				system("cls");
				this->linkedList.deleteTerm(delTerm);
				std::cout << "Successfully deleted" << std::endl;
			}
			else
			{
				std::cout << "That term is not in list. Return to main menu" << std::endl;
			}
			system("pause");
			system("cls");
		}
	}
	printDefFile();
	printScoreFile();
}

/*************************************************************
* Function: loadDefFile ()
* Description:  loads in definition files
* Input parameters: none
* Returns: none
*************************************************************/
void Wrapper::loadDefFile()
{
	std::ifstream infile("defs.csv");
	std::string term, def;
	while (infile.peek() != EOF) // will go till end of file
	{
		std::getline(infile, term, ',');
		std::getline(infile, def, '\n');
		this->linkedList.insert(term, def);
	}
	infile.close();
}

/*************************************************************
* Function: loadSavedGames ()
* Description:  loads in profiles file
* Input parameters: none
* Returns: none
*************************************************************/
void Wrapper::loadSavedGames()
{
	std::ifstream infile("profiles.csv");
	std::string name, intTemp;
	int score;
	while (infile.peek() != EOF) // will go till end of file
	{
		std::getline(infile, name, ',');
		std::getline(infile, intTemp, '\n');
		score = std::stoi(intTemp);
		insertIntoArray(name, score);
	}
	infile.close();
}

/*************************************************************
* Function: insertIntoArray ()
* Description: inserts profile into array
* Input parameters: name, points
* Returns: none
*************************************************************/
void Wrapper::insertIntoArray(std::string name, int score)
{
	Players temp;
	int index = 0;
	if (this->savedGames[0].name == "")
	{
		//no profiles saved
		this->savedGames[0].name = name;
		this->savedGames[0].points = score;
	}
	else
	{
		//profiles already in array
		while (this->savedGames[index+1].name != "")
		{
			//travel to end index of array
			++index;
		}
		while (index != -1)
		{
			this->savedGames[index + 1].name = this->savedGames[index].name;
			this->savedGames[index + 1].points = this->savedGames[index].points;
			--index;
		}
		this->savedGames[0].name = name;
		this->savedGames[0].points = score;
	}
}

/*************************************************************
* Function: printMenu ()
* Description:  prints the menu
* Input parameters: none
* Returns: none
*************************************************************/
void Wrapper::printMenu()
{
	std::cout << "Main Menu: Please select an option below" << std::endl;
	std::cout << "1. Display Rules" << std::endl;
	std::cout << "2. Play Game" << std::endl;
	std::cout << "3. Load Previous Game" << std::endl;
	std::cout << "4. Add Command" << std::endl;
	std::cout << "5. Remove Command" << std::endl;
	std::cout << "6. Exit" << std::endl;
}

/*************************************************************
* Function: printRules ()
* Description:  prints rules
* Input parameters: none
* Returns: none
*************************************************************/
void Wrapper::printRules()
{
	std::cout << "Rules:" << std::endl;
	std::cout << "1. You will be given a term. Find and enter the correct definition" << std::endl;
	std::cout << "2. For each correct term you will earn one point. Your points can be loaded in from previous games" << std::endl;
	std::cout << "3. Once you have answered all the questions you requested, you will be brought back to the main menu" << std::endl;
}

/*************************************************************
* Function: runGame ()
* Description:  runs the question part of the game
* Input parameters: name, points
* Returns: total points
*************************************************************/
int Wrapper::runGame(std::string name, int points)
{
	std::string placeholder;
	int questionCount = 0, index = 0, rando = 0, innerIndex = 0, answer = 0;
	bool checker = true;
	int questionArray[30] = { 0 }, choicesArray[3] = {0}, orderArray[3] = {0};
	while (questionCount < 5 || questionCount > 30)
	{
		std::cout << "How many Questions would you like to recieve? (5-30)" << std::endl;
		std::getline(std::cin, placeholder, '\n');
		questionCount = stoi(placeholder);
	}

	for (index = 0; index < questionCount; ++index)
	{
		checker = true;
		while (checker == true)
		{
			rando = returnRando(30);
			checker = dupeChecker(rando, questionArray);
		}
		//not a duper
		questionArray[index] = rando;
	}
	//question array should be filled
	for (index = 0; index < questionCount; ++index)
	{
		std::cout << "Name: " << name << "                                 Score: " << points << std::endl;
		//array will run for all questions asked for 
		//this->linkedList.printTermByIndex(questionArray[index]);
		// add chosen question to the choices array
		choicesArray[0] = 0;
		choicesArray[1] = 0;
		choicesArray[2] = 0;
		choicesArray[0] = questionArray[index];
		for (innerIndex = 1; innerIndex < 3; ++innerIndex)
		{
			checker = true;
			while (checker == true)
			{
				rando = returnRando(questionCount); // will give two more random defitions
				checker = dupeChecker(rando, choicesArray);
			}
			//not a duper
			choicesArray[innerIndex] = rando;
		}
		orderArray[0] = 0;
		orderArray[1] = 0;
		orderArray[2] = 0;
		for (innerIndex = 0; innerIndex < 3; ++innerIndex)
		{
			checker = true;
			while (checker == true)
			{
				rando = returnRando(3);
				checker = dupeChecker(rando, orderArray);
			}
			//not a duper
			orderArray[innerIndex] = rando;

		}
		//after all the randomizing has been done
		std::cout << "Question " << index + 1 << ":" << std::endl;
		this->linkedList.printTermByIndex(questionArray[index]);
		std::cout << "1. " << std::endl;
		this->linkedList.printDefByIndex(choicesArray[orderArray[0]-1]);
		std::cout << "2. " << std::endl;
		this->linkedList.printDefByIndex(choicesArray[orderArray[1]-1]);
		std::cout << "3. " << std::endl;
		this->linkedList.printDefByIndex(choicesArray[orderArray[2]-1]);
		std::cout << "Please enter the correct answer: " << std::endl;
		std::getline(std::cin, placeholder, '\n');
		answer = stoi(placeholder);
		if (answer == 1 && choicesArray[orderArray[0] - 1] == questionArray[index])
		{
			std::cout << "Correct!:" << std::endl;
			++points;
		}
		else if (answer == 2 && choicesArray[orderArray[1] - 1] == questionArray[index])
		{
			std::cout << "Correct!" << std::endl;
			++points;
		}
		else if (answer == 3 && choicesArray[orderArray[2] - 1] == questionArray[index])
		{
			std::cout << "Correct!" << std::endl;
			++points;
		}
		else
		{
			std::cout << "Incorrect." << std::endl;
			--points;
		}
		system("pause");
		system("cls");
	}
	return points;
}

/*************************************************************
* Function: fetchPoints ()
* Description:  brings back points given name
* Input parameters: name
* Returns: points
*************************************************************/
int Wrapper::fetchPoints(std::string name)
{
	int index = 0;
	while (this->savedGames[index].name != name)
	{
		++index;
	}
	return this->savedGames[index].points;
}

/*************************************************************
* Function: dupeChecker()
* Description:  checks for duplicate in array
* Input parameters: checker, array
* Returns: t/f
*************************************************************/
bool Wrapper::dupeChecker(int checker, int array[])
{
	int index = 0, flag = 0;
	//flag 1 means dupe, flag 0 means none
	while (array[index] != 0) //zero means spot not filled
	{
		if (array[index] == checker)
		{
			flag = 1;
		}
		++index;
	}
	if (flag == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*************************************************************
* Function:returnRando ()
* Description:  returns random number
* Input parameters: upper bound
* Returns: random number
*************************************************************/
int Wrapper::returnRando(int bound)
{
	return rand() % ((bound - 1) + 1) + 1;
}

/*************************************************************
* Function: printDefFile ()
* Description:  prints list to file
* Input parameters: none
* Returns: none
*************************************************************/
void Wrapper::printDefFile()
{
	std::ofstream outfile;
	outfile.open("defs.csv");
	Node<std::string>* pCur = this->linkedList.getpList();
	while (pCur != nullptr)
	{
		outfile << pCur->getTerm() << ", " << pCur->getDef() << std::endl;
		pCur = pCur->getNext();
	}
	outfile.close();
}

/*************************************************************
* Function: printScoreFile ()
* Description:  prints profiles to file
* Input parameters: none
* Returns: none
*************************************************************/
void Wrapper::printScoreFile()
{
	std::ofstream outfile;
	outfile.open("profiles.csv");
	int index = 0;
	while (this->savedGames[index].name != "")
	{
		outfile << this->savedGames[index].name << ", " << this->savedGames[index].points << std::endl;
		++index;
	}
	outfile.close();
}


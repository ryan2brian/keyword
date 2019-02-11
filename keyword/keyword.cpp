
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;
//My words:
//White
//Tango 
//Buddy
//Microwave
//Charlie 
//Water
//Plumber 
//Sting 
//Covert 
//Frosted 


int main()
{
	char playAgain;
	int Num = 0;
	const int MAX_WRONG = 10;

	//Display Title of program to user
	cout << "Welcome to Keywords" << endl;
	// Ask the recruit to login using thier name
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	cout << "Enter your Name: " << endl;
	string login; //This string stores the users name
	cin >> login;
	// Display an overview of what Keywords II is to the recruit 
	cout << "Hello" << login << endl;
	cout << "Welcome to Keywords 2!\n";
	// Display an directions to the recruit on how to use Keywords
	cout << "\n\nThe way the game works is it's similar to hang man.";
	cout << "You will have 10 attempts to guess 3 words.";
	cout << "Good Luck!\n";

	// Create a collection of 10 words you had wrote down manually
	vector <string> words;
	words.push_back("White");
	words.push_back("Tango");
	words.push_back("Buddy");
	words.push_back("Microwave");
	words.push_back("Charlie");
	words.push_back("Water");
	words.push_back("Plumber");
	words.push_back("Sting");
	words.push_back("Covert ");
	words.push_back("Frosted");

	do
	{
		//     Increment the number of simiulations ran counter (This will set our previous 0 to 1)
		Num++;
		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(words.begin(), words.end());

		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		// The list was already shuffled with the vector function random_shuffle, so we just choose the first 3 words from that list instead of creating a list to hold the 3 words randomly selected.
		for (int i = 0; i < 3; ++i)
		{
			const string WORD = words[i]; // word to guess
			int wrong = 0;                // number of incorrect guesses
			string soFar(WORD.size(), '-'); // word guessed so far
			string used = "";               // letters already guessed

											// recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
			while ((wrong < MAX_WRONG) && (soFar != WORD))
			{
				// Display the simulation # is staring to the recruit. 
				cout << "This is simulation #" << Num << endl;
				cout << "************************" << endl;
				//     Tell recruit how many incorrect guesses he or she has left
				cout << "\n\nYou have " << (MAX_WRONG - wrong) << " tries remaining.\n";
				cout << "****************************" << endl;
				//     Show recruit the letters he or she has guessed
				cout << "\nYou've used the following letters:\n" << used << endl;
				//     Show player how much of the secret word he or she has guessed
				cout << "\nSo far, the word is:\n" << soFar << endl;
				//Get recruit's next guess

				char guess;
				cout << "\n\nEnter your guess: ";
				cin >> guess;
				guess = toupper(guess); //make uppercase since our secret words in uppercase

										//While recruit has entered a letter that he or she has already guessed
				while (used.find(guess) != string::npos)
				{
					//Get recruit ’s guess
					cout << "\nYou've already guessed " << guess << endl;
					cout << "Enter your guess: ";
					cin >> guess;
					guess = toupper(guess);
				}
				//Add the new guess to the group of used letters
				used += guess;
				//If the guess is in the secret word
				if (WORD.find(guess) != string::npos)
				{
					//tells the recruit the guess is correct
					cout << "That's right! " << login << " " << guess << " is in the word.\n";

					// update soFar to include newly guessed letter
					for (unsigned int i = 0; i < WORD.length(); ++i)
					{
						if (WORD[i] == guess)
						{
							soFar[i] = guess;
						}
					}
				}
				//     Otherwise
				else
				{
					//          Tell the recruit the guess is incorrect
					cout << "Sorry, " << login << " " << guess << " isn't in the word.\n";
					//          Increment the number of incorrect guesses the recruit has made
					++wrong;
				}
			}

			// If the recruit has made too many incorrect guesses
			if (wrong == MAX_WRONG)
				//     Tell the recruit that he or she has failed the Keywords II course.
				cout << login << "\nYou've failed the simulation!";
			// Otherwise
			else
				//     Congratulate the recruit on guessing the secret words
				cout << "\nCongratulations" << login << " you have guessed the secret word!";

			cout << "\nThe word was " << WORD << endl;
		}
		// Ask the recruit if they would like to run the simulation again
		cout << login << "Would you like to run the simulation again? Y/N";
		cin >> playAgain;
		playAgain = toupper(playAgain);
		// If the recruit wants to run the simulation again
		// Move program execution back up to // Display the simulation # is staring to the recruit. 
		// Otherwise 
		// Display End of Simulations to the recruit
		// The above 4 comments are all taken care of with this one Do While loop.
	} while (playAgain == 'Y');
	system("pause");
	return 0;
}

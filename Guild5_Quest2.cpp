
#include <iostream>

using namespace std;



struct Sentinel {
	string name;
	string greeting;
	string introDialogue;
	string question;

	string trueAnswer;
	string falseAnswer;

	string correctLine;
	string wrongLine;

	string getYesNoValidation;
};


Sentinel list:
- Lion
- Cheetah/cat
- Horse
- Wolf

Other possible choices
- Snake
- Fox
- Tiger
- Spider
- Bear
- Turtle.Tortoise
- Bull
- Rhino
*/



/* TO-DO List
- Finish personal sentinel dialogue

- Add dialogue for when the player walks to the next sentinel rather than just going straight to the next 
sentinel's script

- Add dialogue for when the player has encountered all sentinels in the path they chose (Ex. You have 
encountered all the sentinels in this path. You head back to the start.) We can also introduce the "start" as having an actual 
name, like the type of room it is or having a sign that names it rather than just calling it the start.

- The conditions for winning should probably include finishing the whole labyrinth and then revealing 
at the end whether the player answered enough questions right
*/

Sentinel sentinels[8] = {
	{
		"The Crimson Lion", // Aiso
		"A statue resembling a lion rumbles and studies you...",
		"[Intro Dialogue]",
		"What is Aiso's favorite color?",
		"Red.",
		"Black.",
		"You are correct. The stone grunts approvingly. You have obtained a key.",
		"You are mistaken. The stone grumbles.",
		"[getYesNoValidation]"
	},
	{
		"The ___ Cheetah", // Gabby
		"A sharp-eyed sentinel watches you...",
		"[Intro Dialogue]",
		"What is Gabby's favorite color?",
		"Blue.",
		"Black.",
		"[correctLine].",
		"[wrongLine]",
		"[getYesNoValidation]"
	},
	{    // can also use Steed or something similar rather than Horse
		"The __ Horse", // Emeka
		"[greeting]",
		"[Intro Dialogue]...",
		"What is Emeka's favorite hobby?",
		"Running.",
		"Painting.",
		"[correctLine]",
		"[wrongLine]",
		"[getYesNoValidation]"
	},
	{
		"The Midnight Snake", // Amolika
		"Welcome, wanderer. Beware… the snake watches all.",
        "Few dare tread these shadowed paths… and fewer still encounter the serpent that dwells within. Speak carefully, for the snake senses truth from lies.",
		"What is Amolika's dream travel destination?",
		"Japan.",
		"Europe.",
		"Ah ha! You are correct. Darkness whispers its approval.",
		"Uh oh.. you're mistaken! The shadows frown, your answer fails to satisfy the snake.",
		"Give an answer"
	},
	{
		"The ____ ____", // Hania
		"[greeting]",
		"[Intro Dialogue]",
		"What sport does Hania play?",
		"Cricket.",
		"Baseball.",
		"[correctLine]",
		"You answer false, and it rumbles unfavorably.",
		"[getYesNoValidation]"
	},
	{
		"The ____ ____" // Kripa
		"[greeting]",
		"[Intro Dialogue]",
		"What is Kripa's favorite pastime?",
		"Dance.",
		"Reading books.",
		"[correctLine].",
		"[wrongLine]",
		"[getYesNoValidation]"
	},
	{
		"The Ashen Wolf", // Adrian
		"[greeting]",
		"[Intro Dialogue]..."
		"What is Adrian's favorite color?",
		"Green",
		"Black",
		"[correctLine]",
		"[wrongLine]",
		"[getYesNoValidation]"
	},
	{
		"The ____ ____", // Caitlyn
	    "[greeting]",
	    "[Intro Dialogue]...",
		"What instrument does Caitlyn play?",
		"Violin.",
		"Piano.",
		"Well done; you perceived the truth.",
		"Alas, you have been deceived.",
		"[getYesNoValidation]"
	}
};




// Intro story
void showIntro() {
	cout << "You wake up in a dark labyrinth, its crumbling hallways lined with torches of blue flame," << endl; 
	cout << "and the sound of water dripping echoes around you..." << endl;
	cout << "You have no idea how you got here but you know you have to find a way out." << endl;
}

// Win ending
void showWin() {
	cout << "\nCongratulations, traveler. You have successfully made your way through the labyrinth and have obtained enough keys to open the gate.\n";
}

// Lose ending
void showLose() {
	cout << "\nYou have reached the end of the labyrinth with less than 5 questions answered correctly. You have failed." << endl;
}



// Validate sentinel/path choice
int getValidNumber(int min, int max) {
	int choice;
	cin >> choice;

	// TODO:
	// - Loop until valid number
	// - Handle invalid input
	if (choice < min || choice > max) {
		cout << "Please enter a number between " << min << " and " << max << ": ";
		return getValidNumber(min, max);   // Recursively ask again
	}

	return choice;
}

// Validate Yes/No input
string getYesNo(int index) {
	string input;
	cin >> input;

	// TODO:
	// - Ensure only "yes" or "no"
	// - Keep asking if invalid
	if (input != "Yes" && input != "No" && input != "yes" && input != "no") {
		cout << sentinels[index].getYesNoValidation << endl;
		cout << "Do you believe this to be true? (Yes/No): ";
		return getYesNo(index);   // Recursively ask again
	}


	return input;
}



// Handles ONE sentinel interaction
bool encounterSentinel(int index) {

	// Print greeting
	cout << "\n" << sentinels[index].greeting << endl;
	
	
	cout << "\n" << sentinels[index].introDialogue << endl;

	// Ask question
	cout << "\nYou ask the question: " << sentinels[index].question << endl;

	// Random truth or lie
	int isTruth = rand() % 2;

	string answer;

	if (isTruth == 0) {
		answer = sentinels[index].trueAnswer;
	} else if (isTruth == 1) {
		answer = sentinels[index].falseAnswer;
	}

	cout << "The sentinel says: " << answer << endl;

	// Ask player
	cout << "Do you believe this to be true? (Yes/No): ";
	string guess = getYesNo(index);

	// TODO:
	// - Check if player is correct
	// - Print correctLine or wrongLine
    bool correct = false;

    if (guess == "Yes" || guess == "yes") {
		if (isTruth == 0) {
			cout << sentinels[index].correctLine << endl;
			correct = true;
		} else {
			cout << sentinels[index].wrongLine << endl;
		}
	} else if (guess == "No" || guess == "no") {
		if (isTruth == 1) {
			cout << sentinels[index].correctLine << endl;
			correct = true;
		} else {
			cout << sentinels[index].wrongLine << endl;
		}
	}

	return correct;
}


// Each row = path
// Each number = sentinel index
int paths[3][3] = {
	{0, 1, -1},   // Path 1
	{2, 3, 4},    // Path 2
	{5, 6, 7}     // Path 3
};

// Track visited paths
bool pathUsed[3] = {false, false, false};


int choosePath() {

	cout << "\nThree doors lay before you, each leading to a different path. Choose a door:\n";
	cout << "1. Left Path\n2. Middle Path\n3. Right Path\n" << endl;

	int choice = getValidNumber(1, 3);
	int index = choice - 1;

	// Prevent choosing the same path twice
	if (pathUsed[index]) {
		cout << "\nYou already took that path. Choose a different one.\n";
		return choosePath();   // Recursively ask again
	}

	pathUsed[index] = true;   // Mark path as used
	return index;
}

int main() {

	srand(time(0));

	// Game tracking
	int score = 0;
	int questionsAsked = 0;

	// TODO:
	// - initialize sentinel data (call function if needed)

	showIntro();

	int pathsRemaining = 3;

	// MAIN LOOP
	while (score < 5 && pathsRemaining > 0) {

		int chosenPath = choosePath();

		// Mark path used
		pathUsed[chosenPath] = true;
		pathsRemaining--;

		cout << "\nYou walk down the path...\n";

		// Loop through sentinels in path
		for (int i = 0; i < 3; i++) {

			int sentinelIndex = paths[chosenPath][i];

			if (sentinelIndex == -1) continue;

			bool result = encounterSentinel(sentinelIndex);

			questionsAsked++;

			if (result) {
				score++;
			}

			cout << "[Score: " << score << "/5]\n";

			// Optional: break early if win
		}
	}

	// ENDING
	if (score >= 5) {
		showWin();
	} else {
		showLose();
	}

	// Optional: print stats
	cout << "\nQuestions Asked: " << questionsAsked << endl;

	return 0;
}

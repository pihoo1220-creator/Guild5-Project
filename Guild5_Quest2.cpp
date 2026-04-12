#include <iostream>
#include <cstdlib>
#include <ctime>

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

Sentinel sentinels[8] = {

    //  Aiso
    {
        "The Crimson Lion",
        "A towering stone lion draped in deep red etches its gaze into you. The air grows heavy.",
        "I am the Crimson Lion. I have stood at this threshold since the first flame was lit. "
        "Many have tried to pass me with guesswork alone. They did not fare well. "
        "I will speak a truth or a lie — it is yours to decide which.",
        "What is Aiso's favorite type of video game?",
        "First-person shooter.",   // true answer
        "Strategy.",               // false answer
        "The lion's mane shimmers red. \"You see clearly, traveler.\" A key clatters to the floor.",
        "The lion exhales a low, rumbling growl. \"You have misjudged. The stone does not forget.\"",
        "Answer with Yes or No, nothing more."
    },

    //  Gabby 
    {
        "The Cerulean Cheetah",
        "A sleek stone cheetah, streaked with brilliant blue, snaps its head toward you with unsettling speed.",
        "Swift. Precise. Unforgiving. That is what I am, and that is what this passage demands of you. "
        "I speak one statement — true or false, you decide. Hesitation is the same as being wrong.",
        "What language did Gabby study for four years?",
        "American Sign Language.",   // true answer
        "French.",                   // false answer
        "The cheetah's blue markings gleam. \"Fast and correct. You may pass.\" A key slides toward you.",
        "\"Slow and wrong.\" The cheetah turns away with a flick of its stone tail.",
        "Answer with Yes or No, nothing more."
    },

    //  Emeka 
    {
        "The Emerald Steed",
        "The corridor trembles as a great green stone horse stamps once and raises its head to face you.",
        "I am the Emerald Steed, and I respect only those with endurance. "
        "The path ahead is long — are you the type to keep moving, or to stop when it gets hard? "
        "Answer my challenge and prove you belong here.",
        "What is Emeka's favorite hobby?",
        "Running.",    // true answer
        "Swimming.",   // false answer
        "The steed snorts and stamps again, this time with approval. \"You kept pace. Well done.\" A key drops.",
        "The horse shakes its stone mane slowly. \"You stumbled. The path remembers those who do.\"",
        "Answer with Yes or No, nothing more."
    },

    //  Amolika 
    {
        "The Midnight Snake",
        "Welcome, wanderer... the snake has been expecting you.",
        "Few dare walk these shadow-drenched corridors... and fewer still leave unchanged. "
        "I am ancient. I am patient. I have watched a thousand travelers convince themselves they knew the answer. "
        "Most were wrong. Speak carefully — the serpent senses hesitation as easily as lies.",
        "What is Amolika's dream travel destination?",
        "Japan.",    // true answer
        "Italy.",    // false answer
        "The darkness seems to exhale. \"Yesss... you have seen through the veil.\" A key emerges from the shadows.",
        "A slow, cold hiss fills the corridor. \"Interesting guess. Incorrect, but... interesting.\"",
        "Answer with Yes or No, nothing more."
    },

    //  Hania 
    {
        "The Ashen Lion",
        "A grey stone lion regards you with calm, ancient authority. It does not move. It does not need to.",
        "I am patience carved into stone. I have watched empires rise and crumble from this very spot. "
        "I will not rush you — but I will not repeat myself either. "
        "Listen closely. Decide wisely.",
        "What sport does Hania play?",
        "Cricket.",    // true answer
        "Tennis.",     // false answer
        "The ashen lion closes its eyes briefly. \"A composed answer. You have earned your key.\"",
        "The lion opens one eye wider. \"That was not composure. That was a guess. There is a difference.\"",
        "Answer with Yes or No, nothing more."
    },

    //  Kripa 
    {
        "The Lavender Hare",
        "A small stone hare with pale violet markings peeks out from behind a crumbled pillar, ears flat.",
        "O-oh... you found me. I didn't think anyone would come down this path so soon. "
        "I'm supposed to ask you something — and I will, I promise — I just... "
        "please don't laugh if I seem nervous. I take my duty seriously, even if I don't look it.",
        "What is Kripa's favorite pastime?",
        "Dance.",      // true answer
        "Painting.",   // false answer
        "The hare's ears perk straight up. \"You got it right! I knew you would — well, I hoped.\" "
        "It nudges a key toward you with its nose.",
        "The hare's ears droop. \"Oh... that wasn't it. That's okay. I'm not upset. I'm fine. Really.\"",
        "Answer with Yes or No, nothing more."
    },

    //  Adrian 
    {
        "The Ashen Wolf",
        "A grey stone wolf steps from the shadows, unhurried. Its eyes hold something colder than stone.",
        "The pack watches every corridor in this labyrinth. We have seen what you did at the last sentinel. "
        "We remember everything. I ask my question once. "
        "The wolf does not repeat itself for those who weren't paying attention.",
        "What is Adrian's favorite color?",
        "Green.",    // true answer
        "Black.",    // false answer
        "The wolf holds your gaze a moment longer than comfortable, then dips its head. "
        "\"Correct. The pack acknowledges you.\" A key drops at its paws.",
        "The wolf exhales slowly through its nose. \"Wrong. The pack has noted it.\" It steps back into the dark.",
        "Answer with Yes or No, nothing more."
    },

    // Caitlyn 
    {
        "The Sly Fox",
        "You feel sharp eyes on you before you even see the fox. It steps into the torchlight wearing a thin smile.",
        "Ah, a new face. How refreshing. I do so enjoy these little conversations — "
        "they never quite go the way people expect. "
        "I'll tell you something. Whether it's the truth or a clever misdirection... well, "
        "that's rather the whole point, isn't it? Answer my question correctly and I will let you pass.",
        "What instrument does Caitlyn play?",
        "Viola.",    // true answer
        "Violin.",   // false answer
        "The fox tilts its head, looking almost impressed. "
        "\"Well done. You perceived the truth beneath the trick. A rare quality.\" A key spins across the floor.",
        "The fox lets out a quiet, delighted laugh. \"Alas, you have been deceived. "
        "Don't feel too bad — most are.\"",
        "Answer with Yes or No, nothing more."
    }

};


//  Intro / endings 

void showIntro() {
    cout << "\nYou wake up in a dark labyrinth, its crumbling hallways lined with torches of blue flame." << endl;
    cout << "The sound of water dripping echoes somewhere in the dark." << endl;
    cout << "You have no idea how you got here — but you know you must find a way out." << endl;
    cout << "Scattered throughout the labyrinth are stone sentinels. Each will speak a statement." << endl;
    cout << "Decide whether it is true or false. Collect 5 keys to open the gate.\n" << endl;
}

void showWin() {
    cout << "\nThe gate groans, shudders, and swings open." << endl;
    cout << "Cool air rushes in from beyond. You step through, keys in hand." << endl;
    cout << "Congratulations, traveler. The labyrinth has been conquered.\n" << endl;
}

void showLose() {
    cout << "\nYou stand before the great gate. You reach for the lock." << endl;
    cout << "It does not move." << endl;
    cout << "You have collected fewer than 5 keys. The labyrinth keeps you a little longer.\n" << endl;
}


// Input validation 

int getValidNumber(int min, int max) {
    int choice;

    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        return getValidNumber(min, max);
    }

    if (choice < min || choice > max) {
        cout << "Please enter a number between " << min << " and " << max << ": ";
        return getValidNumber(min, max);
    }

    return choice;
}

string getYesNo(int index) {
    string input;
    cin >> input;

    for (char& c : input) c = tolower(c);

    if (input != "yes" && input != "no") {
        cout << sentinels[index].getYesNoValidation << endl;
        cout << "Do you believe this to be true? (Yes/No): ";
        return getYesNo(index);
    }

    return input;
}


// Sentinel encounter 

bool encounterSentinel(int index) {

    cout << "\n----------------------------------------" << endl;
    cout << "  " << sentinels[index].name << endl;
    cout << "----------------------------------------" << endl;

    cout << "\n" << sentinels[index].greeting << endl;
    cout << "\n" << sentinels[index].introDialogue << endl;

    int isTruth = rand() % 2;   // 0 = truth, 1 = lie
    string answer = (isTruth == 0) ? sentinels[index].trueAnswer
                                   : sentinels[index].falseAnswer;

    cout << "\nThe sentinel says: \"" << sentinels[index].question
         << " " << answer << "\"" << endl;

    cout << "\nDo you believe this to be true? (Yes/No): ";
    string guess = getYesNo(index);

    bool playerSaysYes     = (guess == "yes");
    bool sentinelToldTruth = (isTruth == 0);
    bool correct           = (playerSaysYes == sentinelToldTruth);

    cout << "\n";
    if (correct) {
        cout << sentinels[index].correctLine << endl;
    } else {
        cout << sentinels[index].wrongLine << endl;
    }

    return correct;
}


// Paths & path selection 

int paths[3][3] = {
    {0, 1, -1},   // Left Path   — Aiso, Gabby
    {2, 3,  4},   // Middle Path — Emeka, Amolika, Hania
    {5, 6,  7}    // Right Path  — Kripa, Adrian, Caitlyn
};

bool pathUsed[3] = {false, false, false};

int choosePath() {
    cout << "\nThree doors stand before you, each leading somewhere different." << endl;
    cout << "1. Left Path\n2. Middle Path\n3. Right Path\n";

    int choice = getValidNumber(1, 3);
    int index  = choice - 1;

    if (pathUsed[index]) {
        cout << "\nYou have already walked that path. The torches there burn low. Choose another.\n";
        return choosePath();
    }

    return index;
}


//  Main 

int main() {

    srand(static_cast<unsigned int>(time(0)));

    int score          = 0;
    int questionsAsked = 0;
    int pathsRemaining = 3;

    showIntro();

    time_t startTime = time(0);   // Start the clock once the game begins

    while (score < 5 && pathsRemaining > 0) {

        int chosenPath = choosePath();
        pathUsed[chosenPath] = true;
        pathsRemaining--;

        cout << "\nYou step through the door. The stone closes behind you.\n";

        for (int i = 0; i < 3; i++) {

            int sentinelIndex = paths[chosenPath][i];

            if (sentinelIndex == -1) {
                cout << "\nThe corridor stretches quietly here. No sentinel guards this stretch — only silence.\n";
                continue;
            }

            bool result = encounterSentinel(sentinelIndex);
            questionsAsked++;

            if (result) score++;

            cout << "\n[Keys collected: " << score << " / 5]\n";

            if (score >= 5) break;
        }

        if (score >= 5) break;

        if (pathsRemaining > 0) {
            cout << "\nYou find your way back to the entrance chamber.\n";
        } else {
            cout << "\nYou have walked every path the labyrinth offers.\n";
        }
    }

    cout << "\n========================================" << endl;

    if (score >= 5) {
        showWin();
    } else {
        showLose();
    }

    int elapsedSeconds = static_cast<int>(time(0) - startTime);
    int minutes        = elapsedSeconds / 60;
    int seconds        = elapsedSeconds % 60;

    cout << "Keys collected : " << score          << " / 5"    << endl;
    cout << "Questions faced: " << questionsAsked              << endl;
    cout << "Time taken     : " << minutes << "m " << seconds << "s" << endl;
    cout << "========================================\n"        << endl;

    return 0;
}

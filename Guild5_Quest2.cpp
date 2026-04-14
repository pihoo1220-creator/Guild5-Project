/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <chrono>    //time

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
    { "The Crimson Lion",       //aiso
        "A towering stone lion draped in deep red etches its gaze into you. The air grows heavy.",
        "I am the Crimson Lion. I have stood at this threshold since the first flame was lit. "
        "Many have tried to pass me with guesswork alone. They did not fare well. "
        "I will speak a truth or a lie — it is yours to decide which.",
        "What is Aiso's favorite type of video game?",
        "First-person shooter.",   // true answer
        "Strategy.",               // false answer
        "The lion's mane shimmers red. \"You see clearly, traveler.\" A key clatters to the floor.",
        "The lion exhales a low, rumbling growl. \"You have misjudged. The stone does not forget.\"",
        "Answer with Yes or No, nothing more." },

    { "The Cerulean Cheetah",          //gabby
        "A sleek stone cheetah, streaked with brilliant blue, snaps its head toward you with unsettling speed.",
        "Swift. Precise. Unforgiving. That is what I am, and that is what this passage demands of you. "
        "I speak one statement — true or false, you decide. Hesitation is the same as being wrong.",
        "What language did Gabby study for four years?",
        "American Sign Language.",   // true answer
        "French.",                   // false answer
        "The cheetah's blue markings gleam. \"Fast and correct. You may pass.\" A key slides toward you.",
        "\"Slow and wrong.\" The cheetah turns away with a flick of its stone tail.",
        "Answer with Yes or No, nothing more."  },

    { "The Emerald Steed",             //emeka
        "The corridor trembles as a great green stone horse stamps once and raises its head to face you.",
        "I am the Emerald Steed, and I respect only those with endurance. "
        "The path ahead is long — are you the type to keep moving, or to stop when it gets hard? "
        "Answer my challenge and prove you belong here.",
        "What is Emeka's favorite hobby?",
        "Running.",    // true answer
        "Swimming.",   // false answer
        "The steed snorts and stamps again, this time with approval. \"You kept pace. Well done.\" A key drops.",
        "The horse shakes its stone mane slowly. \"You stumbled. The path remembers those who do.\"",
        "Answer with Yes or No, nothing more." },

    { "The Midnight Snake",        //amolika
        "Welcome, wanderer... the snake has been expecting you.",
        "Few dare walk these shadow-drenched corridors... and fewer still leave unchanged. "
        "I am ancient. I am patient. I have watched a thousand travelers convince themselves they knew the answer. "
        "Most were wrong. Speak carefully — the serpent senses hesitation as easily as lies.",
        "What is Amolika's dream travel destination?",
        "Japan.",    // true answer
        "Italy.",    // false answer
        "The darkness seems to exhale. \"Yesss... you have seen through the veil.\" A key emerges from the shadows.",
        "A slow, cold hiss fills the corridor. \"Interesting guess. Incorrect, but... interesting.\"",
        "Answer with Yes or No, nothing more." },

    { "The Ashen Lion",          //hania
        "A grey stone lion regards you with calm, ancient authority. It does not move. It does not need to.",
        "I am patience carved into stone. I have watched empires rise and crumble from this very spot. "
        "I will not rush you — but I will not repeat myself either. "
        "Listen closely. Decide wisely.",
        "What sport does Hania play?",
        "Cricket.",    // true answer
        "Tennis.",     // false answer
        "The ashen lion closes its eyes briefly. \"A composed answer. You have earned your key.\"",
        "The lion opens one eye wider. \"That was not composure. That was a guess. There is a difference.\"",
        "Answer with Yes or No, nothing more." },

    { "The Lavender Hare",          //kripa
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
        "Answer with Yes or No, nothing more." },

    { "The Ashen Wolf",      //adrian
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
        "Answer with Yes or No, nothing more." },

    { "The Sly Fox",           //caitlyn
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
        "Answer with Yes or No, nothing more." }
};

// GLOBAL TRACKERS
int wrongAnswers = 0;
int score = 0;
const int maxWrong = 4;

// INTRO / ENDINGS
void showIntro() {
    cout << "\nYou wake up in a dark labyrinth, its crumbling hallways lined with torches of blue flame." << endl;
    cout << "The sound of water dripping echoes somewhere in the dark." << endl;
    cout << "You have no idea how you got here — but you know you must find a way out." << endl;
    cout << "Scattered throughout the labyrinth are stone sentinels. Each will speak a statement." << endl;
    cout << "Decide whether it is true or false. Collect 5 keys to open the gate.\n" << endl;
    cout << "BEWARE Though, If you get 4 wrong answers, you will be stuck in Labyrinth and must try to find the way again.\n" << endl;
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

// YES/NO INPUT
string getYesNo(int index) {
    string input;
    cin >> input;

    for (char &c : input) c = tolower(c);

    if (input != "yes" && input != "no") {
        cout << sentinels[index].getYesNoValidation << endl;
        return getYesNo(index);
    }
    return input;
}

// SENTINEL ENCOUNTER
bool encounterSentinel(int index) {

    cout << "\n" << sentinels[index].name << endl;
    cout << sentinels[index].greeting << endl;
    cout << sentinels[index].introDialogue << endl;

    int isTruth = rand() % 2;
    string answer = (isTruth == 0)
        ? sentinels[index].trueAnswer
        : sentinels[index].falseAnswer;

    // FIX: PLAYER IS ASKING
    cout << "\nYou ask: " << sentinels[index].question << endl;

    cout << "Sentinel responds: \"" << answer << "\"\n";

    cout << "Do you believe this is true? (Yes/No): ";
    string guess = getYesNo(index);

    bool playerSaysYes = (guess == "yes");
    bool correct = (playerSaysYes == (isTruth == 0));

    if (correct) cout << sentinels[index].correctLine << endl;
    else cout << sentinels[index].wrongLine << endl;

    return correct;
}

auto startTime = chrono::high_resolution_clock::now();

int main() {

    srand(time(0));

    showIntro();

    vector<int> pool = {0,1,2,3,4,5,6,7};
    random_shuffle(pool.begin(), pool.end());

    vector<int> pathA(pool.begin(), pool.begin() + 3);
    vector<int> pathB(pool.begin() + 3, pool.begin() + 6);
    vector<int> pathC(pool.begin() + 6, pool.end());

    vector<vector<int>> paths = {pathA, pathB, pathC};

    bool used[3] = {false, false, false};
    int pathsLeft = 3;

    while (score < 5 && pathsLeft > 0) {

        int choice;

        while (true) {
          cout << "\nChoose pathway to take (1-3): ";
          cout << "\n1. Left Path ";
          cout << "\n2. Middle Path ";
          cout << "\n3. Right Path ";

        if (!(cin >> choice)) {
          cin.clear();
          cin.ignore(1000, '\n');
          cout << "Invalid input.\n";
          continue;
        }

        if (choice >= 1 && choice <= 3 && !used[choice - 1]) break;

    cout << "Uh oh! you just used this, Try another.\n";
        }

        int p = choice - 1;
        used[p] = true;
        pathsLeft--;

        cout << "\nYou enter the corridor...\n";

        for (int idx : paths[p]) {

            bool result = encounterSentinel(idx);

            if (result) score++;
            else wrongAnswers++;

            cout << "\n[Keys: " << score << "/5]";
            cout << "  [Wrong: " << wrongAnswers << "/4]\n";

            // FIX: HARD LOSS CONDITION
            if (wrongAnswers >= maxWrong) {
              cout << "\n[Wrong Answers: " << wrongAnswers << "/4]\n";
              showLose();
              return 0;
            }

            if (score >= 5) break;
        }

        if (score >= 5) break;
    }

    cout << "\n====================\n";

    if (score >= 5) {

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(endTime - startTime);

    int minutes = duration.count() / 60;
    int seconds = duration.count() % 60;

    showWin();

    cout << "\nTIME TAKEN: " << minutes << "m " << seconds << "s\n";
    }
    else {
    showLose();
    }

    cout << "Keys: " << score << "/5\n";
    cout << "Wrong: " << wrongAnswers << "\n";

    return 0;
}

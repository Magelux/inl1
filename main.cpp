#include <iostream> // för att använda cout och cin . cin är för skriva in, cout är det som skrivs ut i fönstret
#include <vector> // för att använda vector för att spara gissningarna, vector är en typ av array för att spara flera värden
#include <cstdlib> // för att använda rand() och srand() (en annan random number generator än den du vísade oss på lektionen)
#include <ctime> // för att använda time(0) för att få en random seed (seed är en startpunkt för en sekvens av tal)
#include <typeinfo> // används inte i detta programmet

/* includerar vi typeinfo så kan vi använda :typeid(), i detta fall för att se vilken typ av variabel och omvandla till
 * string.
så programmet inte "kraschar" i detta fall så menar jag med "krasch" en loop oändligt med en cout om vi inte gör det */


using namespace std; /* för att slippa skriva std:: i varje cout och cin samt vector och andra funktioner som vi
använder från standard library */

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); /* srand() för att seeda random number generator
    och time(0) för att få en random seed */ // static_cast<unsigned int> för att konvertera time(0) till unsigned int
    /* dvs en int som inte kan vara negativ,
     * time(0) är en funktion som returnerar antalet sekunder sedan 1970-01-01 00:00:00 UTC */

    while (true) {
        int target = rand() % 101; /* rand() för att få ett random tal och %101 för att få ett tal mellan 0 och 100,
        101 eftersom första siffran är 0, dvs i memory "blocket" */
        vector<int> attempts; // vector för att spara alla gissningar
        int guess; // int för att spara användarens gissning
        string rawGuess = "hejsan"; /* string för att spara användarens gissning,
        jag valde att använda string för att användaren ska skriva in en gissning */
        cout << "Gissa vad jag har valt för nummer mellan 0 och 100: "; /* cout för att skriva ut att användaren ska
        gissa ett tal mellan 0 och 100 */

        while (true) { // while loop för att användaren ska gissa tills hen gissar rätt
            //cin >> guess; // cin för att användaren ska skriva in sin gissning

            try {
                cin >> rawGuess;  /* Guess är en string
                och rawGuess är en string för att användaren ska skriva in sin gissning */
                guess = stoi(rawGuess);  //parse till number
                cout << rawGuess << endl;
            } catch (...) { /* är en exception för just parsing failar pga att det är en string,
                parsing är att omvandla en sträng till en int */
                cout << "Du måste skriva in ett nummer!" << endl;
                continue; /* loopar om dena while loopen, eftersom vi implementerade en exception för att användaren ska skriva in ett nummer
                så loopar den tills användaren skriver in ett nummer */
            }
            attempts.push_back(guess); /* push_back för att spara gissningarna i vectorn
            (Vector är en typ av array för att spara flera värden) */

            if (guess < target) { // if-sats för att ge användaren ledtrådar om gissningen är för hög eller för låg
                cout << "Högre!" << endl; // cout för att skriva ut att gissningen är för låg
            } else if (guess > target) { // else if för att ge användaren ledtrådar om gissningen är för hög eller för låg
                cout << "Lägre!" << endl; // cout för att skriva ut att gissningen är för hög
            } else { // else för att användaren har gissat rätt
                cout << "Grattis! Du gissade rätt!" << endl; // cout för att skriva ut att användaren har gissat rätt
                break; // break för att avsluta while loopen
            }
        }

        cout << "Dina gissningar: "; // cout för att skriva ut att användaren ska se sina gissningar
        for (int attempt : attempts) { // for loop för att skriva ut användarens gissningar
            cout << attempt << " "; // cout för att skriva ut användarens gissningar med mellanslag
        }
        cout << " & du har gjort " << attempts.size() << " gissningar"; // cout för att skriva ut antal gissningar
        cout << endl; // cout för att skriva ut en ny rad, jag valde att använda endl istället för \n

        char playAgain; // char för att spara om användaren vill spela igen
        cout << "Vill du spela igen? (j/n): "; // cout för att skriva ut vad användaren ska skriva
        cin >> playAgain; // cin för att användaren ska skriva j eller n

        if (playAgain != 'j' && playAgain != 'J') { // if-sats för att avsluta spelet om användaren skriver "j" eller "J"
            break; // break för att avsluta while loopen
        }
    }

    return 0; // return 0 för att avsluta programmet, dvs om vi breakar while loopen som annars hade startat om programmet
} // avslutar man däremot programmet på "stop" knappen med exit code 143. 0 är en "normal" exit code



/* #include <iostream> // för att använda cout och cin
#include <vector> //för att använda vector för att spara gissningarna förklarar mer senare i koden
#include <cstdlib> //för att använda rand() och srand()
#include <ctime> //för att använda time(0) för att få en random seed

using namespace std; //för att slippa skriva std:: i varje cout och cin

int main() {  //main funktionen i int för att returnera 0
    srand(static_cast<unsigned int>(time(nullptr))); //jag valde att använda time(0) för att få en random seed och det var mest för att prova
    int target = rand() % 101; // rand implementerar en random number generator och %101 för att få ett tal mellan 0 och 100
   // int howManyGuess;
    vector<int> attempts; //vector för att spara alla gissningar

    cout << "Gissa vad jag har valt för nummer mellan 0 and 100: "; //användaren ska gissa ett tal mellan 0 och 100 och cout för att skriva ut det

    while (true) {
        int guess;
        while (guess != target) { //while loop för att användaren ska gissa tills hen gissar rätt
            cin >> guess; //,howmanyGuess ++
            attempts.push_back(guess); //push_back för att spara gissningarna i vectorn

            if (guess < target) { // if-satsen för att ge användaren ledtrådar om gissningen är för hög eller för låg
                cout << "Högre!" << endl;
            } else if (guess > target) { // else if för att ge användaren ledtrådar om gissningen är för hög eller för låg
                cout << "Lägre!" << endl;
            } else { // else för att användaren har gissat rätt som ger cout för att gratulera användaren
                cout << "Grattis! Du gissade rätt!" << endl;
                break;
            }
        }

        cout << "Dina gissningar: "; // HÄR VILL JAG HA UT ANTAL GISSNINGAR, ska lösa en annan output som inte är själva siffrorna
        for (int attempt : attempts) {
            cout << attempt << " "; // quotes för att skriva ut gissningarna med mellanslag
            //cout << howManyGuess << " ";
        }
        cout << endl;

        return 0;

    }
} */
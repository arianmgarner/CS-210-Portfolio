#include <iostream>
#include <ctime>
#pragma warning(disable : 4996)


//Arian Garner


using namespace std;

int hr;
int min;
int sec;
int hr2;
int min2;
int sec2;
string APM;

void addHour() { //I am adding an hour here
    hr = hr + 1;
    if (hr > 12) {
        hr = hr - 12;
        if (APM == "A M") {
            APM = "P M";
        }
        else {
            APM = "A M";
        }
    }
}

void addMins() { // Function to be called for adding minute for both clocks as they should be the same 
    min = min + 1;
    if (min > 59) { // Once the minutes get to 59, it should add an hour do to 60 minutes in an hour 
        min = 0;
        addHour(); // Calling hour function to add the hour 
    }
}

void addSecs() { // Function to be called for adding seconds for both clocks 
    sec = sec + 1;
    if (sec > 59) { //This is the same as minutes and should add a minute 
        sec = 0;
        addMins(); // Calling minute function to add the minute 
    }
}

int main() { // my main function 

    time_t curr_time;
    curr_time = time(NULL); // I tried to display the current time here

    tm* tm_local = localtime(&curr_time);

   


    int userInput = 0;
    hr = tm_local->tm_hour;
    min = tm_local->tm_min; // I thought this was the way to set my variables to each current increment of time 
    sec = tm_local->tm_sec;
    APM = "P M";


    while (true) { // I used a while loop so that the program runs until the user enters 4 
        if (APM == "P M") {
            hr2 = hr + 12;
            if (hr2 >= 24) { // *This is where I  
                hr2 = hr2 - 24; //* calculated and converted the 12 hour clock into the 24 hour clock to be added into the display 
            }
        }
        else {
            hr2 = hr;
        }

        cout << "***************************" << "     " << "***************************" << endl; // I know there is a more simple way to print the stars, but I could not figure it out 
        cout << "*      12-Hour Clock      *" << "     " << "*      24-Hour Clock      *" << endl;
        cout << "*       " << hr << ":" << min << ":" << sec << "           *" << "     " << "*       " << hr2 << ":" << min << ":" << sec << "          *" << endl;
        cout << "***************************" << "     " << "***************************" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "                 ****************************" << endl;
        cout << "                 * 1 - Add Hour             *" << endl;
        cout << "                 * 2 - Add Minute           *" << endl; //Printing the menu 
        cout << "                 * 3 - Add Second           *" << endl;
        cout << "                 * 4 - Exit Program         *" << endl;
        cout << "                 ****************************" << endl;

        cin >> userInput; // taking user input 

        if (userInput == 1) { // The next line are if statements to compare the input to the options provided 
            addHour(); // it should add an hour if the user chose that option 
        }

        else if (userInput == 2) {
            addMins();
        }

        else if (userInput == 3) {
            addSecs();
        }

        else if (userInput == 4) {
            break;
        }

        else { // I was not sure if you wanted us to print a statement for an invalid input or not so I broke it 
            break;
        }

    }

}

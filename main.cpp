// Name: Artur Manvelyan
// Date: Oct 11, 2026
// Assignment: Assignment 4 - Fitness Tracker

#include "FitnessTracker.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Discard the rest of the current input line.
void clearInputLine()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    FitnessTracker tracker;
    int choice = 0;

    do
    {
        cout << "===== FITNESS TRACKER =====" << endl;
        cout << "1. Log a workout" << endl;
        cout << "2. View workout history" << endl;
        cout << "3. View summary" << endl;
        cout << "4. View type breakdown" << endl;
        cout << "5. Quit" << endl;
        cout << "===========================" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            if (cin.eof())
                break;

            clearInputLine();
            cout << "Invalid choice. Please try again." << endl;
            choice = 0;
            continue;
        }

        clearInputLine();

        switch (choice)
        {
            case 1:
            {
                string name;
                int typeChoice = 0;
                int duration = 0;
                int calories = 0;
                ExerciseType type = ExerciseType::Cardio;

                cout << "Enter workout name: ";
                if (!getline(cin, name))
                    return 0;

                cout << "Select exercise type:" << endl;
                cout << "1. Cardio" << endl;
                cout << "2. Strength" << endl;
                cout << "3. Flexibility" << endl;
                cout << "4. Sports" << endl;
                cout << "Enter your choice: ";

                if (!(cin >> typeChoice))
                {
                    if (cin.eof())
                        return 0;

                    typeChoice = 0;
                }

                clearInputLine();

                switch (typeChoice)
                {
                    case 1:
                        type = ExerciseType::Cardio;
                        break;
                    case 2:
                        type = ExerciseType::Strength;
                        break;
                    case 3:
                        type = ExerciseType::Flexibility;
                        break;
                    case 4:
                        type = ExerciseType::Sports;
                        break;
                    default:
                        cout << "Invalid choice. Defaulting to Cardio."
                             << endl;
                        type = ExerciseType::Cardio;
                        break;
                }

                cout << "Enter duration (minutes): ";

                if (!(cin >> duration))
                {
                    if (cin.eof())
                        return 0;

                    clearInputLine();
                    cout << "Invalid value. Must be at least 1." << endl;
                    break;
                }

                clearInputLine();

                if (duration < 1)
                {
                    cout << "Invalid value. Must be at least 1." << endl;
                    break;
                }

                cout << "Enter calories burned: ";

                if (!(cin >> calories))
                {
                    if (cin.eof())
                        return 0;

                    clearInputLine();
                    cout << "Invalid value. Must be at least 1." << endl;
                    break;
                }

                clearInputLine();

                if (calories < 1)
                {
                    cout << "Invalid value. Must be at least 1." << endl;
                    break;
                }

                tracker.logWorkout(name, type, duration, calories);
                break;
            }

            case 2:
                tracker.displayWorkouts();
                break;

            case 3:
                tracker.displaySummary();
                break;

            case 4:
                tracker.displayTypeBreakdown();
                break;

            case 5:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    while (choice != 5);

    return 0;
}


// Name: Artur Manvelyan
// Date: Oct 11, 2026
// Assignment: Assignment 4 - Fitness Tracker

#include "FitnessTracker.h"
#include <iostream>
#include <utility>

using namespace std;

string FitnessTracker::getTypeLabel(ExerciseType type) const
{
    switch (type)
    {
        case ExerciseType::Cardio:
            return "Cardio";

        case ExerciseType::Strength:
            return "Strength";

        case ExerciseType::Flexibility:
            return "Flexibility";

        case ExerciseType::Sports:
            return "Sports";

        default:
            return "Unknown";
    }
}

void FitnessTracker::logWorkout(string name, ExerciseType type,
    int duration, int calories)
{
    auto workout = make_unique<Workout>();

    workout->name = name;
    workout->type = type;
    workout->durationMinutes = duration;
    workout->caloriesBurned = calories;

    _workouts.push_back(move(workout));

    cout << "Workout logged: " << name
         << " (" << getTypeLabel(type)
         << ", " << duration << " min, "
         << calories << " cal)" << endl;
}

void FitnessTracker::displayWorkouts() const
{
    if (_workouts.empty())
    {
        cout << "No workouts logged yet." << endl;
        return;
    }

    cout << "===== WORKOUT HISTORY =====" << endl;

    for (size_t i = 0; i < _workouts.size(); i++)
    {
        cout << i + 1 << ". "
             << _workouts[i]->name << " | "
             << getTypeLabel(_workouts[i]->type) << " | "
             << _workouts[i]->durationMinutes << " min | "
             << _workouts[i]->caloriesBurned << " cal"
             << endl;
    }

    cout << "===========================" << endl;
    cout << "Total workouts: " << _workouts.size() << endl;
}

void FitnessTracker::displaySummary() const
{
    if (_workouts.empty())
    {
        cout << "No workouts to summarize." << endl;
        return;
    }

    long long totalDuration = 0;
    long long totalCalories = 0;

    for (const auto& workout : _workouts)
    {
        totalDuration += workout->durationMinutes;
        totalCalories += workout->caloriesBurned;
    }

    long long count = static_cast<long long>(_workouts.size());
    long long averageDuration = totalDuration / count;

    cout << "===== WORKOUT SUMMARY =====" << endl;
    cout << "Total workouts:        " << count << endl;
    cout << "Total duration:        " << totalDuration << " min" << endl;
    cout << "Total calories burned: " << totalCalories << " cal" << endl;
    cout << "Average duration:      " << averageDuration << " min" << endl;
    cout << "============================" << endl;
}

void FitnessTracker::displayTypeBreakdown() const
{
    size_t cardio = 0;
    size_t strength = 0;
    size_t flexibility = 0;
    size_t sports = 0;

    for (const auto& workout : _workouts)
    {
        switch (workout->type)
        {
            case ExerciseType::Cardio:
                cardio++;
                break;
            case ExerciseType::Strength:
                strength++;
                break;
            case ExerciseType::Flexibility:
                flexibility++;
                break;
            case ExerciseType::Sports:
                sports++;
                break;
        }
    }

    cout << "===== TYPE BREAKDOWN =====" << endl;

    if (cardio > 0)
        cout << "Cardio:      " << cardio << " workout(s)" << endl;

    if (strength > 0)
        cout << "Strength:    " << strength << " workout(s)" << endl;

    if (flexibility > 0)
        cout << "Flexibility: " << flexibility << " workout(s)" << endl;

    if (sports > 0)
        cout << "Sports:      " << sports << " workout(s)" << endl;

    cout << "==========================" << endl;
}
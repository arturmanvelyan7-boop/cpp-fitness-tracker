// Name: Artur Manvelyan
// Date: Oct 11, 2026
// Assignment: Assignment 4 - Fitness Tracker

#ifndef FITNESS_TRACKER_H
#define FITNESS_TRACKER_H

#include <string>
#include <vector>
#include <memory>

using namespace std;


enum class ExerciseType
{
    Cardio,
    Strength,
    Flexibility,
    Sports
};

struct Workout
{
    std::string name;
    ExerciseType type;
    int durationMinutes;
    int caloriesBurned;
};

class FitnessTracker{
   private:
    vector<std::unique_ptr<Workout>> _workouts;
    string getTypeLabel(ExerciseType type) const;

public:
    void logWorkout(std::string name, ExerciseType type,
     int duration, int calories);

    void displayWorkouts() const;
    void displaySummary() const;
    void displayTypeBreakdown() const;   
};

#endif
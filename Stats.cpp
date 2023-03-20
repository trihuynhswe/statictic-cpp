/*
Programming Project 6 - Statistics.
---
Using vectors and function to returning
calculate two simple statistics on data entered by the user:
histogram and a standard deviation.
I will divide this project into the 3 parts.
---
Part 1:
- Create 2 vectors named as scores and bins, create 1 variable named userInput.
- Using for loop to get the input from user by userInput and populated into the vectors scores.
- Determine the conditional during taking the input.

Part 2:
- Start create the functions needed for the project.
- Follow the guideline of the Project.

Part 3: Display all the result.
---
Duration: 180 mins
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

// Functions call.
double Mean(vector<int> &scores)
{
    int sum = 0;
    for (int i = 0; i < scores.size(); i++)
    {
        sum += scores.at(i);
    }
    return (double)sum / scores.size();
}
double Deviation(vector<int> &scores)
{
    // Declare the needed variables.
    double mean = Mean(scores);
    double sum = 0;
    double deviation;
    // Using for loop to calculate the inside sqrt of the fomula.
    for (int i = 0; i < scores.size(); i++)
    {
        deviation = pow(scores.at(i) - mean, 2.0);
        sum += deviation;
    }
    return sqrt(sum / scores.size());
}
void Histogram(vector<int> &scores, vector<int> &bins)
{
    for (int i = 0; i < scores.size(); i++)
    {
        if (scores[i] >= 90)
        {
            bins[9]++;
        }
        else if (scores[i] >= 80)
        {
            bins[8]++;
        }
        else if (scores[i] >= 70)
        {
            bins[7]++;
        }
        else if (scores[i] >= 60)
        {
            bins[6]++;
        }
        else if (scores[i] >= 50)
        {
            bins[5]++;
        }
        else if (scores[i] >= 40)
        {
            bins[4]++;
        }
        else if (scores[i] >= 30)
        {
            bins[3]++;
        }
        else if (scores[i] >= 20)
        {
            bins[2]++;
        }
        else if (scores[i] >= 10)
        {
            bins[1]++;
        }
        else
        {
            bins[0]++;
        }
    }
    
}

int main()
{
    // Declare the variables.
    const int MAX = 100;
    vector<int> scores;
    vector<int> bins(10);
    int userInput;

    cout << "\nEnter sequence of integer number: " << endl;
    // Create a loop to take the input from user.
    // When the user input < 0, stop entered data and start calculation.
    while (cin >> userInput)
    {
        if ((userInput <= 0) || (scores.size() >= MAX))
        {
            break;
        }
        else
        {
            scores.push_back(userInput);
        }
    }

    // Display the final answer.
    cout << endl;
    Histogram(scores, bins);
    for (int i = 9; i >= 0; i--)
    {
        cout << setw(2) << i << "| ";
        for (int j = 0; j < bins[i]; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << "SD: " << fixed << setprecision(4) << Deviation(scores) << endl;

    cout << endl;
    return 0;
}

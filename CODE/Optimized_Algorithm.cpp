/*
 * Algorithm 2: Stratified Random Sampling (Optimized)
 * Description: Divides range into N segments and picks one from each.
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

// Function to generate random questions using stratification
vector<int> generateRandomStratified(int start, int end, int N) {
    vector<int> result;
    int range = end - start + 1;
    
    // Calculate the size of each segment
    int step = range / N;
    
    // Handle case where step is 0 (N > Range)
    if (step == 0) step = 1; 

    for (int i = 0; i < N; i++) {
        int segmentStart = start + i * step;
        
        // Ensure we don't exceed the end of the range
        if (segmentStart > end) break;

        // Pick a random value within the current segment
        int value = segmentStart + rand() % step;
        result.push_back(value);
    }
    return result;
}

int main() {
    // Seed the random number generator
    srand(time(0));

    int start = 1, end = 100, N = 10;
    
    cout << "--- Optimized Algorithm Results ---" << endl;
    cout << "Range: [" << start << ", " << end << "], Selecting: " << N << endl;

    vector<int> questions = generateRandomStratified(start, end, N);

    cout << "Selected Questions: ";
    for (int q : questions) {
        cout << q << " ";
    }
    cout << endl;

    return 0;
}

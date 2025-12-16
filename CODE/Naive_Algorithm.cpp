/*
 * Algorithm 1: Naive Random Sampling
 * Description: Selects N random questions without ensuring distribution.
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

// Function to generate random questions naively
vector<int> generateRandomNaive(int start, int end, int N) {
    vector<int> result;
    for (int i = 0; i < N; i++) {
        // Generate random number between start and end
        int value = start + rand() % (end - start + 1);
        result.push_back(value);
    }
    return result;
}

int main() {
    // Seed the random number generator
    srand(time(0));

    int start = 1, end = 100, N = 10;
    
    cout << "--- Naive Algorithm Results ---" << endl;
    cout << "Range: [" << start << ", " << end << "], Selecting: " << N << endl;

    vector<int> questions = generateRandomNaive(start, end, N);

    cout << "Selected Questions: ";
    for (int q : questions) {
        cout << q << " ";
    }
    cout << endl;

    return 0;
}

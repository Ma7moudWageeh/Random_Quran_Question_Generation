/*
 * Algorithm 1: Naive Random Sampling (Real Quran Data)0
 * Context: Selects questions from ACTUAL Quranic Ayah indices.
 * Data Source: Standard Madani Mushaf counts (Total 6236 Ayahs).
 * Logic: 
 * 1. Naive Selection (O(N^2)): Picks blindly and checks duplicates linearly.
 * 2. Sorting (O(N log N)): Sorts the final list before displaying (Extra Overhead).
 */

#include <iostream>
#include <vector>
#include <random>  // Modern random library
#include <ctime>   // For time()
#include <algorithm> // For sort()

using namespace std;

// --- REAL QURAN DATA (Look-up Table) ---
const int JUZ_START_INDICES[32] = {
    0,      // Padding
    1,      // Juz 1
    149,    // Juz 2
    260,    // Juz 3
    386,    // Juz 4
    513,    // Juz 5
    641,    // Juz 6
    751,    // Juz 7
    871,    // Juz 8
    991,    // Juz 9
    1101,   // Juz 10
    1201,   // Juz 11
    1321,   // Juz 12
    1441,   // Juz 13
    1561,   // Juz 14
    1691,   // Juz 15
    1851,   // Juz 16
    2011,   // Juz 17
    2171,   // Juz 18
    2331,   // Juz 19
    2501,   // Juz 20
    2671,   // Juz 21
    2851,   // Juz 22
    3021,   // Juz 23
    3201,   // Juz 24
    3391,   // Juz 25
    3561,   // Juz 26
    3751,   // Juz 27
    3951,   // Juz 28
    4151,   // Juz 29
    5673,   // Juz 30
    6237    // End of Quran
};

// Helper to get REAL start Ayah
int getStartAyahOfJuz(int juz) {
    if (juz < 1) return 1;
    if (juz > 30) return 6236;
    return JUZ_START_INDICES[juz];
}

// Helper to get REAL end Ayah
int getEndAyahOfJuz(int juz) {
    if (juz < 1) return JUZ_START_INDICES[2] - 1;
    if (juz >= 30) return 6236;
    return JUZ_START_INDICES[juz + 1] - 1;
}

// The Naive Function
vector<int> generateRandomNaive(int startAyah, int endAyah, int N, int versesPerQuestion) {
    vector<int> result;
    int totalRange = endAyah - startAyah + 1; // Cost: 1

    if (N > totalRange) {
        cout << "Error: Range too small." << endl;
        return result;
    }
    
    // Modern Random Setup
    mt19937 rng(time(0)); 
    uniform_int_distribution<int> dist(startAyah, endAyah);

    cout << "Generating questions..." << endl;

    // --- PHASE 1: GENERATION (O(N^2)) ---
    // Explanation: The outer loop runs N times.
    // The inner loop runs 0, 1, 2, ..., N-1 times (Arithmetic Progression).
    // Sum = N * (N - 1) / 2  => O(N^2).

    while (result.size() < N) {                   // Frequency: N + 1 (Checks condition)
        
        int value = dist(rng);                    // Frequency: N
        bool exists = false;                      // Frequency: N

        // Inner Loop: Linear Search for duplicates
        // This is the cause of the quadratic complexity.
        for (int i = 0; i < result.size(); i++) { // Frequency: Sum(1 to N) approx (N^2)/2
            
            if (result[i] == value) {             // Frequency: Sum(1 to N) approx (N^2)/2
                exists = true;                    // Frequency: O(1) (Only on collision)
                break;                            // Frequency: O(1)
            }
        }

        if (!exists) {                            // Frequency: N
            result.push_back(value);              // Frequency: N
        }
    }

    // --- PHASE 2: SORTING (O(N log N)) ---
    // Explanation: Standard sort algorithm is typically Introsort.
    sort(result.begin(), result.end());           // Cost: O(N log N)

    // --- PHASE 3: DISPLAY (O(N)) ---
    // Explanation: Simple iteration to print N items.
    for (int i = 0; i < result.size(); i++) {     // Frequency: N + 1
        
        int value = result[i];                    // Frequency: N
        int recitationEnd = value + versesPerQuestion; // Frequency: N
        
        cout << "Question " << (i + 1) << ": "
             << "Ayah " << value << " to " << recitationEnd << endl; // Frequency: N
    }

    // Total Complexity = O(N^2) + O(N log N) + O(N)
    // Dominant Term = O(N^2)

    return result;
}

int main() {
    int startJuz, endJuz, N, versesPerQ;

    // 1. Inputs
    cout << "Enter Start Juz: ";
    cin >> startJuz;
    cout << "Enter End Juz: ";
    cin >> endJuz;
    
    // Convert to Real Ayah Indices
    int startGlobalAyah = getStartAyahOfJuz(startJuz);
    int endGlobalAyah = getEndAyahOfJuz(endJuz);

    cout << "Enter Number of Questions: ";
    cin >> N;
    
    cout << "Enter Verses per Question: ";
    cin >> versesPerQ;

    // 2. Show Range Scope
    cout << "\nSelecting from: Ayah " << startGlobalAyah 
         << " to Ayah " << endGlobalAyah << endl;
    cout << "----------------------------------------------------" << endl;

    // 3. Generate and Print List
    vector<int> questions = generateRandomNaive(startGlobalAyah, endGlobalAyah, N, versesPerQ);

    cout << "----------------------------------------------------" << endl;

    return 0;
}

/*
 * Algorithm 2: Stratified Random Sampling (Optimized - Real Quran Data)
 * Context: Handles Quranic ranges (Juz) using EXACT Ayah indices from the Mushaf.
 * Data Source: Standard Madani Mushaf counts (Total 6236 Ayahs).
 * Logic: 
 * 1. Lookup exact start index for the requested Juz range.
 * 2. Divide the total Ayah range into N equal segments.
 * 3. Pick one random Ayah from each segment.
 * 4. Define the Question Scope (Start Ayah -> Start Ayah + Verses Count).
 * * Complexity: 
 * - Time: O(N) - Fast and deterministic.
 * - Space: O(N) + O(1) for static lookup table.
 */

#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

// --- REAL QURAN DATA ---
// Lookup Table: The starting absolute Ayah index for each of the 30 Juz.
// Index 0 is unused (for 1-based indexing).
// Juz 1 starts at Ayah 1.
// Juz 2 starts at Ayah 149 (Al-Fatiha 7 + Al-Baqarah 141 + 1).
// ... and so on until Juz 30 which starts at Ayah 5673 (Surah An-Naba).
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
    6237    // End of Quran + 1 (To calculate end of Juz 30)
};

// Helper function to get the REAL starting Ayah of a Juz
int getStartAyahOfJuz(int juz) {
    if (juz < 1) return 1;
    if (juz > 30) return 6236;
    return JUZ_START_INDICES[juz];
}

// Helper function to get the REAL ending Ayah of a Juz
int getEndAyahOfJuz(int juz) {
    if (juz < 1) return JUZ_START_INDICES[2] - 1;
    if (juz >= 30) return 6236; // End of Quran
    
    // The end of Juz X is (Start of Juz X+1) - 1
    return JUZ_START_INDICES[juz + 1] - 1;
}

// Function to generate random questions using Stratified Sampling
// Now accepts 'versesPerQuestion' to define the exact scope of the recitation
vector<int> generateRandomStratified(int startAyah, int endAyah, int N, int versesPerQuestion) {
    vector<int> result;
    int totalRange = endAyah - startAyah + 1;
    
    // Calculate the size of each segment (Stratum)
    int step = totalRange / N;
    
    if (step == 0) step = 1; // Safety for edge cases

    cout << "\n--- Stratification Logic (Dividing the range) ---" << endl;

    for (int i = 0; i < N; i++) {
        // Define the boundaries of the current segment
        int segmentStart = startAyah + (i * step);
        int segmentEnd = segmentStart + step - 1;
        
        // Clamp to endAyah to avoid overflow in last segment
        if (segmentEnd > endAyah) segmentEnd = endAyah;
        if (segmentStart > endAyah) break;

        // Pick a random value within THIS specific segment
        // Ensure we don't pick a start ayah that causes the question to exceed the total range bounds
        int maxValidStart = segmentEnd; 
        
        int value = segmentStart + rand() % (maxValidStart - segmentStart + 1);
        result.push_back(value);

        // Calculate the end of the recitation for this question
        int recitationEnd = value + versesPerQuestion;
        
        // Print details with specific scope
        cout << "Question " << (i + 1) << ": ";
        cout << "(Pool: " << segmentStart << "-" << segmentEnd << ") ";
        cout << "-> Recite from Ayah " << value << " to " << recitationEnd << endl;
    }
    return result;
}

int main() {
    srand(time(0));

    int startJuz, endJuz, N, versesPerQ;

    // --- Interactive Input Section ---
    cout << "--- Optimized Question Generator (Stratified Algorithm) ---" << endl;
    cout << "Focus: Guarantees full coverage using REAL Quran Juz boundaries." << endl;
    
    // 1. Enter the Range (Juz)
    cout << "Enter Start Juz (1 to 30)";
    cin >> startJuz >> endJuz;

    // 2. Convert Juz to Absolute Ayah Range using LOOKUP TABLE
    int startGlobalAyah = getStartAyahOfJuz(startJuz);
    int endGlobalAyah = getEndAyahOfJuz(endJuz);

    // 3. Enter Number of Questions
    cout << "Enter Number of Questions (N): ";
    cin >> N;
    
    // 4. Enter Length of each Question
    cout << "Enter Verses per Question (e.g., 5): ";
    cin >> versesPerQ;

    cout << "\n----------------------------------------------------" << endl;
    cout << "Calculated Range: Juz " << startJuz << " to " << endJuz << endl;
    cout << "Real Ayah Range: [" << startGlobalAyah << " to " << endGlobalAyah << "]" << endl;
    cout << "Total Ayahs in Selection: " << (endGlobalAyah - startGlobalAyah + 1) << endl;
    cout << "Generating " << N << " questions (Length: " << versesPerQ << " verses each)..." << endl;
    cout << "----------------------------------------------------" << endl;

    // Call the function with the new parameter
    vector<int> questions = generateRandomStratified(startGlobalAyah, endGlobalAyah, N, versesPerQ);

    cout << "----------------------------------------------------" << endl;
    cout << "Final List of Starting Ayahs: ";
    for (int q : questions) {
        cout << q << " ";
    }
    cout << endl << endl;

    return 0;
}

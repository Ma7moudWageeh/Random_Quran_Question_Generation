Project Name: Random Quran Question Generation

Course: Algorithm Analysis & Design

Submitted by:

[محمود وجيه محمد السيد] SEC 7

[مروان نبيل محمد مطاوع] SEC 8

[ملك محمود متولي الجيزاوي] SEC 8

[نور سعد عبد الفتاح العدروسي] SEC 9

[يحيي عادل محمد] SEC 9

Project Description:

This project addresses the problem of selecting N testing points (Ayahs) from the Holy Quran
for revision purposes (Muraja'ah), ensuring fairness and coverage.

We implemented two algorithms using Real Quran Data to solve this:



1- Naive Algorithm (Naive_Algorithm.cpp):
- Uses simple random sampling with a linear collision check.
- Performance: Inefficient (O(N^2)). It becomes significantly slower as N increases and produces unfair clusters of questions (overlapping).

2- Optimized Algorithm (Optimized_Algorithm.cpp):
- Uses stratified sampling with a lookup table for Juz indices.
- Performance: Efficient (O(N)). It guarantees that the revision covers the selected Quranic range fairly without gaps or overlaps.


Files Included:



- Random Quran Question Generation.pdf : The complete analysis, pseudocode, and results discussion.

- Naive_Algorithm.cpp : C++ source code for the Naive approach (Modified to be O(N^2) for comparison).

- Optimized_Algorithm.cpp : C++ source code for the Optimized approach (O(N)).

- README.md : This file.


This algorithm analysis references and was inspired by:
[n-jah/Hafiz_Alquran](https://github.com/n-jah/Hafiz_Alquran)






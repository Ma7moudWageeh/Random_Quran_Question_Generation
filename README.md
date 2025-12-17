Project Name: Random Quran Question Generation

Course: Algorithm Analysis & Design

Submitted by:

[محمود وجيه محمد السيد] SEC 7

[مروان نبيل محمد مطاوع] SEC 8

[نور سعد عبد الفتاح العدروسي] SEC 9

[يحيي عادل محمد] SEC 9

Project Description:

This project addresses the problem of selecting N testing points (Ayahs) from the Holy Quran
for revision purposes (Murajah), ensuring fairness and coverage.

We implemented two algorithms to explane solve this:

1- Naive Algorithm (Naive_Algorithm.cpp):
Uses simple random sampling. It is fast but may produce clusters of questions
from the same Surah or Juz, leaving other parts unreviewed.

2- Optimized Algorithm (Optimized_Algorithm.cpp):
Uses stratified sampling. It divides the requested Quranic range (e.g., Juz, Hizb)
into equal sections and picks one question from each, ensuring the revision
covers the entire material fairly without gaps.

Files Included:

- Random Quran Question Generation.pdf : The complete analysis, pseudocode, and results discussion.
- Naive_Algorithm.cpp : C++ source code for the Naive approach.
- Optimized_Algorithm.cpp : C++ source code for the Optimized approach.
- README.md : This file.

This algorithm analysis references and was inspired by:
[n-jah/Hafiz_Alquran](https://github.com/n-jah/Hafiz_Alquran)


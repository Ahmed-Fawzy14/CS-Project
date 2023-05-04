#pragma once

void runProgram();
float jaccardSimilarity(const unordered_set<string>& set1, const unordered_set<string>& set2);
vector<string> generateNGrams(const string& str, int n);
void similarityPercent(string main, string c1, string c2, string c3);

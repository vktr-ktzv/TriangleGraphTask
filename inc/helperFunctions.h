#include <iostream>
#include <vector>

bool isNumbersValid(int* numbers); // Провереят, что число принадлежит [1;6]
bool isSumValid(int* numbers, int SumInFirstThree); // Проверяет равнство во второй и третьей тройке с уже заданной первой
bool notTheSame(int num, int* numbers); //Проверяет не было ли уже такой цифры
void printSolutions(const std::vector<std::vector<std::vector<int>>>& solutions); //Печать всех найденных решений

void clearSolutionIfSame(const std::vector<std::vector<std::vector<int>>>& solutions, // если новое рашение с точностью до
                                            std::vector<std::vector<int>>& solution); // перестановки равно уже записанному
                                                                                      // стирает его 

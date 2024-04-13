#include "helperFunctions.h"

bool isNumbersValid(int* numbers) 
{
  for(int i = 0; i < 6; i ++)
  {
    if((numbers[i] > 6) || (numbers[i] < 1 ))
    {
      return false;
    }
  }

  return true;
}

bool isSumValid(int* numbers, int SumInFirstThree)
{
  int SumInSecondThree = numbers[2] + numbers[3] + numbers[4];
  int SumInThirdThree = numbers[0] + numbers[3] + numbers[5];

  if ((SumInSecondThree != SumInFirstThree) != (SumInThirdThree != SumInFirstThree))
  {
    return false;
  }

  return true;
}

bool notTheSame(int num, int* numbers) //Проверяет не было ли уже такой цифры
{
  for(int i = 0; i < 6; i ++)
  {
    if(num == numbers[i])
    {
      return false;
    }
  }
  
  return true;
}

void clearSolutionIfSame(const std::vector<std::vector<std::vector<int>>>& solutions, std::vector<std::vector<int>>& solution )
{
  for (const auto& sol: solutions) 
  {
    for (int m = 0; m < 3; m++)
    {
      for (int l = 0; l < 3; l++)
      {
        if (sol[m] == solution[l])  
        {
          solution.clear();
        }
      }
    }
  }
}

void printSolutions(const std::vector<std::vector<std::vector<int>>>& solutions) 
{
  for (const auto& solution: solutions) 
  {
      std::cout << "SOLUTION: { ";
      for (const auto& three: solution) 
      {  
          std::cout << "{ ";
          for (int node: three) 
          {
            std::cout << node << " ";
          }
          std::cout << " }";
        }
        std::cout << " }" << std::endl;
    }
}
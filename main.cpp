#include "helperFunctions.h"

int main()
{
  std::vector<std::vector<std::vector<int>>> solutions; //сохраняем решения
  int numbers[6] = {}; // вспомогательный массив, который будем использовать для сохранения чисел с их порядковым номером

  for (int nodeOne = 1; nodeOne <= 6; nodeOne++) // первая цифра
  {  
    numbers[0] = nodeOne;
    for(int nodeTwo = 1; nodeTwo <= 6; nodeTwo++) // вторая цифра
    {
      if (!notTheSame(nodeTwo, numbers)) {continue;} 
      numbers[1] = nodeTwo;

      for(int nodeThree = 1; nodeThree <= 6; nodeThree++) // третья цифра
      {
        if (!notTheSame(nodeThree, numbers)) {continue;} // первично откидываем равные цифры в нодах
        numbers[2] = nodeThree;

        for(int nodeFour = 1; nodeFour <= 6; nodeFour++) //задаем четвертую цифру, тогда оставшиеся две однозначно определяются
        {
          if (!notTheSame(nodeFour, numbers)) {continue;} // первично откидываем равные цифры в нодах
          numbers[3] = nodeFour;

          int SumInThree = nodeOne + nodeTwo + nodeThree;

          int nodeFive = SumInThree - (nodeTwo + nodeFour);
          int nodeSix  = SumInThree - (nodeThree + nodeFour);
          
          if ((!notTheSame(nodeFive, numbers)) || (!notTheSame(nodeSix, numbers)) || (nodeFive == nodeSix)) {continue;} // выставили цифры и уверены что они все разные
          
          numbers[4] = nodeFive;
          numbers[5] = nodeSix;

          if(!isNumbersValid(numbers)) // проверка что числа из [1;6]
          {
            numbers[5] = 0; // подчищаем массив для следующей итерации
            numbers[4] = 0;
            numbers[3] = 0;
            continue;
          }

          if(!isSumValid(numbers, SumInThree)) // проверка что все три суммы получились равными
          {
            numbers[5] = 0; // подчищаем массив для следующей итерации
            numbers[4] = 0;
            numbers[3] = 0;
            continue;
          }

          std::vector<std::vector<int>> solution;

          //тройки заполняю в формате от "торчащего" конца к центру
          std::vector<int> firstThree {nodeOne, nodeTwo, nodeThree}; //первая тройка
          std::vector<int> secondThree {nodeSix, nodeThree, nodeFour}; //вторая тройка
          std::vector<int> thirdThree {nodeFive, nodeFour, nodeTwo}; //третья тройка

          // заполняем решение провалидированными тройками
          solution.push_back(firstThree);
          solution.push_back(secondThree);
          solution.push_back(thirdThree);

          clearSolutionIfSame(solutions, solution);

          if(!solution.empty())
          {
            solutions.push_back(solution);
          }

          numbers[5] = 0; // подчищаем временный массив дял новой итерации))
          numbers[4] = 0;
          numbers[3] = 0;
        }
        numbers[2] = 0;
      }
      numbers[1] = 0;
    }
  }

  //Печать решений
  printSolutions(solutions);
     
  return 0;
}
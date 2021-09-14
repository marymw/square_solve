#pragma once
#include "SolveSq.h" 

int main() {
    int       UserAnswer = 0;                  //показывает, хочет ли пользователь решить ещё одно уравнение
    const int MAX_ROOTS  = 3;
    
    Unit_Test(MAX_ROOTS);

    do{
        int       equation_type = 0;        //изначально уравнение не имеет никакого типа

        MainGreetings();                    //приветствие
        GetEquationType(&equation_type);    //возвращает тип уравнения, которое хочет решить пользователь 

        if (equation_type == 0)             //если не хочет решать уравнения
            break;   
        
        int (*PtrOnSolvingFunc) (double *); //указатель на функции которые будут решать тот или иной тип уравнения
        double *Solution_matrix = (double *)calloc(MAX_ROOTS, sizeof(double));  //выделение памяти под матрицу решений

        int RootsNumber = Solution(Solution_matrix, equation_type, *LinearSolving,
        														   *QuadraticSolving);//определяет какой тип уравнения
 
        #ifdef DEBAG
            printf("%d\n", RootsNumber);
        #endif

        PrintAnswer(RootsNumber, Solution_matrix);   //печатает ответ
        UserAnswer = QuestionAgain();                //спрашивает у пользователя, хочет ли он решить ещё
        
        free(Solution_matrix);

    }while (UserAnswer == 1);                        //цикл продолжается, пока пользователь хочет решать уравнения

    PrintGoodBye();
    return 0;
}

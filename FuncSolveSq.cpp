#pragma once
#include "SolveSq.h"

int     GetQuadSolutions  (double a, double b, int c, double *Solution_matrix);

bool IsZero(double a, double b){        //для сравнения с нулем разности чисел
    return abs(a - b) <= eps;
}
     

void MainGreetings(){                    //выводит приветствие
    printf("Program for solving linear and quadratic equations.\n\n");
    PrintSeparator();
}


void GetEquationType(int *equation_type){ //определяет тип уравнения, которое хочет решить пользователь
        printf("Do you want to solve a quadratic or linear equation?\n");
        printf("Enter 1 if you want to solve a linear equation.\n");
        printf("Enter 2 if you want to solve a quadratic equation.\n");
        printf("Any other key if you don't want to solve the equation.\n\n");

        scanf("%d", equation_type);

        if ((*equation_type) == 1)          
            return;
        if ((*equation_type) == 2)
            return;
        else {                      //если введено не 1 и не 2, то пользователь не хочет решать уравнения
            *equation_type   =  0;
            return;
        } 
}


int Solution(  double *Solution_matrix, 
			 const int equation_type,
				   int (*PtrOnSolvingFunc1) (double *),
				   int (*PtrOnSolvingFunc2) (double *)){//по типу уравнения определяет какую функцию для решения вызвать 
                                                                           
    if (equation_type == 0)
        return -1;
    if (equation_type == 1)
        return PtrOnSolvingFunc1(Solution_matrix);      
    if (equation_type == 2)
        return PtrOnSolvingFunc2(Solution_matrix);
    else {
        printf("Error in funcion 'Solution': wrong equation_type");
        return -1;//это вроде никогда не должно происходить, но вдруг? А кому сейчас легко?
    }
}


void LinGreetings(){ //приветствие линейного уравнения
    printf("Linear equation solution\n\n");
    PrintSeparator();
}


void GetLinCoefficient(double *b, double *c){ //получает коэффициенты линейного уравнения
    int check1 = 0;     //для проверок корректного ввода
    int check2 = 0;
    do{                 //циклы до тех пор, пока пользователь не введёт корректные коэффициенты
        printf("Enter coefficient with argument\n\n");
        check1 = scanf("%lf", b);
    }while (check1 != 1);

    do{
        printf("Enter free term\n");
        check2 = scanf("%lf", c);
    }while (check2 != 1);
    PrintSeparator();
}


int GetLinSolutions(double b, double c, double *Solution_matrix){//определяет количество корней
                                                           //и записывает их в матрицу
    if ((IsZero(b, 0)) && (IsZero(c,0)))
        return 3;                                     //для бесконечного числа корней
    else if ((IsZero(b, 0)) && (!IsZero(c,0)))
        return 0;                                     //нет корней
    else if ((!IsZero(b, 0)) && (IsZero(c, 0))){
        Solution_matrix[0] = 0 ;                //записали значение корня
        return 1;
    }
    else if ((!IsZero(b, 0))){
        Solution_matrix[0] = - c / b ;                //записали значение корня
        #ifdef DEBAG
            printf(" b = %lf, c = %lf, solution = %lf" , b, c, -c / b);
        #endif
        return 1;                                     //один корень
    }
    else {
        printf("Error in funcion %s", __FUNCTION__); //а вдруг?
        return -1;
    }                    
}


int LinearSolving (double *Solution_matrix){       //возвращает количество решений линейного уравнения        
    LinGreetings();
    double b = NAN, c = NAN;                           //bx + c = 0
    GetLinCoefficient(&b, &c);                     //получает от пользователя коэффициенты уравнения
    return GetLinSolutions(b, c, Solution_matrix); //функ определяет количество корней и записывает их в матрицу                
}


void PrintAnswer(const int RootsNumber,double *Solution_matrix){ //печатает ответ
    PrintSeparator();
    if (RootsNumber == 3){                                       //бесконечное количество корней
        printf ("Endless number of solutions.\n\n");
    }
    else if (RootsNumber == 2){
        printf ("Two solutions:\n");                             //два корня
        for (int RootCount = 0; RootCount < RootsNumber; RootCount++)
            printf("%lf\n", Solution_matrix[RootCount]);       //записали в матрицу корни
        printf("\n");
    } 
    else if (RootsNumber == 1){                                       //один корень
        printf("One solution:\n");
        printf("%lf", Solution_matrix[0]);
    } 
    else if (RootsNumber == 0){                                       //нет корней
        printf("No solutions\n");
    } 
    else
        printf("Error in funcion %s \n", __FUNCTION__);             //а кому сейчас легко?     
}


void QuadGreetings(){                                           //приветствие для квадратного уравнения
    printf("Quadratic equation solution\n\n");
    PrintSeparator();
}


void GetQuadCoefficient(double *a, double *b, double *c){
    int check1 = 0;                                             //проверки для корректного ввода
    int check2 = 0;
    int check3 = 0;
    do {                                                        //циклы до того как не введут корректные значения
        printf("Enter the coefficient at the second power of the argument:\n");
        check1 = scanf("%lf", a);
    }while (check1 != 1);

    do{
        printf("Enter the coefficient at the first power of the argument:\n");
        check2 = scanf("%lf", b);
    }while(check2 != 1);

    do{
        printf("Enter free term:\n");
        check3 = scanf("%lf", c);
    }while(check3 != 1);
    PrintSeparator();

    return;
}


int GetQuadSolutions(double a, double b, double c, double *Solution_matrix){//возвращает количество корней
                                                                            //и записывает их в матрицу
    double Discriminant = ( b * b - 4 * a * c );                            //вычисление дискриминанта

    if (IsZero(Discriminant, 0)) {
            Solution_matrix[0] = - b / (2 * a);
            return 1;
    }
    if (Discriminant < 0)                                             //нет корней
        return 0;
    if (Discriminant > 0) {                                           //два корня
        double Sqrt_of_Discr = sqrtf(Discriminant);                   //корень из дискриминанта
        Solution_matrix[0] = ( - b + Sqrt_of_Discr) / ( 2 * a );
        Solution_matrix[1] = ( - b - Sqrt_of_Discr) / ( 2 * a );
        return 2;
    }
    else {
        printf("Error in funcion 'GetQuadSolutions'");
        return -1;
    }                    
}


int QuadraticSolving (double *Solution_matrix){        //возвращает количество решений квадратного уравнения уравнения       
    QuadGreetings();                                   //приветствие

    double a = NAN, b = NAN, c = NAN;                        //ax^2 + bx + c = 0
    GetQuadCoefficient(&a, &b, &c);                    //получает от пользователя коэффициенты уравнения

    if (IsZero(a, 0))                                        //если a = 0 квадратное уравнение вырождается в линейное
        return GetLinSolutions(b, c, Solution_matrix);
    return GetQuadSolutions(a, b, c, Solution_matrix); //функция определяет количество корней и записывает их в матрицу                                   
}


void PrintGoodBye(){
    printf("The program has terminated. Goodbye!\n\n");
    PrintSeparator();
}


int QuestionAgain(){                               //спрашивает у пользователя, хочет ли он решить ещё одно уравнение
    PrintSeparator();
    printf("Do you want to solve another equation?\n\n");
    printf("Enter 1, if the answer is \"Yes\"\n");
    printf("Otherwise press any other figure:\n");
    int answer = 0;
    int check = scanf("%d",&answer);
    if (answer == 1 && check == 1)                       //если сканф принял значение и оно равно единице
        return 1;
    else 
        return -1;
}

void PrintSeparator(){                                  //печатает разделитель для красоты
    printf("__________________________________\n\n");
}

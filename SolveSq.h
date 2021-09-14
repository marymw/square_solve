#include <stdio.h>
#include <math.h>
//#define DEBAG 1

double const eps = 1e-6;


bool    IsZero            (double a, double b);       //сравнивает дабл с нулем
void    MainGreetings     ();                         //выводит приветствие для main
void    GetEquationType   (int *equation_type);       //возвращает тип уравнения, которое хочет решить пользователь
void    LinGreetings      ();                         //приветствие линейного уравнения
void    GetLinCoefficient (double *b, double *c);     
void    PrintAnswer       (const int RootsNumber,double *Solution_matrix);
void    QuadGreetings     ();                        //приветствие квадратного уравнения
void    GetQuadCoefficient(double *a, double *b, double *c);
void    PrintGoodBye      ();
void    PrintSeparator    ();
int     Solution          (double * Solution_matrix, const int equation_type, 
                                                           int (*PtrOnSolvingFunc1) (double *),
                                                           int (*PtrOnSolvingFunc2) (double *)); //решает

int     GetLinSolutions   (double b, double c, double *Solution_matrix);  //определяет количество корней
int     LinearSolving     (double *Solution_matrix);                      //возвращает решение линейного уравнения
int     GetQuadSolutions  (double a, double b, double c, double *Solution_matrix); //возвращает решение квадратного уравнения
int     QuadraticSolving  (double *Solution_matrix);
int     QuestionAgain     ();
void    Test_GetQuad_sol(int *TestCount,double a, double b, double c, double *Solution_matrix_forTest, double RightX1, double RightX2, int RightRootsNumber);
void    Test_GetLin_sol(int *TestCount,double b, double c, double *Solution_matrix_forTest, double RightX1, int RightRootsNumber);
void    Unit_Test(const int MAX_ROOTS);

#include <stdio.h>
#include <math.h>
//#define DEBAG 1

//---------------------------------------------------------
/** \brief Constant eps defines epsilon neighborhood of zero
 * Numbers belonging to this neighborhood are considered to be zero */
//---------------------------------------------------------
double const eps = 1e-6;

// All function declaration

//---------------------------------------------------------
/** \brief This function copares two double numbers
    \param [in] a  The first number
    \param [in] b  The second number
    \return true, if the difference between the numbers lies in the epsilon neighborhood of zero */
//---------------------------------------------------------
bool    IsZero            (double a, double b);   

//---------------------------------------------------------
/** \brief This function print main greetings*/
//---------------------------------------------------------
void    MainGreetings     ();                         

//---------------------------------------------------------
/** \brief This function asks the user what equation he wants to solve
    \param [in] equation_type  contains 1, if the equation is linear, 2 - if it is square, 0 if the user doesn't want to solve anything*/
//---------------------------------------------------------
void    GetEquationType   (int *equation_type);   

//---------------------------------------------------------
/** \brief This function printf greetings of linear solving*/
//---------------------------------------------------------
void    LinGreetings      ();  

//---------------------------------------------------------
/** \brief This function obtains from the user the values of the coefficients for the equation \f$ bx + c = 0 \f$
    \param [in] b is the coefficient at the first power of the argument
    \param [in] c is the free term */
//---------------------------------------------------------
void    GetLinCoefficient (double *b, double *c); 

//---------------------------------------------------------
/** \brief This function printf answer of linear or square equations to the console
    \param [in] RootsNumber shows the number of solutions to the equation
    \param [in] Solution_matrix contains an array with the roots of the equation
    */
//---------------------------------------------------------
void    PrintAnswer       (const int RootsNumber,double *Solution_matrix);

//---------------------------------------------------------
/** \brief This function printf greetings of linear solving*/
//---------------------------------------------------------
void    QuadGreetings     ();  

//---------------------------------------------------------
/** \brief This function obtains from the user the values of the coefficients for the equation \f$ ax^2 + bx + c = 0 \f$
    \param [in] a is the coefficient at the second power of the argument
    \param [in] b is the coefficient at the first power of the argument
    \param [in] c is the free term */
//---------------------------------------------------------
void    GetQuadCoefficient(double *a, double *b, double *c);

//---------------------------------------------------------
/** \brief This function printf farewell to user*/
//---------------------------------------------------------
void    PrintGoodBye      ();

//---------------------------------------------------------
/** \brief This function print the separator*/
//---------------------------------------------------------
void    PrintSeparator    ();

//---------------------------------------------------------
/** \brief This function by the type of equation determinates which function to solve it is better to call
    \param [in] Solution_matrix contains an array with the roots of the equation
    \param [in] equation_type  contains 1, if the equation is linear, 2 - if it is square, 0 if the user doesn't want to solve anything
    \param [in] PtrOnSolvingFunc1 contains a pointer to the first function for solving (in our case it will be the function for solving a linear equation)
    \param [in] PtrOnSolvingFunc2 contains a pointer to the second function for solving (in our case it will be the function for solving a square equation)
    \return number of roots*/
//---------------------------------------------------------
int     Solution          (double * Solution_matrix, const int equation_type, 
                                                           int (*PtrOnSolvingFunc1) (double *),
                                                           int (*PtrOnSolvingFunc2) (double *)); 

//---------------------------------------------------------
/** \brief This function actually solves the equation \f$ bx + c = 0 \f$ and enters the solution into the matrix of solutions 
    \param [in] b is the coefficient at the first power of the argument
    \param [in] c is the free term 
    \param [in] Solution_matrix contains an array with the roots of the equation
    \return number of roots*/
//---------------------------------------------------------
int     GetLinSolutions   (double b, double c, double *Solution_matrix); 

//---------------------------------------------------------
/** \brief This function solves a linear equation by sequentially calling the corresponding functions 
    \param [in] Solution_matrix contains an array with the roots of the equation
    \return number of roots*/
//---------------------------------------------------------
int     LinearSolving     (double *Solution_matrix); 

//---------------------------------------------------------
/** \brief This function actually solves the equation \f$ ax^2 + bx + c = 0 \f$ and enters the solution into the matrix of solutions 
    \param [in] a is the coefficient at the second power of the argument
    \param [in] b is the coefficient at the first power of the argument
    \param [in] c is the free term 
    \param [in] Solution_matrix contains an array with the roots of the equation
    \return number of roots*/
//---------------------------------------------------------
int     GetQuadSolutions  (double a, double b, double c, double *Solution_matrix); 

//---------------------------------------------------------
/** \brief This function solves a square equation by sequentially calling the corresponding functions 
    \param [in] Solution_matrix contains an array with the roots of the equation
    \return number of roots*/
//---------------------------------------------------------
int     QuadraticSolving  (double *Solution_matrix);

//---------------------------------------------------------
/** \brief This function asks the user if he wants to solve another equation*/
//---------------------------------------------------------
int     QuestionAgain     ();

//---------------------------------------------------------
/** \brief This function tests the "GetQuadSolutions" of solving square equipment \f$ ax^2 + bx + c = 0 \f$ by many tests 
    \param [in] TestCount shows the number of this test
    \param [in] a is the coefficient at the second power of the argument
    \param [in] b is the coefficient at the first power of the argument
    \param [in] c is the free term 
    \param [in] Solution_matrix contains an array with the roots of the equation
    \param [in] RightX1 is a right value of first root of  square equipment f$ ax^2 + bx + c = 0 \f$
    \param [in] RightX2 is a right value of second root of  square equipment f$ ax^2 + bx + c = 0 \f$
    \param [in] RightRootsNumber shows the right number of roots of square equipment f$ ax^2 + bx + c = 0 \f$ */
//---------------------------------------------------------
void    Test_GetQuad_sol(int *TestCount,double a, double b, double c, double *Solution_matrix_forTest, double RightX1, double RightX2, int RightRootsNumber);

//---------------------------------------------------------
/** \brief This function tests the "GetLinSolutions" of solving linear equipment \f$ bx + c = 0 \f$ by many tests 
    \param [in] TestCount shows the number of this test
    \param [in] b is the coefficient at the first power of the argument
    \param [in] c is the free term 
    \param [in] Solution_matrix contains an array with the roots of the equation
    \param [in] RightX1 is a right value of first root of  square equipment f$ ax^2 + bx + c = 0 \f$
    \param [in] RightRootsNumber shows the right number of roots of square equipment f$ ax^2 + bx + c = 0 \f$ */
//---------------------------------------------------------
void    Test_GetLin_sol(int *TestCount,double b, double c, double *Solution_matrix_forTest, double RightX1, int RightRootsNumber);


//---------------------------------------------------------
/** \brief This function calls functions to check other functions and performs tests with different values
    \param [in] MAX_ROOTS shows the max number of roots*/
//---------------------------------------------------------
void    Unit_Test(const int MAX_ROOTS);

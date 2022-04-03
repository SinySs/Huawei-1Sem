#ifndef SOLVER_H_INCLUDED
#define SOLVER_H_INCLUDED
/// Возможное колличество корней уравнения
enum solutions_amount {
    ZERO_SOLUTIONS = 0, ///< Уравнение не имеет корней
    ONE_SOLUTION = 1, ///< Уравнение имеет два корня
    TWO_SOLUTIONS = 2, ///< Уравнение имеет три корня
    INFINITE_SOLUTIONS = -1 ///< Уравнение имеет бесконечно много корней
};

/*! \brief Функция, решающяя линейное уравнение
    \returns Корень линейного уравнения
*/

solutions_amount solveLinear(const float b, const float c, float *x1);

/*! \brief Функция, решающяя квадратное уравнение
    \returns Корни квадратного уравнения

*/

solutions_amount solveQuadratic(const float a, const float b, const float c, float *x1, float *x2);


#endif // SOLVER_H_INCLUDED

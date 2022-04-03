#ifndef SOLVER_H_INCLUDED
#define SOLVER_H_INCLUDED
/// ��������� ����������� ������ ���������
enum solutions_amount {
    ZERO_SOLUTIONS = 0, ///< ��������� �� ����� ������
    ONE_SOLUTION = 1, ///< ��������� ����� ��� �����
    TWO_SOLUTIONS = 2, ///< ��������� ����� ��� �����
    INFINITE_SOLUTIONS = -1 ///< ��������� ����� ���������� ����� ������
};

/*! \brief �������, �������� �������� ���������
    \returns ������ ��������� ���������
*/

solutions_amount solveLinear(const float b, const float c, float *x1);

/*! \brief �������, �������� ���������� ���������
    \returns ����� ����������� ���������

*/

solutions_amount solveQuadratic(const float a, const float b, const float c, float *x1, float *x2);


#endif // SOLVER_H_INCLUDED

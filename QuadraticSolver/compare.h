#ifndef COMPARE_H_INCLUDED
#define COMPARE_H_INCLUDED
///����� ��������� ����������� ���������
enum compare_result {
    LESS  = -1, ///< ��������� ��� ����� ������
    EQUAL = 0, ///< ��������� ��� ����� �����
    MORE  = 1 ///< ��������� ��� ����� ������
};


/*! \brief �������, ������������ ��� �����
    \param [in] a ������ ����� ��� ���������
    \param [in] b ������ ����� ��� ���������
    \param [out] LESS ����� a ������ b
    \param [out] MORE ����� a ������ b
    \returns ��������� ����� a � b

*/
compare_result float_is_less(const float a, const float b);

/*! \brief �������, ������������ ����� �� ����� �����
    \param [in] a ������ ����� ��� �������� ���������
    \param [in] b ������ ����� ��� �������� ���������
    \param [out] EQUAL ����� a ����� b
    \returns ����� �� �����

*/


compare_result float_is_equal(const float a, const float b);

#endif // COMPARE_H_INCLUDED

#ifndef STATUS_H_INCLUDED
#define STATUS_H_INCLUDED
/// ����� ��������� ������ ��� �����
enum input_errors {
    STATUS_SUCCESS   = 0, ///< ���������, ��� ���� �������
    ERROR_BAD_INPUT = 1, ///< ���������, ��� ������� ����������� �������
    ERROR_NAN       = 2, ///< ���������, ��� ������� �� �����
    ERROR_INF       = 3, ///< ���������, ��� ������� �� ��� ��������
};

/*! \brief �������, ����������� �� ������ �����
    \returns ������, ������� ���� �������� ��� �����

*/
const char *statusToString(input_errors statusCode);

/*! \brief �������, ����������� ������������ ��������� ������
    \returns ��������� �� ���� ������� ������

*/
bool isFailure (input_errors statusCode);

#endif // STATUS_H_INCLUDED

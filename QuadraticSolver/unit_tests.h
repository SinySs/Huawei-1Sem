#ifndef UNIT_TESTS_H_INCLUDED
#define UNIT_TESTS_H_INCLUDED
/// ���������� � ������������
struct UnitTestInfo {
    int totalTests; ///< ����� ��������� ������
    int succededTests; ///< ������� ����������� �����
};

typedef bool (*UnitTestFunction)(void);
/*! \brief �������, ����������� ������������ �������������
    \returns ������ �������������, ���� ������� �������

*/

void initUnitTesting(struct UnitTestInfo *info);

/*! \brief �������, ����������� ���������� ����������� �����

    \returns ��������� ���������� ����� (����� ��� �������)

*/
void runUnitTest(
    struct UnitTestInfo *info,
    const char *name,
    UnitTestFunction func
);

#endif // UNIT_TESTS_H_INCLUDED

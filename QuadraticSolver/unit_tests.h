#ifndef UNIT_TESTS_H_INCLUDED
#define UNIT_TESTS_H_INCLUDED
/// Информация о тестировании
struct UnitTestInfo {
    int totalTests; ///< Всего совершено тестов
    int succededTests; ///< Успешно выполненные тесты
};

typedef bool (*UnitTestFunction)(void);
/*! \brief Функция, проверяющая правильность инициализации
    \returns Ошибку инициализации, если таковая имеется

*/

void initUnitTesting(struct UnitTestInfo *info);

/*! \brief Функция, проверяющая успешность прохождения теста

    \returns Результат выполнения теста (успех или неудача)

*/
void runUnitTest(
    struct UnitTestInfo *info,
    const char *name,
    UnitTestFunction func
);

#endif // UNIT_TESTS_H_INCLUDED

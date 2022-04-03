#ifndef STATUS_H_INCLUDED
#define STATUS_H_INCLUDED
/// Набор возможных ошибок при вводе
enum input_errors {
    STATUS_SUCCESS   = 0, ///< Указывает, что ввод успешен
    ERROR_BAD_INPUT = 1, ///< Указывает, что введены посторонние символы
    ERROR_NAN       = 2, ///< Указывает, что введено не число
    ERROR_INF       = 3, ///< Указывает, что введены не три значения
};

/*! \brief Функция, указывающая на ошибку ввода
    \returns Ошибку, которая была допущена при вводе

*/
const char *statusToString(input_errors statusCode);

/*! \brief Функция, проверяющая корректность введенных данных
    \returns Корректно ли были введены данные

*/
bool isFailure (input_errors statusCode);

#endif // STATUS_H_INCLUDED

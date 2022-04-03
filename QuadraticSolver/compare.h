#ifndef COMPARE_H_INCLUDED
#define COMPARE_H_INCLUDED
///Набор возможных результатов сравнения
enum compare_result {
    LESS  = -1, ///< Указывает что число меньше
    EQUAL = 0, ///< Указывает что число равно
    MORE  = 1 ///< Указывает что число больше
};


/*! \brief Функция, сравнивающая два числа
    \param [in] a первое число для сравнения
    \param [in] b второе число для сравнения
    \param [out] LESS число a меньше b
    \param [out] MORE число a больше b
    \returns Сравнение числа a и b

*/
compare_result float_is_less(const float a, const float b);

/*! \brief Функция, показывающая равны ли числа чисел
    \param [in] a первое число для проверки равенства
    \param [in] b второе число для проверки равенства
    \param [out] EQUAL число a равно b
    \returns Равны ли числа

*/


compare_result float_is_equal(const float a, const float b);

#endif // COMPARE_H_INCLUDED

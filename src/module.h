/** @file module.h
 *  @brief Example module (header)
 *
 *  This is an example. Please, change the description.
 *
 *  @author Name Surname - xxx@spbstu.ru
 */

 /** @brief Calculate square of a float variable.
  *
  *  It is returns x*x explicitly.
  *
  *  @param[in] x A float variable.
  *  @return float
  */
float sqr(float x);

/** @brief Apply sqr function to array.
 *
 *  Calculate sqr(x) for each array element. @see sqr()
 *
 *  @param[in] x    A pointer to a float array.
 *  @param[in] size A size of an array.
 *  @return void
 */
void sqr_arr(float* x,  int size);

/** @brief Clear array.
 *
 *  It fills the array with 0s.
 *
 *  @param[in] x    A pointer to a float array.
 *  @param[in] size A size of an array.
 *  @return void
 */
void clear_arr(float* x,  int size);

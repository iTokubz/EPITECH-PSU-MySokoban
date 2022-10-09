/*
** EPITECH PROJECT, 2020
** sort_array
** File description:
** sort
*/

void my_swap_for_sort(int *nbr_1, int *nbr_2)
{
    int temp = *nbr_1;
    *nbr_1 = *nbr_2;
    *nbr_2 = temp;
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;

    while (i < size - 1) {
        if (array[i] > array[i + 1]) {
            my_swap_for_sort(&array[i], &array[i + 1]);
            i = 0;
        } else {
            i++;
        }

    }

    for (int i = 0; i < size - 1; ++i) {
        if (array[i] > array[i + 1]) {
            my_swap_for_sort(&array[i], &array[i + 1]);
            i = 0;
        }
    }
}
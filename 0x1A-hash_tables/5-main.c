#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"
#include "0-hash_table_create.c"
#include "1-djb2.c"
#include "2-key_index.c"
#include "3-hash_table_set.c"
#include "4-hash_table_get.c"
#include "5-hash_table_print.c"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    hash_table_print(ht);
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Bob", "and Kris love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Cool");
    hash_table_set(ht, "98", "Battery Street");
    hash_table_print(ht);
    return (EXIT_SUCCESS);
}
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"
#include "0-hash_table_create.c"
#include "1-djb2.c"
#include "2-key_index.c"
#include "3-hash_table_set.c"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    hash_table_set(ht, "betty", "cool");
    return (EXIT_SUCCESS);
}
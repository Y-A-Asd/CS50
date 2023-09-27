#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <strings.h>

#include <ctype.h>

#include <stdbool.h>

#include "dictionary.h"

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

const unsigned int N = 27;

node *table[N];


bool check(const char *word)
{
    int l = strlen(word);
    char cop[LENGTH + 1];

    for (int i = 0; i < l; i++)
    {
        cop[i] = tolower(word[i]);
    }
    cop[l] = '\0';

    int h = hash(cop);

    node *pntr = table[h];

    while (pntr != NULL)
    {
        if (strcasecmp(pntr->word, cop) == 0)
        {
            return true;
        }
        else
        {
            pntr = pntr->next;
        }
    }
    return false;
}

unsigned int hash(const char *word)
{

    unsigned int v = (int) word[0];
    if (v == 39)
    {
        return 0;
    }
    else if (v > 96)
    {
        return v - 96;
    }
    else
    {
        return v - 64;
    }
}


int count_size = 0;

bool load(const char *dictionary)
{
    FILE *dictnr = fopen(dictionary, "r");
    if (dictnr == NULL)
    {
        return false;
    }
    char wb[LENGTH + 1];
    while (fscanf(dictnr, "%s", wb) != EOF)
    {
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            unload();
            return false;
        }
        strcpy(new->word, wb);
        new->next = NULL;
        int h = hash(new->word);
        node *upp = table[h];
        if (upp == NULL)
        {
            table[h] = new;
            count_size++;
        }
        else
        {
            new->next = table[h];
            table[h] = new;
            count_size++;
        }

    }
    fclose(dictnr);
    return true;
}
unsigned int size(void)
{
    return count_size;
}

bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *upp = table[i];
        node *pntr = upp;
        upp = NULL;
        while (pntr != NULL)
        {
            node *tmp = pntr;
            pntr = pntr->next;
            free(tmp);
        }
    }
    return true;


}
//Yousof.A.Asadi(Y.A.A)11/16/2021
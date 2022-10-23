#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1


typedef struct
{
    int dia, mes, ano;

} Date;

struct aluno

{
    char mat[10], nome[11];
    Date nasc;
    float med;
    struct aluno *next;
};
typedef struct aluno Aluno;

Aluno *include(Aluno *head)
{

    head = (Aluno *)malloc(sizeof(Aluno));

    int dia, mes, ano;

    scanf("%s", head->mat);
    scanf("%s", head->nome);
    scanf("%d/%d/%d", &dia, &mes, &ano);
    head->nasc.dia = dia, head->nasc.mes = mes, head->nasc.ano = ano;
    scanf("%f", &head->med);
    head->next = NULL;
    return head;
}

Aluno *delete (Aluno *insert, const char *mat)
{
    Aluno *aux, *prev = insert;
    for (aux = insert; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->mat, mat) == 0)
        {

            if (aux == insert)
            {
                insert = insert->next;
                free(prev);
                return insert;
            }

            prev->next = aux->next;
            free(aux);
            return insert;
        }
        prev = aux;
    }
    return insert;
}

void aluno_lista(Aluno *insert)
{
    Aluno *aux;

    for (aux = insert; aux != NULL; aux = aux->next)
    {
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->mat, aux->nome, aux->nasc.dia, aux->nasc.mes, aux->nasc.ano, aux->med);
    }
}

int Aluno_count(Aluno *insert)
{
    int count = 0;
    while (insert != NULL)
    {

        count++;
        insert = insert->next;
    }
    return count;
}

void lista_invertida(Aluno *insert)
{
    if (insert == NULL)
        return;
    lista_invertida(insert->next);
    printf("%s, %s, %d/%d/%d, %.2f\n", insert->mat, insert->nome, insert->nasc.dia, insert->nasc.mes, insert->nasc.ano, insert->med);
}

void sair_(Aluno *insert)
{
    Aluno *aux;
    aux = insert;
    while (aux != NULL)
    {
        Aluno *next = aux->next;
        free(aux);
        printf("-");
        aux = next;
    }
}
int ponteiros(Aluno *insert, const char mat[10])
{

    Aluno *aux;
    int count = 0;

    for (aux = insert; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->mat, mat) == 0)
            count++;
    }
    
    return count;
}
Aluno *update(Aluno *insert, Aluno *aux)
{
    if (insert != NULL)
        aux = insert;
    while (TRUE)
    {
        if (aux ->next == NULL)
            return aux;

        aux = aux->next;
    }

    return NULL;
}

int main()
{
    int num;
    char mat[10];

    Aluno *head, *aux, *insert = NULL;

    while (TRUE)
    {
        scanf("%d", &num);
        switch (num)
        {
        case 0:

            sair_(insert);
            exit(0);

            break;
        case 1:

            head = include(head);
            if (insert == NULL)
            {

                insert = head;
                aux = head;
            }

            else
            {
                aux->next = head;
                aux = head;
            }

            break;
        case 2:
            if (!Aluno_count(insert))
                printf("Lista Vazia!\n");

            else
            {
                scanf("%s", mat);
                for (int i = ponteiros(insert, mat); i > 0; i--)
                {

                    insert = delete (insert, mat);
                    aux = update(insert, aux);
                }
            }

            break;

        case 3:

            if (!Aluno_count(insert))
            {
                printf("Lista Vazia!\n");
            }
            else
                aluno_lista(insert);

            break;

        case 4:

            if (!Aluno_count(insert))
            {
                printf("Lista Vazia!\n");
            }
            else
                lista_invertida(insert);

            break;

        case 5:
            if (Aluno_count(insert))
                printf("%d\n", Aluno_count(insert));

            else
                printf("Lista Vazia!\n");

            break;
        }
    }

    return 0;
}
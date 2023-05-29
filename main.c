#include "header.h"

int main(int argc, char *argv[])
{
    FILE *input, *output, *cerinta;
    Node *head;
    int cerinta1 = 0, cerinta2 = 0, cerinta3 = 0, cerinta4 = 0, cerinta5 = 0;
    head = (Node *)malloc(sizeof(Node));
    head = NULL;
    int nr_echipe, i, nr_max_player = 1;
    cerinta = fopen(argv[1], "r");
    input = fopen(argv[2], "r");
    output = fopen(argv[3], "w");
    if (input == NULL || output == NULL)
    {
        printf("Eroare\n");
        return 1;
    }
    if (fscanf(input, "%d", &nr_echipe) == 1)
        for (i = 0; i < nr_echipe; i++)
            Initializare_lista(&head, input, i);
    cerinte(cerinta, &cerinta1, &cerinta2, &cerinta3, &cerinta4, &cerinta5);
    if (cerinta1 == 1 && cerinta2 == 0)
        scriere_nod(head, output);
    while (nr_max_player <= nr_echipe / 2 + 1)
        nr_max_player = nr_max_player * 2;
    while (nr_max_player != nr_echipe)
    {
        pregatire_concurs(&head);
        nr_echipe--;
    }
    if (cerinta2 == 1 && cerinta3 == 0)
        scriere_nod(head, output);
    Queue *q;
    q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
        printf("eroare");
    q->front = (qNode *)malloc(sizeof(qNode));
    q->rear = (qNode *)malloc(sizeof(qNode));
    q->front = NULL;
    q->rear = NULL;
    Node *copy;
    copy = head;
    for (i = 0; i < nr_echipe; i++)
        enQueue(q, &copy);
    if (cerinta3 == 1)
        display_q(q, output);
    int round = 1;
    char round_char[14] = "--- ROUND NO:";
    char winners[21] = "WINNERS OF ROUND NO:";
    stiva *spierzator_top, *scastigator_top, *copie_castigatori;
    lista_castigatori *list_castig;
    list_castig = (lista_castigatori *)malloc(sizeof(lista_castigatori));
    list_castig = NULL;
    copie_castigatori = NULL;
    spierzator_top = NULL;
    scastigator_top = NULL;
    while (nr_echipe != 1)
    {
        if (cerinta3 == 1)
            afisare_runda(output, round, round_char);
        while (q->front != NULL)
        {
            if (cerinta3 == 1)
                meci(output, q->front->nume, q->front->next->nume);
            if (q->front->scor > q->front->next->scor)
            {
                push_elem1(&scastigator_top, q);
                push_elem2(&spierzator_top, q);
            }
            else
            {
                push_elem1(&spierzator_top, q);
                push_elem2(&scastigator_top, q);
            }
            q->front = q->front->next->next;
        }
        adugare_punct(scastigator_top);
        sterge_stiva(spierzator_top);
        copie_castigatori = scastigator_top;
        nr_echipe = nr_echipe / 2;
        for (i = 0; i < nr_echipe; i++)
            enQueue_stiva(q, &scastigator_top);
        if (cerinta3 == 1)
        {
            fprintf(output, "\n");
            afisare_text_winner(output, winners, round);
            int j = 1;
            for (i = 1; i <= round; i++)
                j = j * 2;
            round++;
            afisare_castigatori(output, q, nr_echipe);
            if (j != nr_max_player)
                fprintf(output, "\n");
        }
        if (nr_echipe == 8)
            completare_lista_castigatori(&list_castig, copie_castigatori, nr_echipe);
    }
    arbore *root = (arbore *)malloc(sizeof(arbore));
    lista_castigatori *copie = list_castig;
    root = NULL;
    for (i = 0; i < 8; i++)
    {
        root = insert_arbore(root, copie);
        copie = copie->next;
    }
    copie = list_castig;
    if (cerinta4 == 1)
    {
        fprintf(output, "\n");
        fprintf(output, "TOP 8 TEAMS:\n");
        inordine(output, root, &copie);
    }
    if (cerinta5 == 1)
    {
        arbore_avl *root_avl = (arbore_avl *)malloc(sizeof(arbore_avl));
        root_avl = NULL;
        for (i = 0; i < 8; i++)
        {
            root_avl = insert_arbore_avl(root_avl, list_castig);
            list_castig = list_castig->next;
        }
        scriere_arbore_avl(root_avl, output);
    }
    fclose(input);
    fclose(output);
    fclose(cerinta);
}
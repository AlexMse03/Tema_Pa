#include "header.h"
void Initializare_lista(Node **head, FILE *fp, int nr)
{
    char *buffer;
    int l, i;
    float suma = 0;
    Jucator *head_lista_player;
    head_lista_player = (Jucator *)malloc(sizeof(Jucator));
    head_lista_player = NULL;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->scor = 0;
    buffer = (char *)malloc(50 * sizeof(char));
    if (fp == NULL || buffer == NULL)
        printf("Eroare petnru pointer fp sau buffer");
    fscanf(fp, "%d", &newNode->nr_juc);
    if (fgets(buffer, 50, fp) != NULL)
    {
        l = strlen(buffer);
        newNode->nume_echip = (char *)malloc(l * sizeof(char));
        strcpy(newNode->nume_echip, buffer + 1);
    }
    for (i = 0; i < newNode->nr_juc; i++)
    {
        Jucator *newteam = (Jucator *)malloc(sizeof(Jucator));
        citire_player(&newteam, fp);
        suma = suma + newteam->points;
        add_at_end_player(&head_lista_player, &newteam);
    }
    newNode->scor = suma / newNode->nr_juc;
    newNode->next = *head;
    *head = newNode;
    (*head)->jucatori = head_lista_player;
    free(buffer);
}
void add_at_beginning_player(Jucator **head, Jucator **newplayer)
{
    (*newplayer)->next = *head;
    *head = *newplayer;
}
void add_at_end_player(Jucator **head, Jucator **newplayer)
{
    Jucator *aux = *head;
    if (*head == NULL)
        add_at_beginning_player(&*head, &*newplayer);
    else
    {
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = *newplayer;
        (*newplayer)->next = NULL;
    }
}
void citire_player(Jucator **player, FILE *fp)
{
    Jucator *newplayer = (Jucator *)malloc(sizeof(Jucator));
    char *buffer;
    buffer = (char *)malloc(50 * sizeof(char));
    if (fp == NULL || buffer == NULL)
        printf("Eroare petnru pointer fp sau buffer");
    int i, l;
    if (fscanf(fp, "%s", buffer) != 1)
        printf("eroare citire cuvant");
    l = strlen(buffer);
    newplayer->firstName = (char *)malloc(l * sizeof(char));
    strcpy(newplayer->firstName, buffer);
    buffer = (char *)realloc(buffer, 50 * sizeof(char));
    if (fscanf(fp, "%s", buffer) != 1)
        printf("eroare citire cuvant");
    l = strlen(buffer);
    newplayer->secondName = (char *)malloc(l * sizeof(char));
    strcpy(newplayer->secondName, buffer);
    fscanf(fp, "%d", &newplayer->points);
    (*player)->firstName = newplayer->firstName;
    (*player)->secondName = newplayer->secondName;
    (*player)->points = newplayer->points;
    free(newplayer->firstName);
    free(newplayer->secondName);
    free(newplayer->next);
    free(buffer);
}
void display(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->nr_juc);
        printf("%s", head->nume_echip);
        displayplayer(head->jucatori);
        head = head->next;
        printf("\n");
    }
    printf("\n");
}
void displayplayer(Jucator *head)
{
    while (head != NULL)
    {
        printf("%s ", head->firstName);
        printf("%s ", head->secondName);
        printf("%d\n", head->points);
        head = head->next;
    }
}
void scriere_nod(Node *head, FILE *fp)
{
    while (head != NULL)
    {
        fprintf(fp, "%s", head->nume_echip);
        head = head->next;
    }
}
void scriere_jucator(Jucator *head, FILE *fp)
{
    while (head != NULL)
    {
        fprintf(fp, "%s ", head->firstName);
        fprintf(fp, "%s ", head->secondName);
        fprintf(fp, "%d\n", head->points);
        head = head->next;
    }
}
void pregatire_concurs(Node **head)
{
    if (*head == NULL)
        printf("eroare");
    float minim = 11;
    Node *aux = *head;
    Node *prev = *head;
    while (aux != NULL)
    {
        if (aux->scor < minim)
            minim = aux->scor;
        aux = aux->next;
        /// aflare minim
    }
    aux = *head;
    while (aux->scor != minim)
    {
        aux = aux->next;
    }
    aux = *head;
    if ((*head)->scor == minim)
    {
        *head = (*head)->next;
        free(aux->nume_echip);
        free(aux->jucatori);
        return;
    }
    while (aux != NULL)
    {
        if (aux->scor != minim)
        {
            prev = aux;
            aux = aux->next;
        }
        else
        {
            prev->next = aux->next;
            free(aux->nume_echip);
            return;
        }
    }
}
void enQueue(Queue *q, Node **head)
{
    qNode *newNode = (qNode *)malloc(sizeof(qNode));
    newNode->nume = (*head)->nume_echip;
    int l;
    l = strlen((*head)->nume_echip);
    l = l - 2;
    if ((*head)->nume_echip[l - 1] == ' ')
    {
        strncpy((*head)->nume_echip, (*head)->nume_echip, l - 2);
        (*head)->nume_echip[l + 1] = '\0';
    }
    l = strlen((*head)->nume_echip);
    l = l - 2;
    if ((*head)->nume_echip[l - 1] == ' ')
        printf("spatiu la a 2 a cuvantul %s", (*head)->nume_echip);
    newNode->nume = (*head)->nume_echip;
    newNode->scor = (*head)->scor;
    newNode->next = NULL;
    if (q->front == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    (*head) = (*head)->next;
}
void enQueue_stiva(Queue *q, stiva **top)
{
    qNode *newNode = (qNode *)malloc(sizeof(qNode));
    newNode->nume = (*top)->nume;
    newNode->scor = (*top)->scor;
    newNode->next = NULL;
    if (q->front == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    (*top) = (*top)->next;
    /// mai trebuie adaugat free de stiva top
}
void push_elem1(stiva **top, Queue *q)
{
    stiva(*newNode) = (stiva *)malloc(sizeof(stiva));
    newNode->scor = q->front->scor;
    newNode->nume = q->front->nume;
    newNode->next = (*top);
    *top = newNode;
}
void push_elem2(stiva **top, Queue *q)
{
    stiva(*newNode) = (stiva *)malloc(sizeof(stiva));
    newNode->scor = q->front->next->scor;
    newNode->nume = q->front->next->nume;
    newNode->next = (*top);
    *top = newNode;
}
void display_stack(stiva *top)
{
    while (top != NULL)
    {
        printf("punctaj %f ", top->scor);
        printf("nume %s", top->nume);
        top = top->next;
    }
}
void adugare_punct(stiva *top)
{
    while (top != NULL)
    {
        top->scor++;
        top = top->next;
    }
}
void sterge_stiva(stiva *top)
{
    stiva *aux;
    while (top != NULL)
    {
        aux = top;
        top = top->next;
        /// free(aux);
    }
}
void completare_lista_castigatori(lista_castigatori **head, stiva *top, int max)
{
    for (int i = 0; i < max; i++)
    {
        lista_castigatori(*newNode) = (lista_castigatori *)malloc(sizeof(lista_castigatori));
        newNode->nume = top->nume;
        /// printf("nume %s", newNode->nume);
        newNode->scor = top->scor;
        newNode->next = (*head);
        *head = newNode;
        top = top->next;
    }
}
void display_lista_c(lista_castigatori *top)
{

    while (top != NULL)
    {
        printf("punctaj %f ", top->scor);
        printf("nume %s", top->nume);
        top = top->next;
    }
}
void display_q(Queue *q, FILE *output)
{
    qNode *copy;
    copy = q->front;
    while (copy != NULL)
    {
        int l;
        l = strlen(copy->nume);
        l = l - 2;
        fprintf(output, "%.*s", l, copy->nume);
        /// printf("stiva nume %s", copy->nume);
        fprintf(output, "\n");
        copy = copy->next;
    }
    fprintf(output, "\n");
}
void afisare_runda(FILE *output, int round, char *round_char)
{

    fprintf(output, "%s", round_char);
    fprintf(output, "%d", round);
    fprintf(output, "\n");
}
void afisare_text_winner(FILE *output, char *winners, int round)
{
    fprintf(output, "%s", winners);
    fprintf(output, "%d", round);
    fprintf(output, "\n");
}
void meci(FILE *output, char *primul, char *al2lea)
{
    int l;
    l = strlen(primul);
    l = l - 2;
    /// printf("lungime primul %d\n", l);
    fprintf(output, "%.*s", l, primul);
    for (int i = 0; i < 33 - l; i++)
        fprintf(output, " ");
    fprintf(output, "-");
    l = strlen(al2lea);
    l = l - 2;
    /// printf("%s este aici", al2lea);
    for (int i = 0; i < 33 - l; i++)
        fprintf(output, " ");
    fprintf(output, "%.*s", l, al2lea);
    fprintf(output, "\n");
}
void afisare_castigatori(FILE *output, Queue *q, int nr_echipe)
{
    qNode *copy;
    copy = q->front;
    for (int i = 0; i < nr_echipe; i++)
    {
        int l;
        l = strlen(copy->nume);
        l = l - 2;
        fprintf(output, "%.*s", l, copy->nume);
        for (int i = 0; i < 34 - l; i++)
            fprintf(output, " ");
        fprintf(output, "-");
        fprintf(output, "  ");
        fprintf(output, "%.2f", copy->scor);
        fprintf(output, "\n");
        copy = copy->next;
    }
}
arbore *insert_arbore(arbore *node, lista_castigatori *head)
{
    if (node == NULL)
        return newNode_arbore(head->nume, head->scor);
    if (head->scor < node->scor)
        node->left = insert_arbore(node->left, head);
    else if (head->scor > node->scor)
        node->right = insert_arbore(node->right, head);
    else if (strcmp(head->nume, node->nume) < 0)
        node->left = insert_arbore(node->left, head);
    else
        node->right = insert_arbore(node->right, head);
    return node;
}
arbore *newNode_arbore(char *nume, float scor)
{
    arbore *newNode = (arbore *)malloc(sizeof(arbore));
    newNode->nume = nume;
    newNode->scor = scor;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void inordine(FILE *output, arbore *root, lista_castigatori **head)
{
    if (root == NULL)
    {
        return;
    }
    inordine(output, root->right, head);
    int l;
    l = strlen(root->nume);
    l = l - 2;
    /// printf("verf nume %s", root->nume);
    (*head)->nume = root->nume;
    (*head)->scor = root->scor;
    (*head) = (*head)->next;
    fprintf(output, "%.*s", l, root->nume);
    for (int i = 0; i < 34 - l; i++)
        fprintf(output, " ");
    fprintf(output, "-  ");
    fprintf(output, "%.2f\n", root->scor);
    inordine(output, root->left, head);
}
void cerinte(FILE *cerinte, int *cerinta1, int *cerinta2, int *cerinta3, int *cerinta4, int *cerinta5)
{
    fscanf(cerinte, "%d", &(*cerinta1));
    fscanf(cerinte, "%d", &(*cerinta2));
    fscanf(cerinte, "%d", &(*cerinta3));
    fscanf(cerinte, "%d", &(*cerinta4));
    fscanf(cerinte, "%d", &(*cerinta5));
}
void inordine_avl(FILE *output, arbore_avl *root)
{
    if (root == NULL)
    {
        return;
    }
    inordine_avl(output, root->right);
    printf("scor %f si nume %s", root->scor, root->nume);
    inordine_avl(output, root->left);
}
int arboreHeight(arbore_avl *root)
{
    if (root == NULL)
        return -1;
    else
        return root->height;
}
arbore_avl *LRRotation(arbore_avl *Z)
{
    Z->left = leftRotation(Z->left);
    return rightRotation(Z);
}
arbore_avl *RLRotation(arbore_avl *Z)
{
    Z->right = rightRotation(Z->right);
    return leftRotation(Z);
}
arbore_avl *leftRotation(arbore_avl *z)
{
    arbore_avl *y = z->right;
    arbore_avl *T2 = y->left;
    y->left = z;
    z->right = T2;
    z->height = max(arboreHeight(z->left), arboreHeight(z->right)) + 1;
    y->height = max(arboreHeight(y->left), arboreHeight(y->right)) + 1;
    return y;
}
arbore_avl *rightRotation(arbore_avl *z)
{
    arbore_avl *y = z->left;
    arbore_avl *T3 = y->right;
    y->right = z;
    z->left = T3;
    z->height = max(arboreHeight(z->left), arboreHeight(z->right)) + 1;
    y->height = max(arboreHeight(y->left), arboreHeight(y->right)) + 1;
    return y;
}
int max(int a, int b)
{
    if (a < b)
        return b;
    if (a >= b)
        return a;
}
arbore_avl *insert_arbore_avl(arbore_avl *root, lista_castigatori *head)
{
    if (root == NULL)
    {
        root = (arbore_avl *)malloc(sizeof(arbore_avl));
        root->nume = head->nume;
        root->scor = head->scor;
        root->height = 0; // adaugare ca frunza
        root->left = root->right = NULL;
        return root;
    }
    if (head->scor < root->scor)
        root->left = insert_arbore_avl(root->left, head);
    else if (head->scor > root->scor)
        root->right = insert_arbore_avl(root->right, head);
    else
    {
        if (strcmp(head->nume, root->nume) < 0)
            root->left = insert_arbore_avl(root->left, head);
        else
            root->right = insert_arbore_avl(root->right, head);
    }
    root->height = 1 + max(arboreHeight(root->left), arboreHeight(root->right));
    int k = (arboreHeight(root->left) - arboreHeight(root->right));
    if (k > 1 && head->scor < root->left->scor)
        return rightRotation(root);
    if (k > 1 && head->scor == root->left->scor)
        if (k > 1 && strcmp(head->nume, root->nume) < 0)
            return rightRotation(root);

    if (k < -1 && head->scor > root->right->scor)
        return leftRotation(root);
    if (k < -1 && head->scor == root->right->scor)
        if (k < -1 && strcmp(head->nume, root->nume) > 0)
            return leftRotation(root);

    if (k > 1 && head->scor > root->left->scor)
        return RLRotation(root);
    if (k > 1 && head->scor == root->left->scor)
        if (k > 1 && strcmp(head->nume, root->nume) > 0)
            return RLRotation(root);

    if (k < -1 && head->scor < root->right->scor)
        return LRRotation(root);
    if (k < -1 && head->scor == root->right->scor)
        if (k < -1 && strcmp(head->nume, root->nume) < 0)
            return LRRotation(root);
    return root;
}
void afisare_nivel2(arbore_avl *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("root %f ", root->scor);
    ///
    ("%s", root->nume);
    /// printf("left %f ", root->left->scor);
    /// printf("%s", root->left->nume);
    /// printf("right %f ", root->right->scor);
    /// printf("%s", root->right->nume);

    if (root->right != NULL)
    {
        printf("right right %f ", root->right->right->scor);
        printf("%s", root->right->right->nume);
        printf("right left %f ", root->right->left->scor);
        printf("%s", root->right->left->nume);
    }
    if (root->left != NULL)
    {
        printf("left right %f ", root->left->right->scor);
        printf("%s", root->left->right->nume);
        printf("left left %f ", root->left->left->scor);
        printf("%s", root->left->left->nume);
    }
    /// printf("%s", root->right->left->left->nume);
}
void scriere_arbore_avl(arbore_avl *root, FILE *output)
{
    fprintf(output, "\n");
    fprintf(output, "THE LEVEL 2 TEAMS ARE:\n");
    if (root->right != NULL)
    {
        fprintf(output, "%s", root->right->right->nume);
        fprintf(output, "%s", root->right->left->nume);
    }
    if (root->left != NULL)
    {
        fprintf(output, "%s", root->left->right->nume);
        fprintf(output, "%s", root->left->left->nume);
    }
}
void afisare(arbore *root)
{
    if (root == NULL)
    {
        return;
    }
    afisare(root->left);
    printf("scor %f si nume %s", root->scor, root->nume);
    afisare(root->right);
    /// printf("radacina %s", root->nume);
}
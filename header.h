#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Player
{
    char *firstName;
    char *secondName;
    int points;
    struct Player *next;
};
typedef struct Player Jucator;
struct echipa
{
    int nr_juc;
    char *nume_echip;
    struct Player *jucatori;
    float scor;
    struct echipa *next;
};
typedef struct echipa Node;
struct lista
{
    char *nume;
    float scor;
    struct lista *next;
};
typedef struct lista lista_castigatori;
struct a
{
    char *nume;
    float scor;
    struct a *left, *right;
};
typedef struct a arbore;
struct avl
{
    int height;
    float scor;
    char *nume;
    struct avl *left, *right;
};
typedef struct avl arbore_avl;
struct s
{
    char *nume;
    float scor;
    struct s *next;
};
typedef struct s stiva;
struct q
{
    char *nume;
    float scor;
    struct q *next;
};
typedef struct q qNode;
struct Q
{
    qNode *front, *rear;
};
typedef struct Q Queue;
void Initializare_lista(Node **, FILE *, int);
void citire_player(Jucator **, FILE *);
void add_at_end_player(Jucator **, Jucator **);
void add_at_beginning_player(Jucator **, Jucator **);
void displayplayer(Jucator *);
void display(Node *);
void scriere_nod(Node *, FILE *);
void scriere_jucator(Jucator *, FILE *);
void pregatire_concurs(Node **);
void stergere(Node **);
void enQueue(Queue *, Node **);
void enQueue_stiva(Queue *, stiva **);
void push_elem1(stiva **, Queue *);
void push_elem2(stiva **, Queue *);
void display_stack(stiva *);
void adugare_punct(stiva *);
void sterge_stiva(stiva *);
void completare_lista_castigatori(lista_castigatori **, stiva *, int);
void display_lista_c(lista_castigatori *);
void display_q(Queue *, FILE *);
void afisare_runda(FILE *, int, char *);
void meci(FILE *, char *, char *);
void afisare_text_winner(FILE *, char *, int);
void afisare_castigatori(FILE *, Queue *, int);
arbore *insert_arbore(arbore *, lista_castigatori *);
arbore *newNode_arbore(char *, float);
void inordine(FILE *, arbore *, lista_castigatori **);
int arboreHeight(arbore_avl *);
int max(int a, int b);
arbore_avl *LRRotation(arbore_avl *);
arbore_avl *RLRotation(arbore_avl *);
arbore_avl *leftRotation(arbore_avl *);
arbore_avl *rightRotation(arbore_avl *);
arbore_avl *insert_arbore_avl(arbore_avl *, lista_castigatori *);
void inordine_avl(FILE *, arbore_avl *);
void afisare_nivel2(arbore_avl *);
void cerinte(FILE *, int *, int *, int *, int *, int *);
void scriere_arbore_avl(arbore_avl *, FILE *);
void afisare(arbore *);
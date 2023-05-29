# Checker Tema 1 - 2021

Checker-ul este o aplicație de testare automată a temelor. Este un produs open-source realizat de către și pentru studenții din Facultatea de Automatică și Calculatoare - UPB, și este menit atât să usureze munca asistenților de a corecta teme cât și sa ofere studenților o evaluare cât mai obiectivă.

## Rularea checker-ului

Pentru a verifica functionarea checker-ului va trebui sa descarcati tot depozitul de mai sus, dupa aceasta deschideti un terminal in folderul in care se afla depozitul descarcat si scrieti urmatoarea comanda:

```shell
./checker.sh
```

Task1:

- am creat o lista principala care contine ca si date numele echipei, nr de participanti ai echipei, un pointer catre o alta lista care are ca si nod un player din echipa respectiva, acest player fiind caracterizat de numele lui si scorul obtinut. Lista principala contine si scorul ce reprezinta media aritmetica pentru toti playerii din echipa

Task2:

- am determinat minimul scorului dintre toate echipele dupa care am eliminat echipa din lista cu scorul egal cu minimul si am actualizat nr echipelor participante

Task3:

-am creat stivele si coada necesara si am inceput sa realizez meciurile
-se actualizeaza stivele si cozile conform enuntului iar coada est reactualizata, retinand informatiile memorate in stiva cu castigatori
-cand nr de echipe este egal cu 8 se retin echipele intr o lista(lista retine numele echipei si scorul) iar meciurile se realizeaza in continuare pana la aflarea castigatorului

Task4:

-am inserat elementele din lista in arborele bst iar in cazul in care scorul coincide am folosit pentru departajare functia predefinita strcmp
-pentru afisarea descrescatoare am folosit o functie ce parcurge arborele incpand cu subarborele drept, radacina si subarborele stang(inordine dRs)

Task5:

-cand am afisat echipele la task4 am creat o noua lista care contine echipele in ordinea descrescatoare
-am inserat pe rand cate o echipa in arborele avl si l-am echilibrat pt fiecare echipa introdusa
-la sfarsit am afisat folosind o functie ce afiseaza echipele de pe nivel 2 incepand de la dreapta la stanga(ordinea:root->right->right,root->right->left,root->left->right,root->left->left)

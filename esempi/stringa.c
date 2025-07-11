#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Studente
{
    char *nome;
    char cognome[10];
};

int main()
{
    struct Studente miei[2];
    struct Studente mio;
    struct Studente mio2 = {"Ab", "Bb"};
    mio.nome = "Mario";
    strcpy(mio.cognome, "Bianchi");

    // riassegnazione
    mio.nome = "Mario2";
    strcpy(mio.cognome, "Bianchi2");
    mio2.nome = "CC";

    // modifica
    // mio.nome[0]= 'W'; segmentation fault
    mio.cognome[0] = 'W';
    // mio2.nome[0]='W';
    mio2.cognome[0] = 'W';

    // però posso fare
    mio.nome = malloc(10 * sizeof(char));
    strcpy(mio.nome, "Mario");
    mio.nome[0] = 'W';

    printf("%s - %s\n", mio.nome, mio.cognome);
    printf("%s - %s\n", mio2.nome, mio2.cognome);

    // ricordati di liberare la memoria se usi malloc
    free(mio.nome);
    return 0;
}
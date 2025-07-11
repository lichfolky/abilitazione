#include <stdio.h>
#include <string.h>

struct MiaStruttura
{
    int dato;
    struct MiaStruttura *altraStruttura;
};

int main()
{
    struct Studente st = {"Luigi", "Verdi", 2.0};
    strcpy(st.cognome, "Rossi");
    st.media = 10.0;
    printf("%s %s ha media %.1f\n", st.nome, st.cognome, st.media);
}
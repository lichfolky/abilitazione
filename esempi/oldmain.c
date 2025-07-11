#include <stdio.h>
#include <stdlib.h> // per usare malloc
#include <string.h> // per usare strcmp
#include "mystruct.h" 


void printAnimale(struct Animale mioAnimale){
    printf("%s ha %d anni\n", mioAnimale.nome, mioAnimale.anni);
}
void testAnimale(struct Animale mioAnimale){
    printf("%s ha %d anni\n", mioAnimale.nome, mioAnimale.anni);
}

int main() {
    Persona p4 = {"Giovanni Neri", 40};
    struct Animale anim;
    struct Animale *mio = malloc(sizeof(struct Animale));
    anim.anni = 1;
    strcpy(anim.nome,"uno");
    struct Animale *test = &anim;
    mio->anni = 2; 
    // invece di (*mio).anni 
    // prima deferenzio poi accedo
    mio->nome = "due";
    test->anni = 100;
    printAnimale(anim);
    printf("%s\n",p4.nome);
    printAnimale(*mio);
    printAnimale(*test);
    return 0;
}

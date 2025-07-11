#include <stdio.h>

typedef struct {
    int anni;
    char nome[10];
} Animale;


void printAnimale(Animale mioAnimale){
    printf("%s ha %d anni\n", mioAnimale.nome, mioAnimale.anni);
}
void editAnimaleVal(Animale myanimale){
    myanimale.nome = "bello";
}
void editAnimaleRef(Animale *myanimale){
    myanimale->nome = "bello";
}

int main() {
    Animale anim1 = {1,"brutto"};
    Animale anim2 = {2,"brutto"};
    printAnimale(anim1);
    editAnimaleVal(anim1);
    printAnimale(anim1);
    editAnimaleRef(&anim1);
    printAnimale(anim1);
    printf("%d",sizeof(Animale));
    return 0;
}

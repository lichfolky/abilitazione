#include <stdio.h>
#include <string.h>

int main()
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num); // & is the address-of operator
    printf("You entered: %d\n", num);
    float price;
    printf("Enter price: ");
    scanf("%f", &price);
    printf("Price: %.2f\n", price);
    char name[50];
    printf("Enter your name (no spaces): ");
    scanf("%s", name); // No & for strings (arrays decay to pointers)
    printf("Hello, %s!\n", name);

    // safe
    char buffer[100];
    int num;
    char ch;
    printf("Enter a number: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &num);

    /*
    buffer: Where to store the input (e.g., char[100]).

    max_size: Maximum characters to read (prevents buffer overflow).

    stdin: Standard input (keyboard).
        */
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    printf("You wrote: %s", sentence);
    // ⚠ Note: fgets() includes the newline (\n) in the buffer. To remove it:
    sentence[strcspn(sentence, "\n")] = '\0'; // Removes trailing newline

    strlen("ok");
}
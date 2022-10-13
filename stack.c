#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

struct stack_st{
    int len;
    int arr[STACK_SIZE];
};

struct stack_st stack = {.len = 0};

/* Globaalse pinu pikkus, ehk mitu elementi on pinus. Antud muutuja väärtust
   on võimalik kasutada massiivist viimase elemendi leidmiseks, mis asub indeksil
   stack_len - 1, sest massiivi indekseerimine algiab 0-st ja esimene vaba koht,
   kui see eksisteerib asub indeksil stack_len.
*/

/* Globaalne pinu int väärtustest pikkusega stack_size. Olulised indeksid:
   stack[stack_len - 1]    - pinu pealmine element, kui stack_len > 0,
   stack[stack_len]        - massiivi esimene "vaba" koht, kui stack_len < stack_size 
*/

/* Funktsioon push saab parameetriks int tüüpi väärtuse, mille lisab globaalsesse pinusse, kui
 * selles on veel ruumi. Vastasel korral trükib ekkraanile vea. Funktsioon ei tagasta midagi.
 */

void stack_push(int element) {
    /* Kontrollime kas pinus on veel ruumi, kui ei ole, siis trükime ekraanile veateate. */
    if (stack.len >= STACK_SIZE) {
        printf("Viga: pinusse rohkem elemente ei mahu!\n");
        return;
    }

    /* Antud hetkel teame, et pinusse mahub veel vähemalt üks element. */
    stack.arr[stack.len] = element;

    /* Suurendame pinusse lisatud elementide arvu. */
    stack.len++;

    return;
}

/* Funktsioon pop ei saa ühtegi parameetrit ja tagastab globaalse pinu pealmise elemendi, mille ta
 * pinust eemaldab. Kui pinu on juba tühi, siis funktsioon tagastab väärtuse 0.
 */
int stack_pop(void) {
    /* Kontrollime, kas pinus on elemente. Kui ei ole, siis tagastame väärtuse 0. */
    if (stack.len == 0) {
        /* Pinu on tühi, tagastame väärtuse 0. */
        return 0;
    }

    /* Teame, et pinus on vähemalt üks element. */
    int element = stack.arr[stack.len - 1];

    /* Vähendame pinu elementide arvu. */
    stack.len--;

    /* Tagastame eemaldatud väärtuse. */
    return element;
}

/* Funktsioon isEmpty tagastab tõeväärtuse (0-vale ja mitte 0 tõene) vastavalt sellele kas
 * pinu on tühi või mitte.
*/
int stack_isEmpty(void) {
    //return stack_len == 0;
    /* Int väärtus võib olla ka negatiivne, pigem kontrollime kas stack_len on suurem kui 0. */
    return !(stack.len > 0);
}

/* Funktsioon peek tagastab pinu pealmise elemendi ilma seda eemaldamata.
 * Kui pinu on tühi, siis see tagastab 0 väärtuse.
 */
int stack_peek(void) {
    /* Kontrollime, kas pinu on tühi, sel juhul tagastame 0 väärtuse. */
    if (stack.len == 0) {
        return 0;
    }
    /* Teame, et pinu ei ole tühi, seega tagastame pealmise elemendi. */
    return stack.arr[stack.len - 1];
}

/* Funktsioon print_stack trükib ekraanile kõik pinu elemendid eraldi reale alustades ülemisest. */
void stack_print(void) {
    /* Alustame trükkimist ülemisest elemendist, seega liigume praeguest pikkusest nulliini. */
    int i = stack.len - 1;
    while (i >= 0) {
        printf("%d\n", stack.arr[i]);
        i--;
    }
    return;
}
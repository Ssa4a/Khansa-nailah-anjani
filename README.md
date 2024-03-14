Pada tugas kali ini tertera tugas membuat program dengan menggunakan pointer untuk menyelesaikan permasalahan yang diberikan yaitu Pada abad ke 500 SM terdapat raja yang mengadakan sayembara, barang siapa yang berhasil mengkategorikan 500 naskah pidato raja sesuai dengan kategori yang ditentukan maka dia akan diberi imbalan sebuah tanah seluas 500 hektar.leng long ling yang menggunakan mesin waktunya untuk kembali ke 500SM pun sangat kegirangan. Leng Long Ling pun ikut pada sayembara tersebut dan membuat sebuah program yang bisa mengkategorikan naskah raja ke kategori yang ditentukan karena leng long ling tidak berencana untuk menetap disana jadi sumber daya yang ia gunakan cukup sedikit. leng long ling berencana untuk menggunakan pointer agar lebih efisien.

Berikut codingan yang akan diberi untuk membantu menyelesaikan masalah dari cerita tersebut.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

void lessThanRequired (){
    printf("The length of your text is less than specified, please update your text,keep it spirit!\n");
}

void equalThanRequired (){
    printf("Thank you, Your text length is correct\n");
}

void moreThanRequired (){
    printf("Sorry:( your text is too long, please reduce the text\n");
}

int checkLenghtRequirement(char* text){
    int length = strlen(text);
    if (length < MIN_LENGTH)
        return 0;
    else if (length == MIN_LENGTH)
        return 1;
    else if (length <= MAX_LENGTH)  // Added condition for maximum length
        return 2;
    else
        return 3; //when length exceeds MAX_LENGTH
}

int main() {
    int length, lengthOfText, selectOption;
    FILE *fptr = NULL;
    char text[MAX_LENGTH];

    fptr = fopen("file.txt", "r");

    if(fptr == NULL){
        printf("Error");
        exit(1);
    }

    fgets(text, MAX_LENGTH, fptr);

    fclose(fptr);

    selectOption = checkLenghtRequirement(text);

    void (*functions[3])() = {lessThanRequired, equalThanRequired, moreThanRequired};
    lengthOfText = (MIN_LENGTH * (selectOption == 0)) + (MIN_LENGTH * (selectOption == 2));

    functions[selectOption]();

    printf("\nThe Length is updated to %d", lengthOfText);
    printf("\n===============================================");

    return 0;
}

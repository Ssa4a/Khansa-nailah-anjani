# Tugas
###### _Khansa Nailah Anjani | IF-03-02 | 1203230038_

Pada tugas kali ini tertera tugas membuat program dengan menggunakan pointer untuk menyelesaikan permasalahan yang diberikan yaitu Pada abad ke 500 SM terdapat raja yang mengadakan sayembara, barang siapa yang berhasil mengkategorikan 500 naskah pidato raja sesuai dengan kategori yang ditentukan maka dia akan diberi imbalan sebuah tanah seluas 500 hektar.leng long ling yang menggunakan mesin waktunya untuk kembali ke 500SM pun sangat kegirangan. Leng Long Ling pun ikut pada sayembara tersebut dan membuat sebuah program yang bisa mengkategorikan naskah raja ke kategori yang ditentukan karena leng long ling tidak berencana untuk menetap disana jadi sumber daya yang ia gunakan cukup sedikit. leng long ling berencana untuk menggunakan pointer agar lebih efisien.


- Code
- Penjelasan


### Code

```
//DECLARE LIBRARY YANG DIGUNAKAN 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DECLARE MAKSIMUM DAN MINIMUM UNTUK TEXT LENGTH
#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

//FUNGSI UNTUK MENAMPILKAN OUTPUT BERDASARKAN KONDISI LENGTH TEXT 
void lessThanRequired (){
    printf("The length of your text is less than specified, please update your text,keep it spirit!\n");
}

void equalThanRequired (){
    printf("Thank you, Your text length is correct\n");
}

void moreThanRequired (){
    printf("Sorry:( your text is too long, please reduce the text\n");
}

// MEMBUAT FUNGSI UNTUK MELAKUKAN CEK TERHADAP LENGTH TEXT
int checkLenghtRequirement(char* text){
    int length = strlen(text);
    if (length < MIN_LENGTH) //KONDISI JIKA LENGTH KURANG DARI JUMLAH MINIMUM LENGHT 
        return 0;
    else if (length == MIN_LENGTH) //KONDISI JIKA LENGTH SAMA DENGAN MINIMUM LENGTH
        return 1;
    else if (length <= MAX_LENGTH)  //KONDISI JIKA LENGTH KURANG DARI SAMA DENGAN JUMLAH MAKSIMAL LENGTH
        return 2;
    else
        return 3; 
}

//MENDEKLARASI MAIN PROGRAM 
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

    //MEMANGGIL FUNGSI UNTUK MELAKUKAN PENGECEKAN TEXT 
    void (*functions[3])() = {lessThanRequired, equalThanRequired, moreThanRequired};
    lengthOfText = (MIN_LENGTH * (selectOption == 0)) + (MIN_LENGTH * (selectOption == 2));

    functions[selectOption]();

    //OUTPUT DITAMBAH HASIL YANG SUDAH DIDAPATKAN SEETELAH MELALUI PROSES PENGECEKAN 
    printf("\nThe Length is updated to %d", lengthOfText);
    printf("\n===============================================");

    return 0;
}
```



### Penjelasan

berikut adalah penjelasan mengenai code program diatas : 


```
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
```
Baris diatas berguna untuk mengimpor tiga header file standar yang diperlukan untuk operasi input/output, alokasi memori, dan manipulasi string.

```
#define MAX_LENGTH 2024
#define MIN_LENGTH 1945
```
Baris diatas terdapat dua makro yang didefinisikan untuk menetapkan panjang maksimum dan minimum yang diperbolehkan untuk teks. Seperti pada program panjang maksimum 2024 dan panjang minimum 1945.

```
void lessThanRequired (){
    printf("The length of your text is less than specified, please update your text\n");
}

void equalThanRequired (){
    printf("Thank you, Your text length is correct\n");
}

void moreThanRequired (){
    printf("Your text is too long, please reduce the text\n");
}
```
Tiga fungsi diatas nantinya akan mencetak sebuah pesan (output),yang dimana memberikan output tergantung dari kondisi panjang teks yang akan diperiksa. Seperti panjang teks kurang dari yang diizinkan,panjang teks sudah sesuai dengan yang diizinkan,panjang teks terlalu panjang dan perlu dipersingkat. Fungsi ini digunakan dalam program untuk memberikan umpan balik kepada pengguna berdasarkan panjang teks yang diberikan.


```
int checkLenghtRequirement(char* text){
    int length = strlen(text);
    if (length < MIN_LENGTH)
        return 0;
    else if (length == MIN_LENGTH)
        return 1;
    else if (length <= MAX_LENGTH)  
        return 2;
    else
        return 3; 
}
```
Diatas adalah fungsi yang akan memeriksa panjang teks yang diberikan dan akan mengembalikan nilai yang menunjukkan kondisi apakah panjangnya kurang dari minimum, sama dengan minimum, atau lebih dari minimum,tetapi kurang dari atau sama dengan maksimum seperti yang ditentukan.

```
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
```
Barisan dalam fungsi main() diatas,terdapat beberapa variabel yang dideklarasikan untuk menyimpan panjang teks, pilihan opsi, pointer file, dan array untuk menyimpan teks dari file.

File "file.txt" dibuka dan teksnya dibaca ke dalam array text. File ditutup setelah selesai dibaca. 

Kemudian, fungsi checkLengthRequirement() dipanggil untuk memeriksa panjang teks dan memutuskan opsi mana yang harus dipilih. Berdasarkan pilihan tersebut, fungsi yang sesuai dipilih dari array fungsi dan dipanggil. Panjang teks yang akan diupdate juga dihitung dan dicetak di akhir.

Kemudian selesailah jalan program diatas.

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)

   [dill]: <https://github.com/joemccann/dillinger>
   [git-repo-url]: <https://github.com/joemccann/dillinger.git>
   [john gruber]: <http://daringfireball.net>
   [df1]: <http://daringfireball.net/projects/markdown/>
   [markdown-it]: <https://github.com/markdown-it/markdown-it>
   [Ace Editor]: <http://ace.ajax.org>
   [node.js]: <http://nodejs.org>
   [Twitter Bootstrap]: <http://twitter.github.com/bootstrap/>
   [jQuery]: <http://jquery.com>
   [@tjholowaychuk]: <http://twitter.com/tjholowaychuk>
   [express]: <http://expressjs.com>
   [AngularJS]: <http://angularjs.org>
   [Gulp]: <http://gulpjs.com>

   [PlDb]: <https://github.com/joemccann/dillinger/tree/master/plugins/dropbox/README.md>
   [PlGh]: <https://github.com/joemccann/dillinger/tree/master/plugins/github/README.md>
   [PlGd]: <https://github.com/joemccann/dillinger/tree/master/plugins/googledrive/README.md>
   [PlOd]: <https://github.com/joemccann/dillinger/tree/master/plugins/onedrive/README.md>
   [PlMe]: <https://github.com/joemccann/dillinger/tree/master/plugins/medium/README.md>
   [PlGa]: <https://github.com/RahulHP/dillinger/blob/master/plugins/googleanalytics/README.md>

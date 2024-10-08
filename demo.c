#include <stdio.h>

/*
  *
  * Mendemokan sebuah "bug" dari FILE stream saat setelah operasi fgets dengan scanf
  *
  * Sesungguhnya, scanf tidak 'membaca' stream FILE (default stdin) sampai dengan '\n'
  *
  * Makanya saat setelah scanf dilanjutkan dengan fgets apa yang terjadi masih ada 'sisa' pada stream FILE yakni '\n'
  */

int main(void)
{
  while(1)
  {
    char str[256];
    int dev;
  
    printf("input str:\n");
    fgets(str,255,stdin);
    printf("%s\n", str);
    printf("input int:\n");
    scanf("%d",&dev);
    printf("%d\n",dev);

    /*
     * menggunakan getchar() pada akhir atau sebelum operasi fgets() adalah untuk 'membuang' sisa-sisa non numerik-karakter dalam stream
     * dalam kasus ini adalah sebuah DATALINKESCAPE atau '\n'
    */
    //printf("%d %d\n",getchar(), '\n'); // comment baris ini untuk melihat apa yang ingin didemokan
  }
  return 0;
}

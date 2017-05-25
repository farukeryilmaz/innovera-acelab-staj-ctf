/* 
Faruk Eryilmaz.
Innovera staj alim yarismasinda birinci sorunun cozumu icin yazmis oldugum basit C programi.
Cozum yazisi: https://farukeryilmaz.com/innovera-acelab-staj-alim-ctf-yarismasi-17/
*/

#include <stdio.h>

int main(void)
{
	int bin = 0,	// binary. varsayilan olarak 0'dan baslar
		k = 0,		// "k" karakterinin sayisi
		i, j;		// dongu indexleri
	
	char temp;

	errno_t err;
	FILE *encoded_text;
	err = fopen_s(&encoded_text, "soru.txt", "r");

	if (err != 0)
		puts("File read error!"); // dosya bulunamazsa veya hata olusursa ekrana cikti verir.
	else
	{
		// "Coz beni." yazisina veya dosya sonuna ulasincaya kadar okuma islemi yapar
		while (fscanf(encoded_text, "%c", &temp) != EOF && temp != 'o') 
		{
			// her "ACE" ve "LAB" kelimesinden sonra gelen "k" harfini sayar
			if (temp == 'k')
				k++;
			
			/* bosluga ulasinca yani "k" harfi bitince, harf sayisi kadar ekrana 0 yazdirir,
				daha sonra binary 1 olur ve k yi sifirlar, bir sonraki kelime icin k sayar, ekrar yazdirir */
			if (temp == ' ' || temp == '\0' || temp == '\n'){
				for (j = 0; j < k; j++)
					printf("%d", bin);
				bin = (bin + 1) % 2;
				k = 0;
			}
		}
	}
	printf("\n");

	return(0);
}
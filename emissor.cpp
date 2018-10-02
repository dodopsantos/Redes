#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void byte2bits(char* bit);
void gravar_arquivos(char* bit);

char palavra[99];

int main()
{
    char bits[9];
	
    printf("Insira um caractere\n");
    scanf("%[^\n]", palavra);
    byte2bits(bits);
    gravar_arquivos(bits);
    printf("Binario: %s\n", bits);
       
 }

void byte2bits(char* bit)
{
char c;

	for(int j=0;j < strlen(palavra);j++){

	c = palavra[j];

	int i = 7;
	while(i >= 0){

		*bit++ = '0' + ((c >> i--)&0x1);
		
	}	  
		*bit = 0;
	}
}

void gravar_arquivos(char* bit)
{
	FILE *arq;
	FILE *code;
	char binarios[99];
	int flagP=0, flagN=0;
	
	strcpy(binarios, bit);
	
	code = fopen("binarios.txt", "w");
		fprintf(code, "%s", bit);
	fclose(code);
	arq = fopen("amostra.txt", "w");

		fprintf(arq, "Palavra: %s\nBinário: %s\n\n",palavra, bit);
		
		for(int i = 0; i < strlen(binarios); i++){
		if(binarios[i] == '1'){
			if(flagP > 0){
				fprintf(arq, "   _");
			}else{
				fprintf(arq, "  _");
			}
			flagP++;
			flagN=0;	
		}else if(binarios[i] == '0'){
			if(flagN > 0){
				fprintf(arq, " _  ");
			}else{
				fprintf(arq, "_  ");
			}
			flagN++;
			flagP=0;
		}
	}
	flagP=0;
	flagN=0;
	fprintf(arq, "\n");
	for(int j = 0; j < strlen(binarios); j++){		
		
		if(binarios[j] == '1'){
			if(flagP > 0){
				fprintf(arq, "|");
			}
			fprintf(arq, "_| ");
			flagP++;
			flagN=0;
		}else if(binarios[j] == '0'){
			if(flagN > 0){
				fprintf(arq, "|");
			}
			fprintf(arq, " |_");
			flagN++;
			flagP=0;
		}
		
	}
		
	fclose(arq);
}



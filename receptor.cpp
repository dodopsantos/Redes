#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

void read();
void ASCII();

char ch[256];
char *result;

main(){
	read();
	ASCII();
}

void read(){
	char url[]="binarios.txt";
	
	FILE *code;
	
	code = fopen(url, "r");
	if(code == NULL)
	    printf("Erro, nao foi possivel abrir o arquivo\n");
	else
		result = fgets(ch, 256, code);
    	
	fclose(code);
	
}

void ASCII(){
	char matriz[256];
	char letra[8] = "";
	int cont=0;
	int byte=0;
	int dec=0;
	
	printf(" |------------ Receptor ------------ *\n");
	printf(" |\n");
	printf(" | Palavra: ");
			
	strcpy(matriz, result);

	for(int i=0;i < (strlen(matriz)/8);i++){
		
		for(int j=0; j <= 7; j++){
			
			
			if(matriz[cont] == '0'){

				strcat(letra, "0");
					
			}else if(matriz[cont] == '1'){	

				strcat(letra, "1");
				
			}				
			cont++;
		}
		
		byte = atoi(letra);
		for(int y = 0; byte > 0; y++){
			dec = dec + pow(2,y) * (byte % 10);
       		byte = byte / 10;
		}	

		printf("%c", dec);
		strcpy(letra, "");	
		dec = 0;
	}
	
	printf("\n |\n");
	printf(" |---------------------------------- *\n");
}

#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int i, j, num = 1, qtd = 1, matriz[3][3];
	
	// Colocar os valores das posições
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			matriz[i][j] = num;
			num++;
		}
	}
	
	do{
		int posicao = 0;
		// Imprimir o jogo da velha completo
		for(i = 0; i < 3; i++){
			printf("\t\t ");
			for(j = 0; j < 3; j++){
				printf("0%d ", matriz[i][j]);
				if(j < 2){
					printf("| ");
				}
			}
			if(i < 2){
				printf("\n\t\t-----------\n");
			}
		}
		
		printf("\n\n");
		
		if(qtd % 2 != 0){
			
			// Teste para ver se a posição esta entre 1 e 9
			do {
				printf("\tVez do Jogador 1 \n");
				printf("Digite o número referente a posição: ");
				scanf("%d", &posicao);
			} while(posicao < 1 || posicao > 9);
			
			switch(posicao){
				case 1:
					matriz[0][0] = 1;
					break;
				case 2:
					matriz[0][1] = 1;
					break;
				case 3:
					matriz[0][2] = 1;
					break;
				case 4:
					matriz[1][0] = 1;
					break;
				case 5:
					matriz[1][1] = 1;
					break;
				case 6:
					matriz[1][2] = 1;
					break;
				case 7:
					matriz[2][0] = 1;
					break;
				case 8:
					matriz[2][1] = 1;
					break;
				default:
					matriz[2][2] = 1;
			}
		} else {
			
			// Teste para ver se a posição esta entre 1 e 9
			do {
				printf("\tVez do Jogador 2 \n");
				printf("Digite o número referente a posição: ");
				scanf("%d", &posicao);
			} while(posicao < 1 || posicao > 9);
			
			switch(posicao){
				case 1:
					matriz[0][0] = 0;
					break;
				case 2:
					matriz[0][1] = 0;
					break;
				case 3:
					matriz[0][2] = 0;
					break;
				case 4:
					matriz[1][0] = 0;
					break;
				case 5:
					matriz[1][1] = 0;
					break;
				case 6:
					matriz[1][2] = 0;
					break;
				case 7:
					matriz[2][0] = 0;
					break;
				case 8:
					matriz[2][1] = 0;
					break;
				default:
					matriz[2][2] = 0;
			}
		}
		
		if(matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]){
			if(qtd % 2 != 0){
				printf("\n\n\t O jogador 1 ganhou! \n\n");
				break;
			} else {
				printf("\n\n\t O jogador 2 ganhou! \n\n");
				break;
			}
		}
		
		qtd++;
		
	} while(qtd < 10);
	
	// Imprimir o jogo da velha completo para mostar resultado
	for(i = 0; i < 3; i++){
		printf("\t\t ");
		for(j = 0; j < 3; j++){
			printf("%d ", matriz[i][j]);
			if(j < 2){
				printf("| ");
			}
		}
		if(i < 2){
			printf("\n\t\t-----------\n");
		}
	}
	
	printf("\n\n");
	
	system("PAUSE");
}

// Autores Ian e William

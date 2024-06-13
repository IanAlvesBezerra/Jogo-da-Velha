#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int i, j, num = 1, qtd = 1, empate = 0;
	char matriz[3][3];
	
	printf("         ___  _______  _______  _______    ______   _______    __   __  _______  ___      __   __  _______ \n");
	printf("        |   ||       ||    ___||       |  |      | |   _   |  |  | |  ||    ___||   |    |  | |  ||   _   |\n");
	printf("        |   ||   _   ||   | __ |   _   |  |   _   ||  |_|  |  |  |_|  ||   |___ |   |    |  |_|  ||  |_|  |\n");
	printf("        |   ||  | |  ||   ||  ||  | |  |  |  | |  ||       |  |       ||    ___||   |    |       ||       |\n");
	printf("     ___|   ||  |_|  ||   |_| ||  |_|  |  |  |_|  ||   _   |  |       ||   |___ |   |___ |   _   ||   _   |\n");
	printf("    |       ||       ||       ||       |  |       ||  | |  |   |     | |       ||       ||  | |  ||  | |  |\n");
	printf("    |_______||_______||_______||_______|  |______| |__| |__|    |___|  |_______||_______||__| |__||__| |__|\n");
	printf("\n\n");

	do{
		int posicao = 0, quadrado = 1;
		printf("\n");
		
		// Imprimir o jogo da velha completo
		for(i = 0; i < 3; i++){
			printf("\t\t ");
			for(j = 0; j < 3; j++){
				if(matriz[i][j] == 'X' || matriz[i][j] == 'O'){
					printf("%c ", matriz[i][j]);
					quadrado++;
				} else {
					printf("%d ", quadrado);
					quadrado++;
				}
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
			
			int teste = 1;
			
			// Teste para ver se a posições esta entre 1 e 9
			do {
				printf("\tVez do Jogador 1 \n");
				printf("Digite o número referente a posição: ");
				scanf("%d", &posicao);
			} while(posicao < 1 || posicao > 9);

			// Alocação do valor na posição
			for(i = 0; i < 3; i++){
				for(j = 0; j < 3; j++){
					if(posicao == teste){
						matriz[i][j] = 'X';
						teste = 999;
					}
					teste++;
				}
				if(teste == 999){
					break;
				}
			}
		} else {
			
			int teste = 1;
			
			// Teste para ver se a posição esta entre 1 e 9
			do {
				printf("\tVez do Jogador 2 \n");
				printf("Digite o número referente a posição: ");
				scanf("%d", &posicao);
			} while(posicao < 1 || posicao > 9);

			// Alocação do valor na posição
			for(i = 0; i < 3; i++){
				for(j = 0; j < 3; j++){
					if(posicao == teste){
						matriz[i][j] = 'O';
						teste = 999;
					}
					teste++;
				}
				if(teste == 999){
					break;
				}
			}
		}
		
		if(
			matriz[0][0] == 'X' && matriz[0][0] == matriz[0][1] && matriz[0][1] == matriz[0][2] || //linhas X
			matriz[1][0] == 'X' && matriz[1][0] == matriz[1][1] && matriz[1][1] == matriz[1][2] ||
			matriz[2][0] == 'X' && matriz[2][0] == matriz[2][1] && matriz[2][1] == matriz[2][2] ||
			matriz[0][0] == 'O' && matriz[0][0] == matriz[0][1] && matriz[0][1] == matriz[0][2] || //linhas O
			matriz[1][0] == 'O' && matriz[1][0] == matriz[1][1] && matriz[1][1] == matriz[1][2] ||
			matriz[2][0] == 'O' && matriz[2][0] == matriz[2][1] && matriz[2][1] == matriz[2][2] ||
			matriz[0][0] == 'X' && matriz[0][0] == matriz[1][0] && matriz[1][0] == matriz[2][0] || //colunas X
			matriz[0][1] == 'X' && matriz[0][1] == matriz[1][1] && matriz[1][1] == matriz[2][1] ||
			matriz[0][2] == 'X' && matriz[0][2] == matriz[1][2] && matriz[1][2] == matriz[2][2] ||
			matriz[0][0] == 'O' && matriz[0][0] == matriz[1][0] && matriz[1][0] == matriz[2][0] || //colunas O
			matriz[0][1] == 'O' && matriz[0][1] == matriz[1][1] && matriz[1][1] == matriz[2][1] ||
			matriz[0][2] == 'O' && matriz[0][2] == matriz[1][2] && matriz[1][2] == matriz[2][2] ||
			matriz[0][0] == 'X' && matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] || //diagonais X
			matriz[2][0] == 'X' && matriz[2][0] == matriz[1][1] && matriz[1][1] == matriz[0][2] ||
			matriz[0][0] == 'O' && matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] || //diagonais O
			matriz[2][0] == 'O' && matriz[2][0] == matriz[1][1] && matriz[1][1] == matriz[0][2]
		){
			if(qtd % 2 != 0){
				printf("\n\n\t O jogador 1 ganhou! \n\n");
				break;
			} else {
				printf("\n\n\t O jogador 2 ganhou! \n\n");
				break;
			}
		} else {
			empate++;
		}
		
		qtd++;
		
	} while(qtd < 10);
	
	printf("\n");
	
	// Imprimir o jogo da velha completo para mostar resultado
	for(i = 0; i < 3; i++){
		printf("\t\t ");
		for(j = 0; j < 3; j++){
			if(matriz[i][j] == 'X' || matriz[i][j] == 'O'){
				printf("%c ", matriz[i][j]);
			} else {
				printf("  ");
			}
			if(j < 2){
				printf("| ");
			}
		}
		if(i < 2){
			printf("\n\t\t-----------\n");
		}
	}
	
	if(empate == 9){
		printf("\n\n\t\tEMPATE");
	}
	printf("\n\n");
	
	system("PAUSE");
}

// Autores Ian e William

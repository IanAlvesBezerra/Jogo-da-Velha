#include <stdio.h>
#include <locale.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
    void sleep_ms(int milliseconds) {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>
    void sleep_ms(int milliseconds) {
        usleep(milliseconds * 1000);
    }
#endif

// Função para imprimir o nome
void showName(){
	printf("         ___  _______  _______  _______    ______   _______    __   __  _______  ___      __   __  _______ \n");
	printf("        |   ||       ||    ___||       |  |      | |   _   |  |  | |  ||    ___||   |    |  | |  ||   _   |\n");
	printf("        |   ||   _   ||   | __ |   _   |  |   _   ||  |_|  |  |  |_|  ||   |___ |   |    |  |_|  ||  |_|  |\n");
	printf("        |   ||  | |  ||   ||  ||  | |  |  |  | |  ||       |  |       ||    ___||   |    |       ||       |\n");
	printf("     ___|   ||  |_|  ||   |_| ||  |_|  |  |  |_|  ||   _   |  |       ||   |___ |   |___ |   _   ||   _   |\n");
	printf("    |       ||       ||       ||       |  |       ||  | |  |   |     | |       ||       ||  | |  ||  | |  |\n");
	printf("    |_______||_______||_______||_______|  |______| |__| |__|    |___|  |_______||_______||__| |__||__| |__|\n");
	printf("\n\n");
	sleep_ms(500);
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int i, j, num = 1, jogada = 1, empate = 0;
	int posicoesOcupadas[9];
	char matriz[3][3];

	//Zerar o vetor de posicoes ocupadas
	for(i = 0; i < 9; i++){
		posicoesOcupadas[i] = 0;
	}

	do{
		showName();
		int posicao = 0, quadrado = 1;
		printf("\n");
		
		// Imprimir o jogo da velha completo
		for(i = 0; i < 3; i++){
			printf("\t\t\t\t\t\t   ");
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
				printf("\n\t\t\t\t\t\t  -----------\n");
			}
		}
		
		printf("\n\n");
		
		if(jogada % 2 != 0){
			
			int teste = 1;
			
			// Teste para ver se a posição esta entre 1 e 9
			do {
				printf("\t\t\t\t\t\tVez do Jogador 1 \n");
				printf("\t\t\t\t\tDigite o número referente a posição: ");
				scanf("%d", &posicao);
				
				// Teste para saber se a posição já estava ocupada
				int aux = 0;
				for(i = 0; i < 9; i++){
					if(posicao == posicoesOcupadas[i]){
						aux++;
					}
				}
				if(aux > 0){
					posicao = 999;
					printf("\nESTA POSIÇÃO JÁ ESTÁ OCUPADA\n\n");
				}
				else{
					posicoesOcupadas[jogada-1] = posicao;
				}
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
				printf("\t\t\t\t\t\tVez do Jogador 2 \n");
				printf("\t\t\t\t\tDigite o número referente a posição: ");
				scanf("%d", &posicao);
				
				// Teste para saber se a posição já estava ocupada
				int aux = 0;
				for(i = 0; i < 9; i++){
					if(posicao == posicoesOcupadas[i]){
						aux++;
					}
				}
				if(aux > 0){
					posicao = 999;
					printf("\n\t\t\t\t\tESTA POSIÇÃO JÁ ESTÁ OCUPADA\n\n");
				}
				else{
					posicoesOcupadas[jogada-1] = posicao;
				}
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
			printf(jogada % 2 != 0 ? "\n\n\t\t\t\t\t      O jogador 1 ganhou! \n\n" : "\n\n\t\t\t\t\t      O jogador 2 ganhou! \n\n");
			break;
		} else {
			empate++;
		}
		
		jogada++;
		system("cls || clear");
		
	} while(jogada < 10);
	
	if(empate == 9){
		showName();
		printf("\n\t\t\t\t\t\t     EMPATE\n");
	}
	printf("\n");
	
	// Imprimir o jogo da velha completo para mostar resultado
	for(i = 0; i < 3; i++){
		printf("\t\t\t\t\t\t   ");
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
			printf("\n\t\t\t\t\t\t  -----------\n");
		}
	}
	
	printf("\n\n");
	
	system("PAUSE");
}

// Autores Ian e William

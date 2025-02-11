#include <stdio.h>
#define TAM 3
#define total_jogadas TAM*TAM

void apresentar_matriz(int MAT[TAM][TAM]) {
	int i,j;
	
	    printf("   "); 
    for (j = 0; j < TAM; j++) {
        printf(" %d  ", j); 
    }
    printf("(Linha)\n");

    for (i = 0; i < TAM; i++) {
        printf(" %d ", i);
        for (j = 0; j < TAM; j++) {
            printf(" %d  ", MAT[i][j]); 
        }
        printf("\n");
    }
	
}

int ler_coords(int num_jogada, int opt) {
  	  int cord;
    
    if (num_jogada % 2 == 0)
        printf("\nPlayer 01: ");
    else
        printf("\nPlayer 02: ");

    if (opt == 1)
        printf("Digite a linha da coordenada para jogar: ");
    else
        printf("Digite a coluna da coordenada para jogar: ");
    
    scanf("%d", &cord);
	return cord;
}

int validar_cord(int linha, int coluna, int VET_linha[total_jogadas], int VET_coluna[total_jogadas]) {
	int i;
	
	for(i=0;i<total_jogadas;i++) {
		if(VET_linha[i] == linha && VET_coluna[i] == coluna) {
			return 1;
		} else {
			VET_linha[i] = linha;
			VET_coluna[i] = coluna;
		}
	}
}

int validar_vitoria(int JOGO[TAM][TAM]) {
    int i, j;
    for (i = 0; i < TAM; i++) {
        if (JOGO[i][0] != 0 && JOGO[i][0] == JOGO[i][1] && JOGO[i][1] == JOGO[i][2])
            return 1;
        if (JOGO[0][i] != 0 && JOGO[0][i] == JOGO[1][i] && JOGO[1][i] == JOGO[2][i])
            return 1;
    }
    if (JOGO[0][0] != 0 && JOGO[0][0] == JOGO[1][1] && JOGO[1][1] == JOGO[2][2])
        return 1;
    if (JOGO[0][2] != 0 && JOGO[0][2] == JOGO[1][1] && JOGO[1][1] == JOGO[2][0])
        return 1;
    return 0;
}

void editar_matriz(int JOGO[TAM][TAM], int cord_linha, int cord_coluna, int jogada) {
	if(jogada % 2 == 0){
		JOGO[cord_linha][cord_coluna] = 1;
	} else {
		JOGO[cord_linha][cord_coluna] = 2;
	}
}

int main() {
	int JOGO[TAM][TAM], jogada,i,j;
	int cord_linha, cord_coluna, validacao, validar_vit;
	int V_linha[total_jogadas], V_coluna[total_jogadas];
	
	for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            JOGO[i][j] = 0;
            
			V_linha[i] = -1;
			V_coluna[i] = -1;
        }
    }
	
	jogada=0;
	do {
		apresentar_matriz(JOGO);
		validacao = 0;
		do {
			cord_linha = ler_coords(jogada,1);
			cord_coluna = ler_coords(jogada,2);	 
			validacao = validar_cord(cord_linha, cord_coluna, V_linha, V_coluna);
		
			if(validacao == 1) {
				printf("\n[ERRO] coordenada nao existe ou ja foi preenchida!");
			}else {
				editar_matriz(JOGO, cord_linha, cord_coluna, jogada);  
				validar_vit = validar_vitoria(JOGO);
				jogada++; 
			}
		}while(validacao == 1);
	
	}while(validar_vit == 0);
	
	if(validar_vit == 1) {
		printf("\nO ganhador foi o player %i. Parabens!!!", (jogada - 1) % 2 + 1);	   	
		return 0;
	} 
	
	printf("\nNao houve ganhador!");

}
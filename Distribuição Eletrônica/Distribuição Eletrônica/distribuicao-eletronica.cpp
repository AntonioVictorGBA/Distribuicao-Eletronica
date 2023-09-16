/**
 * Programa que, dado um (elemento de) número atômico Z, mostra a sua distribuição eletrônica.
 *
 * @author Antonio Victor
 * @version 1.0
 */


#include <stdio.h>


/**
* Recebe como entrada um número atômico Z de algum elemento e retorna sua distribuição eletrônica.
* 
* @param z Número atômico.
*/
void imprimeDistribuicaoEletronica(int z) {
	int eletronsNaoDistribuidos = (int)z;
	for (int nivel = 1; eletronsNaoDistribuidos > 0 && nivel <= 8; nivel++) {
		if (nivel >= 7 && eletronsNaoDistribuidos > 0) {	//imprime os subníveis f
			if (eletronsNaoDistribuidos < 14) {
				printf("%df%d ", nivel - 3, eletronsNaoDistribuidos);
				eletronsNaoDistribuidos = 0;
			}
			else {
				printf("%df%d ", nivel - 3, 14);
				eletronsNaoDistribuidos -= 14;
			}
		}
		if (nivel >= 5 && eletronsNaoDistribuidos > 0) {	//imprime os subníveis d
			if (eletronsNaoDistribuidos < 10) {
				printf("%dd%d ", nivel - 2, eletronsNaoDistribuidos);
				eletronsNaoDistribuidos = 0;
			}
			else {
				printf("%dd%d ", nivel - 2, 10);
				eletronsNaoDistribuidos -= 10;
			}
		}
		if (nivel >= 3 && eletronsNaoDistribuidos > 0) {	//imprime os subníveis p
			if (eletronsNaoDistribuidos < 6) {
				printf("%dp%d ", nivel - 1, eletronsNaoDistribuidos);
				eletronsNaoDistribuidos = 0;
			}
			else {
				printf("%dp%d ", nivel - 1, 6);
				eletronsNaoDistribuidos -= 6;
			}
		}
		if (eletronsNaoDistribuidos > 0) {	//imprime os subníveis s
			if (eletronsNaoDistribuidos < 2) {
				printf("%ds%d ", nivel, eletronsNaoDistribuidos);
				eletronsNaoDistribuidos = 0;
			}
			else {
				printf("%ds%d ", nivel, 2);
				eletronsNaoDistribuidos -= 2;
			}
		}
	}
	printf("\n");
}

/**
* Classe principal e loop do programa.
* Encerra o processo se Z < 1 ou Z > 118 ou não é um número.
*/
int main() {
	int z;				//número atômico
	bool valido = true;	//foi dado um número atômico válido

	printf("* * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	printf("Este programa recebe como entrada um numero atomico de algum elemento e retorna sua distribuicao eletronica.\n\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * *\n\n");

	do {
		printf("Digite o numero atomico: ");
		scanf_s("%d", &z); //scanf_s para funcionar no visual studio
		if (z >= 1 && z <= 118)
			imprimeDistribuicaoEletronica(z);
		else {
			valido = false;
			printf("Numero atomico invalido, encerrando o programa...\n\n");
		}
	} while (valido);

	return 0;
}
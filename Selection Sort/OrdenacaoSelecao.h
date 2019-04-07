/*	Biblioteca do Algoritmo de Ordenação: SELECTION SORT

	Autor: Alexandre Gadelha
	
	ORDENAÇÃO POR SELEÇÃO ou SELECTION SORT possui uma implementação simples, mas que possui complexidade QUADRÁTICA,
	sendo eficiente para MENORES entradas de dados.
	
	O método de complexidade quadrática, tem base na Propriedade do Somatório em função de I, conforme abaixo:
	
					Somatório de I com o I=1 até N, que gera, (N^2 + N) / 2 em função de N.
	
	Contudo, o último termo da sequência do Somatório, nunca será avaliado. Logo, assumindo até N-1 e teremos N menos N.
	
	a) No MELHOR CASO, teremos uma complexidade ainda QUADRÁTICA [O(n^2)] pelo fato das comparações serem realizadas todas as vezes e as
	   trocas de elementos serem realizadas de forma maneira inútil UMA vez para cada operação de N-1 comparações. Logo, teremos o efeito de
	   um somatório aqui que resultaria em [f(n) = (n^2 - n) / 2].
	
	b) No PIOR CASO, com as comparações ocorrendo todas as vezes e com as trocas também, como o SELECTION SORT não possui métodos de
	   otimização para o PIOR CASO, o algoritmo assumirá a complexidade natural dele - que é a QUADRÁTICA [O(n^2)] em Notação Big O.
	
	OBS: Como o MELHOR CASO e o PIOR CASO possuem a mesma complexidade QUADRÁTICA, é correto afirma que o CASO MÉDIO também é de complexidade
	     QUADRÁTICA. Dos algoritmos de ordenação mais simples de complexidade QUADRÁTICA, é correto afirmar que o SELECTION SORT É O PIOR DELES!
*/
void selectionSort (int vetor[], int n)
{
	int i, j, menor, alce;
	
	for (i = 0; i < n-1; i++)
	{
		menor = i;
		
		for (j = i+1; j < n; j++)
		{
			if (vetor[j] < vetor[menor])
			{
				menor = j;
			}
		}
		alce = vetor[i];
		vetor[i] = vetor[menor];
		vetor[menor] = alce;
	}
}

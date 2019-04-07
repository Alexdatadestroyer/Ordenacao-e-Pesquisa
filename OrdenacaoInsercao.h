/*	Biblioteca do Algoritmo de Ordenação: INSERTION SORT

	Autor: Alexandre Gadelha
	
	ORDENAÇÃO POR INSERÇÃO ou INSERTION SORT possui uma implementação simples, mas que possui complexidade QUADRÁTICA,
	sendo eficiente para MENORES entradas de dados.
	
	O método de complexidade quadrática, tem base na Propriedade do Somatório em função de I, conforme abaixo:
	
					Somatório de I com o I=1 até N, que gera, (N^2 + N) / 2 em função de N.
	
	Contudo, o último termo da sequência do Somatório, nunca será avaliado. Logo, assumindo até N-1 e teremos N menos N.
	
	a) No MELHOR CASO, teremos uma complexidade LINEAR [O(n)] pelo fato das comparações dentro do WHILE serem realizadas apenas UMA vez
	   para cada N-1 posições do Vetor em questão a ser verificado, retornando FALSE nem chegando a entrar no WHILE.
	
	b) No PIOR CASO, com as comparações ocorrendo todas as vezes e com as trocas também, o INSERTION SORT assume complexidade QUADRÁTICA
	   de Notação Big O [O(n^2)]. Contudo, a novidade dos algoritmos de ordenação como esse que possui o efeito de um somatório, é que as
	   trocas são realizadas em sincronia com as comparações do WHILE.
	   
	   Se uma comparação der FALSE, aquele Primeiro Valor armazenado que serviu de comparação dentro do WHILE [Variável "val"] irá justamente
	   para a posição J+1 do Vetor que deu FALSE ou para a posição 0 deste Vetor se todas as trocas forem realizadas até J chegar ao valor "-1".
	
	OBS: Existe um versão oficial melhorada do INSERTION SORT que possui complexidade LINEARÍTMICA [O(n log n)], ou seja, a complexidade mais
	     eficiente dos algoritmos de ordenação. O nome dele é SHELL SORT.
*/
void insertionSort (int vetor[], int n)
{
	int i, j, val;
	
	for (i = 1; i < n; i++)
	{
		j = i-1;
		val = vetor[i];
		
		while (j >= 0 && vetor[j] > val)
		{
			vetor[j+1] = vetor[j];
			j--;
		}
		
		vetor[j+1] = val;
	}
}

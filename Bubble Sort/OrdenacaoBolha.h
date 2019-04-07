/*	Biblioteca do Algoritmo de Ordenação: BUBBLE SORT otimizado

	Autor: Alexandre Gadelha
	
	ORDENAÇÃO POR BOLHA ou BUBBLE SORT possui uma implementação simples, mas que possui complexidade QUADRÁTICA,
	sendo eficiente para MENORES entradas de dados.
	
	O método de complexidade quadrática, tem base na Propriedade do Somatório em função de I, conforme abaixo:
	
					Somatório de I com o I=1 até N, que gera, (N^2 + N) / 2 em função de N.
	
	Contudo, o último termo da sequência do Somatório, nunca será avaliado. Logo, assumindo até N-1 e teremos N menos N.
	
	a) No MELHOR CASO, teremos uma complexidade LINEAR [O(n)] pelo fato de ser realizada apenas a verificação de todos os elementos do
	   Vetor apenas UMA vez. A variável booleana "swapcontrol" que irá controlar isso. Sem ela, o BUBBLE SORT, assumiria complexidade
	   QUADRÁTICA mesmo no MELHOR CASO, pois as comparações iriam ocorrer todas as vezes - embora não haveria trocas (swaps) de valores.
	
	b) No PIOR CASO, com as comparações ocorrendo todas as vezes e com as trocas também, como o BUBBLE SORT não possui métodos de otimização
	   para o PIOR CASO, o algoritmo assumirá a complexidade natural dela - que é a QUADRÁTICA [O(n^2)] em Notação Big O.
	   
	OBS: Aqui, temos a versão otimizada do BUBBLE SORT, mas existe uma versão mais simples do BUBBLE SORT sem a variável de controle de swaps.
	     Pra esses modelos de BUBBLE SORT, a complexidade de custo é QUADRÁTICA para o MELHOR CASO, tornando este igual ao SELECTION SORT em eficiência.
*/
void bubbleSort (int vetor[], int n)
{
	int i, j, alce;
	bool swapcontrol = true;
	
	for (i = 0; (swapcontrol && i < n-1); i++)
	{
		swapcontrol = false;
		
		for (j = n-1; j > i; j--)
		{
			if (vetor[j] < vetor[j-1])
			{
				alce = vetor[j-1];
				vetor[j-1] = vetor[j];
				vetor[j] = alce;
				swapcontrol = true;
			}
		}
	}
}

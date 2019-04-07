/*	Biblioteca do Algoritmo de Ordenação: SHELL SORT

	Autor: Alexandre Gadelha
	
	ORDENAÇÃO SHELL ou SHELL SORT possui uma implementação derivada do INSERTION SORT, mas que se torna mais eficiente que ele.
	SHELL SORT possui complexidade LINEARÍTMICA (LINEAR + LOGARÍTMICA) sendo bem eficiente para entradas maiores e o mais
	eficiente algoritmo de ordenação existente.
	
	O método de complexidade linearítmica, tem base na seguinte na fusão entre o método linear e logarítmico. Linear pois se trata de
	percorrer o Vetor e logarítmico por utilizar o método de "Dividir pra conquistar" semelhante a uma construção de Árvore Binária.
	
	a) No MELHOR CASO, teremos uma complexidade LINEARÍTMICA de Notação [O(n log n)], pois, embora o Vetor já esteja ordenado, serão
	   necessárias verificações de Valores no processo de Divisão do Vetor, não sendo apenas no final de maneira linear. Como o SHELL
	   SORT depende fortemente do GAP (Variável "gap"), o processo de verificação de Valores no processo de Divisão do Vetor pode demorar,
	   contudo, é esperado que PELO MENOS UMA VARREDURA seja feita durante esse processo, antes da varredura linear.
	
	   Na varredura linear, a verificação será realizada N-1 vezes assumindo o comportamento do INSERTION SORT.
	
	b) No PIOR CASO, pode-se dizer que SHELL SORT ainda se trata de um Problema Aberto (Open Problem). Pra alguns estudiosos, a complexidade
	   na Notação Big O é [O(n^1.5)], pra outros é [O(n^1.25)] e num PIOR CASO mais terrível, chegou-se obter a complexidade {O[n (log2)^2 n]}
	   onde o Logaritmo assume exponenciação QUADRÁTICA na BASE 2 de N.
	   
	   Contudo, como geralmente desprezamos a BASE do Logaritmo que não faz diferença, num PIOR CASO mais terrível, pode-se dizer que a complexidade
	   ainda é [O(n log n)] de maneira geral, sendo a mais aceita até os dias atuais.
	   
	   A respeito de comparações e trocas, no INSERTION SORT, teríamos um efeito de somatório [O(n^2)]. No SHELL SORT, não teríamos esse efeito pelo
	   fato das trocas que seriam realizadas no processo de Divisão do Vetor antes da Varredura Linear. Isso mantém a complexidade LINEARÍTMICA.
	   
	OBS: Dos algoritmos de complexidade eficiente, SHELL SORT é o mais fácil de implementar e pode chegar a ser mais eficiente que o QUICK SORT em certos
	     casos devido a sua complexidade QUADRÁTICA. Contudo, o algoritmo é INSTÁVEL, pois depende fortemente do GAP (Variável "gap").
*/
void shellSort (int vetor[], int n)
{
	int gap = 1, i, j, alce;
	
	do
	{
		gap = (gap * 3) + 1;
		
	}while (gap < n);
	
	do
	{
		gap /= 3;
		
		for (i = gap; i < n; i++)
		{
			j = i;
			alce = vetor[i];
			
			while (j >= gap && vetor[j-gap] > alce)
			{
				vetor[j] = vetor[j-gap];
				j -= gap;
			}
			
			vetor[j] = alce;
		}
		
	}while (gap != 1);
}

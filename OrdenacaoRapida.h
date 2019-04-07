/*	Biblioteca do Algoritmo de Ordenação: QUICK SORT

	Autor: Alexandre Gadelha
	
	ORDENAÇÃO RÁPIDA ou QUICK SORT possui uma implementação via Funções Recursivas. Devido a sua complexidade QUADRÁTICA, não se torna
	muito eficiente para grandes entradas. Contudo, para entradas pequenas e medianas, possui complexidade LINEARÍTMICA e se torna
	mais relevante.
	
	Da mesma forma que o INSERTION SORT, QUICK SORT utiliza o método de "Dividir pra conquistar" por meio de Funções Recursivas
	a definir divisões chamadas de PARTIÇÕES e um centro referencial que chamamos de PIVÔ.
	
	a) No MELHOR CASO, teremos a complexidade LINEARÍTMICA sendo [O(n log n)], pois, mesmo o Vetor já estando ordenado, pode-se dizer
	   que a Divisão deste ainda ocorrerá (Processo de criação de PARTIÇÕES) até que reste APENAS UM elemento nas Partições para declarar
	   o fim do processo. A troca será realizada de forma inútil do PIVÔ com ele mesmo, uma vez que NENHUM Valor à Esquerda seria MAIOR que
	   ele e NENHUM Valor à Direita seria MENOR que o PIVÔ.
	   
	   Logo, as variáveis de controle "I" e "J" caminhariam livremente até o PIVÔ sem interrupções a não ser a troca do PIVÔ com ele mesmo.
	   Essa caminhada das variáveis de controle, define parte da complexidade ser Linear.   
	
	b) No PIOR CASO, o algoritmo assume a complexidade QUADRÁTICA sendo [O(n^2)], tendo em vista que haveria uma Varredura Linear no Vetor
	   em forma de somatório. Contudo, esses casos são raros de acontecer e seria possível APENAS se o PIVÔ fosse colocado em UM DOS EXTREMOS.
	   
	   Na maioria das vezes, acaba assumindo complexidade LINEARÍTMICA mesmo [O(n log n)], pois sempre haverá trocas durante o processo de
	   varredura da Partição.
	
	OBS: Assim como o SHELL SORT depende fortemente do GAP sendo INSTÁVEL, QUICK SORT também é assim e depende da posição que o PIVÔ está
	     configurado pra assumir (Geralmente, fica no MEIO). QUICK SORT é mais difícil de implementar por utilizar Funções Recursivas mas
		 pode chegar a ser mais eficiente que o SHELL SORT e costuma ser aclamado como o algoritmo de ordenação mais rápido que existe.	 
*/

/*------------------------ EXPLICAÇÃO DAS PARTES DO QUICK SORT ABAIXO -----------------------*/

/* Procedimento essencial do algoritmo. Aqui, será feita a Varredura Linear da Partição criada em análise a verificar se os Valores a Esquerda do
   PIVÔ são MENORES que ele e se os Valores da Direita do PIVÔ são MAIORES que ele. Caso positivo, a Partição já está ordenada e o PIVÔ realizará a
   troca com ele mesmo. Caso contrário, as posições de UM elemento da Esquerda e de UM elemento da Direita, são evidenciadas e os Valores serão trocados.
   
   A Varredura Linear só irá acabar quando as Variáveis de extremos dinâmicos "&I" e "&J" SE CRUZAREM (I > J). */

void percorreParticao (int esqParc, int dirParc, int &i, int &j, int vetor[])
{
	int pivot, alce;
	
	i = esqParc;
	j = dirParc;
	
	pivot = vetor[(i+j)/2];				// Definição do PIVÔ como Ponto Central do Vetor
	
	do
	{
		/* Percorrer elementos à Esquerda do PIVÔ da Esquerda para a Direita (i++) */
		
		while (vetor[i] < pivot)
		{
			i++;
		}
		
		/* Percorrer elementos à Direita do PIVÔ da Direita para a Esquerda (j--) */
		
		while (vetor[j] > pivot)
		{
			j--;
		}
		
		/* Depois das Variáveis "I" e "J" estiverem evidenciadas, deve-se realizar a troca de elementos ou do PIVÔ com ele mesmo */
		
		if (i <= j)
		{
			alce = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = alce;
			
			i++;
			j--;
		}
				
	}while (i <= j);
}
/*-------------------------------------------------------------------------------------------*/

/* Procedimento-cérebro do algoritmo. Aqui, criam-se Partições com base nos extremos do Vetor fornecidos e/ou recebidos do Procedimento
   "percorreParticao" que irá retornar as posições dos extremos dinâmicos (Variáveis "I" e "J") da Esquerda e da Direita, respectivamente. */

void criaParticao (int extEsq, int extDir, int vetor[])
{
	int i, j;
	
	percorreParticao (extEsq, extDir, i, j, vetor);
	
	if (extEsq < j)
	{
		criaParticao (extEsq, j, vetor);
	}
	
	if (extDir > i)
	{
		criaParticao (i, extDir, vetor);
	}
}
/*-------------------------------------------------------------------------------------------*/

/* Procedimento-chave do QUICK SORT. Aqui, serão definidos os EXTREMOS do Vetor para ser colocado na Primeira Partição.
   Depois, os extremos vão se reduzindo e novas Partições são criadas se necessário. */

void quickSort (int vetor[], int n)
{
	int esquerda, direita;
	
	esquerda = 0;
	direita = n-1;
	
	criaParticao (esquerda, direita, vetor);
}
/*-------------------------------------------------------------------------------------------*/

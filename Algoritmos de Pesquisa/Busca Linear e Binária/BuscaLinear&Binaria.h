/*	Biblioteca do Algoritmo de Pesquisa de Dados: Busca Binária de um Array

	Autor: Alexandre Gadelha
	
	Com a Letra a ser buscada informada na Função Principal ou via Função comum, acha-se o ÍNDICE desse
	elemento primeiro no Vetor pra depois realizar a Busca Binária com base no ÍNDICE deste.
	
	Se NÃO for encontrado o elemento no Vetor, nenhum ÍNDICE será obtido e a Busca NÃO irá ocorrer.
*/
void binarySearchArray (char vetor[], int &extEsq, int &extDir, int indiletra)
{
	int indipivot;
	
	indipivot = (extEsq + extDir) / 2;
	
	if (extEsq <= extDir)
	{
		if (indiletra == indipivot)
		{
			printf ("\n\nA Letra [%c] informada foi encontrada na posição %d durante a Busca Binária no Vetor!", vetor[indiletra], indipivot);
		}
		else if (indiletra > indipivot)
		{
			indipivot++;
			binarySearchArray (vetor, indipivot, extDir, indiletra);
		}
		else
		{
			indipivot--;
			binarySearchArray (vetor, extEsq, indipivot, indiletra);
		}
	}
}

void indexElementSearch (char vetor[], char letra)
{
	int tamanho, extEsq, extDir, i, indice;
	bool achou = false;
	
	tamanho = strlen (vetor);
	extEsq = 0;
	extDir = tamanho-1;
						
	for (i = 0; vetor[i] != '\0'; i++)
	{
		if (letra == vetor[i])
		{
			indice = i;
			achou = true;
			break;
		}
	}
	
	if (!achou)
	{
		printf ("\n\nA Letra [%c] informada NÃO foi encontrada no Vetor e nem foi possível buscar seu Índice!", letra);
	}
	else
	{
		binarySearchArray (vetor, extEsq, extDir, indice);
	}
}

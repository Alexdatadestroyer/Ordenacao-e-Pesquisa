/*	Biblioteca do Algoritmo de Pesquisa de Dados: Busca Linear de um Array

	Autor: Alexandre Gadelha
*/
void linearSearchArray (char vetor[], char letra)
{
	int i;
	bool flag = false;
	
	for (i = 0; vetor[i] != '\0'; i++)
	{
		if (letra == vetor[i])
		{
			printf ("\n\nLetra [%c] foi encontrada na String na posição %d com sucesso!", letra, i);
			flag = true;
			break;
		}
	}
	
	if (!flag)
	{
		printf ("\n\nA Letra [%c] informada NÃO foi encontrada na String criada!", letra);
	}
}

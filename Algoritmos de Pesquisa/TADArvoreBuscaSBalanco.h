/*	Biblioteca do Tipo Abstrato de Dado: Árvore Binária de Busca SEM BALANCEAMENTO

	Autor: Alexandre Gadelha
	
	Operações da Árvore Binária de Busca apresentadas aqui:
	
	a) Operação de RESET (Limpeza da Árvore toda).
	b) Processo de Limpeza da Árvore de Busca (Se estiver na operação de RESET).
	c) Inserir Valor na Árvore que NÃO SEJA REPETIDO.
	d) Percurso Pré-ordem da Árvore: RAIZ, SAE, SAD.
	e) Percurso Ordem Simétrica da Árvore: SAE, RAIZ, SAD.
	f) Percurso Pós-ordem da Árvore: SAE, SAD, RAIZ.
	g) Pesquisa de Valores na Árvore de Busca.
	h) Identificação e preparação para o processo de remoção de elemento da Árvore.
	i) Remoção real do elemento da Árvore onde o resultado final seja NÓ FOLHA ou NÓ de GRAU 1.
	
	OBS 1: No processo de remoção de um NÓ de GRAU 2, faremos o processo de obter o MENOR À DIREITA
	       DO VALOR A SER REMOVIDO (O Menor Valor da SAD deste elemento). Contudo, se quiséssemos
	       obter o MAIOR ELEMENTO À ESQUERDA DESTE VALOR (O Maior Valor da SAE deste elemento), também
	       daria certo.
	     
	       Caso não haja uma SAE ou SAD próxima do Valor em questão de acordo com o processo escolhido,
	       deverá ser feito um tratamento específico a pegar o mais próximo elemento ativo dele, em
	       outras palavras, aquele filho ativo (Elemento Esquerda da SAE ou Elemento Direita da SAD).
	
	OBS 2: Variável Global (_blocos) irá contar quantos Blocos de Memória foram removidos no total
	       durante o processo de Limpeza da Árvore Binária de Busca.
*/

int _blocos = 0;

struct BinaryTreeSearch
{
	char letra;
	struct BinaryTreeSearch *left, *right;
};

struct BinaryTreeSearch *root = NULL;

void removerLetraReal (struct BinaryTreeSearch *NoAncestral, struct BinaryTreeSearch *NoAtual, char letra)
{
	struct BinaryTreeSearch *NoExcluido;
	
	/* IF: Caso de exclusão de elemento que seja NÓ FOLHA (GRAU 0). Nesse caso, apenas redireciona-se o Ponteiro da Esquerda ou
	       da Direita do elemento ancestral, de acordo com o seu Valor em comparação a ele, pra NULL (IF-ELSE internos).
		   
		   No caso exclusivo da RAIZ, esta passará a apontar pra NULL, uma vez que a Árvore estará VAZIA!
		   
		   OBS: O Ponteiro "NoExcluido" recebe o elemento da Árvore a ser excluído DEPOIS das operações do IF principal!
	   
	   ELSE: Caso de exclusão de elemento que seja NÓ de GRAU 1, possuindo apenas UM FILHO. Nesse caso, é verificado qual elemento
	         estará disponível para tomar seu lugar, sendo a Esquerda dele ou a Direita (IF-ELSE em Condição Ternária superior).
			 O elemento disponível será apontado pelo elemento ancestral da Esquerda ou da Direita dependendo de seu Valor perante
			 a ele (IF-ELSE em Condição Ternária inferior) num processo parecido com o da exclusão de um NÓ FOLHA.
			 
		     No caso exclusivo da RAIZ, esta passará a apontar pra esse elemento ("NoAtual" depois da mudança) sendo da Esquerda ou da
		     Direita do elemento a ser excluído posteriormente ("NoAtual" antes da mudança. Agora, na variável "NoExcluido").
		     
		     OBS: O Ponteiro "NoExcluido" recebe o elemento da Árvore a ser excluído ANTES das operações do ELSE principal!
	   
	    Depois de realizadas as devidas operações antes da exclusão, o elemento é finalmente eliminado da Árvore Binária de Busca. O
	    antigo elemento "NoAtual" foi atribuído ao Ponteiro "NoExcluido" pra ser possível as operações e também pra exclusão dar certo! */
	
	if ((!NoAtual->left) && (!NoAtual->right))
	{		
		if (NoAtual == root)						// Caso específico da exclusão da RAIZ da Árvore
		{
			root = NULL;
		}
		else										// Para todos os outros casos de exclusão de elementos...
		{
			(NoAtual->letra < NoAncestral->letra) ? (NoAncestral->left = NULL) : (NoAncestral->right = NULL);
		}
		
		NoExcluido = NoAtual;
		printf ("\n\nA Letra [%c], que é um NÓ FOLHA, foi excluída com sucesso!", letra);
	}
	else
	{
		NoExcluido = NoAtual;
		
		if (NoAtual == root)						// Caso específico da exclusão da RAIZ da Árvore
		{
			(!NoAtual->left && NoAtual->right) ? (NoAtual = NoAtual->right) : (NoAtual = NoAtual->left);
					
			root = NoAtual;
		}
		else										// Para todos os outros casos de exclusão de elementos...
		{	
			(!NoAtual->left && NoAtual->right) ? (NoAtual = NoAtual->right) : (NoAtual = NoAtual->left);
					
			(NoAtual->letra < NoAncestral->letra) ? (NoAncestral->left = NoAtual) : (NoAncestral->right = NoAtual);
		}
		printf ("\n\nA Letra [%c], que é um NÓ DE GRAU 1, foi excluída com sucesso!", letra);
	}
	free (NoExcluido);
}

void removerLetraArvoreBusca (struct BinaryTreeSearch *NoAncestral, struct BinaryTreeSearch *NoAtual, char letra)
{
	struct BinaryTreeSearch *NoProfundo;
	char alce;
	
	while (NoAtual)
	{
		if (letra < NoAtual->letra)
		{
			NoAncestral = NoAtual;
			NoAtual = NoAtual->left;
		}
		else if (letra > NoAtual->letra)
		{
			NoAncestral = NoAtual;
			NoAtual = NoAtual->right;
		}
		else
		{
			break;
		}
	}
	
	if (NoAtual)
	{
		if ((NoAtual->left) && (NoAtual->right))
		{
			NoAncestral = NoAtual;
			NoProfundo = NoAtual->right;
			
			printf ("\n\nA Letra [%c] é um NÓ DE GRAU 2 na Árvore: É achar um substituto e excluir na segunda fase...", letra);
			
			if (!NoProfundo->left)						// Caso exclusivo de carência de elementos MENORES na SAD da Árvore Binária
			{
				alce = NoProfundo->letra;
				NoProfundo->letra = NoAncestral->letra;
				NoAncestral->letra = alce;
				
				NoAncestral->right = NoProfundo->right;
				
				printf ("\n\nA Letra [%c] foi removida diretamente com sucesso da Árvore de Busca!", letra);
				free (NoProfundo);
			}
			else										// Casos comuns onde, geralmente, há elementos MENORES na SAD da Árvore Binária
			{
				while (NoProfundo->left)
				{
					NoAncestral = NoProfundo;
					NoProfundo = NoProfundo->left;
				}
				
				alce = NoProfundo->letra;
				NoProfundo->letra = NoAtual->letra;
				NoAtual->letra = alce;
				
				removerLetraReal (NoAncestral, NoProfundo, letra);
			}
		}
		else
		{
			removerLetraReal (NoAncestral, NoAtual, letra);
		}
	}
	else
	{
		printf ("\n\nA Letra [%c] informada não foi encontrada para a sua remoção!", letra);
	}
}

struct BinaryTreeSearch *pesquisaLetraArvoreBusca (struct BinaryTreeSearch *NoAtual, char letra)
{
	while (NoAtual)
	{
		if (letra < NoAtual->letra)
		{
			NoAtual = NoAtual->left;
		}
		else if (letra > NoAtual->letra)
		{
			NoAtual = NoAtual->right;
		}
		else
		{
			break;
		}
	}
	
	if (!NoAtual)
	{
		return NULL;
	}
	else
	{
		return NoAtual;
	}
}

void ordemSimetricaArvoreBusca (struct BinaryTreeSearch *NoAtual)
{
	if (NoAtual)
	{		
		ordemSimetricaArvoreBusca (NoAtual->left);
		
		if (NoAtual->letra == root->letra)
		{
			printf ("%c", NoAtual->letra);
		}
		else if (NoAtual->letra < root->letra)
		{
			printf ("%c, ", NoAtual->letra);
		}
		else
		{
			printf (", %c", NoAtual->letra);
		}
		
		ordemSimetricaArvoreBusca (NoAtual->right);
	}
}

void preOrdemArvoreBusca (struct BinaryTreeSearch *NoAtual)
{
	if (NoAtual)
	{
		if (NoAtual->letra == root->letra)
		{
			printf ("%c", NoAtual->letra);
		}
		else
		{
			printf (", %c", NoAtual->letra);
		}
		
		preOrdemArvoreBusca (NoAtual->left);
		preOrdemArvoreBusca (NoAtual->right);
	}
}

void posOrdemArvoreBusca (struct BinaryTreeSearch *NoAtual)
{
	if (NoAtual)
	{
		posOrdemArvoreBusca (NoAtual->left);
		posOrdemArvoreBusca (NoAtual->right);
		
		if (NoAtual->letra == root->letra)
		{
			printf ("%c", NoAtual->letra);
		}
		else
		{
			printf ("%c, ", NoAtual->letra);
		}
	}
}

void inserirElementoArvoreBusca (struct BinaryTreeSearch *NoAncestral, struct BinaryTreeSearch *NoAtual, char letra)
{
	while (NoAtual)
	{
		if (letra < NoAtual->letra)
		{
			NoAncestral = NoAtual;
			NoAtual = NoAtual->left;
		}
		else if (letra > NoAtual->letra)
		{
			NoAncestral = NoAtual;
			NoAtual = NoAtual->right;
		}
		else
		{
			printf ("\n\nNÃO SERÃO permitidas Letras Iguais na Árvore de Busca: Letra [%c] já presente!", letra);
			break;
		}
	}
	
	if (!NoAtual)
	{
		NoAtual = (struct BinaryTreeSearch *) malloc (sizeof (struct BinaryTreeSearch));
		NoAtual->letra = letra;
		NoAtual->left = NULL;
		NoAtual->right = NULL;
		
		if (!NoAncestral)
		{
			root = NoAtual;
			printf ("\n\nLetra [%c] foi adicionada diretamente na RAIZ da Árvore!", letra);
		}
		else
		{
			if (NoAtual->letra < NoAncestral->letra)
			{
				NoAncestral->left = NoAtual;
				printf ("\n\nLetra [%c] foi adicionada À ESQUERDA de [%c]", letra, NoAncestral->letra);
			}
			else
			{
				NoAncestral->right = NoAtual;
				printf ("\n\nLetra [%c] foi adicionada À DIREITA de [%c]", letra, NoAncestral->letra);
			}
		}
	}
}

void limpezaArvoreBusca (struct BinaryTreeSearch *NoAtual)
{
	if (NoAtual)
	{
		limpezaArvoreBusca (NoAtual->left);
		limpezaArvoreBusca (NoAtual->right);
		free (NoAtual);
		_blocos++;
	}
}

void resetArvoreBusca (struct BinaryTreeSearch *NoAtual)
{
	if (NoAtual)
	{
		limpezaArvoreBusca (NoAtual);
		
		printf ("\n\nForam removidos %d Blocos de Memória da Árvore de Busca!", _blocos);
		root = NULL;
		_blocos = 0;
	}
}

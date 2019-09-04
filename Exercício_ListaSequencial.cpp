/***********************************************/
/* Lista Sequencial                            */
/* objetivo: controle de registros             */
/* programador: Daniela Bagatini               */
/* criado em: 20/08/2017                       */
/* data da última alteração: 21/06/2019        */
/***********************************************/


#include <stdio.h>         // entrada e saída padrão: printf, scanf
#include <stdlib.h>		   // exit, malloc, system
#include <string.h>	  	   // strcmp
#include <locale.h>        // setlocale
//#include <ctype.h>       // toupper
//#include <conio.h>       // getch
//#include <time.h>        // rand  


// bibliotecas incluídas, manter bibliotecas na mesma pasta do arquivo fonte
#include "MODELOSEQ.h"     // modelo de dados
#include "GERA_DADOSSEQ.h" // gera dados para povoar lista de forma automática 
#include "INCLUI_FIM.h"    // inclui novo registro no final da lista

/***********************************************/
/* Definição das Funções                       */
/***********************************************/
void entrada_dados   ( INFORMACAO *aux );     // lê dos dados de entrada
void imprime_lista   ( NODO lista );          // visualiza lista em tela
void cria_lista      ( int *fim );            // inicializa lista com tamanho 0
//void inclui_fim      ( NODO *lista );         // inclui novo registro no final da lista
void inclui_inicio   ( NODO *lista );         // inclui novo registro no início da lista
int  procura_nodo    ( int cod, NODO lista ); // procura por código na lista
void inclui_antes    ( NODO *lista );         // inclui novo registro antes de um código de referência
void inclui_depois   ( NODO *lista );         // inclui novo registro depois de um código de referência
void exclui_nodo     ( NODO *lista );         // exclui regitro por código
void ordena_lista    ( NODO *lista );         // ordena por código - ordem crescente 
void altera_nodo     ( NODO *lista );         // altera regitro a partir de um código de referência
void consulta_nome   ( NODO lista );          // consulta registro por nome e apresenta demais dados do registro
void inclui_ordenado ( NODO *lista );         // inclui em ordem crescente de código
void compara_repetidos( NODO *lista );        // verifica códigos repetidos
void elimina_repetidos( NODO *lista );        // verifica códigos repetidos e exclui, se lista ordenada
// crie sua própria função aqui!


/***********************************************/
/* Programa Principal                          */
/***********************************************/
int main( void ){
    int op;                                   // opção do menu
    NODO lista;                               // variável do tipo lista sequencial = vetor de registros
    setlocale( LC_ALL, "Portuguese" );        // alterar idioma para português

    while( 1 ){
         printf( "\n /--------------------------------------------------------/" );
         printf( "\n Programa registro - Menu                                  " );
         printf( "\n [1 ] Cria lista                                           " );
         printf( "\n [2 ] Inclui registro no final da lista                    " );
         printf( "\n [3 ] Inclui registro no início da lista                   " );
         printf( "\n [4 ] Inclui registro antes de um código de referência     " );
         printf( "\n [5 ] Inclui registro depois de um código de referência    " );
         printf( "\n [6 ] Exclui registro                                      " );
         printf( "\n [7 ] Ordena lista                                         " );
         printf( "\n [8 ] Altera registro                                      " );  
		 printf( "\n [9 ] Consulta por nome                                    " );        
         printf( "\n [10] Inclui ordenado por código                           " );                  
         printf( "\n [11] Crie sua própria função aqui!                        " );
         printf( "\n [12] Compara repetidos                                    " );
         printf( "\n [13] Elimina repetidos                                    " );                  
         printf( "\n [14] Gera dados                                           " ); 
		 printf( "\n [15] Imprime lista                                        " );
         printf( "\n [0 ] Para sair do programa                                " );
         printf( "\n /--------------------------------------------------------/" );
         printf( "\n Opção: " );
         fflush( stdin );   // limpa buffer do teclado, funciona antes da entrada de dados
         scanf( "%i", &op );// tecla de opção do menu
         
         switch( op ) {
            case 1:  // rotina cria lista, inicializa a lista em zero
                    cria_lista( &lista.f );
                    break;

            case 2:  // rotina inclui registro no final da lista, conforme indicado pelo gerenciados da lista (posição lista.f)
                    inclui_fim( &lista );
                    break;

            case 3:  // rotina inclui registro no início da lista, posição 0
                    inclui_inicio( &lista );
                    break;

            case 4:  // rotina inclui registro antes de um código de referência informado
                     inclui_antes( &lista );
                     break;

            case 5:  // rotina inclui registro depois de um código de referência informado
                    inclui_depois( &lista );
                    break;

            case 6:  // rotina exclui registro conforme código de referência
                    exclui_nodo( &lista );
                    break;

            case 7: // rotina ordena lista por código, ordem crescente
                    ordena_lista( &lista );
                    break;
                    
            case 8: // rotina altera registro com base no código de referência informado
                    altera_nodo( &lista );
                    break;
                    
            case 9: // rotina consulta por nome e apresentada demais dados do registro
                    consulta_nome( lista ); 
                    break;

            case 10: // rotina inclui registro por ordem crescente de código            
                    ordena_lista( &lista );  // ordena lista para garantir que irá incluir o novo registro em ordem 
                    inclui_ordenado( &lista );
                    break;

            case 11:  
                    // crie sua própria função aqui!   
                    break;            
                    
            case 12: // rotina compara registros com códigos repetidos
                    compara_repetidos( &lista );
                    break;                     
                    
            case 13: // rotina exclui registros com códigos repetidos
                    ordena_lista( &lista );  // ordena lista para garantir que irá eliminar repetidos                     
                    elimina_repetidos( &lista );
                    break;      

            case 14: // rotina gera dados de forma automática para povoar a lista
                    gera_dados( &lista );
                    break;      
                                                               
            case 15: // rotina imprime todos os registros da lista
                    imprime_lista( lista );
                    break;
                    
            case 0: // término do programa
                    exit( 1 );
                    break;

            default :
                    printf( "\n Digite uma opção!" );
                    break;
        } // fim switch( op )
        
        printf("\n");
        getchar();       // parada da tela
        system( "cls" ); // limpar tela
     } // fim do while( 1 )
 return 0;
} // fim do programa principal



/************************************************
 * entrada_dados                                *
 * objetivo: rotina para ler dados              *
 * entrada : registro aux (auxiliar)            *
 * saída   : aux atualizado com dados           *
 ************************************************/
void entrada_dados( INFORMACAO *aux ){
	 
    printf( "\n\n Digite o código: " );
    fflush( stdin );                        // limpa buffer do teclado, funciona junto com entrada de dados
    scanf( "%d", &aux->codigo );

    printf( "\n Digite o nome: " );
    fflush( stdin );     
    gets( aux->nome );
}



/*************************************************
 * imprime_lista                                 *
 * objetivo: rotina para imprimir dados          *
 * entrada : lista                               *
 * saída   : nenhuma, apenas em tela             *
 *************************************************/
void imprime_lista( NODO lista ){
     
    int i;                                // índice do laço

    if( lista.f == 0 )                    // verifica se lista vazia
        printf( "\n Lista vazia! " );
    else{
        printf("\n Relatório Geral ----------------------------------------- ");
	    for( i = 0 ; i < lista.f ; i++ ) { // percorre a lista e imprime dados
	         printf( "\n Registro[%d]", i );
	         printf( "\t Código.: %d", lista.info[ i ].codigo );
	         printf( "\t Nome.: %s", lista.info[ i ].nome );
	    }
    }    
    getchar();                             // parada da tela
}



/************************************************
 * cria_lista                                   *
 * objetivo: rotina para inicializar a lista    *
 * entrada : fim da lista                       *
 * saída   : fim da lista atualizado, com 0     *
 ************************************************/
void cria_lista( int *fim ){
     
    *fim = 0;                                   // iniciliza lista, tamanho da lista = 0
    printf( "\n Lista criada! " );
}



/************************************************
 * inclui_fim                                   *
 * objetivo: rotina para inserir no fim da lista*
 * entrada : lista                              *
 * saída   : lista com novo elemento            *
 ************************************************
void inclui_fim( NODO *lista ){
     

}



/************************************************
 * inclui_início                                *
 * objetivo: inserir no início da lista         *
 * entrada : lista                              *
 * saída   : lista com novo elemento            *
 ************************************************/
void inclui_inicio( NODO *lista ){
     
    int i;                                      // i = índice

    if( lista->f == N_MAX )                     // verifica se a lista está cheia
        printf( "\n Lista cheia! " );
    else{
        INFORMACAO aux;                         // auxiliar para a entrada de dados
        entrada_dados( &aux );                  // lê dados, entrada
        for ( i = lista->f ; i > 0 ; i-- )      // desloca lista até abrir espaço no início (posição 0)
              lista->info[ i ] = lista->info[ i - 1 ]; // deslocamento dos registros para a direita
        lista->info[ 0 ] = aux;                 // insere na lista - outra opção: mencpy(&lista.info[lista.f], &aux, sizeof(NODO));
        lista->f++;                             // incrementa o tamanho da lista  
        printf( "\n Registro incluído no início!" );
    }
}



/************************************************
 * procura_nodo                                 *
 * objetivo: achar posição a partir de um campo *
 * entrada : código de referência e lista       *
 * saída   : posição física da referência ou -1 *
 ************************************************/
int procura_nodo( int cod, NODO lista ){
        
    int i= 0;                                   // i = índice

    while(( i < lista.f ) && ( cod != lista.info[ i ].codigo )) // anda pela lista até o final ou ate encontrar código desejado
            i++;
    if( cod == lista.info[ i ].codigo )         // se encontou código igual    
        return( i );                            // retorna posição física do nodo de referência
    else       
        return( -1 );                           // retorna código não encontrado
}



/************************************************
 * inclui_antes                                 *
 * objetivo: inserir antes de um código         *
 * entrada : lista                              *
 * saída   : lista com novo elemento            *
 ************************************************/
void inclui_antes( NODO *lista ){
     

}



/************************************************
 * inclui_depois                                *
 * objetivo: inserir depois de um código        *
 * entrada : lista                              *
 * saída   : lista com novo elemento            *
 ************************************************/
void inclui_depois( NODO *lista ){
 

}



/************************************************
 * exclui_nodo                                  *
 * objetivo: rotina para excluir registro       *
 * entrada : lista                              *
 * saída   : lista com um elemento removido     *
 ************************************************/
void exclui_nodo( NODO *lista ){
     if( lista->f == 0 )           // verifica se a lista está vazia
         printf( "Lista vazia!" ); 
     else{
     	 int cod_ref;              // código de referência a ser excluído 
         printf( "Informe código de referência: " );      	
         scanf("%i", &cod_ref);         

         int i= 0;                 // controle do laço
         while( i < lista->f && lista->info[i].codigo != cod_ref ) // código que está na lista é diferente de código de referência
                i++;               // percorre a lista  i++ - i=i+1         
		 while( i < lista->f-1 ){  // deslocamento       
		        lista->info[i]= lista->info[i+1]; // desloca registro uma posição à frente
		        i++;               // percorre a lista
	     }
	     if( i < lista->f ){
	         lista->f--;           // exclui registro da lista
	         printf( "Registro excluído!" );
	     }else
		     printf( "Código não encontrado!" );    
	 }    
	 
	 getchar();       // parada da tela
}



/************************************************
* ordena_lista                                  *
* objetivo: rotina para ordenar lista por código*
* entrada : lista                               *
* saída   : lista ordenada                      *
*************************************************/
void ordena_lista( NODO *lista ){              // Algoritmo Método Bolha - Bubble Sort 
    if( lista->f == 0 )                        // verifica se a lista está vazia
        printf( "\n Lista vazia! " );
    else
       if( lista->f == 1 )                     // verifica se a lista tem apenas um registro
           printf( "\n Lista com apenas um registro! " );
       else{
           int i, j;                           // i, j = índices para percorrer a lista
           INFORMACAO aux;                     // auxiliar para a troca de dados
           for( i = 0; i < lista->f-1; i++ )   // percorre a lista realizando a comparação entre registros
                for( j = i + 1; j < lista->f; j++ )
                     if( lista->info[ j ].codigo < lista->info[ i ].codigo ){ // se código do sucessor for maior, troca
                         aux = lista->info[ j ]; // realiza a troca utilizando registro auxiliar
                         lista->info[ j ] = lista->info[ i ];
                         lista->info[ i ] = aux;
                     }
           printf( "\n Lista ordenada! " );
          }  
}



/************************************************
 * altera_nodo                                  *
 * objetivo: rotina para alterar registro       *
 * entrada : lista                              *
 * saída   : lista com um elemento alterado     *
 ************************************************/
void altera_nodo( NODO *lista ){
        

}             


/************************************************
 * consulta_nome                                *
 * objetivo: rotina para consultar nome         *
 * entrada : lista                              *
 * saída   : nenhuma, dados em tela             *
 ************************************************/
void consulta_nome( NODO lista )
{
	
	     
   	char procuraNome[30]; // o nome nao terá mas que 30 char de acordo com definição da Struct
	int index = 0;
	
	if(lista.f  == 0) //valida se a lista está vazia
	{
		printf("Não existem registros a serem consultados!"); //informa usuario
		getchar();
	}
	
	else{
		
			printf("informe o nome a ser consultado:"); //pega nome a ser consultado
			scanf("%s",&procuraNome);

			
			for (index = 0 ;  index <= lista.f ; index ++) //percorre todas as posições do vetor enquanto nao atingir o limite de tamanho ocupado
			
				{
				
					if (strcmp(lista.info[index].nome,procuraNome) == 0) //verifica desde a primeira posição, comparando se o código da próxima é menor que o da posição atual
						{
							printf("%s",procuraNome);	//exibe o nome consultado
							getchar();		
						}
					if(index > lista.f)
						{
							
							printf("Nao encontrei o babilonia!");
							
						}								
				}   
				
			
			}
	
}



/************************************************
 * inclui_ordenado                              *
 * objetivo: rotina que inclui registro ordenado*
 * entrada : lista                              *
 * saída   : lista com novo elemento            *
 ************************************************/         
void inclui_ordenado ( NODO *lista ){
     

}



/************************************************
 * compara_repetidos                            *
 * objetivo: rotina compara registros           *
 * entrada : lista                              *
 * saída   : nenhuma                            *
 ************************************************/ 
void compara_repetidos ( NODO *lista ){   
     

}



/************************************************
 * elimina_repetidos                            *
 * objetivo: rotina exclui registros repetidos  *
 * entrada : lista                              *
 * saída   : lista atualizada                   *
 ***********************************************/ 
void elimina_repetidos( NODO *lista ){ //FUNÇÃO NÃO VALIDADA COM NOME!!!!!!!!!!!!!!!!!!!!
    
    
}

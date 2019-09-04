/***********************************************/
/* Lista Sequencial                            */
/* objetivo: controle de registros             */
/* programador: Daniela Bagatini               */
/* criado em: 20/08/2017                       */
/* data da �ltima altera��o: 21/06/2019        */
/***********************************************/


#include <stdio.h>         // entrada e sa�da padr�o: printf, scanf
#include <stdlib.h>		   // exit, malloc, system
#include <string.h>	  	   // strcmp
#include <locale.h>        // setlocale
//#include <ctype.h>       // toupper
//#include <conio.h>       // getch
//#include <time.h>        // rand  


// bibliotecas inclu�das, manter bibliotecas na mesma pasta do arquivo fonte
#include "MODELOSEQ.h"     // modelo de dados
#include "GERA_DADOSSEQ.h" // gera dados para povoar lista de forma autom�tica 
#include "INCLUI_FIM.h"    // inclui novo registro no final da lista

/***********************************************/
/* Defini��o das Fun��es                       */
/***********************************************/
void entrada_dados   ( INFORMACAO *aux );     // l� dos dados de entrada
void imprime_lista   ( NODO lista );          // visualiza lista em tela
void cria_lista      ( int *fim );            // inicializa lista com tamanho 0
//void inclui_fim      ( NODO *lista );         // inclui novo registro no final da lista
void inclui_inicio   ( NODO *lista );         // inclui novo registro no in�cio da lista
int  procura_nodo    ( int cod, NODO lista ); // procura por c�digo na lista
void inclui_antes    ( NODO *lista );         // inclui novo registro antes de um c�digo de refer�ncia
void inclui_depois   ( NODO *lista );         // inclui novo registro depois de um c�digo de refer�ncia
void exclui_nodo     ( NODO *lista );         // exclui regitro por c�digo
void ordena_lista    ( NODO *lista );         // ordena por c�digo - ordem crescente 
void altera_nodo     ( NODO *lista );         // altera regitro a partir de um c�digo de refer�ncia
void consulta_nome   ( NODO lista );          // consulta registro por nome e apresenta demais dados do registro
void inclui_ordenado ( NODO *lista );         // inclui em ordem crescente de c�digo
void compara_repetidos( NODO *lista );        // verifica c�digos repetidos
void elimina_repetidos( NODO *lista );        // verifica c�digos repetidos e exclui, se lista ordenada
// crie sua pr�pria fun��o aqui!


/***********************************************/
/* Programa Principal                          */
/***********************************************/
int main( void ){
    int op;                                   // op��o do menu
    NODO lista;                               // vari�vel do tipo lista sequencial = vetor de registros
    setlocale( LC_ALL, "Portuguese" );        // alterar idioma para portugu�s

    while( 1 ){
         printf( "\n /--------------------------------------------------------/" );
         printf( "\n Programa registro - Menu                                  " );
         printf( "\n [1 ] Cria lista                                           " );
         printf( "\n [2 ] Inclui registro no final da lista                    " );
         printf( "\n [3 ] Inclui registro no in�cio da lista                   " );
         printf( "\n [4 ] Inclui registro antes de um c�digo de refer�ncia     " );
         printf( "\n [5 ] Inclui registro depois de um c�digo de refer�ncia    " );
         printf( "\n [6 ] Exclui registro                                      " );
         printf( "\n [7 ] Ordena lista                                         " );
         printf( "\n [8 ] Altera registro                                      " );  
		 printf( "\n [9 ] Consulta por nome                                    " );        
         printf( "\n [10] Inclui ordenado por c�digo                           " );                  
         printf( "\n [11] Crie sua pr�pria fun��o aqui!                        " );
         printf( "\n [12] Compara repetidos                                    " );
         printf( "\n [13] Elimina repetidos                                    " );                  
         printf( "\n [14] Gera dados                                           " ); 
		 printf( "\n [15] Imprime lista                                        " );
         printf( "\n [0 ] Para sair do programa                                " );
         printf( "\n /--------------------------------------------------------/" );
         printf( "\n Op��o: " );
         fflush( stdin );   // limpa buffer do teclado, funciona antes da entrada de dados
         scanf( "%i", &op );// tecla de op��o do menu
         
         switch( op ) {
            case 1:  // rotina cria lista, inicializa a lista em zero
                    cria_lista( &lista.f );
                    break;

            case 2:  // rotina inclui registro no final da lista, conforme indicado pelo gerenciados da lista (posi��o lista.f)
                    inclui_fim( &lista );
                    break;

            case 3:  // rotina inclui registro no in�cio da lista, posi��o 0
                    inclui_inicio( &lista );
                    break;

            case 4:  // rotina inclui registro antes de um c�digo de refer�ncia informado
                     inclui_antes( &lista );
                     break;

            case 5:  // rotina inclui registro depois de um c�digo de refer�ncia informado
                    inclui_depois( &lista );
                    break;

            case 6:  // rotina exclui registro conforme c�digo de refer�ncia
                    exclui_nodo( &lista );
                    break;

            case 7: // rotina ordena lista por c�digo, ordem crescente
                    ordena_lista( &lista );
                    break;
                    
            case 8: // rotina altera registro com base no c�digo de refer�ncia informado
                    altera_nodo( &lista );
                    break;
                    
            case 9: // rotina consulta por nome e apresentada demais dados do registro
                    consulta_nome( lista ); 
                    break;

            case 10: // rotina inclui registro por ordem crescente de c�digo            
                    ordena_lista( &lista );  // ordena lista para garantir que ir� incluir o novo registro em ordem 
                    inclui_ordenado( &lista );
                    break;

            case 11:  
                    // crie sua pr�pria fun��o aqui!   
                    break;            
                    
            case 12: // rotina compara registros com c�digos repetidos
                    compara_repetidos( &lista );
                    break;                     
                    
            case 13: // rotina exclui registros com c�digos repetidos
                    ordena_lista( &lista );  // ordena lista para garantir que ir� eliminar repetidos                     
                    elimina_repetidos( &lista );
                    break;      

            case 14: // rotina gera dados de forma autom�tica para povoar a lista
                    gera_dados( &lista );
                    break;      
                                                               
            case 15: // rotina imprime todos os registros da lista
                    imprime_lista( lista );
                    break;
                    
            case 0: // t�rmino do programa
                    exit( 1 );
                    break;

            default :
                    printf( "\n Digite uma op��o!" );
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
 * sa�da   : aux atualizado com dados           *
 ************************************************/
void entrada_dados( INFORMACAO *aux ){
	 
    printf( "\n\n Digite o c�digo: " );
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
 * sa�da   : nenhuma, apenas em tela             *
 *************************************************/
void imprime_lista( NODO lista ){
     
    int i;                                // �ndice do la�o

    if( lista.f == 0 )                    // verifica se lista vazia
        printf( "\n Lista vazia! " );
    else{
        printf("\n Relat�rio Geral ----------------------------------------- ");
	    for( i = 0 ; i < lista.f ; i++ ) { // percorre a lista e imprime dados
	         printf( "\n Registro[%d]", i );
	         printf( "\t C�digo.: %d", lista.info[ i ].codigo );
	         printf( "\t Nome.: %s", lista.info[ i ].nome );
	    }
    }    
    getchar();                             // parada da tela
}



/************************************************
 * cria_lista                                   *
 * objetivo: rotina para inicializar a lista    *
 * entrada : fim da lista                       *
 * sa�da   : fim da lista atualizado, com 0     *
 ************************************************/
void cria_lista( int *fim ){
     
    *fim = 0;                                   // iniciliza lista, tamanho da lista = 0
    printf( "\n Lista criada! " );
}



/************************************************
 * inclui_fim                                   *
 * objetivo: rotina para inserir no fim da lista*
 * entrada : lista                              *
 * sa�da   : lista com novo elemento            *
 ************************************************
void inclui_fim( NODO *lista ){
     

}



/************************************************
 * inclui_in�cio                                *
 * objetivo: inserir no in�cio da lista         *
 * entrada : lista                              *
 * sa�da   : lista com novo elemento            *
 ************************************************/
void inclui_inicio( NODO *lista ){
     
    int i;                                      // i = �ndice

    if( lista->f == N_MAX )                     // verifica se a lista est� cheia
        printf( "\n Lista cheia! " );
    else{
        INFORMACAO aux;                         // auxiliar para a entrada de dados
        entrada_dados( &aux );                  // l� dados, entrada
        for ( i = lista->f ; i > 0 ; i-- )      // desloca lista at� abrir espa�o no in�cio (posi��o 0)
              lista->info[ i ] = lista->info[ i - 1 ]; // deslocamento dos registros para a direita
        lista->info[ 0 ] = aux;                 // insere na lista - outra op��o: mencpy(&lista.info[lista.f], &aux, sizeof(NODO));
        lista->f++;                             // incrementa o tamanho da lista  
        printf( "\n Registro inclu�do no in�cio!" );
    }
}



/************************************************
 * procura_nodo                                 *
 * objetivo: achar posi��o a partir de um campo *
 * entrada : c�digo de refer�ncia e lista       *
 * sa�da   : posi��o f�sica da refer�ncia ou -1 *
 ************************************************/
int procura_nodo( int cod, NODO lista ){
        
    int i= 0;                                   // i = �ndice

    while(( i < lista.f ) && ( cod != lista.info[ i ].codigo )) // anda pela lista at� o final ou ate encontrar c�digo desejado
            i++;
    if( cod == lista.info[ i ].codigo )         // se encontou c�digo igual    
        return( i );                            // retorna posi��o f�sica do nodo de refer�ncia
    else       
        return( -1 );                           // retorna c�digo n�o encontrado
}



/************************************************
 * inclui_antes                                 *
 * objetivo: inserir antes de um c�digo         *
 * entrada : lista                              *
 * sa�da   : lista com novo elemento            *
 ************************************************/
void inclui_antes( NODO *lista ){
     

}



/************************************************
 * inclui_depois                                *
 * objetivo: inserir depois de um c�digo        *
 * entrada : lista                              *
 * sa�da   : lista com novo elemento            *
 ************************************************/
void inclui_depois( NODO *lista ){
 

}



/************************************************
 * exclui_nodo                                  *
 * objetivo: rotina para excluir registro       *
 * entrada : lista                              *
 * sa�da   : lista com um elemento removido     *
 ************************************************/
void exclui_nodo( NODO *lista ){
     if( lista->f == 0 )           // verifica se a lista est� vazia
         printf( "Lista vazia!" ); 
     else{
     	 int cod_ref;              // c�digo de refer�ncia a ser exclu�do 
         printf( "Informe c�digo de refer�ncia: " );      	
         scanf("%i", &cod_ref);         

         int i= 0;                 // controle do la�o
         while( i < lista->f && lista->info[i].codigo != cod_ref ) // c�digo que est� na lista � diferente de c�digo de refer�ncia
                i++;               // percorre a lista  i++ - i=i+1         
		 while( i < lista->f-1 ){  // deslocamento       
		        lista->info[i]= lista->info[i+1]; // desloca registro uma posi��o � frente
		        i++;               // percorre a lista
	     }
	     if( i < lista->f ){
	         lista->f--;           // exclui registro da lista
	         printf( "Registro exclu�do!" );
	     }else
		     printf( "C�digo n�o encontrado!" );    
	 }    
	 
	 getchar();       // parada da tela
}



/************************************************
* ordena_lista                                  *
* objetivo: rotina para ordenar lista por c�digo*
* entrada : lista                               *
* sa�da   : lista ordenada                      *
*************************************************/
void ordena_lista( NODO *lista ){              // Algoritmo M�todo Bolha - Bubble Sort 
    if( lista->f == 0 )                        // verifica se a lista est� vazia
        printf( "\n Lista vazia! " );
    else
       if( lista->f == 1 )                     // verifica se a lista tem apenas um registro
           printf( "\n Lista com apenas um registro! " );
       else{
           int i, j;                           // i, j = �ndices para percorrer a lista
           INFORMACAO aux;                     // auxiliar para a troca de dados
           for( i = 0; i < lista->f-1; i++ )   // percorre a lista realizando a compara��o entre registros
                for( j = i + 1; j < lista->f; j++ )
                     if( lista->info[ j ].codigo < lista->info[ i ].codigo ){ // se c�digo do sucessor for maior, troca
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
 * sa�da   : lista com um elemento alterado     *
 ************************************************/
void altera_nodo( NODO *lista ){
        

}             


/************************************************
 * consulta_nome                                *
 * objetivo: rotina para consultar nome         *
 * entrada : lista                              *
 * sa�da   : nenhuma, dados em tela             *
 ************************************************/
void consulta_nome( NODO lista )
{
	
	     
   	char procuraNome[30]; // o nome nao ter� mas que 30 char de acordo com defini��o da Struct
	int index = 0;
	
	if(lista.f  == 0) //valida se a lista est� vazia
	{
		printf("N�o existem registros a serem consultados!"); //informa usuario
		getchar();
	}
	
	else{
		
			printf("informe o nome a ser consultado:"); //pega nome a ser consultado
			scanf("%s",&procuraNome);

			
			for (index = 0 ;  index <= lista.f ; index ++) //percorre todas as posi��es do vetor enquanto nao atingir o limite de tamanho ocupado
			
				{
				
					if (strcmp(lista.info[index].nome,procuraNome) == 0) //verifica desde a primeira posi��o, comparando se o c�digo da pr�xima � menor que o da posi��o atual
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
 * sa�da   : lista com novo elemento            *
 ************************************************/         
void inclui_ordenado ( NODO *lista ){
     

}



/************************************************
 * compara_repetidos                            *
 * objetivo: rotina compara registros           *
 * entrada : lista                              *
 * sa�da   : nenhuma                            *
 ************************************************/ 
void compara_repetidos ( NODO *lista ){   
     

}



/************************************************
 * elimina_repetidos                            *
 * objetivo: rotina exclui registros repetidos  *
 * entrada : lista                              *
 * sa�da   : lista atualizada                   *
 ***********************************************/ 
void elimina_repetidos( NODO *lista ){ //FUN��O N�O VALIDADA COM NOME!!!!!!!!!!!!!!!!!!!!
    
    
}

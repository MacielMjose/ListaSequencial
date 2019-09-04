//#include "MODELOSEQ.h"

void inclui_fim( NODO *lista ){
     
    if( lista->f == N_MAX )                    // verifica se a lista est� cheia
        printf( "\n Lista cheia! " );
    else{
        printf( "\n\n Digite o c�digo: " );
	    fflush( stdin );                        // limpa buffer do teclado, funciona junto com entrada de dados
	    scanf( "%d", &lista->info[ lista->f ].codigo );
	
	    printf( "\n Digite o nome: " );
	    fflush( stdin );     
	    gets( lista->info[ lista->f ].nome );

        lista->f++;                            // incrementa o tamanho da lista
        printf( "\n Registro inclu�do no fim!" );
    }
}

// � poss�vel substituir as entradas por uma nova fun��o chamada entrada de dados e inclu�-la como biblioteca, utilizando:
   	    //INFORMACAO aux;                        // auxiliar para a entrada de dados
        //entrada_dados( &aux );                 // l� dados, entrada
        //lista->info[ lista->f ] = aux;         // inclui dados ao final da lista (posi��o lista->f)

//#include "MODELOSEQ.h"

void inclui_fim( NODO *lista ){
     
    if( lista->f == N_MAX )                    // verifica se a lista está cheia
        printf( "\n Lista cheia! " );
    else{
        printf( "\n\n Digite o código: " );
	    fflush( stdin );                        // limpa buffer do teclado, funciona junto com entrada de dados
	    scanf( "%d", &lista->info[ lista->f ].codigo );
	
	    printf( "\n Digite o nome: " );
	    fflush( stdin );     
	    gets( lista->info[ lista->f ].nome );

        lista->f++;                            // incrementa o tamanho da lista
        printf( "\n Registro incluído no fim!" );
    }
}

// É possível substituir as entradas por uma nova função chamada entrada de dados e incluí-la como biblioteca, utilizando:
   	    //INFORMACAO aux;                        // auxiliar para a entrada de dados
        //entrada_dados( &aux );                 // lê dados, entrada
        //lista->info[ lista->f ] = aux;         // inclui dados ao final da lista (posição lista->f)

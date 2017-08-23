#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

struct arbol
	{
	int dato;
	struct arbol *izq;
	struct arbol *der;
	}*raiz;

enum{ FALSO=0, VERDADERO };


/*PROTOTIPOS*/
//void inicializar( void );
struct arbol *newnodo(void);
int vacio( struct arbol *hoja );
int eshoja( struct arbol *hoja );
struct arbol *insertar( struct arbol *raiz, struct arbol *hoja, int num );
int busqueda( struct arbol *hoja, int num );
//int alturax( struct arbol *hoja, int num );
//int alturafull( struct arbol *hoja, int *altura );
//void auxaltura( struct arbol *hoja, int *altura, int cont );
//int nodos( struct arbol *hoja );
//void auxnodos( struct arbol *hoja, int *cont );
struct arbol *borrarx( struct arbol *hoja, int num );
struct arbol *podar( struct arbol *hoja );
void preorden( struct arbol *hoja );
void inorden( struct arbol *hoja );
void posorden( struct arbol *hoja );
//void menu_recorridos( void );
//void menu_busquedas( void );
//void menu_alturas( void );
//void menu_nodos( void );
//void menu_podar( void );


struct arbol *newnodo(void) {
  return (struct arbol *) malloc(sizeof(struct arbol));
}

int vacio( struct arbol *hoja ){
	if( !hoja ) return VERDADERO;
	return FALSO;
}

int eshoja( struct arbol *hoja ){
	if( hoja->izq==NULL && hoja->der==NULL )
		return VERDADERO;
	return FALSO;
}

struct arbol *insertar( struct arbol *raiz, struct arbol *hoja, int num ){
	if( !hoja ){

		hoja= (struct arbol *) malloc( sizeof (struct arbol) );
		hoja->dato= num;
		hoja->izq= NULL;
		hoja->der= NULL;
		if( !raiz ) return hoja;
		else if( num<raiz->dato ) raiz->izq= hoja;
		else raiz->der= hoja;
		return hoja;
	}
	else if( num<hoja->dato )
		insertar( hoja, hoja->izq, num );
	else insertar( hoja, hoja->der, num );
	return raiz;
}

int busqueda( struct arbol *hoja, int num ){
	while( hoja ){
		if( num==hoja->dato ) return VERDADERO;
		else
		{
			if( num<hoja->dato ) hoja= hoja->izq;
			else hoja= hoja->der;
		}
	}
	return FALSO;
}

/*
int alturax( struct arbol *hoja, int num ){
	int altura=1;

	while( hoja )
		{
		if( num==hoja->dato ) return altura;
		else
			{
			altura++;
			if( num<hoja->dato ) hoja= hoja->izq;
			else hoja= hoja->der;
			}
		}
	return FALSO;
}
*/

/*
int alturafull( struct arbol *hoja, int *altura ){
	auxaltura( hoja, altura, 1 );
	return *altura;
}
*/

/*
void auxaltura( struct arbol *hoja, int *altura, int cont )
	{
	if( !hoja ) return;

	auxaltura( hoja->izq, altura, cont+1 );
	auxaltura( hoja->der, altura, cont+1 );
	if( (eshoja( hoja ) && cont)>*altura ) *altura= cont;
	}
*/	

/*
int nodos( struct arbol *hoja )
	{
	int nodos=0;
	auxnodos( hoja, &nodos );
	return nodos;
	}

void auxnodos( struct arbol *hoja, int *cont )
	{
	if( !hoja ) return;

	(*cont)++;
	auxnodos( hoja->izq, cont );
	auxnodos( hoja->der, cont );
	}
*/

struct arbol *borrarx( struct arbol *hoja, int num ){
	if( hoja->dato==num )
		{
		struct arbol *p, *p2;

		if( vacio( hoja ) )
			{
			free( hoja );
			hoja= NULL;
			return hoja;
			}
		else if( hoja->izq==NULL )
			{
			p= hoja->der;
			free( hoja );
			return p;
			}
		else if( hoja->der==NULL )
			{
			p= hoja->izq;
			free( hoja );
			return p;
			}
		else
			{
			p= hoja->der;
			p2= hoja->der;
			while( p->izq ) p= p->izq;
			p->izq= hoja->izq;
			free( hoja );
			return p2;
         }
		}
	else if( num<hoja->dato )
		hoja->izq= borrarx( hoja->izq, num );
	else
		hoja->der= borrarx( hoja->der, num );
	return hoja;
}

struct arbol *podar( struct arbol *hoja )
	{
	if( !hoja ) return hoja;

	podar( hoja->izq );
	podar( hoja->der );
	free( hoja );
	hoja= NULL;
   return hoja;
   }

/*Recorridos*/

void preorden( struct arbol *hoja ){
	if( !hoja ) return;

	printf( "%i ", hoja->dato );
	preorden( hoja->izq );
	preorden( hoja->der );
}

void inorden( struct arbol *hoja ){
	if( !hoja ) return;

	inorden( hoja->izq );
	printf( "%i ", hoja->dato );
	inorden( hoja->der );
}

void posorden( struct arbol *hoja ){
	if( !hoja ) return;

	posorden( hoja->izq );
	posorden( hoja->der );
	printf( "%i ", hoja->dato );
}

/*
///Menus del Arbol
void menu_recorridos( void )
	{
	char _op='S';

	while( _op!='4' )
		{
		clrscr();
		printf( "1. PreOrden." );
		printf( "\n2. InOrden." );
		printf( "\n3. PosOrden." );
		printf( "\n4. Salir." );
		printf( "\n\n:: " );
		_op= getch();
		switch( _op )
			{
			case '1':
				preorden( raiz );
				getch();
				break;
			case '2':
				inorden( raiz );
				getch();
				break;
			case '3':
				posorden( raiz );
				getch();
				break;
			}
		}
	return;
	}

void menu_busquedas( void )
	{
	int val;

	printf( "\n\nNumero: " );
	scanf( "%i", &val );
	if( busqueda( raiz, val ) )
		printf( "\n\nEncontrado.." );
	else printf( "\n\nError, No se encuentra." );
	getch();
	}

void menu_alturas( void )
	{
	char _op='A';
	int val, altura;

	while( _op!='3' )
		{
		clrscr();
		printf( "1. Altura de Un Nodo \( Profundidad \). " );
		printf( "\n2. Altura de Todo el Arbol." );
		printf( "\n3. Salir." );
		printf( "\n\n:: " );
		_op= getch();
		switch( _op )
			{
			case '1':
				printf( "\n\nNumero: " );
				scanf( "%i", &val );
				altura= alturax( raiz, val );
				if( !altura ) printf( "\n\nImposible, numero inexistente." );
				else printf( "\n\nLa Altura es: %i", altura );
				getch();
				break;
			case '2':
				altura= 0;
				printf( "\n\nLa Altura del Arbol es: %i", alturafull( raiz, &altura ) );
				getch();
				break;
			}
		}
	return;
	}

void menu_nodos( void )
	{
	printf( "\n\nEl Numero de Nodos es: %i", nodos( raiz ) );
	getch();
	}

void menu_podar( void )
	{
	char _op='A';
	int val;

	while( _op!='3' )
		{
		clrscr();
		printf( "1. Podar Un Nodos del Arbol." );
		printf( "\n2. Podar Todo el Arbol." );
		printf( "\n3. Salir." );
		_op= getch();
		switch( _op )
			{
			case '1':
				printf( "\n\nNumero: " );
				scanf( "%i", &val );
				raiz= borrarx( raiz, val );
				printf( "\n\n.... Borrado ...." );
				break;
			case '2':
         			raiz= podar( raiz );
				printf( "\n\nArbol Borrado por Completo." );
            			getch();
				break;
			}
		}
	return;
	}

int main()
	{
	char _op='A';
	int val;

	inicializar();

	while( _op!='S' )
		{
		clrscr();
		printf( "Insertar." );
		printf( "\nRecorridos." );
		printf( "\nBusquedas." );
		printf( "\nAlturas." );
		printf( "\nNodos." );
		printf( "\nPodar." );
		printf( "\nSalir." );
		printf( "\n\n:: " );
		_op= toupper( getch() );
		switch( _op )
			{
			case 'I':
				printf( "\n\nNumero: " );
				scanf( "%i", &val );
				if( busqueda( raiz, val ) )
					{
					printf( "\n\nEste numero ya ha sido insertado." );
					getch();
					break;
					}
				raiz= insertar( raiz, raiz, val );
				break;
			case 'R':
				if( vacio( raiz ) )
					{
					printf( "\n\nEl Arbol Aun esta Vacio." );
					getch();
					break;
					}
				menu_recorridos();
				break;
			case 'B':
				if( vacio( raiz ) )
					{
					printf( "\n\nEl Arbol Aun esta Vacio." );
					getch();
					break;
					}
				menu_busquedas();
				break;
			case 'A':
				if( vacio( raiz ) )
					{
					printf( "\n\nEl Arbol Aun esta Vacio." );
					getch();
					break;
					}
				menu_alturas();
				break;
			case 'N':
				if( vacio( raiz ) )
					{
					printf( "\n\nEl Arbol Aun esta Vacio." );
					getch();
					break;
					}
				menu_nodos();
				break;
			case 'P':
				if( vacio( raiz ) )
					{
					printf( "\n\nEl Arbol Aun esta Vacio." );
					getch();
					break;
					}
				menu_podar();
				break;
			}
		}
	printf( "\n\nPulsa para salir..." );
	getchar();
	return 0;
	}
*/
// stack2.c - LIFO stack
// Implementation of Stack by linked list

#include <stdio.h>
#include <stdlib.h>


#define SIZE 100

typedef struct tray {  
   int value;           
   struct tray *below;   /* pointer to successor on stack */
} node;

node *top = NULL;    /* pointer to top node on stack */
int currsize = 0;  /* number of items on stack */

void  get_data(node *ptr ), put_data( const node *ptr );
node *pop( void ), *push( node tr );

main()
{
     int ans, flag;
     node t, *ptr;

   //  clrscr();

	// printf ("\n size = %d", sizeof(node));

     /* do stack operations until user signals halt */
     do {
	  do {
	       printf( "\nEnter 1 to push, 2 to pop:  " );
	       scanf( "%d", &ans );

	       switch ( ans ) {
	       case 1: /* get a node and add it to stack */
		    get_data( &t );
		    if ( push( t ) == NULL )
			 printf( "\nSTACK FULL\n\n" );
		    break;
	       case 2: /* delete a node from stack and print it */
		    if ( ( ptr = pop() ) != NULL )
			 put_data( ptr );
		    else
			 printf( "\nSTACK EMPTY\n\n" );
		    break;
	       default:
		    printf( "\nIllegal response\n" );
		    break;
	       }
	  } while ( ans != 1 && ans != 2 );
	  printf( "\n1 to continue, 0 to quit: " );
	  scanf( "%d", &flag );
     } while ( flag );

     return 0;
}

/*   get_data prompts the user for a tray's color and id and stores
     it at the address passed.   */

void  get_data(node *ptr )
{
   
}

/*   put_data writes the color and id of the node whose address is
     passed by ptr.   */

void put_data( const node *ptr )
{
}

/*   If the stack is full, push returns NULL. Otherwise, push
     allocates storage for a node, copies the data passed into the
     allocated storage, adds the node to the linked list, updates top
     and the current size of the stack, and returns the address of
     the node added. */

node  *push(node tr )
{
     node *ptr;

     if ( currsize  >=  SIZE ) /* stack full? */
	  return NULL;
     ptr = (node *) malloc( sizeof ( node ) ); /* new TRAY */
     *ptr = tr;   /* store data */
     ptr -> below = top; /* push it on stack */
     top = ptr;   /* update top */
     ++currsize;   /* update current stack size */

     return ptr;
}

/*   If the stack is empty, pop returns NULL. Otherwise, pop copies
     the top node to permanent storage, updates top, frees the stack
     storage, updates the current size of the stack, and returns the
     address of the popped node.   */

node *pop( void )
{
     static node popped_node;
     node *ptr;

     if ( currsize < 1 )   /* empty stack? */
	  return NULL;
     popped_node = *top;    /* copy data to be returned */
     ptr = top;       /* save address of 1st node for garbage collection */
     top = top -> below;    /* update top */
     free( ptr );           /* collect garbage */
     --currsize;            /* update current size */

     return &popped_node;
}

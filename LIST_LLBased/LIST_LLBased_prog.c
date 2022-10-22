/*
 * LIST_LLBased_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sky-pc
 */



#include<stdlib.h>

#include"../DS_LIB/DS_ErrorStatus.h"
#include"../DS_LIB/STD_TYPES.h"



#include"LIST_LLBased_private.h"
#include"LIST_LLBased_interface.h"


/*******************************************************************************/
/*******************************************************************************/
/* Syntax          : DS_ES_t   InitializeList(List_t* pl)                      */
/* Description     : Initialize already created list size to Zero and return   */
/*                   one of Error status value to announce it job status.      */
/* Complexity      : Big-Theta(1)                                              */
/*                                                                             */
/* Parameters (in) : Address of already created list.                          */
/* Parameters (out): None                                                      */
/* Return value:   : None                                                      */
/*******************************************************************************/
void         InitializeList(List_t * pl)
{

	/*************************************************
	 *
	 *           +----------------+-------+
	 *           |  +---------+   |       |
	 *           |  |   0     |   |  O--------->NULL
	 *           |  +---------+   |current|
	 *   O------>|    size        |       |
	 *   pl      |  +---------+   |       |
	 *           |  |   0     |   |  O--------->NULL
	 *           |  +---------+   | head  |
	 *           |currentPosition |       |
	 *           +----------------+-------+
	 *            List_t
	 *************************************************/
	pl->head   = NULL  ;
	pl->current= NULL ;

	pl->currentPosition = 0 ;
	pl->size            =  0   ;

}//_End of InitializeList().

/*******************************************************************************/
/*******************************************************************************/
/* Syntax          : Boolean_type    ListEmpty(List_t* pl)                     */
/* Description     : utility function to check if a list is empty or not.      */
/* Complexity      : Big-Theta(1)                                              */
/*                                                                             */
/* Parameters (in) : Address of already created and initialized list.          */
/* Parameters (out): None                                                      */
/* Return value:   : Boolean_type     FLASE   ---> Not Empty list.             */
/*                                    TRUE    ---> Empty list.                 */
/*                                                                             */
/*******************************************************************************/
Boolean_type    ListEmpty(List_t* pl)
{
	return (pl->size) ?FALSE:TRUE;

}//_End of ListEmpty().

/*******************************************************************************/
/*******************************************************************************/
/* Syntax          : Boolean_type    ListFull(List_t* pl)                      */
/* Description     : utility function to check if a list is full or not.       */
/* Complexity      : Big-Theta(1)                                              */
/*                                                                             */
/* Parameters (in) : Address of already created and initialized list.          */
/* Parameters (out): None                                                      */
/* Return value:   : Boolean_type     FLASE   ---> always Not full list.       */
/*******************************************************************************/
Boolean_type    ListFull(List_t* pl)
{
	return FALSE   ;

}//_End of ListFull().

/*******************************************************************************/
/*******************************************************************************/
/* Syntax          : DS_ES_t     ListSize(u8* valRef ,List_t*  pl)             */
/* Description     : utility function to get size of list.                     */
/* Complexity      : Big-Theta(1)                                              */
/*                                                                             */
/* Parameters (in) : Address of already created and initialized list.          */
/* Parameters (out): Address of u8 variable.                                   */
/* Return value:   : DS_ES_t                                                   */
/*                    ES_OK            ---> Read size successfully.            */
/*                    ES_NULLPOINTER   ---> Address of not created variable.   */
/*******************************************************************************/
void           ListSize(u8* valRef ,List_t*  pl)
{

	if(valRef  != NULL )
	{
		*valRef= pl->size;
	}
	else
	{

	}

}//_End of  ListSize().


/*******************************************************************************/
/*******************************************************************************/
/* Syntax          : DS_ES_t    DestroyList(List_t*  pl)                       */
/* Description     : Destroying list by freeing all list nodes.                */
/* Complexity      : Big-Theta(n)                                              */
/*                                                                             */
/* Parameters (in) : Address of already created.                               */
/* Parameters (out): None.                                                     */
/* Return value:   : DS_ES_t                                                   */
/*                    ES_OK            ---> Read size successfully.            */
/*                    ES_NULLPOINTER   ---> Address of not created variable.   */
/*******************************************************************************/
void    DestroyList(List_t*  pl)
{

	if( pl->head != NULL )
	{
		//_There is One node at least.
		pl->current = pl->head->next;

		while( pl->current != NULL )
		{
			free(pl->head);
			pl->head = pl->current ;
			pl->current = pl->current->next;
		}

		free(pl->head);

		pl->head = NULL;
		pl->current= NULL;

		//_Reset list size to zero.
		pl->size = 0 ;

	}
	else
	{
		//_Nothing to destroy.
	}

}//_End of DestroyList().


/*******************************************************************************/
/*******************************************************************************/
/* Syntax          : viod TraverseList(List_t * , void (*visit)(ListEntry))    */
/* Description     : visit all nodes in the list and pass theme to user        */
/*                   function through pointer to function.                     */
/* Complexity      : Big-Theta(n)                                              */
/*                                                                             */
/* Parameters (in) : 1_Address of already created list to visit.               */
/* Parameters (out): 2_Address of user implemented function.                   */
/* Return value:   : None.                                                     */
/*******************************************************************************/
void        TraverseList(List_t* pl , void (*visit)(keyType))
{
	if( pl->head  != NULL )
	{
		//_if you are here --> there is at least One node.

		ListNode_t* ptr = pl->head ;

		do{
			(*visit)(ptr->data.key);

			ptr = ptr->next ;

		}while( ptr != NULL );

	}
	else
	{
		//_NO nodes to visit.
	}

}//_End of TraverseList().


/*******************************************************************************/
/*******************************************************************************/
/* Syntax          : DS_ES_t  InsertList(u8  p, ListEntry  e , List_t *pl)    */
/* Description     : Insert node in a specific position p in the list.         */
/* Complexity      : Big-Theta(n)                                              */
/*                                                                             */
/* Parameters (in) : 1_Address of already created list to visit.               */
/*                   2_number of position to insert at.                        */
/*                   3_reauired data in the inserted node.                     */
/* Parameters (out): None.                                                     */
/* Return value:   : Error state of type DS_ES_t.                              */
/*                         ES_NOK  ----> if the new node is no                 */
/*                                       successfully allocated.               */
/*                         ES_OK   ----> the new node allocated successfully.  */
/*******************************************************************************/
DS_ES_t        InsertList(u8  p, keyType e , List_t *pl)
{
	DS_ES_t  Local_enuErrorState = ES_NOK  ;


	ListNode_t* new=(ListNode_t*)malloc(sizeof(ListNode_t));

	/*************************************************
	 *           +----------------+--+               *
	 *   O------>|                | O----->          *
	 *  new      +----------------+--+               *
	 *                      	                     *
	 *************************************************/

	if((new != NULL)&&(p >= 0) )
	{

		new->data.key = e    ;
		new->next = NULL ;

		/*************************************************
		 *           +----------------+----+             *
		 *   O------>|       e        |   O----->NULL    *
		 *  new      +----------------+----+             *
		 *                      	                     *
		 *************************************************/

		if(p == 0 )
		{
			//_special case.
			new->next = pl->head ;
			pl->head = new  ;

			pl->current = pl->head ;
			pl->currentPosition=0;

			pl->size++ ;
		}
		else if( pl->currentPosition < p)
		{
			while(pl->currentPosition != (p-1) )
			{
				pl->currentPosition++;
				pl->current = pl->current->next;
			}

			new->next = pl->current->next ;

			pl->current->next =new ;

			pl->current = new ;

			pl->currentPosition++ ;

			pl->size++ ;

		}
		else
		{
			pl->current = pl->head ;
			pl->currentPosition = 0 ;

			while(pl->currentPosition != (p-1))
			{
				pl->current =pl->current->next;
				pl->currentPosition++ ;
			}


			new->next = pl->current->next ;

			pl->current->next =new ;

			pl->current = new ;

			pl->currentPosition++ ;

			pl->size++ ;

		}




		Local_enuErrorState = ES_OK  ;

	}
	else
	{

		//_Report error.
	}


	return Local_enuErrorState ;

}//_End of InsertList().


/*******************************************************************************/
/*******************************************************************************/
/* Syntax          : DS_ES_t  DeletList(u8 , ListEntry* , List_t*)            */
/* Description     : Delete a specific node from list after returning it data  */
/*                   to the caller through pointer of type ListEntry.         */
/* Complexity      : Big-O(n)                                                  */
/*                                                                             */
/* Parameters (in) : 1_Address of already created list to visit.               */
/*                   2_position number of Node to delete.                      */
/* Parameters (out): 1_Addres of ListEntry type variable to pass Data.        */
/* Return value:   : Error state of type DS_ES_t.                              */
/*                         ES_NOK  ----> if the new node is no                 */
/*                                       successfully allocated.               */
/*                         ES_OK   ----> the new node allocated successfully.  */
/*******************************************************************************/
DS_ES_t         DeletList(u8 p, keyType* valRef , List_t* pl)
{
	DS_ES_t  Local_enuErrorState = ES_NOK  ;

	if(valRef != NULL )
	{
		ListNode_t* tmp = NULL;

		if (p == 0)
		{
			pl->current = pl->head->next;
			pl->currentPosition = 0 ;
			*valRef = pl->head->data.key ;

			free(pl->head);
			pl->head =pl->current ;


			pl->size-- ;


		}
		else if(  p > pl->currentPosition)
		{
			while(pl->currentPosition != (p-1))
			{
				pl->current =pl->current->next;

				pl->currentPosition++;
			}

			tmp = pl->current->next;

			*valRef = tmp->data.key ;

			pl->current->next = tmp->next;

			free(tmp);

			pl->size-- ;

		}
		else
		{
			pl->current = pl->head ;
			pl->currentPosition = 0 ;

			while(pl->currentPosition != (p-1))
			{
				pl->current =pl->current->next;
				pl->currentPosition++;
			}

			tmp = pl->current->next ;

			*valRef = tmp->data.key ;

			pl->current->next = tmp->next;

			free(tmp);

			pl->size-- ;


		}


		Local_enuErrorState = ES_OK  ;

	}
	else
	{
		Local_enuErrorState = ES_NULLPOINTER  ;
	}


	return Local_enuErrorState ;
}//_End of DeletList().


/*******************************************************************************/
/*******************************************************************************/
/* Syntax          : DS_ES_t  RetrieveList( u8 pos , ListEntry*,List_t*)       */
/* Description     : Get data from a specific node on the list.                */
/* Complexity      : Big-O(n)                                                  */
/*                                                                             */
/* Parameters (in) : 1_Address of already created list to visit.               */
/*                   2_position number of Node to delete.                      */
/* Parameters (out): 1_Addres of ListEntry type variable to pass Data.         */
/* Return value:   : None.                                                     */
/*******************************************************************************/
DS_ES_t         RetrieveList( u8 pos , keyType* pe ,List_t* pl )
{
	DS_ES_t  Local_enuErrorState = ES_NOK  ;

	if( pe != NULL )
	{

		if(pos == 0)
		{
			*pe = pl->head->data.key ;
		}
		else if(pos > pl->currentPosition)
		{

			for(;pl->currentPosition != pos ; pl->current= pl->current->next ,pl->currentPosition++ ){}
			*pe = pl->current->data.key ;
		}
		else
		{
			pl->current = pl->head->next;
			pl->currentPosition = 1 ;

			for(;pl->currentPosition != pos ; pl->current= pl->current->next ,pl->currentPosition++ ){}
			*pe = pl->current->data.key ;



		}

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULLPOINTER;
	}


	return Local_enuErrorState ;
}//_End of  RetrieveList().

/*******************************************************************************/
/*******************************************************************************/
/* Syntax          : ReplaceList(u8 pos ,ListEntry  e, List_t* pl)            */
/* Description     : Replace a specific element at specific position in a list.*/
/* Complexity      : Big-O(n)                                                  */
/*                                                                             */
/* Parameters (in) : 1_Position number to replace at  'pos'.                   */
/*                   2_the new element to replace.                             */
/*                   3_Address of list to replace in.                          */
/* Parameters (out): None.                                                     */
/* Return value:   : None.                                                     */
/*******************************************************************************/
void   ReplaceList(u8 pos ,keyType  e, List_t* pl)
{

	if(pos == 0)
	{
		pl->head->data.key=e  ;
	}
	else if(pos > pl->currentPosition)
	{
		while( pl->currentPosition != pos)
		{
			pl->current = pl->current->next ;
			pl->currentPosition++ ;
		}

		pl->current->data.key = e ;

	}
	else
	{
		pl->current = pl->head->next ;
		pl->currentPosition = 1 ;

		while( pl->currentPosition != pos)
		{
			pl->current = pl->current->next ;
			pl->currentPosition++ ;
		}

		pl->current->data.key = e ;
	}

}

void InsertOrder(keyType e, List_t* pl )
{
	ListNode_t* new  = (ListNode_t*)malloc(sizeof(ListNode_t));

	if(new != NULL )
	{
		new->data.key =e ;
		new->next = NULL ;

		if(pl->size == 0)
		{
			pl->head = new ;
			pl->current = new ;
			pl->currentPosition = 0 ;
			pl->size++ ;
		}
		else
		{
			if(e < pl->current->data.key)
			{
				pl->current = pl->head ;
				pl->currentPosition = 0 ;

				if(pl->current->data.key >= e)
				{
					new->next = pl->head ;
					pl->head  = pl->current = new ;
					pl->size++ ;

				}else
				{
					while(pl->current->next->data.key <= e)
					{
						pl->current = pl->current->next ;
						pl->currentPosition++ ;
					}
					new->next = pl->current->next ;
					pl->current->next = new ;
					pl->size++ ;

				}

			}

		}











	}
	else
	{

	}




}

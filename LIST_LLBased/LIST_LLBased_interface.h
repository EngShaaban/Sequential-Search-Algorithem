/*
 * LIST_LLBased_interface.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sky-pc
 */

#ifndef LIST_LLBASED_INTERFACE_H_
#define LIST_LLBASED_INTERFACE_H_


#include"../Globle.h"


typedef struct listNode
{
	QueueEntry         data;

	struct listNode*   next ;

}ListNode_t;


typedef struct list
{
	ListNode_t*  head           ;
	ListNode_t*  current        ;

	u8       size               ;
	u8       currentPosition    ;

}List_t;



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
void         InitializeList(List_t *);


/*******************************************************************************/
/*******************************************************************************/
/* Syntax          : Boolean_type    ListEmpty(List_t* pl)                     */
/* Description     : utility function to check if a list is empty or not.      */
/*                                                                             */
/* Complexity      : Big-Theta(1)                                              */
/*                                                                             */
/* Parameters (in) : Address of already created and initialized list.          */
/* Parameters (out): None                                                      */
/* Return value:   : Boolean_type     FLASE   ---> in case of empty list.      */
/*                                    TRUE    ---> in case of NOT empty list.  */
/*                                                                             */
/*******************************************************************************/
Boolean_type    ListEmpty(List_t* pl);



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
Boolean_type    ListFull(List_t*);


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
void           ListSize(u8* ,List_t*);


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
void           DestroyList(List_t *);


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
DS_ES_t     InsertList(u8, keyType, List_t *);

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
DS_ES_t     DeletList(u8 , keyType*, List_t *);


/*******************************************************************************/
/*******************************************************************************/
/* Syntax          : DS_ES_t  RetrieveList( u8 pos , ListEntry*,List_t*)       */
/* Description     : Get data from a specific node on the list.                */
/* Complexity      : Big-O(n)                                                  */
/*                                                                             */
/* Parameters (in) : 1_Address of already created list to visit.               */
/*                   2_position number of Node to delete.                      */
/* Parameters (out): 1_Addres of ListEntry type variable to pass Data.         */
/* Return value:   : Error state of type DS_ES_t.                              */
/*                         ES_NOK  ----> if the new node is no                 */
/*                                       successfully allocated.               */
/*                         ES_OK   ----> the new node allocated successfully.  */
/*******************************************************************************/
DS_ES_t         RetrieveList( u8 pos , keyType* pe ,List_t* pl );


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
void   ReplaceList(u8 pos ,keyType  e, List_t* pl);

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
void        TraverseList(List_t * pl , void (*visit)(keyType ));

void InsertOrder(keyType e, List_t* pl );

#endif /* LIST_LLBASED_INTERFACE_H_ */

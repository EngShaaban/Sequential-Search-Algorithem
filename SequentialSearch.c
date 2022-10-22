

#include"DS_LIB/DS_ErrorStatus.h"
#include"DS_LIB/STD_TYPES.h"

#include"LIST_LLBased/LIST_LLBased_interface.h"


s8  SequentialSearch(keyType  target , List_t*  pl )
{

	u8     size = 0;

	keyType  currentElement;

	ListSize(&size , pl );

	for(u8 iterator = 0;  iterator < size ;  iterator++)
	{

		RetrieveList(iterator, &currentElement , pl);

		if( EQ(target , currentElement) )
		{
			return iterator;
		}
	}



	return  -1 ;
}

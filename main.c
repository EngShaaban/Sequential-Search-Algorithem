/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sky-pc
 */

#include<stdio.h>
#include"DS_LIB/DS_ErrorStatus.h"
#include"DS_LIB/STD_TYPES.h"

#include"LIST_LLBased/LIST_LLBased_interface.h"

#include"SequentialSearch.h"

List_t l ;

int main(void)
{
	puts("############################################");

	InitializeList(&l);

	InsertList(0, 0,&l);
	InsertList(1, 11,&l);
	InsertList(2, 22,&l);

	InsertList(4, 44,&l);
	InsertList(5, 55,&l);

	InsertOrder(7, &l );

	s8 i = SequentialSearch(99 ,&l );

	printf("---> %d\n",i);


	puts("############################################");
	return 0 ;
}

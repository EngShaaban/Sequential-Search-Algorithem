/*
 * Globle.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sky-pc
 */

#ifndef GLOBLE_H_
#define GLOBLE_H_

typedef u8 keyType;

#define  EQ(A,B)   ((A)==(B))
#define  LT(A,B)   ((A)<(B))
#define  LE(A,B)   ((A)<=(B))
#define  GT(A,B)   ((A)>(B))
#define  GE(A,B)   ((A)>=(B))


typedef struct elementType
{

	keyType   key ;

}ElementType_t;


#define MAXELEMENTS   100

typedef ElementType_t      QueueEntry ;
#define MAXQUEUE           MAXELEMENTS

typedef ElementType_t      StackEntry ;
#define MAXSTACK           MAXELEMENTS




#endif /* GLOBLE_H_ */

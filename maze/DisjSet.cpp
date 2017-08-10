#include "DisjSet.h"

/**
 * Construct the disjoint sets object.
 * numElements is the initial number of disjoint sets.
 */
DisjSets::DisjSets( int numElements ) : s( numElements )
{
    for( int i = 0; i < s.size( ); i++ )
        s[ i ] = -1;
}

/**
 * Union two disjoint sets.
 * For simplicity, we assume root1 and root2 are distinct
 * and represent set names.
 * root1 is the root of set 1.
 * root2 is the root of set 2.
 */
void DisjSets::unionSets( int root1, int root2 )
{
    if( s[ root2 ] < s[ root1 ] )  // root2 is deeper
        s[ root1 ] = root2;        // Make root2 new root
    else
    {
        if( s[ root1 ] == s[ root2 ] )
            s[ root1 ]--;          // Update height if same
        s[ root2 ] = root1;        // Make root1 new root
    }
}


/**
 * Perform a find.
 * Error checks omitted again for simplicity.
 * Return the set containing x.
 */
int DisjSets::find( int x ) const
{
    if( s[ x ] < 0 )
        return x;
    else
        return find( s[ x ] );
}


/**
 * Perform a find with path compression.
 * Error checks omitted again for simplicity.
 * Return the set containing x.
 */
int DisjSets::find( int x )
{
    if( s[ x ] < 0 )
        return x;
    else
        return s[ x ] = find( s[ x ] );
}

//access up value
int boardCell::getup(void)
{
	return up;
}

//access down value
int boardCell::getdown(void)
{
	return down;
}

//access left value
int boardCell::getleft(void)
{
	return left;
}
//access right value
int boardCell::getright(void)
{
	return right;
}
//access cell num//
int boardCell::getcellNum(void)
{
	return cellNum;
}
//access visited//
int boardCell::getvisited(void)
{
	return visited;
}

//Assign north wall status//
void boardCell::asgUp(int num)
{
	up=num;
}

//Assign south wall status//
void boardCell::asgDown(int num)
{
	down=num;
}

//Assign west wall status//
void boardCell::asgLeft(int num)
{
	left=num;
}

//Assign east wall status//
void boardCell::asgRight(int num)
{
	right=num;
}

//Assign cell Num//
void boardCell::asgcellNum(int num)
{
	cellNum=num;
}

//Assign visited value//
void boardCell::asgvisited(int num)
{
	visited=num;
}

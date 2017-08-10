#include "DisjSet.h"
#include "queue.h"

//Function prints a ascii maze based off of the input board and size//
void printBoard( vector<vector<boardCell>> &board,int size)
{
	int i=0;
	int j=0;
	int first=1;



	

	for(i=0;i < size;i++)
	{
		for(j=0;j < size;j++)
		{
			int temp = board[i][j].getup();
			//Print all the north walls//
			if((temp == 1)&&(first==0))
				cout<<" __";
			else
			{
				cout<<"   ";
				first=0;
			}
		}

		cout<<endl<<endl;

		cout<<"|";  //Print the first wall in a row//

		for(j=0;j < size-1;j++)
		{
			int temp = board[i][j].getright();
			//Print all walls that exist based off of board//
			if(temp == 1)
				cout<<"  |";
			else
				cout<<"   ";
		}

		//Print the last wall of a line//
		cout<<"  |";
		cout<<endl;

	}

	for(j=0;j < size-1;j++)
	{
		int temp = board[size - 1][j].getdown();
			//Print all lower walls based on if they exist in board//
			if(temp == 1)
				cout<<" __";
			else
				cout<<"   ";
	}

	cout<<endl;

}

//Creates a randomly generated maze that has a solution from the first cell to the last cell//
void initializeBoard( vector<vector<boardCell>> &board,int size,DisjSets &s)
{
	int random=0;
	int row=0;
	int column=0;
	int direction=0;
	int szsqr=0;
	int adjasent=0;


	srand (time(NULL));

	szsqr=size*size;

	board[0][0].asgUp(0);  //The first cell has a hole up//
	board[size-1][size-1].asgDown(0); //The last cell as a hole down//

	while(s.find(0)!=s.find(szsqr-1))
	{
		random=rand()%szsqr;

		row=random/size;
        column=random%size;

		/* After choosing a random cell, there is a case for every type of cell that could be choosen.
		   It could be a corner cell, a side row, a side column, or a center cell. Based off of this position
		   the numbe rof directions that can be choosen is resticted. If the direction choosen does not open up to a new 
		   disjoint set then a new cell is choosen and the process is repeated.         */

		//Top left Corner//
		if((row==0)&&(column==0))
		{
			direction=rand()%2;


			if(direction==0)
			{
				adjasent=random+1;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgRight(0);
					board[row][column+1].asgLeft(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
			if(direction==1)
			{
				adjasent=random+size;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgDown(0);
					board[row+1][column].asgUp(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
		}

		//Top Right Corner
		else if((row==0)&&(column==(size-1)))
		{
			direction=rand()%2;

			if(direction==0)
			{
				adjasent=random-1;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgLeft(0);
					board[row][column-1].asgRight(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
			if(direction==1)
			{
				adjasent=random+size;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgDown(0);
					board[row+1][column].asgUp(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
		}

		//Bottom Left Corner//
		else if((row==(size-1))&&(column==0))
		{
			direction=rand()%2;

			if(direction==0)
			{
				adjasent=random+1;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgRight(0);
					board[row][column+1].asgLeft(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
			if(direction==1)
			{
				adjasent=random-size;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgUp(0);
					board[row-1][column].asgDown(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
		}

		//Bottom Right Corner//
		else if((row==(size-1))&&(column==(size-1)))
		{
			direction=rand()%2;

			if(direction==0)
			{
				adjasent=random-1;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgLeft(0);
					board[row][column-1].asgRight(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
			if(direction==1)
			{
				adjasent=random-size;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgUp(0);
					board[row-1][column].asgDown(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
		}

		//Left Column//
		else if(column==0)
		{
			direction=rand()%3;

			if(direction==0)
			{
				adjasent=random-size;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgUp(0);
					board[row-1][column].asgDown(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
			if(direction==1)
			{
				adjasent=random+1;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgRight(0);
					board[row][column+1].asgLeft(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
			if(direction==2)
			{
				adjasent=random+size;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgDown(0);
					board[row+1][column].asgUp(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
		}

		//Upper Row//
		else if(row==0)
		{
			direction=rand()%3;

			if(direction==0)
			{
				adjasent=random-1;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgLeft(0);
					board[row][column-1].asgRight(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
			if(direction==1)
			{
				adjasent=random+1;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgRight(0);
					board[row][column+1].asgLeft(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
			if(direction==2)
			{
				adjasent=random+size;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgDown(0);
					board[row+1][column].asgUp(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}

			}
		}

		//Right Column//
		else if(column==(size-1))
		{
			direction=rand()%3;

			if(direction==0)
			{
				adjasent=random-size;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgUp(0);
					board[row-1][column].asgDown(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
			if(direction==1)
			{
				adjasent=random-1;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgLeft(0);
					board[row][column-1].asgRight(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
			if(direction==2)
			{
				adjasent=random+size;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgDown(0);
					board[row+1][column].asgUp(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
		}

		//Bottom Row//
		else if(row==(size-1))
		{
			direction=rand()%3;

			if(direction==0)
			{
				adjasent=random-size;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgUp(0);
					board[row-1][column].asgDown(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
			if(direction==1)
			{
				adjasent=random+1;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgRight(0);
					board[row][column+1].asgLeft(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
			if(direction==2)
			{
				adjasent=random-1;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgLeft(0);
					board[row][column-1].asgRight(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
		}

		//All middle squares with 4 directions of travel//
		else
		{

			direction=rand()%4;

			if(direction==0)
			{
				adjasent=random+1;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgRight(0);
					board[row][column+1].asgLeft(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
			if(direction==1)
			{
				adjasent=random-1;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgLeft(0);
					board[row][column-1].asgRight(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
			if(direction==2)
			{
				adjasent=random+size;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgDown(0);
					board[row+1][column].asgUp(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
			if(direction==3)
			{
				adjasent=random-size;
				if(s.find(random)!=s.find(adjasent))
				{
					board[row][column].asgUp(0);
					board[row-1][column].asgDown(0);
					s.unionSets(s.find(random),s.find(adjasent));
				}
			}
		}

	}
}

/*This algorithm solves a maze with a broad search pattern. It also prints all cells visited, all cells for the path,
and prints an ascii representation of the path found.*/
void solveDFT(vector<vector<boardCell>> &board,int size)
{
	vector <boardCell> stack;
	vector<vector<char>> path;
	boardCell current;
	//boardCell temp;
	int room;
	int i = 0;
	int j = 0;
	int left,right,down,up;

	stack.push_back(board[0][0]);
	vector <int> roomsVisited;

	current = stack.back();
	board[0][0].asgvisited(1);
	roomsVisited.push_back(current.getcellNum());
	stack.pop_back();
	room = current.getcellNum();

	if(current.getdown() == 0)
	{
		stack.push_back(board[room/size+1][room%size]);
		board[room/size+1][room%size].asgvisited(1);
	}
		
		
	if(current.getright() == 0)
	{
		stack.push_back(board[room/size][(room%size)+1]);
		board[room/size][(room%size)+1].asgvisited(1);
	}

	
	int row = 0;
	int col = 0;
	
	
	while(!stack.empty())
	{
		current = stack.back();
		current.asgvisited(1);
		roomsVisited.push_back(current.getcellNum());
		stack.pop_back();
		room = current.getcellNum();
		row = current.getcellNum() / size;
		col = current.getcellNum() % size;

		if(room == (size*size -1))
			break;
		
		//int temp = ;
		if(current.getup() == 0)
		{
			if(board[row - 1][col].getvisited() == 0)
			{
				stack.push_back(board[row - 1][col]);
				board[row - 1][col].asgvisited(1);
			}
		}
		//temp = current.getup();
		if(current.getdown() == 0)
		{
			if(board[row + 1][col].getvisited() == 0)
			{
				stack.push_back(board[row + 1][col]);
				board[row + 1][col].asgvisited(1);
			}
		}


		if(current.getright() == 0)
		{
			if(board[row][col + 1].getvisited() == 0)
			{
				stack.push_back(board[row][(col + 1)]);
				board[row][(col + 1)].asgvisited(1);
			}
		}

		if(current.getleft() == 0)
		{
			if(board[row][col - 1].getvisited() == 0)
			{
				stack.push_back(board[row][col - 1]);
				board[row][col - 1].asgvisited(1);
			}
		}
			

	
	}

	cout<<endl;

	cout<<"Rooms visited by DFS: ";
	//roomsVisited.push_back(size*size-1);
	i = 0;
	j = roomsVisited.size();
	
	
	while(i < j)
	{
		cout<<roomsVisited[i]<<" ";
		i++;
	}
	
	cout<<endl;

	for(int k=0;k<size;k++)
	{
		vector<char> single;

		for(int j=0;j<size;j++)
		{
			single.push_back('.');
		}
		path.push_back(single);
	}

	
	int cursz=roomsVisited.size();

	//board[size-1][size-1].asgvisited2(1);
	int current1 = roomsVisited.back();
	row=current1/size;
	col=current1%size;
	path[row][col]='X';
	
	cout<<endl;
	cout<<"The path from end to beginning is: ";
	cout<<endl;
	cout<<current1<<" ";

	while(current1!=0)
	{
				
		//room = current1;
		//current = board[row][col];
		//current.asgvisited2(1);
		left=current1-1;
		right=current1+1;
		up=current1-size;
		down=current1+size;
		
//		solution.push_back(room);
		/*if(room == 0)
			break;*/

		if((roomsVisited[cursz-1] == left) &&(board[row][col].getleft()!=1))
		{
			
				cout<<left<<" ";
				current1=left;
				row=current1/size;
				col=current1%size;
				path[row][col]='X';


		}

		else if((roomsVisited[cursz-1] == right) &&(board[row][col].getright()!=1))
		{
			
				cout<<right<<" ";
				current1=right;
				row=current1/size;
				col=current1%size;
				path[row][col]='X';

		}
		
		else if((roomsVisited[cursz-1] == down) &&(board[row][col].getdown()!=1))
		{
			
				cout<<down<<" ";
				current1=down;
				row=current1/size;
				col=current1%size;
				path[row][col]='X';

		}

			
		else if((roomsVisited[cursz-1] == up) &&(board[row][col].getup()!=1))
		{
			
				cout<<up<<" ";
				current1=up;
				row=current1/size;
				col=current1%size;
				path[row][col]='X';

		}
		
		
		
		roomsVisited.pop_back();
		cursz=cursz-1;			
		
	
	}

	cout<<endl;

	int row_index=0;
	int col_index=0;


	//Prints a visual representation of the path//
	cout<<endl;
	cout<<"A visual representation of your path is: ";
	cout<<endl;
	for (row_index = 0; row_index < size;
		 row_index++)
	{
		for (col_index = 0; col_index < size;
		     col_index++)
		{
			cout<<path[row_index][col_index];
		}

		cout<<endl;
	}
}
	

void solveBFT(vector<vector<boardCell>> &board,int size)
{
	int row=0;
	int column=0;
	vector<vector<char>> path;
	vector<char> single;
	vector<int> traversed;
	Queue<boardCell> q;

	//Initialize the queue with the first board element//
	q.enqueue(board[0][0]);

	cout<<endl;
	cout<<"All the cells explored for BFS are: ";
	cout<<endl;

	while(!q.isEmpty()) //Continue until the loop is broken by getting to the last cell//
	{
		boardCell i;

		i=q.dequeue();

		if(i.getcellNum()==(size*size-1)) //Break condition once the last cel is found//
		{
			cout<<i.getcellNum()<<" "<<endl;
			traversed.push_back(i.getcellNum());
			break;
		}

		//Base case for the first cell used. Needed so the solution doesnt exit the maze//
		if(i.getcellNum()==0)
		{
			if(board[0][0].getdown()==0)
			{
				q.enqueue(board[1][0]);
				board[1][0].asgvisited(1);
			}

			if(board[0][0].getright()==0)
			{
				q.enqueue(board[0][1]);
				board[0][1].asgvisited(1);
			}

			board[0][0].asgvisited(1);
		}

		/*For all cells except the first cell, get the row and column of the cell based on the size of the maze then 
		queue all possible directions based on if it is visited and if there is a wall there. Each time the loop continues
		a new value is printed. Each value is also added to a vector of all cells visited.*/
		else
		{
			row=i.getcellNum()/size;
			column=i.getcellNum()%size;
		
			if((board[row][column].getup()==0))
			{	
				if(board[row-1][column].getvisited()!=1)
				{
					q.enqueue(board[row-1][column]);
					board[row-1][column].asgvisited(1);
				}
			}

			if((board[row][column].getdown()==0))
			{	
				if(board[row+1][column].getvisited()!=1)
				{
					q.enqueue(board[row+1][column]);
					board[row+1][column].asgvisited(1);
				}
			}

			if((board[row][column].getright()==0))
			{	
				if(board[row][column+1].getvisited()!=1)
				{
					q.enqueue(board[row][column+1]);
					board[row][column+1].asgvisited(1);
				}
			}

			if((board[row][column].getleft()==0))
			{	
				if(board[row][column-1].getvisited()!=1)
				{
					q.enqueue(board[row][column-1]);
					board[row][column-1].asgvisited(1);
				}
			}

			
		}
		traversed.push_back(i.getcellNum());
		cout<<i.getcellNum()<<" ";

	}

	int left,up,right,down;
	int cursz=traversed.size();
	int current=traversed.back();
	int i=1;

	//Initialize a small board that can print out a path based on the vector made previously//
	for(int k=0;k<size;k++)
	{
		vector<char> single;

		for(int j=0;j<size;j++)
		{
			single.push_back('.');
		}
		path.push_back(single);
	}

	cout<<endl;
	cout<<"The path from end to beginning is: ";
	cout<<endl;
	cout<<current<<" ";

			row=current/size;
			column=current%size;
			path[row][column]='X';

	/* For finding the path backwards, each element that was placed in the vecotr of visited cells is checked against
	   the possible directions for the current cell. If it is possible it is added to the path otherwise it is removed.
	   An X is also added to the path board to be printed later*/

	while(current!=0)
	{
		left=current-1;
		right=current+1;
		down=current+size;
		up=current-size;

		if((traversed[cursz-i]==left)&&(board[row][column].getleft()!=1))
		{
			cout<<left<<" ";
			i=1;
			current=left;
			row=current/size;
			column=current%size;
			path[row][column]='X';
		}

		else if((traversed[cursz-i]==right)&&(board[row][column].getright()!=1))
		{
			cout<<right<<" ";
			i=1;
			current=right;
			row=current/size;
			column=current%size;
			path[row][column]='X';
		}

		else if((traversed[cursz-i]==up)&&(board[row][column].getup()!=1))
		{
			cout<<up<<" ";
			i=1;
			current=up;
			row=current/size;
			column=current%size;
			path[row][column]='X';
		}

		else if((traversed[cursz-i]==down)&&(board[row][column].getdown()!=1))
		{
			cout<<down<<" ";
			i=1;
			current=down;
			row=current/size;
			column=current%size;
			path[row][column]='X';

		}

		traversed.pop_back();
		cursz=cursz-1;

	}

	cout<<endl;

	int row_index=0;
	int col_index=0;


	//Prints a visual representation of the path//
	cout<<endl;
	cout<<"A visual representation of your path is: ";
	cout<<endl;
	for (row_index = 0; row_index < size;
		 row_index++)
	{
		for (col_index = 0; col_index < size;
		     col_index++)
		{
			cout<<path[row_index][col_index];
		}

		cout<<endl;
	}


}
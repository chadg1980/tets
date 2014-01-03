/******************************************************************************
 *Author:	Chad Glaser
 *File name: tet.cpp
 *Last Modified:	1/1/313
 *
 *overview:
 *	This program
 * 	Creates an array using user input
 * 	Outputs the array and finds the largest 4 numbers multiplied together
 *	In the shape of a tetris piece
 *
 ***************************************************************************************/


#include<iostream>
#include<stdlib.h>		//to use atoi
#include <cstdlib>		// for use of srand and rand
#include <time.h>		// time for the seed of the random number
#include <string>
#include<iomanip>		//to use setw, to make the grid output more readable
#include <string.h>
#include <limits.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//Holds the data of the shapes of the tetris pieces
 class tets	{

         public:



                 								//tets are the shapes of the the teris blocks tetriminos.
                string tetrimino;					//The name of the shape
                string rotation;					//The rotation of the shape (if any)
                int block1_col;					//The starting location of the blocks on the grid
                int block1_row;
                int block2_col;
                int block2_row;
                int block3_col;
                int block3_row;
                int block4_col;
                int block4_row;
                int off_row;								//Offset row so the shape doesn't move beyond the grid
                int off_col;								//offset col so the shape stays within the grid
                unsigned long max_prod;				//The max product (found during the programs run)
                int pos_row;						        //The position of the highest product in row and col
                int pos_col;




         private:



};


                void intro();

                //accepts input from the user.
		int get_rows ();
		int get_cols();




	//Allows users to manually input rows and columns, checks to make sure the input is proper
		void try_again( int &rows,  int &cols);

	//Function that creates the array, seeds the array with random numbers
		int** create_array( int,  int);

	//function that prints the array
		void print_array(int **grid, int rows, int cols);

	//Function that finds the greatest product of 4 adjacent numberin the array, using the shapes of tetriminos
		void find_greatest_product(int **grid, int rows, int cols, tets shape[]);

	//***************Get the shapes functions**********************************
		//All the get_Shapes in one place.
			void get_shapes(tets shape[]);
		//Gets the O shape (square)
			void get_O_shapes(tets shape[]);
		//gets the 2 I shapes, to save space in main()
			void get_I_shapes(tets shape[]);
		//Get the 4 L shapes, to save space in main()
			void get_L_shapes(tets shape[]);
		//Gets all 4 J shapes, to save space in main()
			void get_J_shapes(tets shape[]);
		//Gets all 4 T shapes, to save space in main()
			void get_T_shapes(tets shape[]);
		//Gets all Z shapes, to save space in main()
			void get_Z_shapes(tets shape[]);
		//Gets all S shapes, to save space in main()
			void get_S_shapes(tets shape[]);
	//*********************************************************************

//***********************Set the struct for each shape and rotation functions***********************************
		//Gives the information for the square tetrimino
		void set_square(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int 			block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned 				long max_prod, int pos_row, int pos_col);


		//Gives the information for the I structure tetrimino 0 degree rotation
		void set_I(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int 		block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned 			long max_prod, int 	pos_row, int pos_col);
		//Gives the information for the I structure 90 degretetrimino
		void set_I90(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, 	int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int 		pos_row, int pos_col);

		//Function to give values to L shape structure 0 degree rotation
		void set_L(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, 	int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int 		pos_row, int pos_col);
	//Function to give values to L shape structure 90 degree rotation
        void set_L90(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, 	int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int 		pos_row, int pos_col);
	//Function to give values to the L shape  structure 180 degree rotation
	void set_L180(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col);
        //Function to give values to function  L shape structure 270 degree rotation
        void set_L270(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col);

	//Function to give values to J shape structure 0 degree rotation
	void set_J(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, 	int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int 		pos_row, int pos_col);
	//Function to give values to J shape structure 90 degree rotation
	void set_J90(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, 	int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int 		pos_row, int pos_col);
	//Function to give values to the J shape structure 180 degree rotation
	void set_J180(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col);
	//Function to give values to function  J shape structure 270 degree rotation
	void set_J270(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col);

	//Function to give values to T shape structure 0 degree rotation
	void set_T(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, 	int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int 		pos_row, int pos_col);
	//Function to give values to T shape structure 90 degree rotation
	void set_T90(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, 	int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int 		pos_row, int pos_col);
	//Function to give values to the T shape structure 180 degree rotation
	void set_T180(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col);
	//Function to give values to function  T shape  structure 270 degree rotation
	void set_T270(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col);

	//Function to give values to Z shape structure 0 degree rotation
	void set_Z(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, 	int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int 		pos_row, int pos_col);
	//Function to give values to Z shape structure 90 degree rotation
	void set_Z90(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, 	int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int 		pos_row, int pos_col);

	//Function to give value to S shape structure 0 degree rotation
	void set_S(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, 	int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int 		pos_row, int pos_col);
	//Function to give value to S shape structure 90 degree rotation
	void set_S90(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, 	int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int 		pos_row, int pos_col);
//*******************************************************************************************************************


//Function that prints the max product, the shape that found it, the row and col that it is in and the 4 numbers that make up the largest product.
void print_product(int longer, int max_row, int max_col, tets shape[]);

//Function deletes the array from memory
void delete_array(int **grid_array, int rows, int cols);



int main()
{

	tets shape[19];





                intro();
		//Fucntion get rows cols gets the rows and cols only if the command line was input correctly
		int rows = get_rows();
		int cols = get_cols();



		//function to create the array
		int** grid = create_array(rows, cols);

		//functions to create a structure for the tetrimino
		get_shapes(shape);

		//functin to get the max product of the square
		find_greatest_product(grid, rows, cols, shape);

		//function to print the array
		print_array(grid, rows, cols);

		//function to delete the array
		delete_array(grid, rows, cols);

return 0;
}

void intro()
{
                cout << "This program finds the greatest product of four numbers of a grid. \n";
		cout << "The numbers will be touching \n";
		cout << "and in the shape of tetris pieces \n";
		cout << "The shapes will check the product at 0, 90, and 180, and 270 degees (if differnt).\n";
		cout << "Your must be between 4 and 30 \n";
		cout << "Input the number of rows and cols in the format \n";
		cout << "'-row ##  press enter, -col ## press enter \n";
		cout << "You may enter a whole numbers between 4 and  30\n";

}




int get_rows()
{

                char bufferRow[20];


		cout << endl;
		cout << "How many rows do you want?" <<  endl << "-rows:";
		cin >> bufferRow;



int checkRow = static_cast<int>(strlen(bufferRow)) ;

        for(int i = checkRow; i > 0; i--)
        {
                while (!(isdigit((bufferRow[i-1]))))
                {
                        cout << "Please only enter digits";
                      exit(1);

                }
        }



		int rows = atoi(bufferRow);


                //While loop checks for numbers less than 4 (for the size of the tetris piece)
		//or greater than 30 (only 31 columns would fit on my computer screen.
		if((rows < 4)  || (rows > 30 ))
                {
			cout << "The program will not run unless the columns & rows are greater than 4 and less than 30" << endl;
			exit(1);
		}



return rows;

}



int get_cols()
{

                char bufferCol[20];


		cout << endl;
		cout << "How many cols do you want?" <<  endl << "-cols:";
		cin >> bufferCol;



int checkCol = static_cast<int>(strlen(bufferCol)) ;

        for(int i = checkCol; i > 0; i--)
        {
                while (!(isdigit((bufferCol[i-1]))))
                {
                        cout << "Please only enter digits";
                      exit(1);

                }
        }



		int cols = atoi(bufferCol);


                //While loop checks for numbers less than 4 (for the size of the tetris piece)
		//or greater than 30 (only 31 columns would fit on my computer screen.
		if((cols < 4)  || (cols > 30 ))
                {
			cout << "The program will not run unless the columns & rows are greater than 4 and less than 30" << endl;
			exit(1);
		}



return cols;

}






//Function that Creates the array of numbers to be used and seeds it with random numbers
int** create_array( int rows,  int cols)
{
	srand(time(NULL));				       			//Seeding the random number generator.
	int **grid_array;								//create the array of arrays
	grid_array = new int*[rows];					//creating the rows
		for (int i = 0; i < rows; ++i){				//creating the columns
			grid_array[i] = new int[cols];
		}
			for(int i = 0; i < rows; ++i){			//loop to fill the array
				for(int j = 0; j< cols; ++j){
					grid_array[i][j] = rand () % 99;//filling the array with random numbers 0 to 99
				}
			}
return grid_array;									//returning the grid to main
}
//One function to place all the getshape functions.
//One function to rule them all
void get_shapes(tets shape[])
{
		get_O_shapes(shape);	//shape[0]
		get_I_shapes(shape);	//shape[1], shape[2]
		get_L_shapes(shape);	//shape[3], shape[4], shape[5], shape[6]
		get_J_shapes(shape);	//shape[7], shape[8], shape[9], shape[10]
		get_T_shapes(shape);	//shape[11], shape[12], shape [13], shape[14]
		get_Z_shapes(shape);	//shape[15], shape[16]
		get_S_shapes(shape);	//shape[17], shape[18]

}

//Prints the grid to the console screen
void print_array(int **grid_array, int rows, int cols)
{
		for(int i = 0; i < rows; ++i){
			for(int j = 0; j< cols; ++j){
				cout << std::setw(2);				//sets the width to 2, makes the grid easier to read
				cout << grid_array[i][j] << ", ";
			}
			cout << endl;
		}
		cout << endl;
}


/* *******************************	The following 7 functions include functions that send the same information: *************
tets shape, sring tetrimino, string rotation,  int block1_col, int block1_row, int block2_col, int block2_row,
int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long, max_prod,
int pos_row, int pos_col
	For more information or notes please refer to the notes in the struct begining on line 30 to line 45
*********************************************************************************************************	*/

//This function sends the information to the function set_square where the struct for the square is built.
void get_O_shapes(tets shape[])
{
		set_square(shape, "Square", "no rotation", 0,0, 1,0, 0,1, 1,1, -2, -2, 0, 0, 0);	   //shape[0]

}
	void get_I_shapes(tets shape[])
{
		set_I(shape, "I shaped", "0 degrees",    0,0, 0,1, 0,2, 0,3, -4, -1, 0, 0, 0);			//shape[1]
		set_I90(shape, "I shaped", "90 degrees", 0,0, 1,0, 2,0, 3,0, -1, -4, 0, 0, 0);			//shape[2]

}

	void get_L_shapes(tets shape[])
{
		set_L(shape, "L shaped", "0 degrees",      0,0, 0,1, 0,2, 1,2, -3, -2, 0, 0, 0);		//shape[3]
		set_L90(shape, "L shaped", "90 degrees",   0,1, 1,1, 2,1, 2,0, -2, -3, 0, 0, 0);		//shape[4]
		set_L180(shape, "L shaped", "180 degrees", 0,0, 1,0, 1,1, 1,2, -3, -2, 0, 0, 0);		//shape[5]
		set_L270(shape, "L shaped", "270 degrees", 0,0, 1,0, 2,0, 0,1, -2, -3, 0, 0, 0);		//shape[6]
}
	void get_J_shapes(tets shape[])
{
		set_J(shape,    "J shaped", "0 degrees",   1,0, 1,1, 1,2, 0,2, -3, -2, 0, 0, 0);		//shape[7]
		set_J90(shape,  "J shaped", "90 degrees",  0,0, 0,1, 1,1, 2,1, -2, -3, 0, 0, 0);		//shape[8]
		set_J180(shape, "J shaped", "180 degrees", 0,0, 1,0, 0,1, 0,2, -3, -2, 0, 0, 0);		//shape[9]
		set_J270(shape, "J shaped", "270 degrees", 0,0, 1,0, 2,0, 2,1, -2, -3, 0, 0, 0);		//shape[10]
}
	void get_T_shapes(tets shape[])
{
		set_T(shape, 	"T shaped", "0 degrees",   0,0, 1,0, 2,0, 1,1, -2, -3, 0, 0, 0);		//shape[11]
		set_T90(shape,  "T shaped", "90 degrees",  1,0, 1,1, 1,2, 0,1, -3, -2, 0, 0, 0);		//shape[12]
		set_T180(shape, "T shaped", "180 degrees", 2,1, 1,1, 0,1, 1,0, -2, -3, 0, 0, 0);		//shape[13]
		set_T270(shape, "T shaped", "270 degrees", 0,2, 0,1, 0,0, 1,1, -3, -2, 0, 0, 0);		//shape[14]
}

	//Sends the data to the struct for Z shapes
	void get_Z_shapes(tets shape[])
{
		set_Z(  shape, "Z shaped", "0 degrees" , 0,0, 1,0, 1,1, 2,1, -2, -3, 0, 0, 0);			//shape[15]
		set_Z90(shape, "Z shaped", "90 degrees", 1,0, 1,1, 0,1, 0,2, -3, -2, 0, 0, 0);			//shape[16]

}
	//Sends the data to the struct for S shapes
	void get_S_shapes(tets shape[])
{
		set_S(  shape, "S shaped", "0 degrees",  0,1,  1,1,  1,0,  2,0,  -2, -3, 0, 0, 0);			//shape[17]
		set_S90(shape, "S shaped", "90 degrees", 0,0,  1,0,  1,1,  1,2,  -3, -2, 0, 0, 0);		    //shape[18]

}

//Function that sets the struct for the square.
void set_square(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col)
{
	shape[0].tetrimino = tetrimino;
	shape[0].rotation = rotation;
	shape[0].block1_row = block1_row;
	shape[0].block1_col = block1_col;
	shape[0].block2_row = block2_row;
	shape[0].block2_col = block2_col;
	shape[0].block3_row = block3_row;
	shape[0].block3_col = block3_col;
	shape[0].block4_row = block4_row;
	shape[0].block4_col = block4_col;
	shape[0].off_row = off_row;
	shape[0].off_col = off_col;
	shape[0].max_prod = max_prod;
	shape[0].pos_row = pos_row;
	shape[0].pos_col = pos_col;
}
//Function that sets the struct for the shape I 0 degree rotation
void set_I(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col)
{
	shape[1].tetrimino = tetrimino;
	shape[1].rotation = rotation;
	shape[1].block1_row = block1_row;
	shape[1].block1_col = block1_col;
	shape[1].block2_row = block2_row;
	shape[1].block2_col = block2_col;
	shape[1].block3_row = block3_row;
	shape[1].block3_col = block3_col;
	shape[1].block4_row = block4_row;
	shape[1].block4_col = block4_col;
	shape[1].off_row = off_row;
	shape[1].off_col = off_col;
	shape[1].max_prod = max_prod;
	shape[1].pos_row = pos_row;
	shape[1].pos_col = pos_col;
}

//Function that sets the struct for the shape I rotated 90 degrees
void set_I90(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col)
{
	shape[2].tetrimino = tetrimino;
	shape[2].rotation = rotation;
	shape[2].block1_row = block1_row;
	shape[2].block1_col = block1_col;
	shape[2].block2_row = block2_row;
	shape[2].block2_col = block2_col;
	shape[2].block3_row = block3_row;
	shape[2].block3_col = block3_col;
	shape[2].block4_row = block4_row;
	shape[2].block4_col = block4_col;
	shape[2].off_row = off_row;
	shape[2].off_col = off_col;
	shape[2].max_prod = max_prod;
	shape[2].pos_row = pos_row;
	shape[2].pos_col = pos_col;
}

//Function that sets the struct for the L shape 0 degree rotation
void set_L(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col)
{
	shape[3].tetrimino = tetrimino;
	shape[3].rotation = rotation;
	shape[3].block1_row = block1_row;
	shape[3].block1_col = block1_col;
	shape[3].block2_row = block2_row;
	shape[3].block2_col = block2_col;
	shape[3].block3_row = block3_row;
	shape[3].block3_col = block3_col;
	shape[3].block4_row = block4_row;
	shape[3].block4_col = block4_col;
	shape[3].off_row = off_row;
	shape[3].off_col = off_col;
	shape[3].max_prod = max_prod;
	shape[3].pos_row = pos_row;
	shape[3].pos_col = pos_col;
}
//Function that sets the struct for the L shape 90 degree rotation
void set_L90(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col)
{
	shape[4].tetrimino = tetrimino;
	shape[4].rotation = rotation;
	shape[4].block1_row = block1_row;
	shape[4].block1_col = block1_col;
	shape[4].block2_row = block2_row;
	shape[4].block2_col = block2_col;
	shape[4].block3_row = block3_row;
	shape[4].block3_col = block3_col;
	shape[4].block4_row = block4_row;
	shape[4].block4_col = block4_col;
	shape[4].off_row = off_row;
	shape[4].off_col = off_col;
	shape[4].max_prod = max_prod;
	shape[4].pos_row = pos_row;
	shape[4].pos_col = pos_col;
}
//Function that sets the struct for the L shape 180 degree rotation
void set_L180(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col)
{
	shape[5].tetrimino = tetrimino;
	shape[5].rotation = rotation;
	shape[5].block1_row = block1_row;
	shape[5].block1_col = block1_col;
	shape[5].block2_row = block2_row;
	shape[5].block2_col = block2_col;
	shape[5].block3_row = block3_row;
	shape[5].block3_col = block3_col;
	shape[5].block4_row = block4_row;
	shape[5].block4_col = block4_col;
	shape[5].off_row = off_row;
	shape[5].off_col = off_col;
	shape[5].max_prod = max_prod;
	shape[5].pos_row = pos_row;
	shape[5].pos_col = pos_col;
}
//Function that sets the struct for the L shape 270 degree rotation
void set_L270(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col)
{
	shape[6].tetrimino = tetrimino;
	shape[6].rotation = rotation;
	shape[6].block1_row = block1_row;
	shape[6].block1_col = block1_col;
	shape[6].block2_row = block2_row;
	shape[6].block2_col = block2_col;
	shape[6].block3_row = block3_row;
	shape[6].block3_col = block3_col;
	shape[6].block4_row = block4_row;
	shape[6].block4_col = block4_col;
	shape[6].off_row = off_row;
	shape[6].off_col = off_col;
	shape[6].max_prod = max_prod;
	shape[6].pos_row = pos_row;
	shape[6].pos_col = pos_col;


}
//Function that sets the struct for the J shape 0 degree rotation
void set_J(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col)
{
	shape[7].tetrimino = tetrimino;
	shape[7].rotation = rotation;
	shape[7].block1_row = block1_row;
	shape[7].block1_col = block1_col;
	shape[7].block2_row = block2_row;
	shape[7].block2_col = block2_col;
	shape[7].block3_row = block3_row;
	shape[7].block3_col = block3_col;
	shape[7].block4_row = block4_row;
	shape[7].block4_col = block4_col;
	shape[7].off_row = off_row;
	shape[7].off_col = off_col;
	shape[7].max_prod = max_prod;
	shape[7].pos_row = pos_row;
	shape[7].pos_col = pos_col;


}
//Function that sets the struct for the J shape 90 degree rotation
void set_J90(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col)
{
	shape[8].tetrimino = tetrimino;
	shape[8].rotation = rotation;
	shape[8].block1_row = block1_row;
	shape[8].block1_col = block1_col;
	shape[8].block2_row = block2_row;
	shape[8].block2_col = block2_col;
	shape[8].block3_row = block3_row;
	shape[8].block3_col = block3_col;
	shape[8].block4_row = block4_row;
	shape[8].block4_col = block4_col;
	shape[8].off_row = off_row;
	shape[8].off_col = off_col;
	shape[8].max_prod = max_prod;
	shape[8].pos_row = pos_row;
	shape[8].pos_col = pos_col;


}
//Function that sets the struct for the J shape 180 degree rotation
void set_J180(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col)
{
	shape[9].tetrimino = tetrimino;
	shape[9].rotation = rotation;
	shape[9].block1_row = block1_row;
	shape[9].block1_col = block1_col;
	shape[9].block2_row = block2_row;
	shape[9].block2_col = block2_col;
	shape[9].block3_row = block3_row;
	shape[9].block3_col = block3_col;
	shape[9].block4_row = block4_row;
	shape[9].block4_col = block4_col;
	shape[9].off_row = off_row;
	shape[9].off_col = off_col;
	shape[9].max_prod = max_prod;
	shape[9].pos_row = pos_row;
	shape[9].pos_col = pos_col;


}
//Function that sets the struct for the J shape 270 degree rotation
void set_J270(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col)
{
	shape[10].tetrimino = tetrimino;
	shape[10].rotation = rotation;
	shape[10].block1_row = block1_row;
	shape[10].block1_col = block1_col;
	shape[10].block2_row = block2_row;
	shape[10].block2_col = block2_col;
	shape[10].block3_row = block3_row;
	shape[10].block3_col = block3_col;
	shape[10].block4_row = block4_row;
	shape[10].block4_col = block4_col;
	shape[10].off_row = off_row;
	shape[10].off_col = off_col;
	shape[10].max_prod = max_prod;
	shape[10].pos_row = pos_row;
	shape[10].pos_col = pos_col;


}

//Function that sets the struct for the T shape 0 degree rotation
void set_T(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, 	int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int 		pos_row, int pos_col)
{
	shape[11].tetrimino = tetrimino;
	shape[11].rotation = rotation;
	shape[11].block1_row = block1_row;
	shape[11].block1_col = block1_col;
	shape[11].block2_row = block2_row;
	shape[11].block2_col = block2_col;
	shape[11].block3_row = block3_row;
	shape[11].block3_col = block3_col;
	shape[11].block4_row = block4_row;
	shape[11].block4_col = block4_col;
	shape[11].off_row = off_row;
	shape[11].off_col = off_col;
	shape[11].max_prod = max_prod;
	shape[11].pos_row = pos_row;
	shape[11].pos_col = pos_col;


}
//Function that sets the struct for the T shape 90 degree rotation
void set_T90(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, 	int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int 		pos_row, int pos_col)
{
	shape[12].tetrimino = tetrimino;
	shape[12].rotation = rotation;
	shape[12].block1_row = block1_row;
	shape[12].block1_col = block1_col;
	shape[12].block2_row = block2_row;
	shape[12].block2_col = block2_col;
	shape[12].block3_row = block3_row;
	shape[12].block3_col = block3_col;
	shape[12].block4_row = block4_row;
	shape[12].block4_col = block4_col;
	shape[12].off_row = off_row;
	shape[12].off_col = off_col;
	shape[12].max_prod = max_prod;
	shape[12].pos_row = pos_row;
	shape[12].pos_col = pos_col;




}
//Function that sets the struct for the T shape 180 degree rotation
void set_T180(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col)
{
	shape[13].tetrimino = tetrimino;
	shape[13].rotation = rotation;
	shape[13].block1_row = block1_row;
	shape[13].block1_col = block1_col;
	shape[13].block2_row = block2_row;
	shape[13].block2_col = block2_col;
	shape[13].block3_row = block3_row;
	shape[13].block3_col = block3_col;
	shape[13].block4_row = block4_row;
	shape[13].block4_col = block4_col;
	shape[13].off_row = off_row;
	shape[13].off_col = off_col;
	shape[13].max_prod = max_prod;
	shape[13].pos_row = pos_row;
	shape[13].pos_col = pos_col;





}
//Function that sets the struct for the T shape 270 degree rotation
void set_T270(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int pos_row, int pos_col)
{
	shape[14].tetrimino = tetrimino;
	shape[14].rotation = rotation;
	shape[14].block1_row = block1_row;
	shape[14].block1_col = block1_col;
	shape[14].block2_row = block2_row;
	shape[14].block2_col = block2_col;
	shape[14].block3_row = block3_row;
	shape[14].block3_col = block3_col;
	shape[14].block4_row = block4_row;
	shape[14].block4_col = block4_col;
	shape[14].off_row = off_row;
	shape[14].off_col = off_col;
	shape[14].max_prod = max_prod;
	shape[14].pos_row = pos_row;
	shape[14].pos_col = pos_col;




}
//Function that sets the struct for the Z shape 0 degree rotation
void set_Z(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, 	int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int 		pos_row, int pos_col)
{
	shape[15].tetrimino = tetrimino;
	shape[15].rotation = rotation;
	shape[15].block1_row = block1_row;
	shape[15].block1_col = block1_col;
	shape[15].block2_row = block2_row;
	shape[15].block2_col = block2_col;
	shape[15].block3_row = block3_row;
	shape[15].block3_col = block3_col;
	shape[15].block4_row = block4_row;
	shape[15].block4_col = block4_col;
	shape[15].off_row = off_row;
	shape[15].off_col = off_col;
	shape[15].max_prod = max_prod;
	shape[15].pos_row = pos_row;
	shape[15].pos_col = pos_col;


}
//Function that sets the struct for the Z shape 90 degree rotation
void set_Z90(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, 	int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int 		pos_row, int pos_col)
{
	shape[16].tetrimino = tetrimino;
	shape[16].rotation = rotation;
	shape[16].block1_row = block1_row;
	shape[16].block1_col = block1_col;
	shape[16].block2_row = block2_row;
	shape[16].block2_col = block2_col;
	shape[16].block3_row = block3_row;
	shape[16].block3_col = block3_col;
	shape[16].block4_row = block4_row;
	shape[16].block4_col = block4_col;
	shape[16].off_row = off_row;
	shape[16].off_col = off_col;
	shape[16].max_prod = max_prod;
	shape[16].pos_row = pos_row;
	shape[16].pos_col = pos_col;


}

//Function that sets the struct for the S shape 0 degree rotation
void set_S(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, 	int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int 		pos_row, int pos_col)
{
	shape[17].tetrimino = tetrimino;
	shape[17].rotation = rotation;
	shape[17].block1_row = block1_row;
	shape[17].block1_col = block1_col;
	shape[17].block2_row = block2_row;
	shape[17].block2_col = block2_col;
	shape[17].block3_row = block3_row;
	shape[17].block3_col = block3_col;
	shape[17].block4_row = block4_row;
	shape[17].block4_col = block4_col;
	shape[17].off_row = off_row;
	shape[17].off_col = off_col;
	shape[17].max_prod = max_prod;
	shape[17].pos_row = pos_row;
	shape[17].pos_col = pos_col;


}

//Function that sets the struct for the S shape 90 degree rotation
void set_S90(tets shape[], string tetrimino, string rotation, int block1_col, int block1_row, int block2_col, int block2_row, 	int block3_col, int block3_row, int block4_col, int block4_row, int off_row, int off_col, unsigned long max_prod, int 		pos_row, int pos_col)
{
	shape[18].tetrimino = tetrimino;
	shape[18].rotation = rotation;
	shape[18].block1_row = block1_row;
	shape[18].block1_col = block1_col;
	shape[18].block2_row = block2_row;
	shape[18].block2_col = block2_col;
	shape[18].block3_row = block3_row;
	shape[18].block3_col = block3_col;
	shape[18].block4_row = block4_row;
	shape[18].block4_col = block4_col;
	shape[18].off_row = off_row;
	shape[18].off_col = off_col;
	shape[18].max_prod = max_prod;
	shape[18].pos_row = pos_row;
	shape[18].pos_col = pos_col;


}


//Calculates the greatest product in the grid using the tetris shapes.
//I cound 14 "Lines of code" The spaced out for readability.
void find_greatest_product(int **grid, int rows, int cols, tets shape[])
{
		int longer, max_row, max_col,temp_max = 0, bigger_max = 0;
		int longa, longb, longc, longd;
			//the first for loop X goes through the 18 shapes and rotations.
		for (int x = 0; x <= 18; x++){
				//The next for loop sends each shape through the gid,
				//has offset so the shape doesn't go beyond the grid.
			for(int i = 0; i <= (rows + shape[x].off_row); i++)	{
				for(int j = 0; j <= (cols + shape[x].off_col); j++)	{
					//temp_max stores the biggest number for every product of every shape
						temp_max = (grid[i + shape[x].block1_row][j+ shape[x].block1_col])*
						(grid[i+shape[x].block2_row][j+shape[x].block2_col]) *
						(grid[i+ shape[x].block3_row][j + shape[x].block3_col]) *
						(grid[i+shape[x].block4_row][j+shape[x].block4_col]);
			//If temp_max > bigger max will give the information to the variables when the program finds
					// a bigger product on the grid.
					if(temp_max>bigger_max)	{
						bigger_max = temp_max;
						//longer will be used to print out the struct of the largest product
						longer = x;
						max_row = (i + shape[x].block1_row);
						max_col = (j + shape[x].block1_col);

						longa= (grid[i + shape[x].block1_row][j+ shape[x].block1_col]);
						longb = (grid[i+shape[x].block2_row][j+shape[x].block2_col]);
						longc =(grid[i+ shape[x].block3_row][j + shape[x].block3_col]);
						longd = (grid[i+shape[x].block4_row][j+shape[x].block4_col]);


					}
				}
			}
		}

shape[longer].max_prod = bigger_max;
print_product(longer, max_row, max_col, shape);
cout << "The numbers for the largest product are " << longa << " " << longb << " " << longc << " " << longd << endl << endl;




}
//Prints the outcome of the largest product, the shape that found it, the row and col that it is found.
void print_product(int longer, int max_row, int max_col, tets shape[])
{
	cout << endl; //Blank line for seperation
	cout << "The biggest product in the Grid is:" << shape[longer].max_prod << "." << endl;
	cout << "The shape that found the biggest prodct is: " << shape[longer].tetrimino <<  ", "
	<< shape[longer].rotation << endl;
	cout << "And starts at position ROW:" << max_row << ", COL:" << max_col << endl;
	cout << endl; //Blank line for seperation
}




//delete the array to free memory
void delete_array(int **grid, int rows, int cols)
{
//loop to delete the array of arrays
		for (int i = 0; i < rows; ++i)	{
			//cout << "deleting row: " << i << endl;
			//cout << "deleting row: " << i << endl;
			delete [] grid[i];
		}
		//delete the final array
		delete [] grid;
}

//Gabriel Dominic A. Dicar
//202214150

#include <stdio.h>
#include <math.h>

struct line{
	struct point{
		float x;
		float y;
	}point1, point2;
	float *ptr;	//Midpoint
	float slope;
	float distance;
};

float solveSlope(struct line line1);
float *solveMidpont(struct line line1);
float solveDistance(struct line line1);
void getSlopeInterceptForm(struct line line1);

int main(){
	struct line line1; // Declare the structure

	printf("Enter x and y for point1:");
	scanf("%f %f", &line1.point1.x, &line1.point1.y);

	printf("Enter x and y for point2:");
	scanf("%f %f", &line1.point2.x, &line1.point2.y);

	line1.slope = solveSlope(line1); //To solve for the Slope and to store the value of the slope in the data structure
	printf("\nslope is %.6f\n", line1.slope);

	printf("Midpoint: ");
	solveMidpont(line1);	//To solve for the Midpoint

	printf("\nDistance between two points: ");	//To Solve for Distance
	solveDistance(line1);

	getSlopeInterceptForm(line1); //For the slope intercept Form

	return 0;
}


float solveSlope(struct line line1){
	float m;
	m = (line1.point2.y - line1.point1.y)/(line1.point2.x - line1.point1.x);
	printf("\nx is %.2f and y is %.2f for point1", line1.point1.x, line1.point1.y);
	printf("\nx is %.2f and y is %.2f for point2", line1.point2.x, line1.point2.y);

	return m;
}

float *solveMidpont(struct line line1){
	float mp_x;
	float mp_y;

	mp_x = (line1.point1.x + line1.point2.x)/2;	//solving the values of the ordinate and the abscissa first
	mp_y = (line1.point1.y + line1.point2.y)/2;

	float array[2] = {mp_x, mp_y};	//storing the values into the array

	line1.ptr = &array[0];	//pointing at the address of the first value of the array

	for (int i = 0; i < 2; ++i){
		printf("%f ", *(line1.ptr + i)); //For printing the elements
	}
}

float solveDistance(struct line line1){
	float left;
	float right;
	float d;

	left = (line1.point1.x - line1.point2.x);	//For the left part of the equation
	right = (line1.point1.y - line1.point2.y);  //Right part of the equation
	d = pow(left,2) + pow(right,2);	//squaring the values before adding

	printf("%f", sqrt(d));
}

void getSlopeInterceptForm(struct line line1){
	float b;
	//y = mx +b ; y - m*x = b

	b = line1.point2.y - (line1.slope*line1.point2.x);	//Solving for b

	printf("\ny = %fx + (%f)", line1.slope, b);	
}
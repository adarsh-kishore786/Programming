/* bmi.c

   This program accepts the weight and height
   of the user, and calculates the BMI.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>

int main()
{
    float weight, height;

    printf("Enter the weight of the user (in kg):\n");
    scanf(" %f kg", &weight);

    printf("Enter the height of the user (in m):\n");
    scanf(" %f m", &height);

    float bmi = weight / pow(height, 2);

    printf("\n\nBMI: %f\n", bmi);

    if (bmi < 15)
        printf("Starvation");
    else if (bmi <= 17.5)
        printf("Anorexic");
    else if (bmi <= 18.5)
        printf("Underweight");
    else if (bmi <= 24.9)
        printf("Ideal");
    else if (bmi <= 25.9)
        printf("Overweight");
    else if (bmi <= 39.9)
        printf("Obese");
    else
        printf("Morbidly obese");

    return 0;
}

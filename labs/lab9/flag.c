/*
Remember to include the mandatory header!
*/
#include <stdio.h>
/*
Here are some helpful functions you can use!
Don’t worry if you haven’t seen these before! :-)
You’ll learn more about how to make these yourself later, but for now
Just know that you can call these as you would any other function
And you write how they work down below.
*/
void make_pixel (int r, int g, int b);
void make_ppm_header (int width, int height);
void make_ppm_image (int country_code, int width);
void writePoland(int width);
void writeNetherlands(int width);
void writeItaly(int width);

FILE *fp;

int main(int argc,char* argv[])
{
   fp = fopen(argv[1], "w+");

int width, country_code;
// Read image dimensions and pixel color
/*
TODO:
1. prompt user to enter country_code of chosen flag
-  this should look really similar to the line down below
*/
fprintf(stdout, "Pick a country: 1, 2, or 3.\n1 for Poland, 2 for Netherlands, and 3 for Italy. \n");
fscanf(stdin, "%d", &country_code);
fprintf(stderr, "What width (in pixels) do you want it to be? ");
fscanf(stdin, "%d", &width);
fprintf(stderr, "\nMaking country %d’s flag with width %d pixels... \n",
country_code, width);
// Write the image data
make_ppm_image(country_code, width);
fprintf(stderr, "Done!\n\n");
fclose(fp);
return(0);
}


// Creates a pixel with the colors you tell it to use when you call it
// To call it, just do something like make_pixel(244, 244, 244);
void make_pixel (int r, int g, int b)
{
fprintf(fp, "%c%c%c", r, g, b);
}


// Creates a header with the desired width and height when you call it
void make_ppm_header (int width, int height)
{
fprintf(fp, "P6\n");
fprintf(fp, "%d %d %d\n", width, height, 255);
}


// Creates a complete ppm image when you call it
void make_ppm_image (int country_code, int width)
{

/*
Here’s an example of calling one of the functions we made earlier
TODO:
1. Figure out the correct height per flag and pass it into the function
*/
switch (country_code){
    case 1:
        writePoland(width);
    case 2:
        writeNetherlands(width);
    case 3:
        writeItaly(width);
}
/*
Write your logic to print out the pixel data here for each flag
TODO:
1. make an if-else or switch depending on the country
2. use nested for loops to iterate through
3. determine which flag you are creating
4. find where you are in the flag
5. use make_pixel() to write the pixel
-  you can use this like you would any other function.
-  just pass in the values you want for r, g, and b
*/
}
void writePoland(int width){
    int height=(width/8)*5;
    make_ppm_header(width, height);
    for (int i=0; i<height; i++){
        for (int j=0; j<width; j++){
            if (i<(height/2)){
                make_pixel(255,255,255);
            }
            else{
            make_pixel(255,0,0);
            }
        }
    }
}

void writeNetherlands(int width){
    int height=(width/3)*2;
    make_ppm_header(width, height);
    for (int i=0; i<height; i++){
        for (int j=0; j<width; j++){
            if (i<(height/3)){
                make_pixel(174,28,40);
            }
            else if (i<((height*2)/3)){
            make_pixel(255,255,255);
            }
            else{
                make_pixel(33,70,139);
            }
        }
    }
}

void writeItaly(int width){
    int height=(width/3)*2;
    make_ppm_header(width, height);
    for (int i=0; i<height; i++){
        for (int j=0; j<width; j++){
            if (j<(width/3)){
                make_pixel(0,140,69);
            }
            else if (j<((width*2)/3)){
            make_pixel(244,245,240);
            }
            else{
                make_pixel(205,33,42);
            }
        }
    }
}

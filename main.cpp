#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

//values from adobe photo shop
int WIDTH = 750;
int HEIGHT = 500;
int imageSize = WIDTH*HEIGHT;
//[row][column]
char arr[500][750];



void addIntensity(int intensity){
  //unsigned values can only be non negative
  unsigned char newPhotoArr[500][750];
  // create a new output file
  FILE *outputFile; 
  // row 
  for (int i = 0; i < HEIGHT; i++)
  {
    // column
    for (int j = 0; j < WIDTH; j++)
    {
      // convert the current byte into an integer + add the intensity to it.  
      newPhotoArr[i][j] = int(arr[i][j] + intensity);
    }

  }
  // what our output file is going to named 
  string outputFileName = "photo" + to_string(intensity) + ".raw";
  // convert it to char *
  outputFile = fopen(outputFileName.c_str(), "wb");
  fwrite(newPhotoArr, 1, imageSize, outputFile);
  fclose(outputFile);
}

int main(){
  FILE *photoFile;
  photoFile = fopen("unesco750-1.raw", "rb");
  if (photoFile == NULL)
  {
    std::cout << "Unable to open file";
    return 1;
    
  }
  else{
    std::cout << "File open" << std::endl ;
    
  }
   //fread(where you want to store it, size of byte, how large the file is H*W, where the file is at )
   //  stores the data of the photo file to our flobal array 
  fread(arr, 1, imageSize, photoFile);
  fclose(photoFile);

  addIntensity(20);
  addIntensity(100);
  return 0;
}

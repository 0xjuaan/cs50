#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "wav.h"

//Function prototypes
int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    //Checking for proper CLI
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    //Generating a pointer to a new file in memory, the input file
    FILE *input = fopen(argv[1], "r");

    //Checking validity of file (do we have it?)
    if (input == NULL)
    {
        printf("Can't open file\n");
        return 1;
    }

    //Initialising the header
    WAVHEADER header;

    //Reading the header from the input file, and saving it in header
    fread(&header, sizeof(WAVHEADER), 1, input);


    //If the format is not .wav, give error message
    if (check_format(header) == 0)
    {
        printf("Input is not a WAV file.\n");
        return 1;
    }
    //Generate a pointer to the output file
    FILE *output = fopen(argv[2], "w");

    if (output == NULL) //CJecks if the memory address of the output file is NULL (0 address)
    {
        printf("Can't open file\n");
        return 1;
    }
    //Write the header into the output file
    fwrite(&header, sizeof(WAVHEADER), 1, output);

    //Get the size of each block, and the total size of audio chunk
    int blockSize = get_block_size(header);
    int dataSize = header.subchunk2Size;

    BYTE data[dataSize];

    fseek(input, sizeof(WAVHEADER), SEEK_SET); //Setting cursor after header
    fread(&data, blockSize, dataSize/blockSize, input); //Reading data to data[]

    






}






//Function definitions
int check_format(WAVHEADER header)
{
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int get_block_size(WAVHEADER header)
{
    return header.numChannels * header.bitsPerSample / 8;
}
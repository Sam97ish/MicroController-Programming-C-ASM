#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
/**
Author : ALKHAFAJI Hussam Aldeen.

https://repl.it/@sam66ish/ThunderousSparseFrontpage#main.c
**/
int nbcommands = 10; // # of input expected.

char* stringBinarys[10]; //to store input binaries.
int intBinarys[10]; //to store input in int form.

/**
*@role: converts binaries that are of type string to int form.
**/
void stringsToBin(int a[], char* b[], int size){

  for(int i = 0; i < size; i++){
    char* strbin = b[i];
    int j = 0;
    for(int k = 15; k >= 0; k--){
      char bit = strbin[k];

        if(bit == '1'){
          a[i] += pow(2,j) ;
           
        }
      
      j++;
    }
  }
}

/**
*@role: translates the LDI command from binary to assembly.
**/
void LDI(int command){
  int k = command & 0b0000111100000000;
  k = k>>4;
  k += command & 0b0000000000001111;
  int d = command & 0b0000000011110000;
  d = d>>4;
  d += 16;

  printf("%s%d, %d \n", " LDI R", d, k);

}

/**
*@role: translates the ANDI command from binary to assembly.
**/
void ANDI(int command){
  int k = command & 0b0000111100000000;
  k = k>>4;
  k += command & 0b0000000000001111;
  int d = command & 0b0000000011110000;
  d = d>>4;
  d += 16;

  printf("%s%d, %d \n", " ANDI R", d, k);

}
/**
*@role: translates the SUBI command from binary to assembly.
**/
void SUBI(int command){
  int k = command & 0b0000111100000000;
  k = k>>4;
  k += command & 0b0000000000001111;
  int d = command & 0b0000000011110000;
  d = d>>4;
  d += 16;

  printf("%s%d, %d \n", " SUBI R", d, k);

}
/**
*@role: translates the INC command from binary to assembly.
**/
void INC(int command){
  int d = command & 0b0000000111110000;
  d = d>>4;
  printf("%s%d \n", " INC R", d);

}
/**
*@role: translates the ADD command from binary to assembly.
**/
void ADD(int command){
  int d = command & 0b0000000111110000;
  d = d>>4;
  int r = command  & 0b0000000000001111;
  int tmp = command &0b0000001000000000;
  tmp = tmp>>5;
  r += tmp;
  

  printf("%s%d, %s%d \n", " ADD R", d, " R " ,r);

}
/**
*@role: a function that detects the opcode of some binary instructions and calls the cooresponding function to tranlate it.
**/
void chooseOpcode(int opcode, int command){

  switch(opcode) {

   case 0b1110000000000000: //LDI rd,k
      
      LDI(command); //1110 KKKK dddd KKKK (d offset of 16).
      break;
	
    case 0b0000000000000000: 
      ADD(command); //0000 11rd dddd rrrr
      break; 

    case 0b0101000000000000:
      SUBI(command); //0101 KKKK dddd KKKK (d is offset of 16)
      break;
    
    case 0b0111000000000000:
      ANDI(command); //0111 KKKK dddd KKKK (d offset of 16)
     break;

    case 0b1001000000000000:
      INC(command); //1001 010d dddd 0011
      break;

   /* you can have any number of case statements */
   default :
   printf("%s","unknown command");
  }
}

int main(void) {

  //inputing the commands and storing them into array b.
  for(int i =0; i < nbcommands; i++){
    stringBinarys[i] = malloc(sizeof(char) * 16);
    scanf("%s", stringBinarys[i]);
  }

  //converting the strings to int.
  stringsToBin(intBinarys,stringBinarys,nbcommands);

  //converting the binaries into assembly.
  for(int i =0; i < nbcommands; i++){

    int opcode = intBinarys[i] & 0b1111000000000000;

    chooseOpcode(opcode, intBinarys[i]);

  }
  
  return 0;
}

//https://repl.it/@sam66ish/ThunderousSparseFrontpage#main.c

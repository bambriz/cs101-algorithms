//Bryan Ambriz cs 101

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"


#define MAX_LEN 250

int main (int argc, const char * argv[]) {
    FILE *in, *out, *in2;
	char line[MAX_LEN];
    
	//char* token;
    int counter = 0;
    if( argc != 3 ){
		printf("Usage: %s infile outfile\n Bad Error", argv[0]);
		exit(1);
	}
    
	/* open files for reading and writing I hope you enjoy i breh */
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");
    //in = fopen(argv[1], "r");
	if( in==NULL ){
		printf("Unable to open file %s for reading So too bad\n", argv[1]);
		exit(1);
	}
	if( out==NULL ){
		printf("Unable to open file %s for writing woops oh well.\n", argv[2]);
		exit(1);
	}
    
    
    
    while( fgets(line, MAX_LEN, in) != NULL){
        counter++;
    }
     fclose(in);
  in2 = fopen(argv[1], "r");
    //string array and iterator to add strings
    char** strA = malloc(sizeof(char**) * counter);
    int interCount = 0;
    while( fgets(line,MAX_LEN, in2) != NULL){
      char *d = malloc(strlen(line) + 1);
 
       strcpy(d,line);
      strA[interCount]= d;
      interCount++;      
    } 
    // create my list
    List L = newList();
    //Modified version of my java algorithm.
    // appends first item
  if (counter > 0) append(L, 0);
  for (int j = 1; j < counter; j++){
    char *temp = strA[j];
    int indexer = j - 1;
    //move cursor to the indexer
    moveTo(L, indexer);
    //insertion sort on list
    while (indexer > -1 && strcmp(temp, strA[getElement(L)]) < 1){
      indexer--;
      movePrev(L);
    }
    
    //if cursor is not poitning to anythig then prepend
    if(getIndex(L) == -1){
      prepend(L, j);
    } else {
      insertAfter(L, j);
    }
  }
  
  //this will print out to the output file the appropitae sort
   for(moveTo(L, 0); getIndex(L) >= 0; moveNext(L)){
    fprintf(out, "%s", strA[getElement(L)]);
  } 
  //close the files before anything abd happens
  fclose(in2);
  fclose(out);
  
  // manually free all dat inclusing all arrays and list
  for (int i = 0; i < counter; i++){
    free(strA[i]);
  }
  free(strA);
  freeList(&L);

}
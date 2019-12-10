#include<stdio.h>
#include<math.h>
#include<time.h>
#define frameSize 4
#define noPages 12

int pages[12];
int frames[4] ={-1,-1,-1,-1}; // means initially frames are empty

int main(){

randPagesInit();
FIFO();
getFramesEmpty();
LRU();
}

// To get the frames empty or initialize all the frames to -1
void getFramesEmpty(){
for(int i = 0 ; i < frameSize ; i++){
	frames[i]=-1;
}
}
// For random initaizing of page numbers
void randPagesInit(){
// Srand is used to get different random numbers each time rand() function is called
srand(time(0)); 

for(int i=0; i<noPages;i++){

				pages[i]=rand()%10; // for randomly initializing the page numbers from 0 to 9
			    }

}

void LRU(){
int recentValues[frameSize]={-1,-1,-1,-1};
int hit=0 , pFault=0;
for(int i = 0 ; i < noPages;i++){
	for(int j = 0 ; j < frameSize; j++){
		if(frames[j]==pages[i]){
			hit++;
			updateRecentValues(recentValues, frameSize, j);
			break;
		}
	
	}
	if(hit==0){
		frames[getMinIndex(recentValues, frameSize)]=pages[i];
		updateRecentValues(recentValues, frameSize, getMinIndex(recentValues, frameSize));
		pFault++;
	}
hit=0;	
}
printf("Total page faults in LRU (Least Recent Used) is: %d \n\n",pFault);
	printf("\n Pages are: ");
	for(int i = 0 ; i <noPages;i++){
				printf("%d ,",pages[i]);
	}
	printf("\n Last Frame Values in LRU Algorithm: ");
	for(int i = 0 ; i <frameSize;i++){
				printf("%d ,",frames[i]);
	}
	printf("\n \n ");
}

// Function to get the index number of the least recent value used
int getMinIndex(int *array, int size){
int temp=array[0];
int minIndex=0;
for (int i=1 ; i <size;i++){
	if(temp >array[i]){
		temp=array[i];
		minIndex=i;
	}
}
return minIndex;
}

// Function to update the recent values of page numbers. 

// IMPORTANT NOTE: 0 means most recent used
void updateRecentValues(int *array, int size, int index){
*(array+index)=0; // Recently used index updated to zero
for(int i = 0 ; i<size; i++){
	if(i==index)
		continue;
	array[i]--;
}


}


// First In First Out Algorithm logic
void FIFO(){
int pFault=0; // Page faults counter
int hit=0, first_in=0; // first_in is the index number in array of the first page number that had came
for(int i=0; i<12;i++){
	for(int j=0;j<4;j++){
				if(frames[j]==pages[i]){
					hit = 1;
					break;
				}

				
	}
	if(hit==0){
				
				frames[first_in]=pages[i];
				pFault++;
				first_in++;
				if(first_in==frameSize)
							first_in%=4;				
	}
	hit=0;
}
	printf("Total page faults in FIFO is: %d \n\n",pFault);
	printf("\n Pages are: ");
	for(int i = 0 ; i <noPages;i++){
				printf("%d ,",pages[i]);
	}
	printf("\n Last Frame Values in FIFO Algorithm: ");
	for(int i = 0 ; i <frameSize;i++){
				printf("%d ,",frames[i]);
	}
	printf("\n \n ");




}

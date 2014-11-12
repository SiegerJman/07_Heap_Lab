//Justin Reed
//11/11/14
//Done with starter code from Dr. Brinkman, and help from cplusplus.com
#include "Queue.h"
#include <utility>

//This should be the initial arrSize
#define START_SIZE 10

/*
 * This is a priority queue, which means that as items are removed in order
 * of decreasing priority.
 *
 * 
 */
template<class Pri, class T>
class Heap : public Queue<std::pair<Pri, T> > {
public:
  Heap();
  ~Heap();

  //Add a new item
  virtual void add(std::pair<Pri,T> toAdd);

  //Remove the item with lowest priority, and return it
  //If the queue is empty, throw a string exception
  virtual std::pair<Pri,T> remove();

  //Return the number of items currently in the queue
  virtual unsigned long getNumItems();

private:
  int arrSize;
  int numItems;
  std::pair<Pri, T>* backingArray;
  
  //Grow the backingArray by making a new array of twice the size,
  // and copying over the data
  void grow();

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it up the "tree" of the heap until you find the right
  // place
  void bubbleUp(unsigned long index);

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it down the "tree" of the heap until you find the right
  // place
  void trickleDown(unsigned long index);  
};



#include <string>

template<class Pri, class T>
Heap<Pri, T>::Heap(){
	//makes a new heap, sets numItems to 0 and initializes the array.
	backingArray = new std::pair<Pri, T>[START_SIZE];
	numItems = 0;
	arrSize = START_SIZE;
}

template<class Pri, class T>
Heap<Pri, T>::~Heap(){
	//delete it all
	while (backingArray != NULL){
		numItems--;
		delete &backingArray[numItems];
	}
}

template<class Pri, class T>
void Heap<Pri, T>::grow(){
	//doubles the size of the array and transfers old values over through the use of a tmp array
	std::pair<Pri, T>* tmp = backingArray;
	backingArray= new std::pair<Pri, T>[arrSize*2];
	arrSize = arrSize * 2;
	for (int i = 0; i < numItems; i++){
		add(tmp[i]);
	}
}

template<class Pri, class T>
void Heap<Pri, T>::add(std::pair<Pri, T> toAdd){
	//change numItems, checks if we need to grow, add new item to the bottom, bubble up.
	numItems++;
	if (numItems>arrSize)
		grow();
	std::pair<Pri, T> p = toAdd;
	backingArray[numItems-1] = p;
	//std::cout << backingArray[numItems - 1].first << std::endl;
	bubbleUp(numItems - 1);
	

}

template<class Pri, class T>
void Heap<Pri, T>::bubbleUp(unsigned long index){
	//getindex of ancestor one level up
	int oneUp = (index - 1) / 2;
	//see if the values should be switched
	if (index > 0 && (backingArray[oneUp]).first > (backingArray[index]).first){
		std::pair<Pri, T> tmp = backingArray[oneUp];
		backingArray[oneUp] = backingArray[index];
		backingArray[index] = tmp;
		bubbleUp(oneUp);
	}
}

template<class Pri, class T>
void Heap<Pri, T>::trickleDown(unsigned long index){
	//set left baby, right baby, then determine which way to trickle
	int leftBaby = 2 * index + 1;
	int rightBaby = 2 * index + 2;
	//determines if we should trickle in the first place
	if (backingArray[index] > backingArray[rightBaby] || backingArray[index] > backingArray[leftBaby]){
		if (backingArray[rightBaby] > backingArray[leftBaby] && backingArray[leftBaby].second != ""){
			std::pair<Pri, T> tmp = backingArray[index];
			backingArray[index] = backingArray[leftBaby];
			backingArray[leftBaby] = tmp;
			trickleDown(leftBaby);
		}else if (backingArray[rightBaby].second != ""){
			std::pair<Pri, T> tmp = backingArray[index];
			backingArray[index] = backingArray[rightBaby];
			backingArray[rightBaby] = tmp;
			trickleDown(rightBaby);
		}
		else if (backingArray[leftBaby].second != ""){
			std::pair<Pri, T> tmp = backingArray[index];
			backingArray[index] = backingArray[leftBaby];
			backingArray[leftBaby] = tmp;
			trickleDown(leftBaby);
		}
	}
}

template<class Pri, class T>
std::pair<Pri, T> Heap<Pri, T>::remove(){
	//set numItems to the right value, make tmp, switch values then trickleDown
	numItems--;
	std::pair<Pri, T> tmp = backingArray[0];
	backingArray[0] = backingArray[numItems];
	backingArray[numItems] = *(new std::pair< Pri, T >) ;
	trickleDown(0);
	return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri, T>::getNumItems(){
	return numItems;
}

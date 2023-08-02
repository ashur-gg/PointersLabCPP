// Title : PointersLab
// Desc  : User Generated code for sorting scores in an array
// Author: Ashur Baroutta
// Date  : 06/20/23

#include <iostream>
using namespace std;

void sort(float* score, int num_scores);
int indexOf(float* score, int num_scores, float value);

int main() {

  // variables
  int num_scores;
  float* score = nullptr;
  float total = 0;
  float average;
  float value;
  int index;

  // ask for the amount of scores
  cout << "Input the number of scores " << endl;
  cin >> num_scores;

  // make sure atleast 1 score
  while(num_scores<=0){
    cout << "There has to be atleast one score, please reenter the amount of scores." << endl;
    cin >> num_scores;
  }

  score = new float[num_scores]; // allocate the array

  // store them in the array
  for(int i = 0; i< num_scores;i++){
    cout << "Enter score number " << i+1 << " : ";
    cin >> *(score + i);
    total+= *(score+i);
  }

  // calculate the average
  average = total/num_scores;
  cout << "The score average is : " << average << endl;
  cout << "\n";
  // sort the array in ascending order
  // we call our sort function
  sort(score,num_scores);

  cout << "These are the scores in ascending order:\n";
  // print the scores
  for(int i = 0; i<num_scores;i++){
    cout << *(score + i) << endl;
  }
  cout << "\n";

  // searching for a score/id number
  cout << "Enter the score you would like to search for : ";
  cin >> value;

  index = indexOf(score,num_scores,value);

  //return its index if its in the array or explain it is not in the array
  if(index!=27){
    cout << value << " is in the array at index " << index << "."<< endl;
  }
  else {
    cout << value << " is not in the array.";
  }

  delete [] score;
  
  return 0;
} 


// sort method sorts the array in ascending order using insertion sort
void sort(float* score, int num_scores){

  for(int i =1; i< num_scores;i++){
    float temp = *(score + i); // temp holder for swap purposes
    int compare = i - 1; // make a compare tracker for the place behind i

    // swaps appropriately for each iteration
    while(compare >= 0 && *(score+compare)>temp){
      score[compare + 1]=score[compare];
      compare--;
    }
    // sets a new holder for swap
    score[compare+1]=temp;
  }
}

// indexOf method returns the index of a score/id
int indexOf(float* score, int num_scores, float valeu){

  // iterate through and check if the score/id is in the array
  for(int i = 0; i< num_scores;i++){
    if(score[i]== valeu){return i;}
  }

  return 27;
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <limits>
#include <cmath>

#define NAME_LENGTH 255
#define MAX_DATA_LENGTH 8192

using namespace std;

bool read_numbers(char * str, vector<double> & nums) {
  char *p = strtok(str, " ,{}()[]\n\t\r\v\f");
  if(p == NULL) {
    return false;
  }
  while(p != NULL) {
    nums.push_back(atof(p));
    p = strtok(NULL, " ,{}()[]\n\t\r\v\f");
  }
  return true;
}



bool get_numbers(string filename, vector<double> & nums) {
  ifstream file(filename.c_str());
  if(file.is_open()) {
    char temp_str[MAX_DATA_LENGTH];
    while(!file.getline(temp_str, MAX_DATA_LENGTH).eof()) {
      
      read_numbers(temp_str, nums);
    }
  } else {
    return false;
  }
  return true;
}

template <typename T, typename A>
T get_min(vector<T,A> &vec) {
  T min = numeric_limits<T>::max();
  typename vector<T,A>::iterator my_it;
  for(my_it = vec.begin(); my_it != vec.end(); my_it++) {
    if(*my_it < min) {
      min = *my_it;
    }
  }
  return min;
}

template <typename T, typename A>
T get_max(vector<T,A> &vec) {
  T max = numeric_limits<T>::min();
  typename vector<T,A>::iterator my_it;
  for(my_it = vec.begin(); my_it != vec.end(); my_it++) {
    if(*my_it > max) {
      max = *my_it;
    }
  }
  return max;
}

template<typename T, typename A>
void print_vector(vector<T,A> &vec) {
  typename vector<T,A>::iterator my_it;
  cout << "{ ";
  for(my_it = vec.begin(); my_it != vec.end(); my_it++) {
    cout << *my_it << ", ";
  }
  cout << "}" << endl;
}

template<typename T, typename A>
double get_average(vector<T,A> &vec) {
  T sum = 0;
  typename vector<T,A>::iterator my_it;
  for(my_it = vec.begin(); my_it != vec.end(); my_it++) {
    sum += *my_it;
  }
  return ((double)sum / (double)vec.size());
}

template<typename T, typename A>
double variance(vector<T,A> &vec, bool sample = true) {
  double sum = 0;
  double avg = get_average(vec);
  typename vector<T,A>::iterator my_it;
  for(my_it = vec.begin(); my_it != vec.end(); my_it++) {
    sum += pow((double)*my_it - avg, 2);
  }
  return sample ? sum /(vec.size() -1) :sum/vec.size();
}

template<typename T, typename A>
double std_dev(vector<T,A> &vec, bool sample = true) {
  return sqrt(variance(vec, sample));
}

int main() {
  cout << "\n\t\tWelcome to the Number Statistics Program!!!\n" << endl;
  cout << "Please enter the name of your data file: "; 
  vector<double> data;
  char name[NAME_LENGTH];
  cin.getline(name, NAME_LENGTH);
  cout << endl;
  short int i = 0;
  while(!get_numbers(name, data)) {
    if(i == 3) {
      cout << "Could not enter data correctly. Please try again later."
	   << endl;
      return 0;
    }
    cout << "I'm sorry, I could not open '" << name
	 << "'. Please enter another name: ";
    cin.getline(name, NAME_LENGTH);
    cout << endl;
    i++;
  }
  
  cout << "File '" << name << "' opened successfully!"
       << endl << endl;
  print_vector(data);
  
  cout << "\t  Count:\t" << data.size() << endl
       << "\tMinimum:\t" << get_min(data) << endl
       << "\tAverage:\t" << get_average(data) << endl
       << "\tMaximum:\t" << get_max(data) << endl
       << "\t StdDev:\t" << std_dev(data) << endl << endl;

  cout << "Thank you for using the NSP!!" << endl << endl;
  //cout << s.length() << endl;
  cout << "Endeavor to have a undulating day!" << endl << endl;
  
  return 0;
}

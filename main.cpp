/********
 * 
 * Author: re-0
 * Use: Find the arithmetic mean, min value, max value, sum squared, variance, standard deviation, interval range
 * 
 ********
 ********
Program structure
1. Create array containing data
2. Create variable which stores the array's sum
3. Create variables for minimum and maximum value of array
4. Get array element count
    4i. Create some for-loops in the main() to find sum, max, and min value
5. Create a template function to make printing of data easier
6. Compute the actual numbers wanted
7. Print outcome of #6
*********
*********/

// header files
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>

double array[] = {10, 15, 8, 12, 2, 66, 84};
double sum = 0.0; // init sum
double max = array[0]; // init max value of array
double min = array[0]; // init min value

double array_count(){
  return sizeof(array) / sizeof(array[0]); // returns no. of elements
}

// Prepare data output
template<typename A, typename B, typename C, typename D, typename E, typename F, typename G> void list(A a, B b, C c, D d, E e, F f, G g){
std::cout << a << "\t\t" << b << "\t\t" << c << "\t\t" << d << "\t\t" << e << "\t\t" << f << "\t\t" << g << std::endl;
}

int main(){
 
for(int i = 0; i < array_count(); i++){
    sum += array[i];
    
    if(array[i] > max)
        max = array[i];
        
    if(array[i] < min)
        min = array[i];   
}
  
double x = sum / array_count(); // Get mean value
int index = array_count();

double diff[index];
double squared[index];
double squared_sum = 0.0;

for(int w = 0; w < array_count(); w++){
    diff[w] = array[w] - x;
    squared[w] = diff[w] * diff[w];
    squared_sum += squared[w];
}

double variance = squared_sum / (array_count() - 1); //Sample Variance

/********
*********
**
** NOTE: Since I wrote this short program using cpp.sh, the output may not look that nice.
**
*********
*********/

char line[100] = "\t\t\t\t#####################################################";
std::cout << line << std::endl << "\t\t\t\t##" << std::setw(109) << "Written by re-0                ##\n\t\t\t\t## mean, min, max, sum^2, var(x), st.dev(x), range ##" << std::endl << line << "\n\n\n";

double lower = x - std::sqrt(variance);
double upper = x + std::sqrt(variance);

std::string interval = "["+ std::to_string( lower ) +":"+ std::to_string( upper ) +"]";

list("mean", "min", "max", "sum^2", "var(x)", "st.dev(x)", "range");
list(x, min, max, squared_sum, variance, std::sqrt(variance), interval);

return 0;
}
  

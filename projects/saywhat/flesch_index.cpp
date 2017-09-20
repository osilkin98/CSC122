#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cmath>

using namespace std;

// function to check if the passed char value is a vowel character
bool is_vowel(char letter) {  
	char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'y' }; // using a defined array to complete this task, really wishing that there was a different type of structure that would handle
							// this sort of checking in a more efficient manner
	for(int i = 0; i < 6; ++i) { // i dont think I have to explain what this does
		if(tolower(letter) == vowels[i]) {
			return true;
		}
	}
	return false;
}

// checks if the character is a sentence ending character, similar to the is_vowel function with the only difference being the array pre-definition
bool is_sent_end(char const letter) {
	char ends[] = {'.', ':', ';', '?', '!'};
	for(int i = 0; i < 5; ++i) {
		if(letter == ends[i]) {
			return true;
		}
	}
	return false;
}
// designed for bugtesting vectors containing words.
template<typename T, typename A>  // takes the typename of the class along with an allocator though the allocator is passed in silently when this function is used
	void print_vector( vector<T,A> const & vec ) {
		cout << "{ ";
		auto it = vec.begin(); // using an iterator to traverse this vector
		for(it = vec.begin(); it != vec.end(); it++) {
			cout << *it << ", ";
		}
		cout << "}\n"; 
	}

// my algorith to seek and find vowels
/***
 *	split string into a vector array of words by delimiting whitespaces
 *	-> 	go through each element of the vector of length n and perform the following:
 *		
 *		1. If n == 1 then
 *			syllable++
 *		2. If the ith value is a vowel
 *		if 1 is true, then:
 *			if the (i + 1)th term is also a vowel, or ( the (i + 1)th term == 'e' and i == n - 2 ) then
 *				skip
 *			else
 *				syllable++
 *
 *
 *
 */

// splits string into an array of words, 
void split_string(const string & str, vector<string> & words) {
        size_t f, i = 0;
	while((f = str.find_first_of(" .;:?!", i)) != string::npos) { // traverses the given string and appends string containers via delimitation
    		words.push_back(str.substr(i, f - i));
    		i = f + 1;
  	}
	// i didn't feel like making a clever method to delimit everything in one go (i wasn't using c-strings)
	// so im just grabbing the last word if there are any
  	if(i < str.length()) {
    		words.push_back(str.substr(i, str.length() - i));
  	}
	
	
}


// count the number of sentances in the string
int count_sent(const string & str) {
	// no sentence can end on the first character, this is nonsense.
	int n = 0;
	for(int i = 1; i < str.length(); ++i) {
		// if the last character is not a sentence ending character and the current one is
		if( !is_sent_end((char)(str[i - 1])) && is_sent_end((char)(str[i])) ) {
			n++;
		}
	}
	return n;
}
// count the number of words 
int count_words(const string & str) {
	vector<string> words; 
	split_string(str, words); // definitely inefficient, but I don't feel like rewriting my framework at this point
	return words.size();
}
// count the number of syllables
int count_syl(const string & str) {
	vector<string> words;
	split_string(str, words);
	int syl = 0, syl_word = 0;
	// traverses the string vector and performs a syllables check on each element
	for(int x = 0; x < words.size(); ++x) {
		syl_word = 0; // reset the # of syllables per word
		
		for(int i = 0; i < words[x].length(); i++) {
			// checks for adjacent vowels or the ending 'e' on a word
			if( (is_vowel((char)(words[x][i])) && is_vowel((char)(words[x][i + 1]))) 
			|| (i == words[x].length() - 1 && 'e' == tolower((char)(words[x][i])))) {
				continue;
			// the current character creates a syllable
			} else if (is_vowel((char)(words[x][i]))) {
				syl_word++;
				
			}	
		}
		// if we haven't captured any syllables, add one anyway because all words should have at least one syllable
		if(syl_word == 0) {
			syl_word = 1;
			
		}

		
		syl += syl_word;
		
	}
		
	return syl;
}

// basically the main function right here, this bad boy makes use of all the functions defined above
// and determines the flesch_index of a given text
double flesch_index(const string & str) {
	

	int syl = count_syl(str);
	
	int words = count_words(str);
	
	int sent = count_sent(str);
    	// sometimes you'll have people like me who write run-on sentences, and attempting to calculate the index of that
	// would result in a division by 0 error.
	return sent > 0 ? 
	  round(206.385 - 84.6 * ((double)syl/(double)words) - 1.015*((double)words/(double)sent)) : 
	  round(206.385 - 84.6 * ((double)syl/(double)words) - 1.015);	
}

// basically just a function to read from a file should the user wish to specify
string file_input(const string & filename) {
	string s, f;
	ifstream file(filename);
	// if the file was sucessfully opened,
	if( file.is_open() ) {
		// just read all the lines from the file and append them to the main string
		while( getline(file, s) ) {
			f.append(s);
		}
	}
	// i tried to delete the temporary string but it wouldn't work and as we haven't learned how to do that yet
	// i just decided to wait a bit since I was really tired
	//delete &s;
	return f;
}

int main(int argc, char* argv[]) {
	// if we have more arguments than just the initial argument
	if(argc > 1) {
		int x;
		string arg;
		for(int i = 1; i < argc; ++i) {
			arg = string(argv[i]);
			// if argument is to input from files
			if(arg.length() == 2 && arg[0] == '-' && tolower(arg[1]) == 'f') {
				if(argc == 2) { // if we only have two arguments in total
					// IE: "./flesch_index -f"
					cout << "Error: File not specified." << endl;
				}// goes through each file and calculates its flesch index
				for(int j = 1; j <  argc; ++j) {
					if(j != i) {
						cout << "Flesch index of "
						<< argv[j] << ": " << 
						flesch_index(file_input(string(argv[j]))) 
						<< endl;
					}
				}
				// since we found our *one* argument, we no longer need
				// search for more arguments
				break;
			// if we've gone through all possible arguments and haven't matched yet
			// then whatever this current argument is; it's garbage.
			} else if(arg[0] == '-') {
				cout << "\nError: Unknown command,\n" <<
					"\n\tCommands list:" <<
					"\n\n\tread from file(s), usage: -{f|F} [file_1], [file_2], ..., [file_n]\n"
					<< endl;
				break;
			}
		}
       	} else { // otherwise if we don't have any arguments, we can just run it like this.
		// this block just gets the user input and outputs the flesch index.
		string str;
		cout << "This program calculates the flesch index of a piece of text,\n"
			<< "Enter a piece of text to get started:\n" << endl;
		getline(cin, str);
		cout << "\nThe flesch index of this text is: " << flesch_index(str) << "." << endl;
	}
	return 0;
}


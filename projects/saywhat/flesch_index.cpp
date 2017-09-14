#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cmath>

using namespace std;

bool is_vowel(char letter) { 
	char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'y' };
	for(int i = 0; i < 6; ++i) {
		if(tolower(letter) == vowels[i]) {
			return true;
		}
	}
	return false;
}

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
template<typename T, typename A>
	void print_vector( vector<T,A> const & vec ) {
		cout << "{ ";
		auto it = vec.begin();
		for(it = vec.begin(); it != vec.end(); it++) {
			cout << *it << ", ";
		}
		cout << "}\n"; 
	}


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
	while((f = str.find_first_of(" .;:?!", i)) != string::npos) {
    		words.push_back(str.substr(i, f - i));
    		i = f + 1;
  	}
  	if(i < str.length()) {
    		words.push_back(str.substr(i, str.length() - i));
  	}
	
	
}


// count the number of sentances in the string
int count_sent(const string & str) {
	// no sentence can end on the first character, this is nonsense.
	int n = 0;
	for(int i = 1; i < str.length(); ++i) {
		if( !is_sent_end((char)(str[i - 1])) && is_sent_end((char)(str[i])) ) {
			n++;
		}
	}
	return n;
}
// count the number of words 
int count_words(const string & str) {
	vector<string> words; 
	split_string(str, words);
	return words.size();
}
// count the number of syllables
int count_syl(const string & str) {
	vector<string> words;
	split_string(str, words);
	int syl = 0, syl_word = 0;
	for(int x = 0; x < words.size(); ++x) {
		syl_word = 0;
		// checks each single word for syllable
		for(int i = 0; i < words[x].length(); i++) {
			if( (is_vowel((char)(words[x][i])) && is_vowel((char)(words[x][i + 1]))) 
			|| (i == words[x].length() - 1 && 'e' == tolower((char)(words[x][i])))) {
				continue;
			} else if (is_vowel((char)(words[x][i]))) {
				syl_word++;
				
			}	
		}
		
		if(syl_word == 0) {
			syl_word = 1;
			
		}

		
		syl += syl_word;
		
	}
		
	return syl;
}

double flesch_index(const string & str) {
	

	int syl = count_syl(str);
	
	int words = count_words(str);
	
	int sent = count_sent(str);
    
	return sent > 0 ? 
	  round(206.385 - 84.6 * ((double)syl/(double)words) - 1.015*((double)words/(double)sent)) : 
	  round(206.385 - 84.6 * ((double)syl/(double)words) - 1.015);	
}

string file_input(const string & filename) {
	string s, f;
	ifstream file(filename);
	if( file.is_open() ) {
		while( getline(file, s) ) {
			f.append(s);
		}
	}
	//delete &s;
	return f;
}

int main(int argc, char* argv[]) {
	if(argc > 0) {
		int x;
		string arg;
		for(int i = 1; i < argc; ++i) {
			arg = string(argv[i]);
			// if argument is to input from files
			if(arg.length() == 2 && arg[0] == '-' && tolower(arg[1]) == 'f') {
				for(int j = 1; j <  argc; ++j) {
					if(j != i) {
						cout << "Flesch index of " << argv[j] << ": " << flesch_index(file_input(string(argv[j]))) << endl;
					}
				}
				break;

			} else if(arg[0] == '-') {
				cout << "\nError: Unknown command,\n" <<
					"\n\tCommands list:" <<
					"\n\n\tread from file(s), usage: -f [file_1], [file_2], ..., [file_n]\n"
					<< endl;
				break;
			}
		}
       	}
	//system("pause");
	return 0;
}



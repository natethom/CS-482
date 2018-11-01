#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <unordered_map>
#include <locale>

using namespace std;

int main( int argc, char* argv[] )
{
    //initialize variables
    int index, character, ham_count = 0, spam_count = 0;
    char step_variable, temp_spam_or_ham[4] = {}, temp_message[2500] = {};
    string temp_word;
    locale loc;
    regex chars_digits_regex("([A-Za-z0-9]+)");
    unordered_map<string, int> spam_map, ham_map;
    unordered_map<string, int>::const_iterator got;
    ifstream input_file;
    ofstream ham_output_file, spam_output_file;

    input_file.open (argv[2]);

    input_file.getline(temp_message, 2500, '\n');

    //Until the end of the input file is reached
    while( !input_file.eof() ){
        input_file.getline(temp_spam_or_ham, 256, ',');

        // cout << "Spam or ham: " << temp_spam_or_ham << endl;
        // cin >> step_variable;

        input_file.getline(temp_message, 2500, '\n');
        // cout << "Message: " << temp_message << endl;
        // cin >> step_variable;

        index = 0;
        character = 0;
        temp_word = "";
        while(temp_message[index] != '\0'){
            // cout << "index: " << index << endl;
            // cout << "message[index]: " << temp_message[index] << endl;

            string temp_read_in_str(1, temp_message[index]);

            if( regex_match(temp_read_in_str, chars_digits_regex) ){
                temp_word += temp_read_in_str;
            }

            if(temp_read_in_str == " " || temp_read_in_str == "\n"){
                character = 0;
                // cout << "temp_word: " << temp_word << endl;
                while(temp_word[character] != '\0'){
                    // cout << "temp_word[character]: " << temp_word[character] << endl;
                    if(temp_word[character] >= 65 && temp_word[character] <= 90){
                        temp_word[character] += 32;
                    }
                    // cout << "temp_word[character]: " << temp_word[character] << endl;
                    character++;
                }
                // cout << "temp_word: " << temp_word << endl;
                if(temp_spam_or_ham[0] == 'h'){
                    ham_count++;
                    got = ham_map.find(temp_word);

                    if(got == ham_map.end()){
                        ham_map[temp_word] = 1;
                    }
                    else{
                        ham_map[temp_word] = got->second + 1;
                    }
                }
                else{
                    spam_count++;
                    got = spam_map.find(temp_word);

                    if(got == spam_map.end()){
                        spam_map[temp_word] = 1;
                    }
                    else{
                        spam_map[temp_word] = got->second + 1;
                    }
                }
                temp_word = "";
            }
            index++;
        }
    }
    input_file.close();

    spam_output_file.open (argv[4]);

    spam_output_file << spam_count << endl;
    for(auto& x: spam_map)
        // if(x.second > 1){
        //     spam_output_file << x.first << " " << (x.second * 3) << endl;
        // }
        // else{
            spam_output_file << x.first << " " << (x.second*2) << endl;
        // }

    spam_output_file.close();

    ham_output_file.open (argv[6]);

    ham_output_file << ham_count << endl;
    for(auto& x: ham_map)
        ham_output_file << x.first << " " << (x.second) << endl;

    ham_output_file.close();

	return 0;
}

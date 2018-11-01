#include <stdio.h>
#include <math.h>

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <unordered_map>

using namespace std;

int main( int argc, char* argv[] )
{
    //initialize variables
    int index, temp_number, character, counter;
    double ham_count = 0.0, spam_count = 0.0;
    double probability_spam, probability_ham, probability_word_given_spam, probability_spam_given_word;
    double probability_not_spam, probability_word_given_not_spam, probability_not_spam_given_word;
    double probability_message_is_spam, probability_message_is_not_spam;
    char step_variable, temp_input_number[256] = {}, temp_input_word[256] = {}, temp_input_message[2500] = {};
    string temp_word;
    string::size_type sz;
    regex chars_digits_regex("([A-Za-z0-9]+)");
    unordered_map<string, int> spam_map, ham_map;
    unordered_map<string, int>::const_iterator got_spam, got_ham;
    ifstream spam_input_file, ham_input_file, test_input_file;
    ofstream classification_output_file;
    classification_output_file.open (argv[8]);

    spam_input_file.open (argv[4]);

    //create dictionaries for training data
    //Until the end of the input file is reached
    spam_input_file.getline(temp_input_number, 256, '\n');
    spam_count = stoi(temp_input_number, &sz);

    spam_input_file.getline(temp_input_word, 256, ' ');
    spam_input_file.getline(temp_input_number, 256, '\n');
    while( !spam_input_file.eof() ){
        temp_number = stoi(temp_input_number, &sz);

        spam_map[temp_input_word] = temp_number;

        spam_input_file.getline(temp_input_word, 256, ' ');
        spam_input_file.getline(temp_input_number, 256, '\n');
    }

    spam_input_file.close();
    //cin >> step_variable;

    ham_input_file.open (argv[6]);

    //create dictionaries for training data
    //Until the end of the input file is reached
    ham_input_file.getline(temp_input_number, 256, '\n');
    ham_count = stoi(temp_input_number, &sz);

    ham_input_file.getline(temp_input_word, 256, ' ');
    ham_input_file.getline(temp_input_number, 256, '\n');
    while( !ham_input_file.eof() ){
        counter++;
        temp_number = stoi(temp_input_number, &sz);

        ham_map[temp_input_word] = temp_number;

        ham_input_file.getline(temp_input_word, 256, ' ');
        ham_input_file.getline(temp_input_number, 256, '\n');
    }

    ham_input_file.close();

    //go through and calculate probability of spam
    probability_spam = (spam_count) / (spam_count + ham_count);
    probability_ham = (ham_count) / (ham_count+spam_count);

    probability_not_spam = probability_ham;

    test_input_file.open (argv[2]);
    // test_input_file.getline(temp_input_word, 256, '\n');
    // cout << "temp_input_word: " << temp_input_word << endl;
    while( !test_input_file.eof() ){
        probability_message_is_spam = 1;
        probability_message_is_not_spam = 1;
        test_input_file.getline(temp_input_word, 256, ',');

        test_input_file.getline(temp_input_message, 2500, '\n');

        // cout << "temp_word: " << temp_input_word << endl;
        // cout << "temp_message: " << temp_input_message << endl << endl;

        index = 0;
        temp_word = "";
        while(temp_input_message[index] != '\0'){
            string temp_read_in_str(1, temp_input_message[index]);
            // cout << "temp_read_in_str: " << temp_read_in_str << endl;
            if( regex_match(temp_read_in_str, chars_digits_regex) ){
                temp_word += temp_read_in_str;
            }

            if((temp_read_in_str == " " || (temp_input_message[index] == ',' && temp_input_message[index+1] == ',' && temp_input_message[index+2] == ',')) && temp_word != ""){
                character = 0;
                while(temp_word[character] != '\0'){
                    if(temp_word[character] >= 65 && temp_word[character] <= 90){
                        temp_word[character] += 32;
                    }
                    character++;
                }

                got_spam = spam_map.find(temp_word);
                got_ham = ham_map.find(temp_word);

                if(got_spam == spam_map.end()){
                    // probability_word_given_spam = 0;
                    // probability_word_given_not_spam = 0;
                    temp_word = "";
                }
                else if(got_ham == ham_map.end()){
                //     probability_word_given_spam = 0;
                //     probability_word_given_not_spam = 0;
                    temp_word = "";
                }
                // else if(got_spam->second <= 10 || got_ham->second <= 7){
                //     probability_word_given_spam = 0;
                //     probability_word_given_not_spam = 0;
                //     temp_word = "";
                // }
                else{
                    probability_word_given_spam = (got_spam->second)/spam_count;
                    probability_word_given_not_spam = (got_ham->second)/ham_count;

                    probability_spam_given_word = (probability_word_given_spam * probability_spam);
                    if(probability_spam_given_word > 0){
                        probability_message_is_spam *= probability_spam_given_word;
                    }

                    probability_not_spam_given_word = (probability_word_given_not_spam * probability_not_spam);
                    if(probability_not_spam_given_word > 0){
                        probability_message_is_not_spam *= probability_not_spam_given_word;
                    }
                    temp_word = "";
                }

                // cout << "temp word: " << temp_word << endl;
                // cout << "probability_spam: " << probability_spam << endl;
                // cout << "probability_not_spam: " << probability_not_spam << endl;
                //
                // cout << "probability_word_given_spam: " << probability_word_given_spam << endl;
                // cout << "probability_word_given_not_spam: " << probability_word_given_not_spam << endl;
                //
                // cout << "probability_spam_given_word: " << probability_spam_given_word << endl;
                // cout << "probability_not_spam_given_word: " << probability_not_spam_given_word << endl << endl;
                //
                // cout << "probability_message_is_spam: " << probability_message_is_spam << endl;
                // cout << "probability_message_is_not_spam: " << probability_message_is_not_spam << endl << endl;

                // temp_word = "";
            }
            index++;
        }
        if(probability_message_is_not_spam > probability_message_is_spam){
            classification_output_file << "ham" << endl;
        }
        else if(probability_message_is_not_spam == probability_message_is_spam){
            classification_output_file << "ham" << endl;
        }
        else{
            // cout << "spam" << endl;
            classification_output_file << "spam" << endl;
        }
    }
    classification_output_file.close();
    test_input_file.close();


    return 0;
}

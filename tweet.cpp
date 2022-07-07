//
// Created by Miles Friedman on 6/3/21.
//

#include "tweet.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "DSString.h"
using namespace::std;

//CONSTRUCTOR
tweet::tweet(DSString in1, DSString in2, DSString in3, DSString in4, DSString in5, DSString in6){
    senti = in1;
    id = in2;
    date = in3;
    query = in4;
    user = in5;
    msg = in6;
}
//setter method for the sentiment
void tweet::setSenti(DSString& in) {
    senti = in;
}
//setter method for the msg
void tweet::setMsg(DSString& in) {
    msg = in;
}
//prints the sentiment and the msg of the tweet
void tweet::print(ofstream& write){
    write << "User: " << user << endl;
    write << "ID: " << id << endl;
    write << "Sentiment: " << senti << endl;
    write << "Tweet: " << msg << endl;
    write << "Date: " << date << endl;
    write << "Query: " << query << endl;
    write << endl << endl;
}
//prepares the words vector with individual DSString of each word in the tweet
void tweet::tokenMsg(){
    DSString word("");
    int charCount = 0;
    int wordCount = 0;
    int tweet_length = msg.getLength();
    int tagLength = 0;
    for(int i = 0; i < tweet_length; i++){

        //if the char is a space it tokens the word
        if(msg[i] == ' '){
            words.push_back(word);

            if(word[0] == '#' && word[1] != '\0'){
                int i = 1;
                int l = tagLength - 1;
                word = word.substring(i, l);
                hashtags.push_back(word);
            }
            word = "";
            tagLength = 0;
            wordCount++;
            charCount++;
        }
        else{
            word = word + tolower(msg[i]);
            charCount++;
            tagLength++;
        }
        wrdCount = wordCount;
        chrCount = charCount;
    }

}
//prints the individual DSString objects
void tweet::printTokens() {
    for(int i = 0; i < words.size(); i++){
        cout << words.at(i) << endl;
    }
}
bool tweet::operator< (tweet& arg){
    if(strcmp(date.c_str(), arg.date.c_str()) <= 0)
        return true;
    else
        return false;

}
bool tweet::operator< (DSString& arg){
    if(strcmp(date.c_str(), arg.c_str()) <= 0)
        return true;
    else
        return false;

}
bool tweet::operator> (DSString& arg){
    if(strcmp(date.c_str(), arg.c_str()) <= 0)
        return false;
    else
        return true;

}
bool tweet::operator> (tweet& arg){
    if(strcmp(date.c_str(), arg.date.c_str()) <= 0)
        return false;
    else
        return true;

}
void tweet::dateCorrect(){
    DSString year;
    DSString month;
    DSString day;

    int start1 = 4;
    int length1 = 2;
    int length2 = 3;
    int start2 = 8;
    int start3 = 24;
    int length3 = 4;

    month = date.substring(start1, length2);
    day = date.substring(start2,length1);
    year = date.substring(start3, length3);
    if(month == "Jan"){
        month = "01";
    }
    else if(month == "Feb"){
        month = "02";
    }
    else if(month == "Mar"){
        month = "03";
    }
    else if(month == "Apr"){
        month = "04";
    }
    else if(month == "May"){
        month = "05";
    }
    else if(month == "Jun"){
        month = "06";
    }
    else if(month == "Jul"){
        month = "07";
    }
    else if(month == "Aug"){
        month = "08";
    }
    else if(month == "Sep"){
        month = "09";
    }
    else if(month == "Oct"){
        month = "10";
    }
    else if(month == "Nov"){
        month = "11";
    }
    else if(month == "Dec"){
        month = "12";
    }

    date = strcat(year.c_str(), "/");
    date = strcat(date.c_str(), month.c_str());
    date = strcat(date.c_str(), "/");
    date = strcat(date.c_str(), day.c_str());

}
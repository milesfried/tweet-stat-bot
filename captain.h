//
// Created by Miles Friedman on 6/14/21.
//

#ifndef INC_21SU_PA02_TEMPLATE_CAPTAIN_H
#define INC_21SU_PA02_TEMPLATE_CAPTAIN_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "DSVector.h"
#include "tweet.h"
#include "DSString.h"
#include <iomanip>

class captain {
private:
    DSVector<tweet> tweetList;
public:
    /**
     * This function reads the input file and populates the tweet list
     */
    void populateTweetList(DSString fileName) {

        fstream fileIn;
        fileIn.open(fileName.c_str());
        if (fileIn.is_open()) {
            char senti[500];
            char id[500];
            char date[500];
            char query[500];
            char user[500];
            char msg[5000];
            fileIn.getline(senti, 500);
            //primary read
            fileIn.getline(senti, 500, ',');
            //populates vector
            while (!fileIn.eof()) {
                fileIn.getline(id, 500, ',');
                fileIn.getline(date, 500, ',');
                fileIn.getline(query, 500, ',');
                fileIn.getline(user, 500, ',');
                fileIn.getline(msg, 5000);
                tweet listAdd(senti, id, date, query, user, msg);
                listAdd.dateCorrect();
                tweetList.push_back(listAdd);
                fileIn.getline(senti, 500, ',');
            }
        }
        fileIn.close();
    }

    /**
     * outputs all tweet objects which match param username
     * @param username given to check
     */
    void printUserName(DSString username, DSString output) {
        DSVector<tweet> outList;
        ofstream write(output.c_str());
        if (write.is_open()) {
            for (int i = 0; i < tweetList.size(); i++) {
                if (tweetList.at(i).getUser() == username) {

                    outList.push_back(tweetList.at(i));
                }
            }
        }
        outList.sort(0, outList.size() - 1);
        for(int i = 0; i < outList.size(); i++){
            outList.at(i).print(write);
        }
        write.close();
    }

    /**
     * outputs all tweet objects that fall between param date1 and param date2 inclusive
     * @param date1
     * @param date2
     */
    void printDateRange(DSString date1, DSString date2, DSString output) {
        DSVector<tweet> outList;

        ofstream write(output.c_str());
        if (write.is_open()) {
            for (int i = 0; i < tweetList.size(); i++) {
                if (tweetList.at(i).getDate() == date1 || tweetList.at(i).getDate() == date2) {
                    outList.push_back(tweetList.at(i));

                } else if (tweetList.at(i) > date1 && tweetList.at(i) < date2) {
                    outList.push_back(tweetList.at(i));

                }
            }
        }
        outList.sort(0, outList.size() - 1);
        for(int i = 0; i < outList.size(); i++){
            outList.at(i).print(write);
        }
        write.close();
    }

    /**
     * outputs all tweets that contain a given hashtag
     * @param tag
     */
    void printHashTag(DSString tag, DSString output) {
        DSVector<tweet> outList;

        ofstream write(output.c_str());
        if (write.is_open()) {
            for (int i = 0; i < tweetList.size(); i++) {
                tweetList.at(i).tokenMsg();
                for (int j = 0; j < tweetList.at(i).getHashtags().size(); j++) {
                    if (tweetList.at(i).getHashtags().at(j) == tag) {
                        outList.push_back(tweetList.at(i));
                    }
                }
            }
        }
        outList.sort(0, outList.size() - 1);
        for(int i = 0; i < outList.size(); i++){
            outList.at(i).print(write);
        }
        write.close();
    }

    /**
     * outputs various stats about the dataset
     */
    void printStats(DSString output) {
        ofstream write(output.c_str());
        if (write.is_open()) {
            map<DSString, int> tagDict;
            map<DSString, int>::iterator itr;
            double totalChars = 0;
            double totalWords = 0;
            tweet min(" ", " ", "9999", " ", " ", " ");
            tweet max(" ", " ", "0000", " ", " ", " ");

            for (int i = 0; i < tweetList.size(); ++i) {

                if (tweetList.at(i) < min) {
                    min = tweetList.at(i);
                }
                if (tweetList.at(i) > max) {
                    max = tweetList.at(i);
                }
                tweetList.at(i).tokenMsg();
                totalChars += tweetList.at(i).getCharCount();
                totalWords += tweetList.at(i).getWordCount();
                for (int j = 0; j < tweetList.at(i).getHashtags().size(); ++j) {
                    DSString current_tag = tweetList.at(i).getHashtags().at(j);
                    itr = tagDict.find(current_tag);
                    if (itr == tagDict.end()) {
                        tagDict[current_tag] = 1;
                    } else {
                        tagDict[current_tag]++;
                    }
                }
            }

            DSVector<pair<int, DSString>> dict;
            for (itr = tagDict.begin(); itr != tagDict.end(); ++itr) {
                pair<int, DSString> in(itr->second, itr->first);
                dict.push_back(in);
            }
            dict.sort(0, dict.size() - 1);

            double avgChars = totalChars / tweetList.size();
            double avgWords = totalWords / tweetList.size();
            write << "Average of " << setprecision(5) << avgChars << " characters per tweet" << endl << endl;
            write << "Average of " << setprecision(5) << avgWords << " words per tweet" << endl << endl;
            write << "Date Range of " << min.getDate() << " to " << max.getDate() << endl << endl;
            write << tagDict.size() << " unique hashtags used" << endl << endl;
            write << "Top 5 Hashtags" << endl << endl;
            write << "1. " << dict.at(dict.size() - 1).second << " - " << dict.at(dict.size() - 1).first << " entries"
                  << endl << endl;
            write << "2. " << dict.at(dict.size() - 2).second << " - " << dict.at(dict.size() - 2).first << " entries"
                  << endl << endl;
            write << "3. " << dict.at(dict.size() - 3).second << " - " << dict.at(dict.size() - 3).first << " entries"
                  << endl << endl;
            write << "4. " << dict.at(dict.size() - 4).second << " - " << dict.at(dict.size() - 4).first << " entries"
                  << endl << endl;
            write << "5. " << dict.at(dict.size() - 5).second << " - " << dict.at(dict.size() - 5).first << " entries"
                  << endl << endl;


        }
        write.close();
    }

    void printDateandUser(DSString username, DSString date1, DSString date2, DSString output) {
        DSVector<tweet> outList;

        ofstream write(output.c_str());
        if (write.is_open()) {
            for (int i = 0; i < tweetList.size(); i++) {
                if (tweetList.at(i).getDate() == date1 || tweetList.at(i).getDate() == date2) {
                    if (tweetList.at(i).getUser() == username) {
                        outList.push_back(tweetList.at(i));
                    }
                } else if (tweetList.at(i) > date1 && tweetList.at(i) < date2) {
                    if (tweetList.at(i).getUser() == username) {
                        outList.push_back(tweetList.at(i));
                    }
                }
            }
        }
        outList.sort(0, outList.size() - 1);
        for(int i = 0; i < outList.size(); i++){
            outList.at(i).print(write);
        }
        write.close();
    }
};


#endif //INC_21SU_PA02_TEMPLATE_CAPTAIN_H

//
// Created by Miles Friedman on 6/3/21.
//

#ifndef PA01_SENTIMENT_TWEET_H
#define PA01_SENTIMENT_TWEET_H

#include "DSString.h"
#include "DSVector.h"
using namespace::std;
class tweet {
private:
    /**
     * private variable declaration
     */
    DSString msg;
    DSString senti;
    DSString id;
    DSString date;
    DSString query;
    DSString user;
    DSVector<DSString> words;
    DSVector<DSString> hashtags;
    int wrdCount;
    int chrCount;

public:
    tweet(){

    }
    /**
     *
     * @param in1 is set to senti
     * @param in2 is set to id
     * @param in3 is set to date
     * @param in4 is set to query
     * @param in5 is set to user
     * @param in6 is set to msg
     */
    tweet(DSString in1, DSString in2, DSString in3, DSString in4, DSString in5, DSString in6);
    /**
     * @return the DSString senti of the tweet object
     */
    DSString getSenti(){ return senti;}
    /**
     * @return the DSString msg of the tweet object
     */
    DSString getMessage(){return msg;}
    /**
     * @return the DSString id
     */
     DSString getID(){return id;}
     /**
      * @return the DSString date
      */
     DSString getDate(){return date;}
     /**
      * @return the DSString query
      */
     DSString getQuery(){return query;}
     /**
      * @return the DSString user
      */
     DSString getUser(){return user;}
    /**
    * @return the words vector of the tweet object
    */
    DSVector<DSString>& getList(){return words;}
    /**
     *
     * @return the hashtags vector of the tweet object
     */
    DSVector<DSString>& getHashtags(){return hashtags;}
    /**
     * @return the integer wrdCount of the tweet object
     */
    int getWordCount(){return wrdCount;}
    /**
     *
     * @return the integer charCount of the tweet object
     */
    int getCharCount(){return chrCount;}
    /**
     * populates the words vector of the tweet object with tokened words
     */
    void tokenMsg();
    /**
     * senti is set to the value of param one
     */
    void setSenti(DSString&);
    /**
     * msg is set to the value of param one
     */
    void setMsg(DSString&);
    /**
     * prints the DSString objects of the class
     */
    void print(ofstream&);
    /**
     * prints the individual tokens
     */
    void printTokens();

    /**
     * relational operators for sort applications
     * @return
     */
    bool operator< (tweet&);
    bool operator> (tweet&);
    bool operator< (DSString&);
    bool operator> (DSString&);
    /**
     * function reformats the date into YYYY/MM/DD format
     */
    void dateCorrect();
};
#endif //PA01_SENTIMENT_TWEET_H

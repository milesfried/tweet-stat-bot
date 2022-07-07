//
// Created by Mark Fontenot on 6/2/2021.
//

#ifndef PA01_SENTIMENT_DSSTRING_H
#define PA01_SENTIMENT_DSSTRING_H

#include <iostream>
#include <cstring>

class DSString{

private:
    /**
     * private data variable declaration
     */
    char* data;
    int length;


public:

    /**
     * Constructors and destructor
     *
     *
     **/
    DSString();
    DSString(const char*);
    DSString(const DSString&);
    ~DSString(){delete[] data;};

    /**
     * Overloaded Assignment Operators
     */
    DSString& operator= (const char*);
    DSString& operator= (const DSString&);

    /**
     * Overloaded non-modifying string concat
     *
     */
    DSString operator+ (const DSString&);
    DSString operator+ (const char*);
    DSString operator+ (const char);


    /**
     * relational operators
     *
     */
    bool operator== (const char*);
    bool operator== (const DSString&);
    bool operator> (const DSString&);
    bool operator> (const char*);
    bool operator< (const char*);
    bool operator< (const DSString&);
    bool operator< (const DSString&) const;

    /**
     * Subscript operator to access a particular character of a DSString object
     * @return the character requested by reference
     */
    char& operator[] (const int);

    /**
     * getLength() returns the number (count) of characters in the string.
     **/
    int getLength();

    /**
     * The substring method returns a string object that contains a
     * sequence of characters from this string object.
     *
     * param start - the index of where to start
     * param numChars - the number (count) of characters to copy into
     *    the substring
     * @return a DSString object containing the requested substring
     **/
    DSString substring(int& start, int& numChars);

    /**
     * the c_str function returns a null-terminated c-string holding the
     * contents of this object.
     **/
    char* c_str();

    /**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument.
     **/
    friend std::ostream& operator<< (std::ostream&, const DSString&);
    /**
     * makes the string all lowercase
     */
    void toLower(){
        for(int i = 0; i < getLength(); i++){
            data[i] = tolower(data[i]);
        }
    }



};



#endif //PA01_SENTIMENT_DSSTRING_H

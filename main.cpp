#include <iostream>
#include "DSVector.h"
#include "DSString.h"
#include "tweet.h"
#include "captain.h"
int main(int argC, char* argV[]) {
captain run;
DSString fileName, startDate, endDate, username, hashtag, output = "\0";
bool stat, user, date, file, out, tag, both = false;
char in = '\0';
//for loop sorts the user input
for (int i = 0; i < argC; i++){
    if (argV[i][0] == '-'){
        in = argV[i][1];
    }
    if (in == 'r'){
        i++;
        startDate = argV[i];
        endDate = argV[i + 1];
        i++;
        date = true;
        if (user){
            both = true;
        }
    }
    if (in == 'u'){
        i++;
        username = argV[i];
        user = true;
        if (date){
            both = true;
        }
    }
    if (in == 't'){
        i++;
        hashtag = argV[i];
        tag = true;
    }
    if (in == 'f'){
        i++;
        fileName = argV[i];
        file = true;
    }
    if (in == 'o'){
        i++;
        output = argV[i];
        out = true;
    }
    if (in == 's'){
        stat = true;
    }
}
//checks the input and runs the necessary function
    if(out && file){
        if(both){
            run.populateTweetList(fileName);
           run.printDateandUser(username, startDate, endDate, output);
       }
       else if(date){
            run.populateTweetList(fileName);
           run.printDateRange(startDate, endDate, output);
       }
       else if(user) {
            run.populateTweetList(fileName);
           run.printUserName(username, output);
       }
       else if(tag) {
            run.populateTweetList(fileName);
           hashtag.toLower();
           run.printHashTag(hashtag, output);
       }
       else if(stat){
            run.populateTweetList(fileName);
           run.printStats(output);
           }
        }
    return 0;
}

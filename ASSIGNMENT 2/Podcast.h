#ifndef PODCAST_H
#define PODCAST_H
#include<iostream>
#include<string>
#include "Episode.h"
#include "defs.h"
using namespace std;

class Podcast {
  public:
    //Constructors
    Podcast(const string& title, const string& host);
    Podcast(Podcast& p);

    //Destructor
    ~Podcast();

    //Setters
    void setTitle(string title);
    void setHost(string host);

    //Getters
    string getTitle();
    string getHost();
    int getNumEpisodes();

    //Other functions
    bool addEpisode(const string& title, const string& content);
    bool getEpisode(int index, Episode** ep);
    bool lessThan(Podcast& pod);
    void print();


  private:
    string title;
    string host;
    Episode** Episode_Array;
    int numEps;
};

#endif

//DONE

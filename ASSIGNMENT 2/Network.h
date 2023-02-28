#ifndef NETWORK_H
#define NETWORK_H
#include<iostream>
#include<string>
#include "defs.h"
#include "Episode.h"
#include "PodArray.h"
#include "Podcast.h"
#include "Subscriber.h"
using namespace std;

class Network {
  public:
    //Constructor
    Network(const string& name);

    //Destructor
    ~Network();

    //Other functions
    bool getPodcast(const string& title, Podcast** pod);
    bool addPodcast(const string& title, const string& host);
    bool removePodcast(const string& title);
    bool addEpisode(const string& pod, const string& title, const string& content);
    bool addSubscriber(const string& name, const string& creditcard);
    bool download(const string& sub, const string& title, Podcast** pod);
    bool stream(const string& sub, const string& pod, int ep_num, Episode** ep);
    bool hasSubscriber(const string& name);
    void print();


  private:
    string name;
    PodArray* pod_Array;
    Subscriber* subscriber[MAX_SUBS];
    int numSubs;
};

#endif

//DONE

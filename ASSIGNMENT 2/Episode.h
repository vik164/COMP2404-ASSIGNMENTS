#ifndef EPISODE_H
#define EPISODE_H
#include<iostream>
#include<string>
using namespace std;

class Episode {
  public:
    //Constructors
    Episode(const string& podcast, int number, const string& name, const string& content);
    Episode();
    Episode(Episode& e);

    //Setters
    void setName(string name);
    void setContent(string content);
    void setPodcast(string podcast);
    void setNumber(int number);

    //Getters
    string getName();
    string getContent();
    string getPodcast();
    int getNumber();

    //Other functions
    void play();
    void print();


  private:
    string name;
    string content;
    string podcast;
    int number;
};

#endif

//DONE

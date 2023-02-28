#include "Episode.h"

//Constructors
Episode::Episode(const string& podcast, int number, const string& name, const string& content){
  setName(name);
  setContent(content);
  setPodcast(podcast);
  setNumber(number);
}

Episode::Episode(){
  setName("Vik's Episode");
  setContent("Content");
  setPodcast("KUMAR'S Podcast");
  setNumber(0);
}

Episode::Episode(Episode& e){
  setName(e.name);
  setContent(e.content);
  setPodcast(e.podcast);
  setNumber(e.number);
}


//Setters
void Episode::setName(string name){ this->name = name; }
void Episode::setContent(string content){ this->content = content; }
void Episode::setPodcast(string podcast){ this->podcast = podcast; }
void Episode::setNumber(int number){ this->number = number; }


//Getters
string Episode::getName(){ return name; }
string Episode::getContent(){ return content; }
string Episode::getPodcast(){ return podcast; }
int Episode::getNumber(){return number; }


//Other functions
/*
  Function:  play
  Purpose:   Prints episode content information
   return:   nothing
*/
void Episode::play(){
  print();
  cout<< "Content: " <<endl<< getContent()<<endl;
}

/*
  Function:  print
  Purpose:   Prints episode information
   return:   nothing
*/
void Episode::print(){
  cout<<endl<<endl<<"------------Episode------------"<<endl;
  cout<<"     Name:    "<< getName() <<endl;
  cout<<"     Number:  " << getNumber() <<endl;
  cout<<"     Podcast: " << getPodcast() <<endl;
  cout<<"-------------------------------"<<endl;
}

//DONE

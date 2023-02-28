#include "Podcast.h"

//Constructors
Podcast::Podcast(const string& title, const string& host){
  setTitle(title);
  setHost(host);
  numEps = 0;
  Episode_Array = new Episode*[MAX_EPS];
}

Podcast::Podcast(Podcast& p){
  setTitle(p.title);
  setHost(p.host);

  Episode_Array = new Episode*[MAX_EPS];
  numEps = p.numEps;

  for(int i=0;i<numEps; ++i){
    Episode_Array[i] = new Episode(*(p.Episode_Array[i]));
  }
}


//Destructor
Podcast::~Podcast(){
  for(int i=0; i<numEps; ++i){
    delete Episode_Array[i];
  }
  delete [] Episode_Array;
}


//Setters
void Podcast::setTitle(string title){ this->title = title; }
void Podcast::setHost(string host){ this->host = host; }


//Getters
string Podcast::getTitle(){ return title; }
string Podcast::getHost(){ return host; }
int Podcast::getNumEpisodes(){ return numEps; }


//Other functions
/*
  Function:  addEpisode
  Purpose:   add episode to array
   in:       episode title
   in:       episode content
   out:      new episode is added to array
   return:   true for episode added, otherwise false
*/
bool Podcast::addEpisode(const string& title, const string& content){
  if(numEps < MAX_EPS){
    Episode_Array[numEps] = new Episode(this->title, numEps, title, content);
    numEps++;
    return true;
  }
  return false;
}

/*
  Function:  getEpisode
  Purpose:   find episode in array
   in:       episode index in array
   in:       episode pointee
   out:      return episode if found
   return:   true for episode found, otherwise false
*/
bool Podcast::getEpisode(int index, Episode** ep){
  if((index >= numEps) || (index < 0)){
    return false;
  }
  else{
    *ep = Episode_Array[index];
    return true;
  }
}

/*
  Function:  lessThan
  Purpose:   compare if title1 comes before title2
       in:   title2
   return:   true if title1 comes before title2, otherwise false
*/
bool Podcast::lessThan(Podcast& pod){
  if(this->title < pod.title){
    return true;
  }
  else{
    return false;
  }
}

/*
  Function:  print
  Purpose:   Prints podcast information
   return:   nothing
*/
void Podcast::print(){
  cout<<"------------Podcast------------"<<endl;
  cout<<"     Title:     " << getTitle() <<endl;
  cout<<"     Host:      " << getHost() <<endl;
  cout<<"     Episode #: " << getNumEpisodes() <<endl;
  cout<<"-------------------------------"<<endl<<endl;
}

//DONE

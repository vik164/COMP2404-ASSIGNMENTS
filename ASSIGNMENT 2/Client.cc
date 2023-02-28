#include "Client.h"

//Constructors
Client::Client(const string& name){
  this->name = name;
  pod_Array = new PodArray();
}


//Destructor
Client::~Client(){
  delete pod_Array;
}


//Other functions
/*
  Function:  download
  Purpose:   attempt to download podcast
   in:       network pointer
   in:       podcast title
   out:      if download succesful, create a copy of the podcast and add it to array
*/
void Client::download(Network* net, const string& title){
  Podcast* p;
  Podcast* pod;
  if(net->download(name, title, &p) == true){
    pod = new Podcast(*p);
    if(pod_Array->addPodcast(pod) != true){
      std::cout<<"ERROR: COULD NOT ADD PODCAST"<<endl;
    }
  }
  else{
    std::cout<<"ERROR: COULD NOT DOWNLOAD"<<endl;
  }
}

/*
  Function:  stream
  Purpose:   attempt to stream podcast
   in:       network pointer
   in:       episode title
   in:       episode number
   out:      if stream succesful, play episode
*/
void Client::stream(Network* net, const string& title, int Epi_Num){
  Episode* epi;
  if(net->stream(name, title, Epi_Num, &epi) == true){
    epi->play();
  }
}

/*
  Function:  playLocal
  Purpose:   attempt to retrieve the podcast episode from array
   in:       podcast title
   in:       episode number
   out:      if succesful, play episode
*/
void Client::playLocal(const string& title, int Epi_Num){
  Podcast* pod;
  Episode* epi;
  if(pod_Array->getPodcast(title, &pod) == true){
    if(pod->getEpisode(Epi_Num, &epi) == true){
      epi->play();
    }
    else{
      std::cout<<"ERROR: COULD NOT FIND EPISODE"<<endl;
    }
  }
  else{
    std::cout<<"ERROR: COULD NOT FIND PODCAST"<<endl;
  }
}

/*
  Function:  print
  Purpose:   Prints client information
   return:   nothing
*/
void Client::print(){
  cout<<endl<<"------------Client------------"<<endl;
  cout<<"     Name: "<< name <<endl;
  cout<<"------------------------------"<<endl;
}

//DONE

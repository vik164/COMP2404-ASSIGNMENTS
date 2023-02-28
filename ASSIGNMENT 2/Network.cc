#include "Network.h"

//Constructors
Network::Network(const string& name){
  this->name = name;
  numSubs = 0;
  pod_Array = new PodArray();
}


//Destructor
Network::~Network(){
  for(int i=0; i<numSubs; ++i){
    delete subscriber[i];
  }
  delete pod_Array;
}


//Other functions
/*
  Function:  getPodcast
  Purpose:   find podcast in array
   in:       podcast title
   in:       podcast pointee
   out:      return podcast if found
   return:   true for podcast found, otherwise false
*/
bool Network::getPodcast(const string& title, Podcast** pod){
  if(pod_Array->getPodcast(title, pod) == true){
    return true;
  }
  return false;
}

/*
  Function:  addPodcast
  Purpose:   add podcast to array
   in:       podcast title
   in:       podcast host
   out:      new podcast is added to array
   return:   true for podcast added, otherwise false
*/
bool Network::addPodcast(const string& title, const string& host){
  Podcast* Add_Pod;
  Add_Pod = new Podcast(title, host);
  if(pod_Array->addPodcast(Add_Pod) == true){
    return true;
  }
  return false;
}

/*
  Function:  removePodcast
  Purpose:   remmove podcast from array
   in:       podcast title
   out:      podcast is deleted from array
   return:   true for podcast deleted, otherwise false
*/
bool Network::removePodcast(const string& title){
  Podcast* Rem_Pod;
  if(pod_Array->removePodcast(title, &Rem_Pod) == true){
    delete Rem_Pod;
    return true;
  }
  return false;
}

/*
  Function:  addEpisode
  Purpose:   add episode to array
   in:       podcast title
   in:       episode title
   in:       episode content
   out:      new episode is added to array
   return:   true for episode added, otherwise false
*/
bool Network::addEpisode(const string& pod, const string& title, const string& content){
  Podcast* Get_Pod;
  if(getPodcast(pod, &Get_Pod) == true){
    if(Get_Pod->addEpisode(title, content) == true){
      return true;
    }
  }
  return false;
}

/*
  Function:  addSubscriber
  Purpose:   add subscriber to array
   in:       subscriber name
   in:       subscriber creditcard
   out:      new subscriber is added to array
   return:   true for subscriber added, otherwise false
*/
bool Network::addSubscriber(const string& name, const string& creditcard){
  if(numSubs < MAX_SUBS){
    subscriber[numSubs] = new Subscriber(name, creditcard);
    numSubs++;
    return true;
  }
  return false;
}

/*
  Function:  download
  Purpose:   checks if the provided subscriber and podcast exist
   in:       subscriber name
   in:       podcast title
   in:       podcast pointer
   out:      return podcast if found
   return:   true for podcast found, otherwise false
*/
bool Network::download(const string& sub, const string& title, Podcast** pod){
  Podcast* Find_Pod;
  if(hasSubscriber(sub) == true){
    if(getPodcast(title, &Find_Pod) == true){
      *pod = Find_Pod;
      return true;
    }
    else{
      std::cout<<"ERROR: NO SUCH PODCAST"<<endl;
      return false;
    }
  }
  else{
    std::cout<<"ERROR: NO SUCH SUBSCRIBER"<<endl;
    return false;
  }
}

/*
  Function:  stream
  Purpose:   checks if the provided subscriber, podcast and episode number exist
   in:       subscriber name
   in:       podcast title
   in:       episode number
   in:       episode pointer
   out:      return episode if found
   return:   true for episode found, otherwise false
*/
bool Network::stream(const string& sub, const string& pod, int ep_num, Episode** ep){
  Episode* Find_Epi;
  Podcast* Find_Pod;

  if(hasSubscriber(sub) == true){
    if(getPodcast(pod, &Find_Pod) == true){
      if(Find_Pod->getEpisode(ep_num, &Find_Epi) == true){
        *ep = Find_Epi;
        return true;
      }
      else{
        std::cout<<"ERROR: NO SUCH EPISODE"<<endl;
        return false;
      }
    }
    else{
      std::cout<<"ERROR: NO SUCH PODCAST"<<endl;
      return false;
    }
  }
  else{
    std::cout<<"ERROR: NO SUCH SUBSCRIBER"<<endl;
    return false;
  }
}

/*
  Function:  hasSubscriber
  Purpose:   checks if subscriber is in array
       in:   subscriber name
   return:   true if subscriber exists, otherwise false
*/
bool Network::hasSubscriber(const string& name){
  for(int i=0; i<numSubs; ++i){
    if(subscriber[i]->matches(name) == true){
      return true;
    }
  }
  return false;
}

/*
  Function:  print
  Purpose:   Prints network information
   return:   nothing
*/
void Network::print(){
  cout<<endl<<"----------------NETWORK----------------"<<endl;
  cout<<"     Name:        "<< name <<endl;
  cout<<"     Subscribers: "<< numSubs <<endl;
  cout<<"---------------------------------------"<<endl;
}

//DONE

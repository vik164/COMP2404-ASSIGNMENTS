/*
VIKRANT KUMAR 101195442

This program allows the user to experience a streaming podcast network, which consists of podcasts and episodes.
*/
#include <iostream>
#include "Podcast.h"
#include "TestControl.h"

using namespace std;

int main(){

	TestControl* control = new TestControl();

	control->launch();

	delete control;
	return 0;

}

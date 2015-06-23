#include <iostream>
#include "MenuState.h"
#include <vector> 		/* vector array */
#include <sstream>		/* system() function(s) */
#include <stdlib.h>     /* atoi */
#include <cstdlib>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>		/* sleep() */

/*
 *@Author: James Child
 * Jan-April 2015
 * NRDS Main Function
 */

using namespace std;
MenuState *ms;// = new MenuState()
int main(){
	ms = new MenuState();
	ms->run_options();
	return 0;
}




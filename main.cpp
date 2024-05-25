using namespace std;
#include "kssolver.h"

int main(){
    	ksparser Parser1("ks_4_0.txt");
    	Parser1.ksparser_f();
    	kssolver Solver1(&Parser1);
	return 0;
}

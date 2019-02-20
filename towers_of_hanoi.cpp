//Nick Nowak
//This program solves Towers of Hanoi iteratively with stacks of abstract class Item (cast as IntItems)

#include <iostream>
#include <string>
#include <cstdlib>
#include "Stack.h"
#include "LLStack.h"
#include "IntItem.h"

using namespace std;

//Gets top disk value of specified pole.
int get(LLStack * pole) {
	if (pole->ISEMPTY()) return NULL;
	else {
		IntItem * disk = (IntItem *)pole->GANDER();
		return disk->gets();
	}
}

//Moves disk to destination.
void moveDisk(LLStack * srcpole, LLStack * destpole) {
	int src = get(srcpole);
	destpole->PUSH(srcpole->POP());
}

//Determines if moving between source and destination is legal.
bool isLegalMove(LLStack * srcpole, LLStack * destpole) {
	if (get(srcpole) == 0) return false;
	if (destpole->ISEMPTY()) return true;
	if (srcpole->ISEMPTY()) return false;
	else {
		int s = get(srcpole); int d = get(destpole);
		return (s < d);
	}
}

//Either moves the source disk to destination, or the other way around.
LLStack * makeLegalMove(LLStack * srcpole, LLStack * destpole) {
	if (isLegalMove(srcpole, destpole)) {
		int src = get(srcpole);
		moveDisk(srcpole, destpole); 
		cout << "Moved disk " << src;
		return destpole; 
	
	}
	else if (isLegalMove(destpole, srcpole)){
		int src = get(destpole);
		moveDisk(destpole, srcpole);
		cout << "Moved disk " << src; return srcpole;
	}
}

int main(int argc, char **argv) {
	int disks; 
	
	LLStack * A = new LLStack(); 
	LLStack * B = new LLStack();  
	LLStack * C = new LLStack();

	cout << "How many disks? ";
	cin >> disks; cout << endl;

	for (int i = disks; i > 0; i--) 
		A->PUSH(new IntItem(i));
	
	int moves = 0;
	int numMoves = pow(2, disks) - 1;

	while (moves < numMoves){
		//If disks are even, follow 3-step pattern and break when number of moves is reached.
		if ((disks % 2) != 0) {
			LLStack *tn = makeLegalMove(A, C); 
			if (tn == A) cout << " to pole A" << endl;
			if (tn == C) cout << " to pole C" << endl;
			moves++;

			tn = makeLegalMove(A, B);
			if (tn == A) cout << " to pole A" << endl;
			if (tn == B) cout << " to pole B" << endl;
			moves++;

			tn = makeLegalMove(B, C);
			if (tn == B) cout << " to pole B" << endl;
			if (tn == C) cout << " to pole C" << endl;
			moves++;
		}
		
		//If number of disks are odd, follow corresponding 3-step pattern.
		else {
			LLStack * tn = makeLegalMove(A, B);
			if (tn == A) cout << " to pole A" << endl;
			if (tn == B) cout << " to pole B" << endl;
			moves++;

			tn = makeLegalMove(A, C); 
			if (tn == A) cout << " to pole A" << endl;
			if (tn == C) cout << " to pole C" << endl;
			moves++;

			tn = makeLegalMove(B, C); 
			if (tn == B) cout << " to pole B" << endl;
			if (tn == C) cout << " to pole C" << endl;
			moves++;
		}


	}

	system("pause");
	return 0;
}

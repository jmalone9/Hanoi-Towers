#include <iostream>
#include <vector> 
#include <cstring>

using namespace std;

vector<int> rod1; 
vector<int> rod2; 
vector<int> rod3; 
bool printMoves = false;

void displayRods(){
		cout << "outputing rod1: ";
		for (int x : rod1) 
			cout << x << " "; 
		cout << "\n";
		cout << "outputing rod2: ";
		for (int x : rod2) 
			cout << x << " "; 
		cout << "\n";
		cout << "outputing rod3: ";
		for (int x : rod3) 
			cout << x << " "; 
		cout << "\n";
}

void towerSolver(int diskCount, int startRod, int endRod, int spareRod){
	int temp;
	if (diskCount == 0) { 
        return; 
    } 
	towerSolver(diskCount - 1, startRod, spareRod, endRod); 
	//move current disk to another rod
		switch(startRod) {
		case 1:
			temp = rod1.back();
			rod1.pop_back();
			switch(endRod) {
				case 1:
					rod1.push_back(temp);
					break;
				case 2:
					rod2.push_back(temp);
					break;
				case 3:
					rod3.push_back(temp);
					break;
			}
		break;
		case 2:
			temp = rod2.back();
			rod2.pop_back();
			switch(endRod) {
				case 1:
					rod1.push_back(temp);
					break;
				case 2:
					rod2.push_back(temp);
					break;
				case 3:
					rod3.push_back(temp);
					break;
			}
		break;
		break;
		case 3:
			temp = rod3.back();
			rod3.pop_back();
			switch(endRod) {
				case 1:
					rod1.push_back(temp);
					break;
				case 2:
					rod2.push_back(temp);
					break;
				case 3:
					rod3.push_back(temp);
					break;
			}
}
	if(printMoves == true){
		cout << "========================\nMovement\n========================\n";
		displayRods();	
	}
    towerSolver(diskCount - 1, spareRod, endRod, startRod); 
}

//populate the starting rod by adding numbers diskCount to 1 to one of the rods
void populateRods(int diskCount, int startRod){
		switch(startRod) {
		case 1:
			for(int i = diskCount; i >= 1; i--){
				rod1.push_back(i);
			}
		break;
		case 2:
			for(int i = diskCount; i >= 1; i--){
				rod2.push_back(i);
			}
		break;
		case 3:
    		for(int i = diskCount; i >= 1; i--){
			rod3.push_back(i);
			}
		break;
		}
}

int main(int argc, char *argv[]) {
	//Default Values
	int diskCount = 3;
	int startRod = 1;
	int endRod = 3;
	int spareRod = 2;
	
	//user args
	//use: diskCount, startRod, endRod, verbose flag as "-v"
	//alt use: diskCount, verbose flag as "-v"
	if(argc > 1){
		diskCount = atoi(argv[1]);
		if(argc >= 4){
			startRod = atoi(argv[2]);
			endRod = atoi(argv[3]);
			spareRod = (6 - (startRod + endRod));
			if(argc >= 5 && (strcmp(argv[4],"-v")==0)){
				printMoves = true;
			}
		}
		else if(argc == 3 && (strcmp(argv[2],"-v")==0)){
			printMoves = true;
		}
	}
	
	//test output
	cout << "diskCount: " << diskCount << " startRod: " << startRod << " endRod: " << endRod << " spareRod: " << spareRod << "\n";
	
	//populate the rods
	populateRods(diskCount, startRod);
	
	//display start
	cout << "========================\nStarting Set\n========================\n";
	displayRods();
	//solve the towers
	towerSolver(diskCount, startRod, endRod, spareRod);
	//display end
	cout << "========================\nEnding Set\n========================\n";
	displayRods();
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct Block
{
	int fileid;
	bool allocated;
};

int ceil(int a, int b){
	if(a%b!=0){
		return (a/b)+1;
	}
	else{
		return (a/b);
	}
}
int main(){
	int BlockSize,Numberofblocks;
	cout<< "Enter number of blocks:  ";
	cin >> Numberofblocks;

	cout<< "Enter block size: ";
	cin >> BlockSize;

	struct Block blocks[Numberofblocks];

	for(int i=0;i<Numberofblocks;i++){
		blocks[i].allocated=false;
	}	

	int size=0;

	while(size<BlockSize*Numberofblocks){
		cout << "Enter -1 to exit";
		int temp,fsize,start,id;
		cin >> temp;
		if(temp==-1)
			break;
		cout<< "Enter file id,file size and starting block index:  ";
		cin >> id >> fsize >> start;

		if(blocks[start].allocated==true){
			cout << "Not Possible\n";
		}
		else{
			int ans = ceil(fsize,BlockSize);
			if((start+ans-1)<Numberofblocks){
			while(ans && start<=Numberofblocks){
				blocks[start].allocated=true;
				blocks[start++].fileid=id;
				ans--;
				size+=BlockSize;
			}
		}

			/*if(fsize%BlockSize!=0 && start<=Numberofblocks){
				blocks[start].allocated=true;
				blocks[start].fileid=id;
			}
			if (fsize%BlockSize!=0 && start>Numberofblocks){

			}*/

		}
		for(int i=0;i<Numberofblocks;i++){

			if(blocks[i].allocated==true){
				cout << i << "\t\t"<<blocks[i].fileid<<endl;
			}
			else{
				cout << i<< "\t\t empty"<< endl;
			}
		}


	}
	
}
#include <bits/stdc++.h>

using namespace std;
int Numberofblocks;
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
int empty(struct Block a[]){
	int i,count=0;
	for(i=0;i<Numberofblocks;i++){
		if(a[i].allocated==false){
			count++;
		}
	}
	return count;
}
int main(){
	int BlockSize;
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
			//cout << ans<< endl;
			int check1 = empty(blocks);
			//cout << check1 << endl;
			int current = start;
			if(ans<=check1){
				while(ans){
					blocks[current].allocated = true;
					blocks[current].fileid=id;
					ans--;
					if(ans==0){
						break;
					}
					while(blocks[current].allocated==true){
						current = rand()%Numberofblocks;
						//cout << current << endl;
					}
					}
				}
			
			else{
				cout << "Cannot be allocated\n";
			}
		}

			/*if(fsize%BlockSize!=0 && start<=Numberofblocks){
				blocks[start].allocated=true;
				blocks[start].fileid=id;
			}
			if (fsize%BlockSize!=0 && start>Numberofblocks){

			}*/

		
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
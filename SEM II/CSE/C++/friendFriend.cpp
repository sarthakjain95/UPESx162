#include<iostream>
#include<ctime>
using namespace std;

class BlockchainBlock{

	time_t creation_time;
	int senderID, receiverID;
	float amount;

	public:

		BlockchainBlock(int sid, int rid, float amount){
			creation_time= time(0);
			senderID= sid;
			receiverID= rid;
			this->amount= amount;
		}

		friend class BlockInterface;
		friend time_t getBlockTime(BlockchainBlock &bx);
};

time_t getBlockTime(BlockchainBlock &bx){
	return bx.creation_time;
}

class BlockInterface{

	public:

		// ... 

		void printBasicDetails(BlockchainBlock bx){
			cout<<"\nBlock creation time: "<<bx.creation_time;
			// printf("\nSender ID: 0x%x", bx.senderID);
			// printf("\nReceiver ID: 0x%x", bx.receiverID);
			printf("\nAmount: %.2f\n", bx.amount);
		}

};

int main() {

	BlockchainBlock bx(0x112, 0x118, 15.56);
	BlockInterface bx_interface;

	bx_interface.printBasicDetails(bx);
	cout<<"\nAgain. \nBlock creation time was:"<<getBlockTime(bx)<<endl;

	return 0;
}
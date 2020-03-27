
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// bool isEven(const int& x){ return !(x%2); }

int main(){

	vector<int> foobar= {23,234,23,56,234,652,34,235,32,423,4,234,23432};
	cout<<"Size of vector: "<<foobar.size()<<endl;

	for(std::size_t i = 0; i < foobar.size(); ++i) cout<<foobar[i]<<" ";

	cout<<endl;
	cout<<"\nFirst Element:"<<foobar.front()<<endl;
	cout<<"Last Element:"<<foobar.back()<<endl;

	// foobar.front()= 3;
	// foobar.back()= 3;

	if( !foobar.empty() ) cout<<"Vector is not empty!"<<endl;
	else cout<<"Vector is empty!"<<endl;

	foobar.pop_back();
	foobar.pop_back();
	foobar.pop_back();

	cout<<"\nReversing Vector"<<endl;
	for(size_t i=0; i<foobar.size()/2; i++){
		int temp= foobar.front();
		foobar.front()= foobar.back();
		foobar.back()= temp;
	}
	for(const auto& i : foobar) cout<<i<<" ";
	cout<<endl;

	int * arr= foobar.data();
	cout<<"\nConvert To Array! First element is:"<<*arr<<endl;


	cout<<"\nRemoving 23 from the vector!"<<endl;
	foobar.erase( remove(foobar.begin(), foobar.end(), 23), foobar.end() );
	for(const auto& i : foobar) cout<<i<<" ";
	cout<<endl;

	cout<<"\nRemoving Even Values from the vector!"<<endl;
	foobar.erase( remove_if(foobar.begin(), foobar.end(),  [](int x) { return !(x%2); }), foobar.end() );
	// foobar.erase( remove_if(foobar.begin(), foobar.end(),  isEven), foobar.end() );
	for(const auto& i : foobar) cout<<i<<" ";
	cout<<endl;

	cout<<"\nErasing Vector!"<<endl;
	foobar.clear();

	if( !foobar.empty() ) cout<<"Vector is not empty"<<endl;
	else cout<<"Vector is empty"<<endl;

	return 0;
}

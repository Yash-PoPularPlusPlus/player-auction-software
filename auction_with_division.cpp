#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) x.begin(),x.end()
#define vf first 
#define vs second
const int mod = 1000000007;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N = 10;
int number_of_captains;
vector<string> teams[N];
map<string,int> captains;
vector<string> v;

void round_robin(){
	shuffle(all(v),RNG);
	for(int i = 0; i < v.size(); i++){
		cout << "Captain Name" << endl << endl;
		string s;
		cin >> s;
		transform(all(s),s.begin(),::tolower);
		int pos = captains[s];
		while(pos == 0){
			cout << "Wrong Captain Name, Please Input correct Spelling" << endl << endl;
			cin >> s;
			cout << endl << endl;
			transform(all(s),s.begin(),::tolower);
			pos = captains[s];
		}

		cout << "Player Sold - " << v[i] << endl << endl;
		teams[pos].pb(v[i]);
	}
}

void print_teams(){
	for(int i = 1; i <= number_of_captains; i++){
		cout << "Team- " << i << "  ";
		for(int j = 0; j < teams[i].size(); j++){
			cout << teams[i][j] << "  ";
		}
		cout << endl << endl;
	}
}

void conti(){
	cout << "Please enter 'y' to continue" << endl << endl;
	string c;
	cin >> c;
	cout << endl << endl;
	if(c != "y"){
		cout << "Please enter 'y' for random distribution of unsold players" << endl << endl;
		string s;
		cin >> s;
		if(s == "y"){
			round_robin();
			print_teams();
			exit(0);
		}
		else {
			cout << "Please enter 'end' to end the auction" << endl << endl;
			string s;
			cin >> s;
			transform(all(s),s.begin(), ::tolower);
			if(s == "end"){
				print_teams();
				exit(0);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << "Lets start the auction of 13-17 age group Cricket" << endl << endl << endl;

	cout << "Pls enter number of captains" << endl << endl;
	cin >> number_of_captains;

	for(int i = 1; i <= number_of_captains; i++){
		cout << "Name of Captain " << i << ": " << endl << endl;
		string s;
		cin >> s;
		transform(all(s),s.begin(),::tolower);
		teams[i].pb(s);
		cout << endl << endl;	
		captains[s] = i;
	}


	cout << "Please enter number of players" << endl << endl;
	int n;
	cin >> n;
	cout << endl << endl;

	cout << "Pls enter the number of rounds" << endl << endl;

	int number_of_round;
	cin >> number_of_round;

	cout << "Initial Price each Captain has: " << endl << endl;
	int x;
	cin >> x;
	cout << endl << endl;

	int arr[number_of_captains+1];
	for(int i = 1; i <= number_of_captains; i++)arr[i] = x;
	cout << endl;
	int cnt[number_of_captains+1];


	cout << "Minimum number of players captain needs to buy:" << endl << endl;
	int players;
	cin >> players;
	cout << endl << endl;

	for(int i = 1; i <= number_of_captains; i++)cnt[i] = players;

	cout << "Base Price of Each Player:" << endl;
	int baseprice;
	cin >> baseprice;
	cout << endl << endl;

	int max_bid[number_of_captains+1];
	for(int i = 1; i <= number_of_captains; i++){
		max_bid[i] = arr[i] - (cnt[i]-1)*baseprice;
	}

	for(int i = 1; i <= number_of_captains; i++){
		cout << teams[i][0] << ": Money Remaining - " << arr[i] << " , Maximum bid possible: " << max_bid[i] << endl << endl;
	}

while(number_of_round--){
	cout << "Number of players in this round" << endl << endl;
	int round_players;
	cin >> round_players;

	v.clear();
	for(int i = 1; i <= round_players; i++){
		cout << "Name of Player " << i << ": " << endl << endl;
		string s;
		cin >> s;
		v.pb(s);
		cout << endl << endl;
	}

	shuffle(all(v),RNG);

	/*cout << "Minimum increment: " << endl << endl;
	int inc;
	cin >> inc;
	cout << endl << endl;*/

	conti();

	vector<string> unsold;
while(v.size()){
	for(int i = 0; i < (int)v.size(); i++){
		cout << "Player Name - " << v[i] << endl << "Price sold at:" << endl << endl;
		int val;
		cin >> val;
		cout << endl;
		if(val == -1){
			unsold.pb(v[i]);
			cout << endl;
			continue;
		}
		else {
			cout << "Sold to which captain: " << endl << endl;
			string s;
			cin >> s;
			transform(all(s),s.begin(),::tolower);
			cout << endl << endl;
			int pos = captains[s];
			while(pos == 0){
				cout << "Wrong Captain Name, Please Input correct Spelling" << endl << endl;
				cin >> s;
				cout << endl << endl;
				transform(all(s),s.begin(),::tolower);
				pos = captains[s];
			}
			teams[pos].pb(v[i]);
			cnt[pos]--;
			arr[pos] -= val;
			if(cnt[pos] == 0){
				max_bid[pos] = arr[pos];
			}
			else max_bid[pos] = arr[pos] - baseprice*(cnt[pos]-1);

			for(int i = 1; i <= number_of_captains; i++){
				cout << teams[i][0] << ": Money Remaining - " << arr[i] << " , Maximum bid possible: " << max_bid[i] << endl << endl;
			}
			conti();
		}
	}
	v = unsold;
	if(unsold.size() == 0){
		cout << "All Players Are Sold" << endl << endl;
		break;
	}
	shuffle(all(v),RNG);
	unsold.clear();
	cout << "Unsold Players are coming back" << endl;

	conti();
}
}
	
	print_teams();

	return 0;
}
#include<bits/stdc++.h>
using namespace std ;

#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi = acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VC> VVC;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

void c_p_c() {
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}
// Checking if the current placement queen satisfies the condition
bool isSafe( VVC& graph , int row , int col ) {
	int i , j , n = graph.size() ;
	for ( int i = col ; i >= 0 ; i-- ) {
		if ( graph[row][i] == '1' ) {
			return false ;
		}
	}

	for ( int i = row , j = col ; i >= 0 && j >= 0 ; i-- , j-- ) {
		if (graph[i][j] == '1') {
			return false ;
		}
	}

	for ( int i = row , j = col ; i < n && j >= 0 ; i++ , j-- ) {
		if (graph[i][j] == '1') {
			return false ;
		}
	}

	return true ;
}

// Solving the graph for each of the column
bool solve( VVC& graph , int col ) {

	int n = graph.size() ;

	if (col >= n) return true ;

	for ( int i = 0 ; i < n ; i++ ) {
		if (isSafe(graph, i, col)) {
			graph[i][col] = '1' ;
			if (solve(graph, col + 1) ) {
				return true ;
			}
			graph[i][col] = '0' ;
		}
	}
	return false ;
}

// Printing the graph
void print_graph( VVC& graph ) {

	for ( int i = 0 ; i < graph.size() ; i++) {
		for ( int j = 0 ; j < graph[0].size() ; j++) {
			if (graph[i][j] == '1')
				cout << "Q" << " " ;
			else
				cout << "*" << " " ;
		}
		cout << endl;
	}
}

int main() {

	c_p_c() ;

	int n ; cin >> n ;

	for ( int i = 0 ; i < n ; i++ ) {
		int k ; cin >> k ;
		VVC graph(k , VC(k, '0')) ;
		solve(graph, 0) ;
		print_graph(graph) ;
		cout << endl ;
	}

}

//template

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

#define ll                       long long int
#define ld                       long double
#define mod                      1000000007
#define inf                      1e18
#define endl                     "\n"
#define pb                       push_back
#define vi                       vector<ll>
#define vs                       vector<string>
#define pii                      pair<ll,ll>
#define ump                      unordered_map
#define mp                       make_pair
#define pq_max                   priority_queue<ll>
#define pq_min                   priority_queue<ll,vi,greater<ll> >
#define all(n)                   n.begin(),n.end()
#define ff                       first
#define ss                       second
#define mid(l,r)                 (l+(r-l)/2)
#define bitc(n)                  __builtin_popcount(n)
#define SET(a)                   memset( a, -1, sizeof a )
#define CLR(a)                   memset( a,  0, sizeof a )
#define Pi                       3.141592653589793
#define loop(i,a,b)              for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)           for(int i=(a);i>=(b);i--)
#define _fast                    ios_base::sync_with_stdio(0);  cin.tie(0);
#define iter(container,it)       for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)             {string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)          for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
template <typename T> T          gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T          lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
cout << *it << " = " << a << endl;
err(++it, args...);
}


/*Equilibrium index of an array is an index such that the sum of elements at lower 
indexes is equal to the sum of elements at higher indexes. For example, in an array A: 
Input: A[] = {-7, 1, 5, 2, -4, 3, 0} 
Output: 3 
3 is an equilibrium index, because: 
A[0] + A[1] + A[2] = A[4] + A[5] + A[6]

Input: A[] = {1, 2, 3} 
Output: -1 
*/
// int Equilibrium_Index(int a[],int n) {
//       if (n==1) return 1;
//         int prefix_sum[n],suffix_sum[n];
//         prefix_sum[0]=a[0];
//         for (int i=1;i<n;i++) {
//             prefix_sum[i] = prefix_sum[i-1] + a[i];
//         }
//         for (int i=0;i<n;i++) {
        
//             if (i+1 != n && prefix_sum[i] == (prefix_sum[n-1]-prefix_sum[i+1]))
//                 return i+1;
//         }
//         return -1;

// }

// C++ program to find equilibrium index of an array
#include <bits/stdc++.h>
using namespace std;

int equilibrium(int a[], int n)
{
	if (n == 1)
		return (0);
	int forward[n] = { 0 };
	int rev[n] = { 0 };

	// Taking the prefixsum from front end array
	for (int i = 0; i < n; i++) {
		if (i) {
			forward[i] = forward[i - 1] + a[i];
		}
		else {
			forward[i] = a[i];
		}
	}

	// Taking the prefixsum from back end of array
	for (int i = n - 1; i > 0; i--) {
		if (i <= n - 2) {
			rev[i] = rev[i + 1] + a[i];
		}
		else {
			rev[i] = a[i];
		}
	}

	// Checking if forward prefix sum
	// is equal to rev prefix
	// sum
	for (int i = 0; i < n; i++) {
		if (forward[i] == rev[i]) {
			return i;
		}
	}
	return -1;

	// If You want all the points
	// of equilibrium create
	// vector and push all equilibrium
	// points in it and
	// return the vector
}

// Driver code
int main()
{
	int arr[] = { -7, 1, 5, 2, -4, 3, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "First Point of equilibrium is at index "
		<< equilibrium(arr, n) << "\n";
	return 0;
}


// int main(int argc, char const *argv[]){
//     _fast
//     int arr[] = {-7,1,5,2,-4,3,0};
//    cout << Equilibrium_Index(arr,7);
//   return 0;
// }
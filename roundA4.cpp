// @author cebrusfs
// headers {{{
#include<bits/stdc++.h>
using namespace std;
// }}}
// macros {{{
#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(x) (sort(ALL(x)), ((x).erase(unique(ALL(x)), (x).end())))
#define MS(x, v) std::fill(ALL(x), (v));

#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)

#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> PII;
#define MP make_pair
#define F first
#define S second

typedef vector<int> VI;
#define PB push_back
#define PF push_front

#define PPB pop_back
#define PPF pop_front

#define runtime() ((double)clock() / CLOCKS_PER_SEC)

const double eps = 1e-7;

// C++11
#if __cplusplus >= 201103L
#define MT make_tuple
typedef tuple<int, int> TII;

// dump {{{
template<typename T>
void _dump(const char* s, T&& head) {
    cerr<< s << "=" << head << endl;
}
 
template<typename T, typename... Args>
void _dump(const char* s, T&& head, Args&&... tail) {
    int c = 0;
    while (*s!=',' || c!=0) {
        if (*s=='(' || *s=='[' || *s=='{') c++;
        if (*s==')' || *s==']' || *s=='}') c--;
        cerr << *s++;
    }
    cerr << "=" << head << ", ";
    _dump(s+1, tail...);
}
 
#ifdef FISH
#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0);
#else
#define dump(...) ;
#endif
 
template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}
 
template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
// }}}
#endif
// }}}

struct pairhash {
    public:
        template <typename T, typename U>
            std::size_t operator()(const std::pair<T, U> &x) const
            {
                return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
            }
};


#define MAX 100005

const int LIMIT = 1e9;

// R, D, L, U
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int act[MAX][2];

void solve(int caseid)
{
    fprintf(stderr, "solve at Case %d ... \n", caseid);

    unordered_map<PII, int, pairhash> mp;
    unordered_set<PII, pairhash> vis;

    int m, R, C;
    scanf("%d %d %d", &m, &R, &C);
    for (int i = 0; i < m; ++i)
    {
        int x;
        char c;
        scanf("%d %c", &x, &c);
        act[i][0] = x;
        act[i][1] = c == 'R';
    }

    int pos = 0;

    int d = 0;
    int x = 1, y = 1;
    int l = 1;
    int cnt = 0;

    for (int i = 1; i <= LIMIT; ++i)
    {
        if (pos == m and cnt >= R + R and cnt >= C + C)
        {
            fprintf(stderr, "timeout end\n");

            fprintf(stderr, "i = %d\n", i);
            fprintf(stderr, "x, y = (%d, %d), d = %d\n", x, y, d);
            fprintf(stderr, "length = %d\n", l);
            fprintf(stderr, "pos = %d, cnt = %d\n", pos, cnt);
            break;
        }

        // move
        x += dx[d];
        y += dy[d];

        // loop
        if (x <= 0) x = R;
        if (x > R) x = 1;

        if (y <= 0) y = C;
        if (y > C) y = 1;


        PII p = MP(x, y);
        if ((x + y) & 1 and not vis.count(p))
        {
            vis.insert(p);
            l += 1;
            cnt = 0;
        }

        // check end
        int last = mp[p];
        if (last == 0) last = -10;

        if (i - l < last)
        {
            fprintf(stderr, "touch self end\n");

            fprintf(stderr, "i = %d, last = %d\n", i, last);
            fprintf(stderr, "x, y = (%d, %d), d = %d\n", x, y, d);
            fprintf(stderr, "length = %d\n", l);
            fprintf(stderr, "pos = %d, cnt = %d\n", pos, cnt);
            break;
        }
        mp[p] = i;

        // action
        if (pos < m and act[pos][0] == i)
        {
            if (act[pos][1])
                d = (d + 1) % 4;
            else
                d = (d + 3) % 4;

            pos++;
            cnt = 0;
        }
        cnt ++ ;
    }
    printf("Case #%d: %d\n", caseid, l);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        solve(i);
}


/*
-----------------------------------------------------------------------------
Author :            ---------------------------------------------------------
    UTKAR$H $AXENA  ---------------------------------------------------------
    IIT INDORE      ---------------------------------------------------------
-----------------------------------------------------------------------------
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("0.in","r",stdin),freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define lld signed long long int
#define pp pop_back()
#define ps(x) push_back(x)
#define mpa make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define boost ios_base::sync_with_stdio(0)
//vector<int> g[2*100000+5];int par[2*100000+5];
deque<pii >Q;
set<pii >snake,food;
int alright,direction,T,R,C;
void play(){
	pii head = Q.front();
	pii to;
	switch(direction){
	case 1:
		to = mpa(head.fi-1,head.se);
		break;
	case 2:
		to = mpa(head.fi,head.se+1);
		break;
	case 3:
		to = mpa(head.fi+1,head.se);
		break;
	case 4:
		to = mpa(head.fi,head.se-1);
		break;
	}
	if(to.fi==0)
		to.fi=R;
	if(to.fi==R+1)
		to.fi=1;

	if(to.se==0)
		to.se=C;
	if(to.se==C+1)
		to.se=1;
	int x = to.fi;
	int y = to.se;
	if((x+y)%2==1 and food.find(to)==food.end()){
		food.insert(to);
		if(snake.find(to)!=snake.end()){
			alright=0;
			return;
		}
		Q.push_front(to);
		snake.insert(to);
	}
	else{
		pii tail = Q.back();
		if(snake.find(to)!=snake.end() and to!=tail){
			alright = 0;
			return;
		}
		snake.erase(tail);
		snake.insert(to);
		Q.pop_back();
		Q.push_front(to);
	}
}
int what[1000000+100000+5];
void init(){
	alright=1;
	direction = 2;

	T = 1000000+100000;
	for(int i=1;i<=T;++i)
		what[i]=0;
	while(not Q.empty())
		Q.pop_back();
	snake.clear();
	food.clear();
}
lld solve(){
	int S;
	init();

	Q.push_front(mpa(1,1));
	snake.insert(mpa(1,1));

	cin>>S>>R>>C;
	int t;
	char c;
	for(int i=1;i<=S;++i){
		cin>>t>>c;
		if(c=='R')
			what[t] = 1;
		else
			what[t] = -1;
	}
	for(int i=1;i<=T and alright;++i){
		play();

		if(what[i]!=0){
			direction = direction + what[i];
			if(direction==0)
				direction = 4;
			if(direction==5)
				direction=1;
		}
		//cout<<i<<' '<<direction<<endl;
		//cout<<i<<'\t'<<Q.front().fi<<' '<<Q.front().se<<'\t'<<Q.back().fi<<' '<<Q.back().se<<endl;
	}
	return Q.size();
}
int main()
{
	freopen("0.in","r",stdin);
	freopen("0.out","w",stdout);

	int T,test = 0;
	cin>>T;

	while(T--){
		test++;
		printf("Case #%d: %lld\n",test,solve());
	}
}


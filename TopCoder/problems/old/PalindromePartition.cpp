using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << (x) << endl

class PalindromePartition {
  public:
  int partition(vector <string> s);

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AAAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, partition(Arg0)); }
	void test_case_1() { string Arr0[] = {"ABCDEFGH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, partition(Arg0)); }
	void test_case_2() { string Arr0[] = {"QWERTY","TREWQWERT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, partition(Arg0)); }
	void test_case_3() { string Arr0[] = {"BBCDDECAECBDABADDCEBACCCBDCAABDBADD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 22; verify_case(3, Arg1, partition(Arg0)); }
	void test_case_4() { string Arr0[] = {"GKTQWLBWOGQCGERTMYHENNMGUNCAIRFDTPGZFRSHTEAKUGBAIJ",
"BLMJJGQYQRRSASFRMRDCUSEVUJYUXGQEZKRLGKVCGFAFVGGPFA",
"TRRCIACXCMLWOUHJNZSKXYCBPUMNLMEMWBGWTWBAKUBWICDQCB",
"SMLRETHSDQQSYGWOOXERMRLXRPFZMPBINEFSFPOAHGQXXSTHBP",
"HYDRLSLYQSDKSHTRZRYBJNVMLVGBZBQVZKPZHUVGDQUKXCMNQL",
"UMKPXWCNCNUKJWFAGKKMUHHMWSCPYTGADEXMBLSGJIXOUNZYJS",
"UWLIUAUPILVXVTDKQBETPLVPSMSZMQBTBQKEKJTCFXEYPCULBZ",
"MSZVBLBVJAXRGFLJNYAUSJZBHIUVAODPOUJGNZNBFUOWTVSEBK",
"PVPNMRYZVVNXNYHYGXOHGFFZXHFGHBQPFFCOEEDHEHWRJVYMFB",
"HJYENRLFBEEPCGBWVNAUGCJPKYMRDHAHQGXMRMTCREYEUJIZDJ",
"PKATAIKXGVURLLNXAKQMOSDXTWHNKYICFSOAYIYOQCELIKPGVY",
"QEPXOVKMNUSILPOZFEYPZZEFYVTMIEKVGOVWSOFNWOUZLUBJVZ",
"YKGECOBOSBCQKLKDFYINFGXWGYDMSPLPAFKCDEVVLUDKEZKUUS",
"YFXORCWLCPCFNSFSXTPYYIENMINHWYSAYCMELEKBVVJKXLUWAZ",
"MIKDHLAEYYTMIVOMQLYLUJQAHERLBSYSIPNXGTMRNGITXKVVSN",
"FUAJSWGDITKRQVFSBRPAKPXGIOYESLRFOKEEZCDRRYIHYBXKYZ",
"YAHPHSREYWYPZBREMDIJOXYZKIOHSBRVCQKJPATIPIDQVISHFV",
"MIQRPJIVZFNUWRUDTNEKGHOSSSVAYMSBXPCMMCWZPQXKRNBXKP",
"DTERSIZDKVFWNVATGPVNXFQDXNMSVOCGBRXRZSCAIENECIAIBZ",
"EPLGCMGLAEGXMYENDYHQZOEEJLFCZVZIJPLXYHFCJGNABFHIYN",
"WDMVASMIOSUUFCSLDIWDQFBTZEDNUXTZUJHYNJYUACGQJKTJSU",
"MPBHUYYXXISSHJLTXYYLHLMJXUTBJDOWFFNLSPZWJAQYQEDZQW",
"EXGGAWFQHRWABGJMSNIYQAKYTOGJKWTSROARTBLOMNVRUZZYWD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1013; verify_case(4, Arg1, partition(Arg0)); }

// END CUT HERE

};

int PalindromePartition::partition(vector <string> s) {
  
}

// BEGIN CUT HERE
int main(){
    PalindromePartition ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE

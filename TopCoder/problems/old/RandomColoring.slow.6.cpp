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

class RandomColoring {
  public:
  double getProbability(int N, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2);

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; int Arg5 = 0; int Arg6 = 0; int Arg7 = 0; int Arg8 = 1; double Arg9 = 0.0; verify_case(0, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; int Arg5 = 0; int Arg6 = 0; int Arg7 = 0; int Arg8 = 1; double Arg9 = 0.22222222222222227; verify_case(1, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 2; int Arg3 = 2; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 3; int Arg8 = 3; double Arg9 = 1.0; verify_case(2, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 7; int Arg2 = 8; int Arg3 = 9; int Arg4 = 1; int Arg5 = 2; int Arg6 = 3; int Arg7 = 0; int Arg8 = 10; double Arg9 = 0.0; verify_case(3, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 7; int Arg2 = 8; int Arg3 = 9; int Arg4 = 1; int Arg5 = 2; int Arg6 = 3; int Arg7 = 4; int Arg8 = 10; double Arg9 = 0.37826245943967396; verify_case(4, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_5() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; int Arg3 = 2; int Arg4 = 1; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1; int Arg8 = 2; double Arg9 = 0.09090909090909148; verify_case(5, Arg9, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }

// END CUT HERE

};

const int MAXN = 55;

struct Tree {
    double data[MAXN][MAXN][MAXN];
    
    void clear() {
        memset(data, 0, sizeof data);
    }

    double get(int x, int y, int z) {
        return data[x][y][z];
    }

    void add(int x1, int x2, int y1, int y2, int z1, int z2, double what) {
        for (int x = x1; x <= x2; ++x)
            for (int y = y1; y <= y2; ++y)
                for (int z = z1; z <= z2; ++z)
                    data[x][y][z] += what;
    }
};

int maxR, maxG, maxB;

Tree cur, next;

double RandomColoring::getProbability(int N, int _maxR, int _maxG, int _maxB, int startR, int startG, int startB, int d1, int d2) {
    maxR = _maxR, maxG = _maxG, maxB = _maxB;
    maxR--, maxG--, maxB--;

    cur.clear();
    cur.add(startR, startR, startG, startG, startB, startB, 1.0);
    
    for (int i = 0; i < N - 1; ++i) {
        next.clear();
        
        for (int r = 0; r <= maxR; ++r) {
            for (int g = 0; g <= maxG; ++g) {
                for (int b = 0; b <= maxB; ++b) {
                    int count = 0, r1, r2, g1, g2, b1, b2;
                    r1 = max(0, r - d2), r2 = min(maxR, r + d2);
                    g1 = max(0, g - d2), g2 = min(maxG, g + d2);
                    b1 = max(0, b - d2), b2 = min(maxB, b + d2);
                    count += (r2 - r1 + 1) * (g2 - g1 + 1) * (b2 - b1 + 1);
                    printf("i = %d, r = %d, g = %d, b = %d, count_inside = %d\n", i, r, g, b, count);
                    
                    r1 = max(0, r - d1 + 1), r2 = min(maxR, r + d1 - 1);
                    g1 = max(0, g - d1 + 1), g2 = min(maxG, g + d1 - 1);
                    b1 = max(0, b - d1 + 1), b2 = min(maxB, b + d1 - 1);
                    int out = (r2 - r1 + 1) * (g2 - g1 + 1) * (b2 - b1 + 1);
                    count -= (r2 - r1 + 1) * (g2 - g1 + 1) * (b2 - b1 + 1);

                    printf("i = %d, r = %d, g = %d, b = %d, count_outside = %d\n", i, r, g, b, out);
                    printf("i = %d, r = %d, g = %d, b = %d, count = %d\n", i, r, g, b, count);
                    if (count == 0) continue;
                    
                    double add = cur.get(r, g, b) / count;

                    r1 = max(0, r - d2), r2 = min(maxR, r + d2);
                    g1 = max(0, g - d2), g2 = min(maxG, g + d2);
                    b1 = max(0, b - d2), b2 = min(maxB, b + d2);
                    next.add(r1, r2, g1, g2, b1, b2, add);
                    r1 = max(0, r - d1 + 1), r2 = min(maxR, r + d1 - 1);
                    g1 = max(0, g - d1 + 1), g2 = min(maxG, g + d1 - 1);
                    b1 = max(0, b - d1 + 1), b2 = min(maxB, b + d1 - 1);
                    next.add(r1, r2, g1, g2, b1, b2, -add);
                }
            }
        }
        cur = next;
    }
    
    double ans = 0;
    for (int r = 0; r <= maxR; ++r) {
        for (int g = 0; g <= maxG; ++g) {
            for (int b = 0; b <= maxB; ++b) {
                bool good = abs(r - startR) <= d2 and abs(g - startG) <= d2 and abs(b - startB) <= d2;
                good &= abs(r - startR) >= d1 or abs(g - startG) >= d1 or abs(b - startB) >= d1;
                if (!good) ans += cur.get(r, g, b);
            }
        }
    }

    return ans;
}

// BEGIN CUT HERE
int main(){
    RandomColoring ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE

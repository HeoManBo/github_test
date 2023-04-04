//주어진 명세대로 정렬 후 컨벡스 헐 알고리즘을 돌리면 된다
//stack에 푸쉬할때 CCW의 순서에 유의한다. 
//시계 뱡향으로 두고 CCW() < 0으로 해도 무방함.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;

typedef struct point {
	int y;
	int x;
};
int T, N;
point p[51];
vector<point> ans;
long long CCW(point& a, point& b, point& c) {
	return 1LL * (a.x * b.y) - (a.y * b.x) + (b.x * c.y) - (b.y * c.x) + (c.x * a.y) - (c.y * a.x);
}
//y가 큰순으로 같다면 x가 작은 순으로 정렬
int cmp(point& a, point& b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}
	return a.y > b.y;
}
//시계방향으로 정렬한다.
int cmp2(point& a, point& b) {
	long long c = CCW(p[0], a, b);
	if (c == 0) {
		if (a.y == b.y) {
			return a.x < b.x;
		}
		return a.y > b.y;
	}
	return c < 0;
}

int main(void) {
	cin >> T;
	while (T--) {
		memset(p, 0, sizeof(p));
		ans.clear();
		cin >> N;
		int x, y;
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			p[i].x = x;
			p[i].y = y;
		}
		sort(p, p + N, cmp);
		sort(p + 1, p + N, cmp2);
		ans.push_back(p[0]);
		ans.push_back(p[1]);
		for (int i = 2; i < N; i++) {
			while (ans.size() >= 2) {
				point second = ans.back();
				ans.pop_back();
				point first = ans.back();
				//if(CCW(first,second,p[i]) < 0)
				if (CCW(p[i], second, first) > 0) {
					ans.push_back(second);
					break;
				}
			}
			ans.push_back(p[i]);
		}
		cout << ans.size() << "\n";
		for (auto& a : ans) {
			cout << a.x << " " << a.y << "\n";
		}
	}
}

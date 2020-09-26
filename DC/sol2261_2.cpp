// shortest pair second try
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
	int x;
	int y;
	Point() {}
	Point(int x, int y) : x(x) , y(y) {

	}
	bool operator < (const Point &v) const {
		if (x == v.x) {
			return y < v.y;
		}
		else {
			return x < v.x;
		}
	}
};
struct Ppair {
	Point p1;
	Point p2;
};

bool equal(Point p1, Point p2) {
	return (p1.x == p2.x && p1.y == p2.y);
}

bool cmp(const Point&u, const Point& v) {
	return u.y < v.y;
}

int n;

int min(int x, int y) {
	return x < y ? x : y;
}

int distance(Ppair P) {
	return (P.p1.x - P.p2.x) * (P.p1.x - P.p2.x) + (P.p1.y - P.p2.y) * (P.p1.y - P.p2.y);
}

int distance2(Point p1, Point p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

Ppair compareThree(Ppair P1, Ppair P2, Ppair P3) {
	int d1, d2, d3;
	d1 = distance(P1);
	d2 = distance(P2);
	d3 = distance(P3);
	if (d1 < d2 && d1 < d3) {
		return P1;
	}
	if (d2 < d1 && d2 < d3) {
		return P2;
	}
	return P3;
}

Ppair ClosestPair(vector<Point> P) {
	// P의 size가 2이면 P[0] 와 P[1] 의 쌍이 최소거리.
	if (P.size() == 2) {
		Ppair ret;
		ret.p1 = P[0];
		ret.p2 = P[1];
		return ret;
	}

	// P의 size가 3이면 세개를 모두 비교해서 가장 거리가 작은 것 return.
	if (P.size() == 3) {
		Ppair a, b, c, ret;
		a.p1 = P[0];
		a.p2 = P[1];

		b.p1 = P[0];
		b.p2 = P[2];
		
		c.p1 = P[1];
		c.p2 = P[2];
		
		ret = compareThree(a, b, c);
		return ret;
	}

	// Divide. Left 와 Right로 나눈다.
	vector<Point> L;
	vector<Point> R;

	// P.size() >= 4이고, mid는 L중 가장 x값이 큰 값이다.
	int mid = (P.size()/2) - 1;
	int xStar = P[mid].x;

	for (int i = 0; i <= mid; i++) {
		L.push_back(P[i]);
	}
	for (int i = mid + 1; i < P.size(); i++) {
		R.push_back(P[i]);
	}
	
	// left에서 가장 작은 값과 right에서 가장 작은 값을 구한다.
	Ppair Pl = ClosestPair(L);
	Ppair Pr = ClosestPair(R);

	// delta를 구한다.
	int delta = min(distance(Pl), distance(Pr));

	// x* +- delta 안에 있는 점들의 집합은 M이다.
	vector<Point> M;
	for (int i = 0; i < P.size(); i++) {
		if ((xStar - P[i].x) * (xStar - P[i].x) < delta) {
			M.push_back(P[i]);
		}
	}

	//만약 Mid에 point가 한개 이하라면 mid를 신경쓰지 않음.
	bool noMid = false;
	if (M.size() <= 1) {
		noMid = true;
	}

	// Mid에서 가장 작은 값을 구한다.
	Ppair Pm;
	if (M.size() == 2) {
		Pm.p1 = M[0];
		Pm.p2 = M[1];
	}
	else if (M.size() >= 3) {
		sort(M.begin(), M.end(), cmp);
		Pm.p1 = M[0];
		Pm.p2 = M[1];
		int dist = distance(Pm);
		for (int i = 0; i < M.size(); i++) {
			for (int j = i + 1; j < M.size() && j < i + 12; j++) {
				int tmp = distance2(M[i], M[j]);
				if (tmp < dist) {
					dist = tmp;
					Pm.p1 = M[i];
					Pm.p2 = M[j];
				}
			}
		}
	}
	if (noMid) {
		if (distance(Pl) > distance(Pr)) {
			return Pr;
		}
		else {
			return Pl;
		}
	}
	return compareThree(Pl, Pr, Pm);
}

int main() {
	cin >> n;
	vector<Point> xy;
	for (int i = 0; i < n; i++) {
		Point p;
		cin >> p.x >> p.y;
		xy.push_back(p);
	}
	sort(xy.begin(), xy.end());
	Ppair answer = ClosestPair(xy);
	cout << distance(answer) << '\n';
}
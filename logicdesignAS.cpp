#include <iostream>
#include <vector>

using namespace std;

int main() {
	int cnt = 0;
	vector<int> ans;
	for (int i = 0 ; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			for (int k = 0; k <= 1; k++) {
				for(int l=0; l <= 1; l++) {
					for(int m=0; m <= 1; m++) {
						for (int n=0; n<=1; n++) {
							for (int o=0; o<=1; o++) {
								for(int p = 0; p <= 1; p++) {
									for (int q = 0; q <= 1; q++) {
										for (int r=0; r<= 1; r++) {
											for (int s=0; s <= 1; s++) {
												cout << "i0=" << i << "; i1=" << j << "; i2=" << k << "; i3=" << l << "; i4=" << m << "; i5=" << n << "; i6=" << o
												<< "; i7=" << p << "; a=" << q << "; b=" << r << "; c=" << s <<"; #1\n    ";
											}
										}	
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < ans.size() ;i++) {
		cout << ans[i];
	}
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == 1) {
			cout << "-";
		}
		else {
			cout << "_";
		}
	}
}
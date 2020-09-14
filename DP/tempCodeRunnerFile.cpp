for (int dj = 1; j - dj >= i-1; dj++) {
		int tmp = 0;
		for (int k = 0; k < dj; k++) {
			tmp += arr[j-k];
		}
		tmp += dj - 1;
		if (tmp > m) {
			tmp = (m-tmp)*(m-tmp);
		}
		ret = min(ret, solve(i-1, j - dj) + tmp);
	}
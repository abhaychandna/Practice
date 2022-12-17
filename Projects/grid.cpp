bool grid() {
	ll a[2], b[2], c[2];
	cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
	ll distA = (abs(a[0] - c[0]) + abs(a[1] - c[1]));
	ll distB = max(abs(b[0] - c[0]), abs(b[1] - c[1]));
	return distA < distB;
}
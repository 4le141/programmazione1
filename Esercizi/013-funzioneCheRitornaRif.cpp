int& max(int& x, int& y) {
    return (x > y ? x : y);
}
int main() {
    int n1=44, n2=22;
    max(n1, n2) = 55;
}
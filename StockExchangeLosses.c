int main() {
    int size, value, max = 0, solution = 0;
    scanf("%d", &size);
    
    for (int i = 0; i < size; i++) {
        scanf("%d", &value);
        if (value > max) { max = value; }
        if ((value - max) < solution) { solution = value - max; }
    }
    printf("%d\n", solution);
}

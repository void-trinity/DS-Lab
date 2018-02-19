#include <stdio.h>
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\nDisk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\nDisk %d from rod %c to rod %c", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    printf("Siddharth Chandra, 16115078\n");
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("\n");
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}

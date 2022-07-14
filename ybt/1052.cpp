#include <cstdio>

int main (){
        int weight; char f;
        scanf("%d %c", &weight, &f);
        int cost = 8;
        if (f == 'y') { cost += 5; }
        int extra = weight - 1000;
        if (extra > 0) {
                cost += 4*(extra/500);
                if (extra % 500 != 0) { cost += 4; }
        }
        printf("%d", cost);
        return 0;
}


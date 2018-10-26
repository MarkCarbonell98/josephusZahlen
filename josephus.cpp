#include <iostream> 
#include <cmath> 

using namespace std;

int recursiveJosephusDouble(int n) {
    if (n == 1) {
        cout << "J(1) = 1" << endl;
        return 1;
    }

    if ((n % 2) == 0) {
        int result = 2*recursiveJosephusDouble(n/2) - 1;
        cout << "J(" << n << ") = " << result << endl;
        return result;
    }

    if ((n % 2) != 0) {
        int result = 2*recursiveJosephusDouble((n-1) / 2) + 1;
        cout << "J(" << n << ") = " << result << endl;
        return result;
    }

    return 0;
}

int exclusiveJosephus(int n) {
    int m = floor(log( n ));
    int l = n - 2^m;
    int j = 2*l + 1;
    cout << "The result of J(" << n << ") = " << j << endl;
    return j;
}

int recursiveJosephus2(int n, int k) {
    if (n == 1) {
        return 1;
    } else {
        int theResult = (recursiveJosephus2(n -1, k) + k - 1) % n + 1;
        cout << "J(" << n << "," << k << ") = " << theResult << endl;
        return theResult;
    }
}

// std::public class JosephusProblem {
//     public static int nextMan(int currentManToKill, int killStep, int population) {
//         return (currentManToKill + killStep) % population;
//     }

//     public static int findLastManStanding(int population, int killStep ) {
//         int[] manToKill = new int[population+1];
//         manTokill[0] = nextMan(0, killStep, population);

//         for(int i = 1; i <= population; i++) {
//             manTokill[i] = nextMan(manTokill[i -1], killStep, population);
        
//             return nextMan(manToKill[population], killStep, population);
//         }
//     }
// }

int main() {
    recursiveJosephusDouble(20);
    exclusiveJosephus(20);
    cout << "now comes recursive version triple" << endl;
    recursiveJosephus2(20, 3);
    // std::findLastManStanding(20, 2);
    return 0;
}
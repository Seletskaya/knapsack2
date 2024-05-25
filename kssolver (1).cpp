#include "kssolver.h"
using namespace std;

int compare(elem a1, elem a2){
    double b1 = a1.v / a1.w, b2 = a2.v / a2.w;
    if(b1>b2){
            return 1;
    }
    else{
            return 0;
    }
}

int bound(S a, int n, int k, vector <elem> items){
    if (a.w < k){
        int A = a.p,i, entw = a.w;
            while ((entw + items[i].w) <= k){
                    for(i = a.l + 1;i<n;i++){
                        entw += items[i].w;
                        A += items[i].v;
                    }
            }
            if (i < n){
                A += (k - entw)*items[i].v/items[i].w;
            }
            return A;
    }
    else{
            return 0;
        }
}

void knapsack(int k, vector <elem> items, int n,int* ans){ 
        vector <S> A;
        int max = 0;
        S a, b;
        a.p = 0;
        a.w = 0;
        a.l = -1;
        A.push_back(a);
        sort(items.begin(), items.end(), compare);
        while (A.size()!=0){
                a = A[0];
                A.pop_back();
                if (a.l == -1){
                        b.l = 0;
                }
                if (a.l == n-1){
                        a.l = b.l;
                        a.l++;
                }
                b.l = a.l + 1;
                b.w = a.w + items[b.l].w;
                b.p = a.p + items[b.l].v;
                if (b.w <= k && b.p > max){
                        max = b.p;
                }
                b.b = bound(b, n, k, items);
                if (b.b > max){
                        A.push_back(b);
                }
                b.w = a.w;
                b.p = a.p;
                b.b = bound(b, n, k, items);
                if (b.b > max){
                        A.push_back(b);
                }
        }
        *ans = max;
        return;
}

kssolver::kssolver(ksparser *p):el(p){
        int n = el->n,i,k = el->n;
        vector <elem> items;
        elem it;
        for(i = 0;i<n;i++){
                it.w = el->W[i];
                it.v = el->V[i];
                items.push_back(it);
        }
        int res = 0;
        knapsack(k, items, n,&res);
        cout << "Result = "<<res<<endl;
    return;
}

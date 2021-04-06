#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;

void solve(vector<int>& klocki, int index, int Jas, int Maja, int reszta, map<int,pair<int,int>>& roznice){
    if(index < 0){
        int roznica = abs(Jas-Maja);
        if(roznice.count(roznica) > 0){
            pair<int,int> p = roznice[roznica];
            if(p.first < Jas){
                roznice[roznica] = make_pair(Jas, Maja);
            }
        }
        else{
            roznice[roznica] = make_pair(Jas, Maja);
        }
    }
    else{
        solve(klocki, index-1, Jas+klocki[index], Maja, reszta-klocki[index], roznice);
        solve(klocki, index-1, Jas, Maja+klocki[index], reszta-klocki[index], roznice);
        solve(klocki, index-1, Jas, Maja, reszta-klocki[index], roznice);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int pom;
    cin >> n;
    int sum1 = 0;
    int sum2 = 0;
    vector<int> k1;
    vector<int> k2;
    for(int i = 0; i < n; i++){
        cin >> pom;
        if(i < n/2) k1.push_back(pom);
        else k2.push_back(pom);
    }

    map<int,pair<int,int>> roznice1;
    map<int,pair<int,int>> roznice2;

    
    sum1 = accumulate(k1.begin(), k1.end(), 0);
    sum2 = accumulate(k2.begin(), k2.end(), 0);
    solve(k1, k1.size()-1, 0 , 0, sum1, roznice1);
    solve(k2, k2.size()-1, 0 , 0, sum2, roznice2);    
    int max = 0;
    int minRoznica = 500000;
    for(int i = 0; i < roznice1.size();i++){
        for(int j = 0; j < roznice2.size(); j++){
            int J1, J2, M1, M2;
            J1 = roznice1[i].first;
            J2 = roznice2[j].first;
            M1 = roznice1[i].second;
            M2 = roznice2[j].second;
            if((J1 != 0 || M1 != 0) && (J2 != 0 || M2 != 0)){
                if(i==j){
                    if(J1+M2 > max){
                        max = J1+M2;
                    }
                }
                else{
                    J1 = J1 ? J1 : 500000;
                    J2 = J2 ? J2 : 500000;
                    M1 = M1 ? M1 : 500000;
                    M2 = M2 ? M2 : 500000;
                    minRoznica = min(minRoznica, abs(J1-M2));
                    minRoznica = min(minRoznica, abs(J2-M1));
                    minRoznica = min(minRoznica, abs(J1-J2));
                }
            }
            
        }
    }
    if(max != 0){
        cout<<"TAK\n"<<max;
    }
    else{
        cout<<"NIE\n"<<minRoznica;
    }
    return 0;
}
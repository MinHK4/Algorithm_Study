// https://programmers.co.kr/learn/courses/30/lessons/72413?language=cpp

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

#define INF 1e9

vector<vector<pii>> G;
vector<vector<int>> d;
vector<int> from;

void dijkstra(int idx, int start){
    priority_queue<pii> pq;
    pq.push({0, start});
    d[idx][start] = 0;
    
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        // 현재 가지고 있는 거리보다 짧아지지 않으면 패스
        if(dist > d[idx][now])
            continue;
        
        // 현재 정점에서 갈 수 있는 정점들 중에
        // 현재 정점에서 가게 되면 더 짧아지게 되는 정점들만 새로 업데이트
        for(auto x : G[now]){
            int cost = dist + x.first;
            if(cost < d[idx][x.second]){
                d[idx][x.second] = cost;
                from[x.second] = now;
                pq.push({-cost, x.second});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    // 경로 반영
    G.resize(n+1);
    d.resize(3, vector<int>(n+1, INF)); 
    from.resize(n+1, 0); 
    for(auto fare: fares){
        G[fare[0]].push_back({fare[2], fare[1]});
        G[fare[1]].push_back({fare[2], fare[0]});
    }
    
    // 다익스트라로 각각의 경로 탐색
    dijkstra(0, s);
    dijkstra(1, a);
    dijkstra(2, b);
    
    // 어떤 지점을 잡아서 그 지점으로부터 출발지, a, b까지의 거리 구하기
    // 어떤 지점이 s이면 a,b가 아예 합승 안 하는 경우이고 a이거나 b인 경우는 한 지점까지 합승하는 경우
    // 그 외에도 중간 지점까지 합승하다가 흩어지는 경우도 알아서 처리해줌
    for(int i=1; i<=n; i++){
        if(d[0][i] != INF && d[1][i] != INF && d[2][i] != INF)
            answer = min(answer, d[0][i]+d[1][i]+d[2][i]);
    }
    
    return answer;
}
/*
핵심 아이디어는 무방향 그래프이기 때문에 그냥 정점-정점 최단 거리를 s, a, b 기준으로 다 구해서
임의의 중간 지점 잡아서 그 지점을 통과해서 가는 경우 중에 가장 짧게 나오는 경우를 찾아주는 것
*/
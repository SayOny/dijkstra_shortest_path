

#include <iostream>
#include <vector>
#include <queue>


using namespace std;


# define INF 1000000000 // 가는 방법이 없을 때


int node;  // Node의 개수
int edge;  // Edge의 개수
vector<int> dist;  // 한 노드부터 각 노드들까지의 거리를 저장할 Vector
priority_queue<pair<int, int>> q; // 큐 이용

// 매개변수: 어떤 노드에서 출발(n), 그래프 정보(W)
void dijkstra(int n, vector<pair<int, int>> W[])
{
    int i;
    
    dist.assign(node, INF);
    dist[n] = 0;  // 시작 노드 거리를 0으로 설정
    q.push({ 0, n });  // 큐에 넣기

    while (!q.empty())
    {
        int distNow = -q.top().first; // 현재 노드까지의 거리
        int nodeNow = q.top().second;  // 현재 노드 이름
        q.pop(); // 큐에서 이 거리 상태 빼고 다음 진행
        
        for (i = 0; i < W[nodeNow].size(); i++)
        {
//            여태 까지 거리 + 지금에서 타겟까지가 바로 오는 값보다 작으면
            if (distNow + W[nodeNow][i].second < dist[W[nodeNow][i].first])
            {
//                시작 노드부터 i까지의 거리는 여태까지의 거리 + 지금부터 타켓까지 거리
                dist[W[nodeNow][i].first] = distNow + W[nodeNow][i].second;
//                지금까지의 거리를 큐에 넣어 갱신한다.
                q.push({ -(distNow + W[nodeNow][i].second), W[nodeNow][i].first});
            }
        }
    }
}

int main()
{
    int i, j;
   
//     a는 시작 노드, b는 목적지, d는 거리이다.
//    node = 6;
//    edge = 10;
//    vector<int> a = {3, 4, 0, 2, 1, 1, 2, 0, 2, 0};
//    vector<int> b = {4, 5, 3, 5, 2, 3, 3, 4, 4, 1};
//    vector<int> d = {1, 2, 2, 2, 3, 3, 3, 4, 4, 5};
    
//    node = 7;
//    edge = 11;
//    vector<int> a = {0, 2, 2, 0, 1, 1, 4, 3, 0, 0, 3};
//    vector<int> b = {4, 5, 4, 1, 2, 3, 5, 6, 6, 2, 4};
//    vector<int> d = {1, 1, 2, 2, 2, 2, 3, 3, 4, 5, 6};
    
    node = 5;
    edge = 8;
    vector<int> a = {1, 3, 1, 1, 0, 3, 0, 0};
    vector<int> b = {2, 3, 4, 3, 4, 4, 3, 1};
    vector<int> d = {1, 1, 2, 3, 4, 5, 6, 7};
    
    vector<pair<int, int>> W[node];  // 그래프 형태 선언, W[시작노드인덱스], <목적지 인덱스, 거리>
//    그래프 그리기: 시작 노드 인덱스에 <목적지 인덱스, 거리>가 쌍으로 들어간다.
//    연결된 엣지만큼 들어가니까 하나의 시작 노드 인덱스에 여러 개의 쌍이 들어갈 수 있다.
    for (i = 0; i < edge; i++)
    {
        W[a[i]].push_back({ b[i], d[i] });
        W[b[i]].push_back({ a[i], d[i] });
    }
    
//    0부터 4까지의 시작 노드부터 각각 다른 노드들의 거리까지 모든 최단거리를 구해서 출력 한다.
    for (j=0; j<node-1; j++) {
        dijkstra(j, W);
        for (i=j+1; i<node; i++) {
            cout << j << " 부터 " << i << " 까지의 최단 거리: " << dist[i] << endl;
        }
        cout<<endl;
    }
    
    
    return 0;
}


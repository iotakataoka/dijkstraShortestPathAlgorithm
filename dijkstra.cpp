#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <utility> // for pair
#include <algorithm>
#include <iterator>

typedef int vertex_t;
typedef double weight_t;

const weight_t max_weight = 0x3f3f3f3f;

struct neighbor {
    vertex_t target;
    weight_t weight;
    neighbor( vertex_t arg_target, weight_t arg_weight )
            : target(arg_target), weight(arg_weight) { }
};

typedef std::vector<std::vector<neighbor> > adjacency_list_t;
typedef std::pair<weight_t, vertex_t> weight_vertex_pair_t;

/* DijkstraComputePaths(    vertex_t source,
                            const adjacency_list_t &adjacency_list,
                            std::vector<weight_t> &min_distance,
                            std::vector<vertex_t> &previous
                        )
    与えられた隣接リストについてダイクストラ法で最短経路を計算する
    source: ゴールのノード, adjacency_list: 最短経路の前の点を記録する, min_distance: 現在の最小の距離, previous: 前回通ったノード
*/
void DijkstraComputePaths(  vertex_t source,
                            const adjacency_list_t &adjacency_list,
                            std::vector<weight_t> &min_distance,
                            std::vector<vertex_t> &previous
                        ) {
    int n = adjacency_list.size();
    min_distance.clear();
    min_distance.resize(n, max_weight);
    min_distance[source] = 0;
    previous.clear();
    previous.resize(n, -1);

    std::priority_queue<weight_vertex_pair_t,
		std::vector<weight_vertex_pair_t>,
		std::greater<weight_vertex_pair_t>
    > vertex_queue;
    vertex_queue.push(std::make_pair(min_distance[source], source));

    while (!vertex_queue.empty()) {
        weight_t dist = vertex_queue.top().first;
        vertex_t u = vertex_queue.top().second;
        vertex_queue.pop();

	// 頂点の古いコピーをpriority_queueに残して, min_distanceに対して距離をチェックして再び出てきたときにそれを無視する
	if (dist > min_distance[u]) continue;

	const std::vector<neighbor> &neighbors = adjacency_list[u];
        for (   std::vector<neighbor>::const_iterator neighbor_iter = neighbors.begin();
                neighbor_iter != neighbors.end();
                neighbor_iter++) {
            vertex_t v = neighbor_iter->target;
            weight_t weight = neighbor_iter->weight;
            weight_t distance_through_u = dist + weight;
            if (distance_through_u < min_distance[v]) {
                min_distance[v] = distance_through_u;
                previous[v] = u;
                vertex_queue.push(std::make_pair(min_distance[v], v));
            }
        }
    }
}

/* DijkstraGetShortestPathTo(vertex_t vertex, const std::vector<vertex_t> &previous)
    ゴールのノードまでの経路を復元する
    vertex: ゴールのノード, previous: 最短経路の前の点を記録する
*/
std::list<vertex_t> DijkstraGetShortestPathTo(vertex_t vertex, const std::vector<vertex_t> &previous) {
    std::list<vertex_t> path;
    for ( ; vertex != -1; vertex = previous[vertex]) path.push_front(vertex);
    return path;
}


int main() {
    /*
        int node_num: ノードの総数
        int start: スタートするノード
        int goal: ゴールするノード
    */
    int node_num = 11;
    int start = 0;
    int goal = 5;

    // 無向グラフ 両方の方法を挿入する
    adjacency_list_t adjacency_list(node_num);

    adjacency_list[0].push_back(neighbor(1, 2));  //0->1の辺は重み2
    adjacency_list[0].push_back(neighbor(2, 3));
    adjacency_list[0].push_back(neighbor(3, 6));

    adjacency_list[1].push_back(neighbor(0, 2));
    adjacency_list[1].push_back(neighbor(4, 4));
    adjacency_list[1].push_back(neighbor(5, 1));
    adjacency_list[1].push_back(neighbor(8, 10));

    adjacency_list[2].push_back(neighbor(0, 3));
    adjacency_list[2].push_back(neighbor(3, 2));
    adjacency_list[2].push_back(neighbor(5, 2));

    adjacency_list[3].push_back(neighbor(0, 6));
    adjacency_list[3].push_back(neighbor(2, 2));
    adjacency_list[3].push_back(neighbor(5, 1));
    adjacency_list[3].push_back(neighbor(6, 2));
    adjacency_list[3].push_back(neighbor(8, 4));

    adjacency_list[4].push_back(neighbor(1, 4));
    adjacency_list[4].push_back(neighbor(8, 2));
    adjacency_list[4].push_back(neighbor(9, 1));
    adjacency_list[4].push_back(neighbor(10, 8));

    adjacency_list[5].push_back(neighbor(1, 1));
    adjacency_list[5].push_back(neighbor(2, 2));
    adjacency_list[5].push_back(neighbor(3, 1));
    adjacency_list[5].push_back(neighbor(7, 7));
    adjacency_list[5].push_back(neighbor(9, 3));

    adjacency_list[6].push_back(neighbor(3, 2));
    adjacency_list[6].push_back(neighbor(8, 4));
    adjacency_list[6].push_back(neighbor(10, 3));

    adjacency_list[7].push_back(neighbor(5, 7));
    adjacency_list[7].push_back(neighbor(8, 3));
    adjacency_list[7].push_back(neighbor(10, 5));

    adjacency_list[8].push_back(neighbor(3, 4));
    adjacency_list[8].push_back(neighbor(4, 2));
    adjacency_list[8].push_back(neighbor(6, 4));
    adjacency_list[8].push_back(neighbor(7, 3));
    adjacency_list[8].push_back(neighbor(10, 11));

    adjacency_list[9].push_back(neighbor(4, 1));
    adjacency_list[9].push_back(neighbor(5, 3));

    adjacency_list[10].push_back(neighbor(4, 8));
    adjacency_list[10].push_back(neighbor(6, 3));
    adjacency_list[10].push_back(neighbor(7, 5));
    adjacency_list[10].push_back(neighbor(8, 11));
    adjacency_list[10].push_back(neighbor(9, 7));

    std::vector<weight_t> min_distance;
    std::vector<vertex_t> previous;
    DijkstraComputePaths(start, adjacency_list, min_distance, previous);
    std::cout << "Distance from " << start <<  " to " << goal << ": " << min_distance[goal] << std::endl;
    std::list<vertex_t> path = DijkstraGetShortestPathTo(goal, previous);
    std::cout << "Path: ";
    std::copy(path.begin(), path.end(), std::ostream_iterator<vertex_t>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
#include "makeAdjList.hpp"

/* DijkstraComputePaths(    vertex_t source,
                            const adjacency_list_t &adjacency_list,
                            std::vector<weight_t> &min_distance,
                            std::vector<vertex_t> &previous
                        )
    与えられた隣接リストについてダイクストラ法で最短経路を計算する
    source: ゴールのノード, adjacency_list: 最短経路の前の点を記録する, min_distance: 最小の距離, previous: 前回通ったノード
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
        int start: スタートするノード
        int goal: ゴールするノード
    */
    int start = 0;
    int goal = 9;

    std::vector<weight_t> min_distance; // min_distance: 最小の距離
    std::vector<vertex_t> previous; // previous: 前回通過したノード
    DijkstraComputePaths(start, makeAdjList(), min_distance, previous);

    // 最短距離を出力
    std::cout << "Distance from " << start <<  " to " << goal << ": " << min_distance[goal] << std::endl;

    std::list<vertex_t> path = DijkstraGetShortestPathTo(goal, previous); // list: 最短経路を格納する変数

    // 復元した経路を出力
    std::cout << "Path: ";
    std::copy(path.begin(), path.end(), std::ostream_iterator<vertex_t>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
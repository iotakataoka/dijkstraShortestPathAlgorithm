#include <bits/stdc++.h>
using namespace std;

typedef int vertex_t;
typedef double weight_t;

const weight_t max_weight = 0x3f3f3f3f;

struct neighbor {
    vertex_t target;
    weight_t weight;
    neighbor( vertex_t arg_target, weight_t arg_weight )
            : target(arg_target), weight(arg_weight) {}
};

typedef std::vector<std::vector<neighbor> > adjacency_list_t;
typedef std::pair<weight_t, vertex_t> weight_vertex_pair_t;

//最初のintは隣接するノードの頂点, 2番目のintは重み
adjacency_list_t makeAdjList() {
    // int node_num: ノードの総数
    // 以下では10個のノードがあるため, 0〜10を繰り返すようにnode_num=11を設定
    int node_num = 11;
    adjacency_list_t adjacency_list(node_num);

    // インデックスは頂点
    // push_back各辺に隣接する頂点と重みを書く
    adjacency_list[0].push_back(neighbor(1, 2));
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

    return adjacency_list;
}
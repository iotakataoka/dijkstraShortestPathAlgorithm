# dijkstraShortestPathAlgorithm

##
``` c++
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
```
の隣接グラフの下で

``` c++
    int node_num = 11;
    int start = 0;
    int goal = 10;
```
のとき

``` bash
    Distance from 0 to 10: 9
    Path: 0 1 5 3 6 10
```

``` c++
    int node_num = 11;
    int start = 0;
    int goal = 5;
```
のとき

``` bash
    Distance from 0 to 5: 3
    Path: 0 1 5
```
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility>      // std::pair
#include <limits>
#include <tuple>

/** Class Graph
 * Represents a directed Graph
 * 
 */
class Graph {
    
    public:
    
    /** Constructor **/
    Graph(int ver) {
        _V = ver;
        _adj = new std::vector<int>[_V]; 
        _visited = std::vector<bool>(_V, false);
    
    }

    /** 
     * brief Add a new edge 
     * 
     * @param from Vertice of origin 
     * @param to Vertice of destination
     */
    void addEdge(int from, int to) {
        _adj[from].push_back(to);
        // for undirected graphs we should add
        // _adj[to].push_back(from);
    }

    /** 
     * brief Performs the Breadth-First Search, searching all vertices
     * reachable from the origin vertice.
     * Solution iterative.
     * More information https://en.wikipedia.org/wiki/Breadth-first_search
     * 
     * @param s The origin vertice
     */
    void BFSGraph(int s) {
        std::queue<int> q;

        _visited[s] = true;
        q.push(s);
        std::vector<int>::iterator it;

        std::vector<int> nodesRec;
        while (!q.empty()) {
            s = q.front();
            std::cout << " node " << s ;
            nodesRec.push_back(s);
            q.pop();

            for (it = _adj[s].begin(); it != _adj[s].end(); it++) {
                if (!_visited[*it]) {
                    q.push(*it);
                    _visited[*it] = true;
                }
            }
        }
    }

    /** 
     * brief Performs the Breadth-First Search
     * searching from all vertices in the graph
     * 
     */
    void BFSGraph() {

        for (int i = 0; i < _V; i++) {
            if (!_visited[i]) {            
                BFSGraph(i);
            }
        }
        std::fill(_visited.begin(), _visited.end(), false);
        std::cout << "\n";
        
    }

    /** 
     * brief Performs the Depth-First Search, searching all vertices
     * reachable from the origin vertice.
     * Solution iterative.
     * More information https://en.wikipedia.org/wiki/Depth-first_search
     * 
     * @param s The origin vertice
     */
    void DFSGraph(int s) {
        std::stack<int> sta;
        _visited[s] = true;
        sta.push(s);

        while (!sta.empty())
        {
            s = sta.top();
            sta.pop();
            std::cout << " node " << s;

            std::vector<int>::iterator it;
            for (it = _adj[s].begin(); it != _adj[s].end(); it++) {
                if (!_visited[*it]) {
                    _visited[*it] = true;
                    sta.push(*it);
                }
            }
        }
        

    }

    /** 
     * brief Performs the Depth-First Search, searching all vertices
     * reachable from the origin vertice.
     * Solution recursive.
     * More information https://en.wikipedia.org/wiki/Depth-first_search
     * 
     * @param s The origin vertice
     */
    void DFSGraphRe(int s) {
                    std::cout << " node " << s;

        _visited[s] = true;
        std::vector<int>::iterator it;
        for (it = _adj[s].begin(); it != _adj[s].end(); it++) {
            if (!_visited[*it]) {
                _visited[*it] = true;
                DFSGraphRe(*it);
            }
        }
    }

    /** 
     * brief Performs the Depth-First Search
     * searching from all vertices in the graph
     * 
     */
    void DFSGraph(){
        for (int i = 0; i < _V; i++) {
            if (!_visited[i]) {            
                DFSGraph(i);
            }
        }
        std::cout << "\n";
        std::fill(_visited.begin(), _visited.end(), false);
    }
    // DATA

    //! Adjacency list
    std::vector<int>* _adj;
    //! Number of vertices on the graph
    int _V;
    //! Vector of vertices to track if have been visited
    std::vector<bool> _visited;
    
};

/** Class graphWeight
 * Represents a Weighted directed graph
 * 
 */
class graphWeight {

    /** 
     * Auxiliar struct to order by distance
     */
    struct orderByDist
    {   
        bool operator() (std::pair<int,int> const &a, std::pair<int,int> const &b)
        { 
            return std::get<1>(a) < std::get<1>(b); 
        }
    };

    /** 
     * Auxiliar struct to order by cost
     */
    struct orderByCost
    {   
        //public:
        bool operator() (std::tuple<int,int,int> const &a, std::tuple<int,int,int> const &b)
        {   
            bool re = std::get<2>(a) > std::get<2>(b);   
            return std::get<2>(a) > std::get<2>(b); 
        }
    };

    /**
     * brief Add a node to the priority queue order by cost
     * 
     * @param s 
     * @param q
     */

    void addEdges(int s, std::priority_queue<std::tuple<int,int, int>, std::vector<std::tuple<int,int,int>>, orderByCost>& q) {
        _visited[s] = true;
        std::vector<std::pair<int,int>>::iterator it;

        for (it = _adj[s].begin(); it != _adj[s].end(); it++) {
            if (!_visited[(*it).first]) {
                // from, to, cost
                q.push(std::make_tuple(s,  (*it).first, (*it).second));
                std::tuple<int,int,int> current = q.top();
            }
        }
    }
    
    public: 
    
    /** Constructor **/
    graphWeight(int ver) {
        _V = ver;
        _adj = new std::vector<std::pair<int,int>>[_V]; 
        _visited = std::vector<bool>(_V, false);
    
    }

    /** 
     * brief Reset the _visited vector back to false
     */
    void resetVisited() {
        std::fill(_visited.begin(), _visited.end(), false);
    }

    /** 
     * brief Add a new edge with a cost
     * 
     * @param from Vertice of origin 
     * @param to Vertice of destination
     * @param weight The cost to go from-to 
     */
    void addEdge(int from, int to, int weight) {
        _adj[from].push_back(std::make_pair(to, weight));
        // for undirected graphs
        //_adj[to].push_back(std::make_pair(from, weight));
    }

    /** 
     * brief Performs the Breadth-First Search, searching all vertices
     * reachable from the origin vertice.
     * Solution iterative.
     * More information https://en.wikipedia.org/wiki/Breadth-first_search
     * 
     * @param s The origin vertice
     */
    void BFSGraph(int s) {
        std::queue<int> q;

        _visited[s] = true;
        q.push(s);
        std::vector<std::pair<int,int>>::iterator it;

        std::vector<int> nodesRec;
        while (!q.empty()) {
            s = q.front();
            std::cout << " node " << s ;
            nodesRec.push_back(s);
            q.pop();

            for (it = _adj[s].begin(); it != _adj[s].end(); it++) {
                if (!_visited[(*it).first]) {
                    q.push((*it).first);
                    _visited[(*it).first] = true;
                }
            }
        }
    }

    /** 
     * brief Performs the Breadth-First Search
     * searching from all vertices in the graph
     * 
     */
    void BFSGraph() {

        for (int i = 0; i < _V; i++) {
            if (!_visited[i]) {            
                BFSGraph(i);
            }
        }
        std::fill(_visited.begin(), _visited.end(), false);
        std::cout << "\n";
        
    }

    /** 
     * brief Performs the Depth-First Search, searching all vertices
     * reachable from the origin vertice.
     * Solution iterative.
     * More information https://en.wikipedia.org/wiki/Depth-first_search
     * 
     * @param s The origin vertice
     */
    void DFSGraph(int s) {
        std::stack<int> sta;
        _visited[s] = true;
        sta.push(s);

        while (!sta.empty())
        {
            s = sta.top();
            sta.pop();
            std::cout << " node " << s;

            std::vector<std::pair<int,int>>::iterator it;
            for (it = _adj[s].begin(); it != _adj[s].end(); it++) {
                if (!_visited[(*it).first]) {
                    _visited[(*it).first] = true;
                    sta.push((*it).first);
                }
            }
        }
        

    }

    /** 
     * brief Performs the Depth-First Search, searching all vertices
     * reachable from the origin vertice.
     * Solution iterative.
     * More information https://en.wikipedia.org/wiki/Depth-first_search
     * 
     * @param s The origin vertice
     * @param nodesRec Vector to save the order of traversal
     */
    void DFSGraph(int s, std::vector<int>& nodesRec) {
        std::stack<int> sta;
        _visited[s] = true;
        sta.push(s);

        while (!sta.empty())
        {
            s = sta.top();
            sta.pop();

            std::vector<std::pair<int,int>>::iterator it;
            for (it = _adj[s].begin(); it != _adj[s].end(); it++) {
                if (!_visited[(*it).first]) {
                    _visited[(*it).first] = true;
                    sta.push((*it).first);
                }
            }
            nodesRec.push_back(s);
        }
        

    }

    /** 
     * brief Performs the Depth-First Search, searching all vertices
     * reachable from the origin vertice.
     * Solution recursive.
     * More information https://en.wikipedia.org/wiki/Depth-first_search
     * 
     * @param s The origin vertice
     */
    void DFSGraphRe(int s) {
        std::cout << "node " << s << "  \n";

        _visited[s] = true;
        std::vector<std::pair<int,int>>::iterator it;
        for (it = _adj[s].begin(); it != _adj[s].end(); it++) {
            if (!_visited[(*it).first]) {
                _visited[(*it).first] = true;
                DFSGraphRe((*it).first);
            }
        }
    }

    /** 
     * brief Performs the Depth-First Search
     * searching from all vertices in the graph
     * 
     */
    void DFSGraph(){
        for (int i = 0; i < _V; i++) {
            if (!_visited[i]) {            
                DFSGraph(i);
            }
        }
        std::cout << "\n";
        std::fill(_visited.begin(), _visited.end(), false);
    }

    /**
     * brief Find the shortest paths from a starting vertex
     * to all other vertices on the graph. Using dijstra algorithm
     * 
     * @param s The starting vertex
     */
    std::vector<int> dijskraShortestPath(int s) {
        int inf = std::numeric_limits<int>::max();
        std::vector<int> dis(_V, inf);

        dis[s] = 0;
        _visited[s] =true;
        std::pair <int, int> current(s , 0); 
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, orderByDist> q;

        q.push(current);
        while (!q.empty())
        {
            current = q.top();
            q.pop();
            _visited[current.first] = true;
            std::vector<std::pair<int,int>>::iterator it;
            for (it = _adj[current.first].begin(); it != _adj[current.first].end(); it++){
                if (!_visited[(*it).first]) {
                    int newDis = dis[current.first] + (*it).second;
                    if (newDis < dis[(*it).first]) {
                        dis[(*it).first] = newDis;

                        q.push(std::make_pair((*it).first, newDis));
                    } 
                }
            } 
        }
        std::fill(_visited.begin(), _visited.end(), false);
        return dis;
    }

    /**
     * brief Find the shortest paths from a starting vertex
     * to all other vertices on the graph. Using BellamanFord algorithm
     * 
     * @param s The starting vertex
     */
    std::vector<int> bellmanFord(int s) {
        int inf = std::numeric_limits<int>::max();
        std::vector<int> dis(_V, inf);

        dis[s] = 0;
        bool relaxedAnEdge = true;

        for (int j = 0; j < _V-1 && relaxedAnEdge ; j++) {
            relaxedAnEdge = false;
            for (int i = 0; i < _V; i++) {
                std::vector<std::pair<int,int>>::iterator it;
                for (it = _adj[i].begin(); it != _adj[i].end(); it++) {
                    int newDis = dis[i] + (*it).second;
                    if (dis[i] != inf  && newDis < dis[(*it).first]) {
                        dis[(*it).first] = newDis;
                        relaxedAnEdge = true;
                    } 
                }
            }
        }
        relaxedAnEdge = true;

        for (int j = 0; j < _V-1; j++) {
            relaxedAnEdge = false;

            for (int i = 0; i < _V; i++) {
                std::vector<std::pair<int,int>>::iterator it;
                for (it = _adj[i].begin(); it != _adj[i].end(); it++) {
                    int newDis = dis[i] + (*it).second;
                    if (dis[i] != inf && newDis < dis[(*it).first]) {
                        dis[(*it).first] = std::numeric_limits<int>::max();;
                        relaxedAnEdge = true;
                    } 
                }
            }
        }
           
        return dis;
    }


    /**
     * brief Returns a vector with the vertices in topological order
     * using DFS as traversal
     */
    std::vector<int> topoSort() {
        std::vector<int> orderNode(_V, 0);
        int i = _V - 1;

        for (int j = 0; j < _V; j++) {
            if (!_visited[j]) {
                std::vector<int> recNode;
                DFSGraph(j, recNode);
                for (auto re: recNode) {
                    orderNode[i] = re;
                    i--;
                }
            }
        }
        
        return orderNode;
    }

    /**
     * brief Returns a vector with the edges information from the 
     * MST ( minimum spanning tree ) using Prims algorithm
     * 
     * @param s Source vertix
     */
    std::vector<std::tuple<int, int, int>> primsMST(int s) {
        int numberEdges = _V - 1;
        int edgeCount = 0;
        int mstCost = 0;
        std::vector<std::tuple<int, int, int>> mstEdges(numberEdges);

        std::priority_queue<std::tuple<int,int, int>, std::vector<std::tuple<int,int,int>>, orderByCost> q;
        
        addEdges(s, q); 

        while (!q.empty() && numberEdges != edgeCount) {
            std::tuple<int,int,int> current = q.top();
            int from = std::get<0>(current);
            int to = std::get<1>(current);
            int cost = std::get<2>(current);
            q.pop();
            if (_visited[to] == true) {
                continue;
            }
            
            mstEdges[edgeCount++] = current;
            mstCost = mstCost + cost;
        
            addEdges(to, q);
       
        }
        if (numberEdges != edgeCount) {  
            return {};
        }
        std::cout << "COST MST  " << mstCost << "  \n";
        return mstEdges;
    }

    //@todo floyd warshall and A* algorithms

    // DATA

    //! Adjacency list
    std::vector<std::pair<int,int>>* _adj;
    //! Number of vertices on the graph
    int _V;
    //! Vector of vertices to track if have been visited
    std::vector<bool> _visited;
    
};

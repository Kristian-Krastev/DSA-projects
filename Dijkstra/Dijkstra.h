#pragma once

#include <vector>
#include <list>
#include <queue>

using std::vector;
using std::list;
using std::priority_queue;

struct Vertex {
	char name;
	size_t value;
	size_t edge_val;
	vector<Vertex> adjacent;

	Vertex() :name('\0'), value(0), edge_val(0), adjacent(0) {};
	Vertex(const char n, size_t val, size_t edge) : name(n), value(val), edge_val(edge), adjacent(0) {};
	friend bool operator<(const Vertex& lhs, const Vertex& rhs) {
		return lhs.value < rhs.value;
	}
	friend bool operator==(const Vertex& lhs, const Vertex& rhs) {
		return (lhs.edge_val == rhs.edge_val && lhs.name == rhs.name
			&& lhs.value == rhs.value && lhs.adjacent == rhs.adjacent);
	}
	friend bool operator!=(const Vertex& lhs, const Vertex& rhs) {
		return !(lhs == rhs);
	}
};

using Graph = vector<list<Vertex>>;

void Dijkstra(const Graph& G, const Vertex& start_vertex, const Vertex& end_vertex) {
	vector<bool> visited(G.size());
	for (int i = 0; i < G.size(); i++) {
		visited[i] = false;
	}

	priority_queue<Vertex> queue;
	queue.push(start_vertex);
	visited[start_vertex.name - 'A'] = true;
	while (!queue.empty() && queue.top() != end_vertex) {
		Vertex temp = queue.top();
		queue.pop();
		for (int i = 0; i < temp.adjacent.size(); i++) {
			if (temp.adjacent[i].value > temp.value + temp.adjacent[i].edge_val) {
				temp.adjacent[i].value = temp.value + temp.adjacent[i].edge_val;
				queue.push(temp.adjacent[i]);
			}
		}
	}
}
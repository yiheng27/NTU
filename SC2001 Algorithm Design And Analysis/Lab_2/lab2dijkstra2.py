import heapq
import random
import time


def generate_random_graph(num_vertices, num_edges):
    graph = {}
    for vertex in range(num_vertices): 
        graph[vertex] = []

    edge_count = 0
    while edge_count < num_edges:
        vertex1 = random.randint(0, num_vertices - 1)
        vertex2 = random.randint(0, num_vertices - 1)

        if vertex1 != vertex2: #make sure not equal
            weight = random.randint(1, 10)

            if (vertex2, weight) not in graph[vertex1]:
                graph[vertex1].append((vertex2, weight))
                graph[vertex2].append((vertex1, weight))
                edge_count += 1

    return graph

def dijkstra(graph, start):
    key_comp = 0
    # Init 'distances' dict with all vertices in graph
    # Set all distances to infinity, except starting, = 0
    distances = {vertex: float('inf') for vertex in graph}
    distances[start] = 0
    visited = set()

    # Init empty list
    heap = [(0, start)]

    # Loop until heap empty (all vertices visited, shortest dist found)
    while heap:
        #vertex w minimum dist from heap is popped, storing dist and vertex
        current_distance, current_vertex = heapq.heappop(heap)

        # If the vertex has already been visited, skip it
        if current_vertex in visited:
            key_comp += 1
            continue

        # Visit the vertex
        visited.add(current_vertex)

        #If current dist > dist in dict for vertex, shorter path alr found (in dict)
        if current_distance > distances[current_vertex]:
            key_comp += 1
            #skip rest of loop, go to next iteration
            continue 
        
        #else, for each neighbour & weight in adj list of current vertex in graph,
        #new distance computed by adding current_distance to weight
        for neighbor, weight in graph[current_vertex]:
            distance = current_distance + weight

            #if new dist < current dist in dict, update, 
            #push tuple(distance,neighbour) into heap
            key_comp += 1
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(heap, (distance, neighbor))

    return distances, key_comp

def main():

    adjacency_lists = generate_random_graph(10, 25)

    start_time = time.time()
    distances, comp = dijkstra(adjacency_lists, 0)
    end_time = time.time()

    print("Time to run Dijkstra's algorithm:", end_time - start_time)
    print("Number of key comparisons: ", comp)


if __name__ == "__main__":
  main()
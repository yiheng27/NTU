import heapq
import random
import time
import sys
"""
Implement Dijkstra's algorithm in python, 
using input graph G = (V, E) stored in an adjacency matrix,
and using an array for the priority queue.
"""
def dijkstra(graph, start):

    distance = [sys.maxsize] * len(graph)
    distance[start] = 0
    queue = [start]
    comparisons = 0

    while queue:
        # Find the node with the minimum distance in the queue
        min_dist = sys.maxsize
        min_node = None
        for node in queue:
            if distance[node] < min_dist:
                min_dist = distance[node]
                min_node = node

        # Remove the node with the minimum distance from the queue
        queue.remove(min_node)

        # Update the distances of the neighboring nodes
        for i in range(len(graph[min_node])):
            if graph[min_node][i] > 0:
                new_dist = distance[min_node] + graph[min_node][i]
                comparisons += 1
                if new_dist < distance[i]:
                    distance[i] = new_dist
                    queue.append(i)
                    

    return distance, comparisons

def min_distance(dist, visited):
    min_dist = sys.maxsize
    min_index = -1

    for v in range(len(dist)):
        if dist[v] < min_dist and not visited[v]:
            min_dist = dist[v]
            min_index = v

    return min_index


def generate_random_graph(n, m):
  """Generates a random graph with n nodes and m edges."""

  graph = [[0 for i in range(n)] for j in range(n)]

  for i in range(m):
    u = random.randint(0, n - 1)
    v = random.randint(0, n - 1)
    weight = random.randint(1, 100)
    graph[u][v] = weight

  return graph


def main():
  """Empirically analyzes the time complexity of Dijkstra's algorithm."""

  # Generate a random graph with 100 nodes and 1000 edges.
  comp = 0 #key comparisons
  graph = generate_random_graph(10, 25)
  """
  print('Original adjacency matrix:') ###Prints original graph
  for row in graph:
    print(row)

  graph = [
    [0, 4, 0, 0, 0, 0, 0, 8, 0],
    [4, 0, 8, 0, 0, 0, 0, 11, 0],
    [0, 8, 0, 7, 0, 4, 0, 0, 2],
    [0, 0, 7, 0, 9, 14, 0, 0, 0],
    [0, 0, 0, 9, 0, 10, 0, 0, 0],
    [0, 0, 4, 14, 10, 0, 2, 0, 0],
    [0, 0, 0, 0, 0, 2, 0, 1, 6],
    [8, 11, 0, 0, 0, 0, 1, 0, 7],
    [0, 0, 2, 0, 0, 0, 6, 7, 0],
  ]
  """
  # Start the timer.
  start_time = time.time()

  # Run Dijkstra's algorithm.
  distances, comp = dijkstra(graph, 0)

  # Stop the timer.
  end_time = time.time()

  # Print the time it took to run the algorithm.
  print("Time to run Dijkstra's algorithm:", end_time - start_time)
  print("Number of key comparisons: ", comp)

  """
  # Print the shortest path 
  print("Vertex\tDistance from Start")
  for i, distance in enumerate(distances):
      print(f"{i}\t{distance}")
  """

if __name__ == "__main__":
  main()
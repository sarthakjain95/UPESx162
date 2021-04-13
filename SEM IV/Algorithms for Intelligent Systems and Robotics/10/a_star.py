
class node:

    def __init__(self, label, distance_to_target):
        self.label = label
        self.dist = distance_to_target
        self.connections = {}

    def add_connection(self, other_node_label, distance):
        self.connections[other_node_label] = distance


def optimal_path_a_star(nodes, start, end):

    path = [start]
    queue = [(c[0], c[1] + nodes[c[0]].dist) for c in nodes[start].connections.items()]
    reached_destination = False

    while len(queue) != 0 and reached_destination == False:

        # Sort by distance
        queue = sorted(queue, key=lambda x: x[1])
        print("Current queue:", queue)

        # Pop the most optimal node from queue
        n = queue[0]
        node, _ = n
        queue = queue[1:]

        # If the current most optimal node is not present in the connection
        # of the last node added to path, then that means that we've hit a roadblock
        # And we need to travel back a few step to the point which is connected to the
        # current most efficient node 'n'
        while node not in nodes[path[-1]].connections:
            path = path[:-1]
        # Then add this node to path
        path.append(node)

        # Added connections next to the most optimal node
        for next_node, next_node_dist in nodes[node].connections.items():
            queue.append((next_node, next_node_dist + nodes[next_node].dist))
            if next_node == end:
                path.append(next_node)
                reached_destination = True
                break

    cost = 0
    for i in range(0, len(path)-1, 1):
        cost += nodes[path[i]].connections[path[i+1]]

    return path, cost


if __name__ == "__main__":

    # This graph is same as the one shown here:
    # https://www.youtube.com/watch?v=ySN5Wnu88nE

    nodes = {
        's': node('s',10), # Start
        'a': node('a', 9),
        'b': node('b', 7),
        'c': node('c', 8),
        'd': node('d', 8),
        'e': node('e', 0), # Destination
        'f': node('f', 6), 
        'g': node('g', 3),
        'h': node('h', 6),
        'i': node('i', 4),
        'j': node('j', 4),
        'k': node('k', 3),
        'l': node('l', 6),
    }

    # Adding connections
    nodes['s'].add_connection('a', 7)
    nodes['s'].add_connection('b', 2)
    nodes['s'].add_connection('c', 3)
    nodes['a'].add_connection('b', 3)
    nodes['a'].add_connection('d', 4)
    nodes['b'].add_connection('h', 1)
    nodes['b'].add_connection('d', 4)
    nodes['d'].add_connection('f', 5)
    nodes['h'].add_connection('g', 2)
    nodes['h'].add_connection('f', 3)
    nodes['g'].add_connection('e', 2)
    nodes['c'].add_connection('l', 2)
    nodes['l'].add_connection('i', 4)
    nodes['l'].add_connection('j', 4)
    nodes['j'].add_connection('i', 6)
    nodes['i'].add_connection('k', 4)
    nodes['j'].add_connection('k', 4)
    nodes['k'].add_connection('e', 5)

    path, travel_cost = optimal_path_a_star(nodes, 's', 'e')

    print("Path is:", path)
    print("Total travel cost:", travel_cost)

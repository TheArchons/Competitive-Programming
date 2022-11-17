#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

struct route {
    int end;
    int distance;
    int damage;
};

int main() {
    int hull_thickness, islands, routes;
    scanf("%d %d %d", &hull_thickness, &islands, &routes);

    vector<route> routes_arr[routes];

    for (int i = 0; i < routes; i++) {
        int start, end, distance, damage;
        scanf("%d %d %d %d", &start, &end, &distance, &damage);

        start--; end--;

        routes_arr[start].push_back({end, distance, damage});
        routes_arr[end].push_back({start, distance, damage});
    }

    int start_island, end_island;
    scanf("%d %d", &start_island, &end_island);

    start_island--; end_island--;

    int curr_island = start_island;

    queue<pair<int, int>> to_visit;
    to_visit.push(pair(curr_island, 0));

    int visits[islands];
    for (int i = 0; i < islands; i++) {
        visits[i] = -1;
    }
    visits[start_island] = 0;

    while (!to_visit.empty()) {
        curr_island = to_visit.front().first;
        int curr_damage = to_visit.front().second;
        to_visit.pop();

        vector<route> curr_routes = routes_arr[curr_island];
        for(int i = 0; i < curr_routes.size(); i++) {
            route curr_route = curr_routes[i];
            if ((visits[curr_route.end] == -1 || visits[curr_route.end] > curr_damage + curr_route.distance) && curr_damage + curr_route.damage <= hull_thickness) {
                visits[curr_route.end] = (visits[curr_route.end] == -1 ? 0 : visits[curr_route.end]) + curr_route.distance;
                to_visit.push(pair(curr_route.end, curr_damage + curr_route.distance));
            }
        }
    }

    printf("%d", visits[end_island]);
}
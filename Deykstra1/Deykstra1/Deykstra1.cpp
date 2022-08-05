#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <string>

using namespace std;

bool is_in_vector(vector<string> processed, string node) {
    for (auto iter = processed.begin(); iter != processed.end(); iter++)
    {
        if ((*iter) == node)
        {
            return 1;
        }
    }
    return 0;
}

string find_cost_node(map<string, int>& costs, vector<string> processed) {
    int lowest_cost = std::numeric_limits<int>::max();
    string lowest_cost_node = "";

    for (auto iter = costs.begin(); iter != costs.end(); iter++) {
        int cost = (*iter).second;
        if (cost < lowest_cost && !is_in_vector(processed, (*iter).first))
        {
            lowest_cost = cost;
            lowest_cost_node = (*iter).first;
        }
    }
    return lowest_cost_node;
}

int deykstra(map<string, int>& costs, map<string, map<string, int>> graph, map<string, string> parents, vector<string> processed) {
    string node = find_cost_node(costs, processed);
    while (node != "")
    {
        int cost = costs[node];
        map<string, int> neighbors = graph[node];
        for (auto iter = neighbors.begin(); iter != neighbors.end(); iter++) {
            int new_cost = cost + (*iter).second;
            if (costs[(*iter).first] > new_cost) {
                costs[(*iter).first] = new_cost;
                parents[(*iter).first] = node;
            }
        }
        processed.push_back(node);
        string node = find_cost_node(costs, processed);
    }
    return costs["fin"];
}

int main()
{
    map<string, map<string, int>> graph;
    graph["start"] = {};
    graph["start"]["a"] = 6;
    graph["start"]["b"] = 2;
    graph["a"] = {};
    graph["a"]["fin"] = 1;
    graph["b"] = {};
    graph["b"]["a"] = 3;
    graph["b"]["fin"] = 5;

    map<string, int> costs;
    costs["a"] = 6;
    costs["b"] = 2;
    costs["fin"] = std::numeric_limits<int>::max();

    map<string, string> parents;
    parents["a"] = "start";
    parents["b"] = "start";
    parents["fin"] = "";

    vector<string> processed;

    

    cout << deykstra(costs, graph, parents, processed);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

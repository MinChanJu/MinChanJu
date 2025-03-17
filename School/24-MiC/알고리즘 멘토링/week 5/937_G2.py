import heapq
import sys
input = sys.stdin.readline

def dijkstra(start, graph, N):
    dis_list = [2000000]*(N+1)
    dis_list[start] = 0
    heap = [(0,start)]
    while heap:
        cost, node = heapq.heappop(heap)
        if dis_list[node] < cost: continue
        for weight, c_node, in graph[node]:
            if weight + dis_list[node] < dis_list[c_node]:
                dis_list[c_node] = weight+dis_list[node]
                heapq.heappush(heap, (dis_list[c_node], c_node))
    return dis_list

pos = []
for _ in range(int(input())) :
    n, m, t = map(int, input().split())
    s, g, h = map(int, input().split())
    wei_graph = {i:[] for i in range(1,n+1)}
    des_list = []
    
    for i in range(m) :
        a, b, d = map(int, input().split())
        wei_graph[a].append((d,b))
        wei_graph[b].append((d,a))
        if ((g==a)and(h==b)) or ((g==b)and(h==a)):
            g_h = d

    for i in range(t):
        des = int(input())
        des_list.append(des)
    
    des_list.sort()
    
    start_s= dijkstra(s, wei_graph, n)
    start_g= dijkstra(g, wei_graph, n)
    start_h= dijkstra(h, wei_graph, n)

    for des_i in des_list:
        ex1 = start_s[g] + g_h + start_h[des_i]
        ex2 = start_s[h] + g_h + start_g[des_i]
        if start_s[des_i] == min(ex1,ex2):
            pos.append(des_i)
            pos.append(" ")
    pos.append("\n")

print(*pos,sep="",end="")
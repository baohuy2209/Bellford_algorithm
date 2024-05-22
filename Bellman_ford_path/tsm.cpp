#include "tsm.h"
int traveling(int matrix[][1000], int num_vertices, char start){
    int value[num_vertices]; 
    int previous[num_vertices]; 
    for(int i = 0 ; i < num_vertices ; i++){
        value[i] = INF; 
        previous[i] = -1; 
    }
    int source = convert_char_to_enum(start);
    value[source] = 0; // source 

    for(int i = 1; i < num_vertices; i++){
        for(int u = 0; u < num_vertices; u++){
            for(int v = 0; v < num_vertices; v++){
                int weight = matrix[u][v]; 
                if(weight == 0){
                    continue; 
                }else{
                    if(value[u] + weight < value[v]){
                        value[v] = value[u]+weight; 
                        previous[v] = u; 
                    }
                }
            }
        }
    }
    bool has_negative_cycle = false; 
    for(int u = 0; u < num_vertices; u++){
        for(int v = 0; v < num_vertices; v++){
            int weight = matrix[u][v];
            if(weight == 0){
                continue; 
            }else{
                if(value[u] + weight < value[u]){
                    has_negative_cycle = true; 
                    break; 
                }
            }
        }
    }
    if(!has_negative_cycle){
        // short_path(source, destination, previous); 
        for(int i = 0; i < num_vertices; i++){
            if(i == source){
                continue; 
            }else{
                string short_path = "";
                print_path(i, previous,short_path);
                char end = convert_enum_to_char(i);  
                string str_end(1,end); 
                short_path = short_path+" "+str_end; 
                cout<<short_path<<endl; 
            }
        }
        return source; 
    }else{
        cout<<"Has a negative cycle"<<endl; 
    }
}
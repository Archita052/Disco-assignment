/**
 * Group ID - 52
 * Member 1 Name - Prisha Agarwal
 * Member 1 BITS ID - 2022A7PS0121P
 * Member 2 Name - Archita Agarwal
 * Member 2 BITS ID - 2022A7PS0135P
 * Member 3 Name - Tanupriya
 * Member 3 BITS ID - 2022A7PS0038P
*/

// ---------------------------DO NOT MODIFY (Begin)------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Graph {
    int n; // Size of the graph
    int** adj; // Adjacency matrix
    char** station_names; // Array of station names
} Graph;

/**
 * This function has been pre-filled. It reads the input testcase 
 * and creates the Graph structure from it.
*/
Graph* create_graph(char input_file_path[]) {
//Vikas commented line    FILE* f = fopen(input_file_path, "r");
    Graph* g = (Graph*)malloc(sizeof(Graph));
    // Size of graph
//Vikas commented line    fscanf(f, "%d", &(g->n));
     g -> n = 6;
    // Names of stations
    g->station_names = (char**)malloc(g->n * sizeof(char*));
    for(int i = 0; i < g->n; i++) {
        g->station_names[i] = (char*)malloc(100 * sizeof(char));
//Vikas commented line        fscanf(f, "%s", g->station_names[i]);
    }
// Below station names are hardcoded
     g->station_names[0] = "Amritsar";
     g->station_names[1] = "Bangalore";
     g->station_names[2] = "Chennai";
     g->station_names[3] = "Delhi";
     g->station_names[4] = "Faridabad";
     g->station_names[5] = "Gurgaon";
//     g->station_names[6] = "CityG";
//     g->station_names[7] = "CityH";

    // Adjacency matrix
    g->adj = (int**)malloc(g->n * sizeof(int*));
    for(int i = 0; i < g->n; i++) {
        g->adj[i] = calloc(g->n, sizeof(int));
    }

/* Below code is commented by Vikas
    int edges;
    fscanf(f, "%d", &edges);
    for(int i = 0; i < edges; i++) {
        int x, y;
        fscanf(f, "%d%d", &x, &y);
        g->adj[x][y] = 1;
        g->adj[y][x] = 1;
    }
*/
// Below graph is hardcoded by Vikas
// Testcase 1 graph         

   g->adj[0][1] = 1;
   g->adj[1][0] = 1;
   g->adj[1][2] = 1;
   g->adj[2][1] = 1;
   g->adj[2][3] = 1;
   g->adj[3][2] = 1;
   g->adj[3][0] = 1;
   g->adj[0][3] = 1;
   g->adj[0][4] = 1;
   g->adj[4][0] = 1;
   g->adj[4][5] = 1;
   g->adj[5][4] = 1;

/* Testcase 2 Graph
   g->adj[0][1] = 1;
   g->adj[1][0] = 1;
   g->adj[1][2] = 1;
   g->adj[2][1] = 1;
   g->adj[0][2] = 1;
   g->adj[2][0] = 1;
   g->adj[2][3] = 1;
   g->adj[3][2] = 1;
   g->adj[3][4] = 1;
   g->adj[4][3] = 1;
   g->adj[3][5] = 1;
   g->adj[5][3] = 1;

// Testcase 3 Graph 
   g->adj[0][5] = 1;
   g->adj[5][0] = 1;
   g->adj[0][4] = 1;
   g->adj[4][0] = 1;
   g->adj[0][3] = 1;
   g->adj[3][0] = 1;
   g->adj[4][5] = 1;
   g->adj[5][4] = 1;
   g->adj[4][3] = 1;
   g->adj[3][4] = 1;
   g->adj[6][4] = 1;
   g->adj[4][6] = 1;
   g->adj[3][6] = 1;
   g->adj[6][3] = 1;
   g->adj[5][6] = 1;
   g->adj[6][5] = 1;
   g->adj[1][7] = 1;
   g->adj[7][1] = 1;
*/

//Vikas commented line    fclose(f);
    return g;
}
// ---------------------------DO NOT MODIFY (End)------------------------------

/**
 * Q.1 
 * Return the number of junctions.
*/
int find_junctions(Graph* g) {
    
    int count = 0;
    int i, j;
    
    for (i=0; i<g->n; i++)
    {
        int connections = 0;
        
        for (j=0; j<g->n ; j++)
        {
           connections = connections + g->adj[i][j];  
        }
        if (connections > 3)
        count++;
    }
    return count;
}

/**
 * Q.2
 * Return true if the tour specified in the question is possible for this 
 * graph, else return false.
 * Parameter SAME_STATION - If it is true, then question 2(a) must be solved. 
 * If false, then question 2(b) must be solved.
*/
bool sheldons_tour(Graph* g, bool SAME_STATION) {

// Q2.a we are checking the presence of Euler Graph in graph
// Check the degree of each vertex. All vertex should have even degree

// Q2.b We are checking the presence of Euler path in graph 
// Either the degree of all vertex should be even or the Odd degree 
// vertex should be equal to 2

  int degree_vertex[g->n];
  int i, j;

  for (i=0; i<g->n; i++)
  {
      degree_vertex[i] = 0;
  }
  
  for (i=0; i<g->n; i++)
  {
     for (j=0; j< g->n ; j++)
     {
       if (g->adj[i][j] == 1)
         degree_vertex[i] ++;
     }
   }


   if (SAME_STATION)
   {
     for (i =0; i<g->n; i++)
     {
       if (((degree_vertex[i] % 2) == 1))
         return false;
     }  
   }
   else
   {
      int count = 0;
      for (i =0; i<g->n; i++)
      {
        if (((degree_vertex[i] % 2) == 1))
          count++;
      }
      if (count == 2)
      return true;
      else
      return false;
   }  

return true;

}

/**
 * Q.3
 * Return closure, an n * n matrix filled with 0s and 1s as required. 
*/
int** warshall(Graph* g) {
    // Do not modify or delete pre-filled code!
    int** closure = (int**)malloc(g->n * sizeof(int*));
    for(int i = 0; i < g->n; i++) {
        closure[i] = calloc(g->n, sizeof(int));
    }
    // Code goes here
    
  int i, j, k;
  
  for (i=0; i<g->n ; i++)
  {
    for (j=0; j<g->n ; j++)
    {
       closure[i][j] = g-> adj[i][j]; // create copy of graph
       if (i == j )
       {
         closure[i][j] =1; //station is connected to itself
       }
    }
  }

  for (k=0; k<g->n ; k++)
  {
    for (i=0; i<g->n ; i++)
    {
      for (j=0; j<g->n ; j++)
      {
         closure[i][j] = (closure[i][j] || (closure[i][k] && closure[k][j])); 
       

       }
     }
   }

    return closure; // Do not modify
}

/**
 * Q.3
 * Return the number of impossible pairs.
*/
int find_impossible_pairs(Graph* g) {
    int** closure = warshall(g); // Do not modify
    int i, j, city_pair = 0;
    if (closure != NULL)
    {

//       printf("Transitive Closure =\n");
       for (i=0; i<g->n ; i++)
       {
          for(j=0; j <g->n; j++)
          {
//             printf("%d ", closure[i][j]);
             if (closure[i][j] == 0)
                city_pair++;
          }
//          printf("\n");
        }
    }
    return (city_pair/2); // We counted the city pair twice, therefore divided by 2    
}

/**
 * Q.4
 * Return the number of vital train tracks.
*/
int find_vital_train_tracks(Graph* g) {
    int vital_tracks =0;
    int i,j, start_edge, end_edge, impossible_pairs;

    Graph* new_g = (Graph*)malloc(sizeof(Graph));
    // Size of graph
     new_g -> n = g -> n;
    // Names of stations
    new_g->station_names = NULL; 
    // Adjacency matrix of new graph
    new_g->adj = (int**)malloc(new_g->n * sizeof(int*));
    for(int i = 0; i < new_g->n; i++) {
        new_g->adj[i] = calloc(g->n, sizeof(int));
    }
    for (i=0;i<g->n; i++)
    {
        for (j=0; j<g->n; j++)
        {
            new_g->adj[i][j] = g->adj[i][j];
        }
    }

// Store the impossible pairs for original graph

    impossible_pairs = find_impossible_pairs(new_g);

// Logic 1: A track is vital if it is Pendant node. That means it is connected
// with only one vertex.
    for (i=0;i<g->n; i++)
    {
        for (j=0; j<g->n; j++)
        {
            if (new_g->adj[i][j] == 1)
            {
                start_edge = i;
                end_edge = j;
                new_g->adj[start_edge][end_edge] =0;
                new_g->adj[end_edge][start_edge] =0;
                if (find_impossible_pairs(new_g) > impossible_pairs)
                {
                    vital_tracks++;
                    new_g->adj[start_edge][end_edge] = 1;
                    new_g->adj[end_edge][start_edge] = 1;

                    start_edge = 0;
                    end_edge = 0;
}
                else
                {
                    new_g->adj[start_edge][end_edge] = 1;
                    new_g->adj[end_edge][start_edge] = 1;
                    start_edge = 0;
                    end_edge = 0; 
                }
            }
        }
    }

    return (vital_tracks/2); //We counted the track twice
}

/**
 * Q.5
 * Return upgrades, an array of size n.
 * upgrades[i] should be 0 if railway station i gets a restaurant
 * upgrades[i] should be 1 if railway station i gets a maintenance depot
 * If it is not possible to upgrade, then return "-1" in the entire array
*/
int* upgrade_railway_stations(Graph* g) {
    int* upgrades = calloc(g->n, sizeof(int)); // Do not modify
    int i, j;
    // Code goes here

   // Iteratively assign colour to the vertex. If all vertices are satisfied good otherwise return false
   
   for (i=0 ; i < g->n ; i++)
      upgrades[i] = -1;
   for (i=0; i < g->n ; i++)
   {
     for (j=0; j< g->n ; j++)
     {
       if ( i != j)
       {
         if (g-> adj[i][j] == 1)
         {
           if (upgrades[j] == -1 || upgrades[j] == ((i+1) % 2))
           {
              upgrades[j] = (upgrades[i] +1) % 2;
           }
           else
           {
           }
         }
       }
     }
   }

    return upgrades; // Do not modify
}

/**
 * Q.6
 * Return distance between X and Y
 * city_x is the index of X, city_y is the index of Y
*/
int distance(Graph* g, int city_x, int city_y) {
  int distance_matrix[g->n][g->n];
  int link[g->n][g->n];
  int i, j, k;
  
  for (i=0; i<g->n ; i++)
  {
    for (j=0; j<g->n ; j++)
    {
       distance_matrix[i][j] = -1; //initialize distance matrix
       link[i][j] = g-> adj[i][j]; // create copy of graph
       if (i == j )
       {
         link[i][j] =1;
         distance_matrix[i][j] = 0;
       }
        if (g-> adj[i][j] == 1)
        {
          distance_matrix[i][j] = 1;  // adjacent station
        }

    }
  }

  for (k=0; k<g->n ; k++)
  {
    for (i=0; i<g->n ; i++)
    {
      for (j=0; j<g->n ; j++)
      {
         link[i][j] = (link[i][j] || (link[i][k] && link[k][j])); 
       
         if ((i != j) && (link[i][j] != g-> adj[i][j]) && distance_matrix[i][j] == -1)
         { 

            distance_matrix[i][j] = distance_matrix[i][k] + distance_matrix[k][j];
         }
       }
     }
   }

  return distance_matrix[city_x][city_y];

}

/**
 * Q.7
 * Return the index of any one possible railway capital in the network
*/
int railway_capital(Graph* g) {
    int i, j, dist, min_dist, min_node, distance_sum[g->n];
    min_node = -1; //initialize 
    min_dist =0; //initialize 
    for (i=0; i <g->n ; i++)
    {
        distance_sum[i] =0; //initialize to 0
    }
    
    for (i=0; i <g->n ; i++)
    {
        for (j=0; j<g->n; j++)
        {
           if (i != j)
           {
               dist = distance(g, i, j);
               if (dist == -1)
               return -1; // network is not connected
               
               distance_sum[i] = dist + distance_sum[i]; 
//               printf("dist %d, distance_sum %d\n", dist, distance_sum[i]);
           }
        }
    }
    min_dist = distance_sum[i]; //initialize min_dist to 1st station
    min_node = 0; //initialize min_node to 1st station
    
    for(i=0; i<g->n;i++)
    {
        if (min_dist > distance_sum[i])
        {
            min_dist = distance_sum[i];
            min_node = i;
  
        }
        
    }
    return min_node;
}

/**
 * Helper function for Q.8
*/
bool maharaja_express_tour(Graph* g, int source, int current_city, int previous_city, int* visited) {
    
    int j =0;

    
    if (visited[current_city]) //We reached a city that was already visited previously. 
    return false;
    
    visited[current_city] = 1;
  
    // Looping through graph to find out next connected city
    
    for (j=0; j <g->n; j++)
    {
        // Looping through graph to find out next connected city
        // If connected city is previous city then we skip 
        
        if ((g->adj[current_city][j] == 1) && (j != previous_city))
        {
            //If next connected city is not previous city but the source 
            // city itself then we found a loop
            // A (Source) -- B --- C --- A
            
            if (j == source)
              return true;
            else
            // Move to next city in list
              return maharaja_express_tour(g, source, j, current_city, visited);
        }
    }
    
    // We reached till the last stn. No loop found
    return false;
}

/**
 * Q.8 
 * Return true if it is possible to have a Maharaja Express tour 
 * starting from source city, else return false. 
*/
bool maharaja_express(Graph* g, int source) {
    int* visited = (int*)malloc(g->n * sizeof(int)); 
    for(int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }
    // Hint: Call the helper function and pass the visited array created here.
    int i;
    
    // Visited Source city
    visited[source] = 1; 
    
    for (i=0; i <g->n ; i++)
    {
        if (g->adj[source][i] == 1)
        {
           //We are moving to next city that is connected with source city
           
           return maharaja_express_tour(g, source, i, source, visited );
        }
    }
}

int main() {
    char input_file_path[100] = "testcase_1.txt"; // Can be modified
    Graph* g = create_graph(input_file_path); // Do not modify

        
    // Code goes here
   int i, j, dist, vital_tracks;
   int* upgrade_list =NULL;
   /* print the graph matrix
   for (i=0; i<g->n ; i++)
   {
     for(j=0; j <g->n; j++)
     {
       printf("%d ", g->adj[i][j]);
     }
     printf("\n");
   }
*/

    // Q1. Find number of junctions if connections is 4 or more
    printf("Q1.\n");
    printf("Number of junctions = %d \n", find_junctions(g));
    printf("\n");
    // Q2. Sheldon tour
    
    printf("Q2. \n\n");
    bool result;
    result = sheldons_tour(g, true);
    if (result)
    {
    printf("Sheldon's tour (ending in same city as start) is POSSIBLE\n");
    }
    else
    printf("Sheldon's tour (ending in same city as start) is IMPOSSIBLE\n");

    if ((sheldons_tour(g, false)))
    printf("Sheldon's tour (ending in different city as start) is POSSIBLE\n");
    else
    printf("Sheldon's tour (ending in different city as start) is IMPOSSIBLE\n");
    printf("\n");

    // Q3. warshall
    
    printf("Q3.\n");
    printf ("Impossible to travel city pairs = %d \n", find_impossible_pairs(g));
    printf("\n");
    
    // Q4. Find vital train tracks
    printf("Q4\n");
    printf("Number of vital train tracks = %d \n", find_vital_train_tracks(g));
    printf("\n");

    // Q5. Upgrading the Railway Stations
    
    printf("Q5\n");
    printf("Railway Station Upgrades:\n");
    upgrade_list= upgrade_railway_stations(g);
    
    for (i=0; i <g->n ; i++)
    {
        if (upgrade_list[i] == 1)
        printf("%s = Restaurant\n", g->station_names[i] );
        else
        printf("%s = Maintenance Depot \n", g->station_names[i] );
    }
    
    printf("\n");
    
        // Q6. Distance between Stn 1 and stn 2
    printf("Q6. \n");
    printf("Distance between %s and %s = %d\n", g->station_names[3], g->station_names[4], distance(g,3,4));
    printf("\n");
    
    // Q7 Find out Railway Capital
    printf("Q7. \n");
    
    if (railway_capital(g) == -1)
    {
        printf("No Capital found. Network is not connected \n");
    }
    else
    {
       
       printf("Railway Capital = %s \n", g->station_names[railway_capital(g)]);
    }
    printf("\n");
    
    // Q8.Looping through all the stations one by one to check if Maharaja 
    // Express Tour is possible
    printf("Q8. \n");
    for (i=0; i <g->n ; i++)
    {
        if (maharaja_express(g, i))
            printf("Maharaja Express tour starting from %s is POSSIBLE \n", g->station_names[i] );
        else
            printf("Maharaja Express tour starting from %s is IMPOSSIBLE \n", g->station_names[i] );
    }
    printf("\n");
    return 0;
    

}
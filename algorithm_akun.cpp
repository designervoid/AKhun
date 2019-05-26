#include <pch.h> 
#include <iostream> 
#include <vector> 
using namespace std; 
int a, b; 
vector < vector<int> > g; 
vector<int> ab; 
vector<bool> waste; 

bool akun(int v) { 
if (waste[v]) return false; 
waste[v] = true; 
for (size_t i = 0; i<g[v].size(); ++i) { 
int to = g[v][i]; 
if(to!=-1){
if (ab[to] == -1 || akun(ab[to])) { 
ab[to] = v; 
return true; 
} 
}
} 
return false; 
} 

int main() { 
int a, b, c; 
cout << "Number of vertex:" << endl; 
cin >> a; 
cin >> b; 
for (int i = 0; i<a; i++) { 
vector<int> row; 
for (int j = 0; j < b; j++) 
{ 
cin >> c; 
row.push_back(c - 1); 
} 
g.push_back(row); 
} 

ab.assign(b, -1); 


for (int v = 0; v<a; ++v) { 
waste.assign(a, false); 
akun(v); 
} 

for (int i = 0; i<b; ++i) 
if (ab[i] != -1) 
cout << ab[i] + 1 << "-" << i + 1 << endl; 


return 0; 
}

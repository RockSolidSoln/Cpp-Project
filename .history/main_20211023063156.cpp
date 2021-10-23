// ----------------------------------------start of the program---------------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;


// -------------------------type definiations used in the function-------------------------------------------
typedef  vector<tuple<string,int,string,int>> vec;
typedef vector<array<int,5>> vec1;

//----------------------------------------Global variables-----------------------------------------------------
int status=0;
string username,password;
vec1 student;
%3CmxGraphModel%3E%3Croot%3E%3CmxCell%20id%3D%220%22%2F%3E%3CmxCell%20id%3D%221%22%20parent%3D%220%22%2F%3E%3CmxCell%20id%3D%222%22%20value%3D%22view%20function%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221000%22%20y%3D%2240%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%223%22%20value%3D%22find%20minimum%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22-100%22%20y%3D%22340%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%224%22%20value%3D%22find%20maximum%26amp%3Bnbsp%3B%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22240%22%20y%3D%22340%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%225%22%20value%3D%22find%20the%20minimum%20of%20specific%20column%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22-210%22%20y%3D%22470%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%226%22%20value%3D%22find%20the%20minimum%20of%20specific%20row%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22-50%22%20y%3D%22470%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%227%22%20value%3D%22find%20the%20maximum%20of%20specific%20column%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22160%22%20y%3D%22460%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%228%22%20value%3D%22find%20the%20maximum%26lt%3Bspan%20style%3D%26quot%3Bcolor%3A%20rgba(0%20%2C%200%20%2C%200%20%2C%200)%20%3B%20font-family%3A%20monospace%20%3B%20font-size%3A%200px%26quot%3B%26gt%3B%253CmxGraphModel%253E%253Croot%253E%253CmxCell%2520id%253D%25220%2522%252F%253E%253CmxCell%2520id%253D%25221%2522%2520parent%253D%25220%2522%252F%253E%253CmxCell%2520id%253D%25222%2522%2520value%253D%2522find%2520the%2520minimum%2520of%2520specific%2520row%2522%2520style%253D%2522rounded%253D0%253BwhiteSpace%253Dwrap%253Bhtml%253D1%253B%2522%2520vertex%253D%25221%2522%2520parent%253D%25221%2522%253E%253CmxGeometry%2520x%253D%2522360%2522%2520y%253D%2522780%2522%2520width%253D%2522120%2522%2520height%253D%252260%2522%2520as%253D%2522geometry%2522%252F%253E%253C%252FmxCell%253E%253C%252Froot%253E%253C%252FmxGraphModel%253E%26lt%3B%2Fspan%26gt%3B%26amp%3Bnbsp%3Bof%20specific%20row%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22320%22%20y%3D%22460%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%229%22%20value%3D%22findmean%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22550%22%20y%3D%22340%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2210%22%20value%3D%22%26lt%3Bspan%26gt%3Bfind%20the%20mean%20of%20specific%20column%26lt%3B%2Fspan%26gt%3B%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22490%22%20y%3D%22460%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2211%22%20value%3D%22%26lt%3Bspan%26gt%3Bfind%20the%20mean%20of%20specific%20row%26lt%3B%2Fspan%26gt%3B%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22640%22%20y%3D%22460%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2212%22%20value%3D%22find%20the%20sum%20of%20specific%20column%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22480%22%20y%3D%22620%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2213%22%20value%3D%22find%20the%20sum%20of%20specific%20row%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22650%22%20y%3D%22620%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2214%22%20value%3D%22find%20variance%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221010%22%20y%3D%22335%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2215%22%20value%3D%22find%20standard%20deviation%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221440%22%20y%3D%22325%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2216%22%20value%3D%22%26lt%3Bspan%26gt%3Bfind%20the%20variance%20of%20specific%20column%26lt%3B%2Fspan%26gt%3B%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22820%22%20y%3D%22470%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2217%22%20value%3D%22%26lt%3Bspan%26gt%3Bfind%20the%20variance%20of%20specific%20row%26lt%3B%2Fspan%26gt%3B%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221170%22%20y%3D%22470%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2218%22%20value%3D%22%26lt%3Bspan%26gt%3Bfind%20the%20standard%20deviation%20of%20specific%20column%26lt%3B%2Fspan%26gt%3B%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221340%22%20y%3D%22470%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2219%22%20value%3D%22%26lt%3Bspan%26gt%3Bfind%20the%20standard%20deviation%20of%20specific%20row%26lt%3B%2Fspan%26gt%3B%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221540%22%20y%3D%22465%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2220%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BexitX%3D0.5%3BexitY%3D0%3BexitDx%3D0%3BexitDy%3D0%3BentryX%3D0.5%3BentryY%3D1%3BentryDx%3D0%3BentryDy%3D0%3B%22%20edge%3D%221%22%20source%3D%223%22%20target%3D%222%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22310%22%20y%3D%22260%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22360%22%20y%3D%22210%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2221%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BexitX%3D0.5%3BexitY%3D0%3BexitDx%3D0%3BexitDy%3D0%3BentryX%3D0.5%3BentryY%3D1%3BentryDx%3D0%3BentryDy%3D0%3B%22%20edge%3D%221%22%20source%3D%224%22%20target%3D%222%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22310%22%20y%3D%22260%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22360%22%20y%3D%22210%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2222%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BentryX%3D0.5%3BentryY%3D0%3BentryDx%3D0%3BentryDy%3D0%3BexitX%3D0.5%3BexitY%3D1%3BexitDx%3D0%3BexitDy%3D0%3B%22%20edge%3D%221%22%20source%3D%222%22%20target%3D%229%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22360%22%20y%3D%22210%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22410%22%20y%3D%22160%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2223%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BentryX%3D0.5%3BentryY%3D0%3BentryDx%3D0%3BentryDy%3D0%3BexitX%3D0.5%3BexitY%3D1%3BexitDx%3D0%3BexitDy%3D0%3B%22%20edge%3D%221%22%20source%3D%222%22%20target%3D%2214%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22360%22%20y%3D%22210%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22410%22%20y%3D%22160%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2224%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BentryX%3D0.5%3BentryY%3D1%3BentryDx%3D0%3BentryDy%3D0%3BexitX%3D0.5%3BexitY%3D0%3BexitDx%3D0%3BexitDy%3D0%3B%22%20edge%3D%221%22%20source%3D%2215%22%20target%3D%222%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221275%22%20y%3D%22330%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221325%22%20y%3D%22280%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2225%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BexitX%3D0.5%3BexitY%3D0%3BexitDx%3D0%3BexitDy%3D0%3B%22%20edge%3D%221%22%20source%3D%225%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22-90%22%20y%3D%22450%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22-40%22%20y%3D%22400%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2226%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BentryX%3D0.58%3BentryY%3D-0.052%3BentryDx%3D0%3BentryDy%3D0%3BentryPerimeter%3D0%3B%22%20edge%3D%221%22%20target%3D%226%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22-40%22%20y%3D%22400%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%2210%22%20y%3D%22350%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2227%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BexitX%3D0.5%3BexitY%3D0%3BexitDx%3D0%3BexitDy%3D0%3B%22%20edge%3D%221%22%20source%3D%227%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22250%22%20y%3D%22450%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22300%22%20y%3D%22400%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2228%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BentryX%3D0.5%3BentryY%3D0%3BentryDx%3D0%3BentryDy%3D0%3B%22%20edge%3D%221%22%20target%3D%228%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22300%22%20y%3D%22400%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22350%22%20y%3D%22350%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2229%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BexitX%3D0.5%3BexitY%3D0%3BexitDx%3D0%3BexitDy%3D0%3B%22%20edge%3D%221%22%20source%3D%2210%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22560%22%20y%3D%22450%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22610%22%20y%3D%22400%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2230%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BentryX%3D0.5%3BentryY%3D0%3BentryDx%3D0%3BentryDy%3D0%3B%22%20edge%3D%221%22%20target%3D%2211%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22610%22%20y%3D%22400%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22660%22%20y%3D%22350%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2231%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BexitX%3D0.417%3BexitY%3D0%3BexitDx%3D0%3BexitDy%3D0%3BexitPerimeter%3D0%3B%22%20edge%3D%221%22%20source%3D%2212%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22500%22%20y%3D%22570%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22550%22%20y%3D%22520%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2232%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BentryX%3D0.5%3BentryY%3D0%3BentryDx%3D0%3BentryDy%3D0%3B%22%20edge%3D%221%22%20target%3D%2213%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22700%22%20y%3D%22520%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22750%22%20y%3D%22470%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2233%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BexitX%3D0.5%3BexitY%3D0%3BexitDx%3D0%3BexitDy%3D0%3BentryX%3D0.5%3BentryY%3D1%3BentryDx%3D0%3BentryDy%3D0%3B%22%20edge%3D%221%22%20source%3D%2216%22%20target%3D%2214%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22880%22%20y%3D%22450%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22930%22%20y%3D%22400%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2234%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BentryX%3D0.5%3BentryY%3D0%3BentryDx%3D0%3BentryDy%3D0%3BexitX%3D0.5%3BexitY%3D1%3BexitDx%3D0%3BexitDy%3D0%3B%22%20edge%3D%221%22%20source%3D%2214%22%20target%3D%2217%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221000%22%20y%3D%22400%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22980%22%20y%3D%22350%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2235%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BexitX%3D0.5%3BexitY%3D0%3BexitDx%3D0%3BexitDy%3D0%3BentryX%3D0.5%3BentryY%3D1%3BentryDx%3D0%3BentryDy%3D0%3B%22%20edge%3D%221%22%20source%3D%2218%22%20target%3D%2215%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221515%22%20y%3D%22445%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221565%22%20y%3D%22395%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2236%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BentryX%3D0.5%3BentryY%3D0%3BentryDx%3D0%3BentryDy%3D0%3BexitX%3D0.5%3BexitY%3D1%3BexitDx%3D0%3BexitDy%3D0%3B%22%20edge%3D%221%22%20source%3D%2215%22%20target%3D%2219%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221570%22%20y%3D%22395%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221610%22%20y%3D%22350%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2237%22%20value%3D%22find%20correlation%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221840%22%20y%3D%22325%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2238%22%20value%3D%22findmean%20of%20column%201%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221710%22%20y%3D%22465%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2239%22%20value%3D%22findmean%20of%20column%202%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221860%22%20y%3D%22465%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2240%22%20value%3D%22find%20sum%20of%20column%201%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221710%22%20y%3D%22595%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2241%22%20value%3D%22find%20sum%20of%20column%202%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221870%22%20y%3D%22595%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2242%22%20value%3D%22find%20sum%20of%20square%20of%20column%201%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221550%22%20y%3D%22595%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2243%22%20value%3D%22find%20sum%20of%26amp%3Bnbsp%3B%20square%20of%20column%202%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%222005%22%20y%3D%22595%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2244%22%20value%3D%22find%20sum%20of%20column1*column2%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%222000%22%20y%3D%22465%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2245%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BentryX%3D0.5%3BentryY%3D1%3BentryDx%3D0%3BentryDy%3D0%3BexitX%3D0.5%3BexitY%3D0%3BexitDx%3D0%3BexitDy%3D0%3B%22%20edge%3D%221%22%20source%3D%2238%22%20target%3D%2237%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221870%22%20y%3D%22365%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221920%22%20y%3D%22315%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2246%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BentryX%3D0.5%3BentryY%3D1%3BentryDx%3D0%3BentryDy%3D0%3BexitX%3D0.5%3BexitY%3D0%3BexitDx%3D0%3BexitDy%3D0%3B%22%20edge%3D%221%22%20source%3D%2240%22%20target%3D%2238%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221700%22%20y%3D%22585%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221750%22%20y%3D%22535%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2247%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BexitX%3D0.5%3BexitY%3D1%3BexitDx%3D0%3BexitDy%3D0%3BentryX%3D0.5%3BentryY%3D0%3BentryDx%3D0%3BentryDy%3D0%3B%22%20edge%3D%221%22%20source%3D%2237%22%20target%3D%2239%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221870%22%20y%3D%22365%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221920%22%20y%3D%22315%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2248%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BexitX%3D0.5%3BexitY%3D1%3BexitDx%3D0%3BexitDy%3D0%3BentryX%3D0.5%3BentryY%3D0%3BentryDx%3D0%3BentryDy%3D0%3B%22%20edge%3D%221%22%20source%3D%2237%22%20target%3D%2244%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221910%22%20y%3D%22395.0000000000002%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221930%22%20y%3D%22474.9999999999998%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2249%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BexitX%3D0.5%3BexitY%3D1%3BexitDx%3D0%3BexitDy%3D0%3BentryX%3D0.5%3BentryY%3D0%3BentryDx%3D0%3BentryDy%3D0%3B%22%20edge%3D%221%22%20source%3D%2239%22%20target%3D%2241%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221930%22%20y%3D%22535.0000000000002%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221950%22%20y%3D%22614.9999999999998%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2250%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BentryX%3D0.5%3BentryY%3D1%3BentryDx%3D0%3BentryDy%3D0%3BexitX%3D0.5%3BexitY%3D0%3BexitDx%3D0%3BexitDy%3D0%3B%22%20edge%3D%221%22%20source%3D%2242%22%20target%3D%2238%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221780%22%20y%3D%22745%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221780%22%20y%3D%22675%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2251%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BentryX%3D0.5%3BentryY%3D1%3BentryDx%3D0%3BentryDy%3D0%3BexitX%3D0.5%3BexitY%3D0%3BexitDx%3D0%3BexitDy%3D0%3B%22%20edge%3D%221%22%20source%3D%2243%22%20target%3D%2239%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221880%22%20y%3D%22765%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221880%22%20y%3D%22675%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2252%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BexitX%3D0.5%3BexitY%3D0%3BexitDx%3D0%3BexitDy%3D0%3BentryX%3D0.5%3BentryY%3D1%3BentryDx%3D0%3BentryDy%3D0%3B%22%20edge%3D%221%22%20source%3D%2237%22%20target%3D%222%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221615%22%20y%3D%22290%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221665%22%20y%3D%22240%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2253%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BexitX%3D0.567%3BexitY%3D0.986%3BexitDx%3D0%3BexitDy%3D0%3BexitPerimeter%3D0%3BentryX%3D0.5%3BentryY%3D0%3BentryDx%3D0%3BentryDy%3D0%3B%22%20edge%3D%221%22%20source%3D%222%22%20target%3D%2254%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22915%22%20y%3D%22150%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221934.1666666666667%22%20y%3D%22320%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2254%22%20value%3D%22find%20distinct%20members%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%222220%22%20y%3D%22335%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2255%22%20value%3D%22print%20table%20header%26amp%3Bnbsp%3B%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%222150%22%20y%3D%22465%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2256%22%20value%3D%22find%20every%20number%20in%20database%20and%20calculate%20its%20frequency%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%222295%22%20y%3D%22465%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2257%22%20value%3D%22print%20table%20body%26lt%3Bbr%26gt%3B(number%20and%20frequency)%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%222250%22%20y%3D%22610%22%20width%3D%22150%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2258%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BexitX%3D0.5%3BexitY%3D1%3BexitDx%3D0%3BexitDy%3D0%3BentryX%3D0.5%3BentryY%3D0%3BentryDx%3D0%3BentryDy%3D0%3B%22%20edge%3D%221%22%20source%3D%2254%22%20target%3D%2256%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%222270%22%20y%3D%22405%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%222280%22%20y%3D%22475%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2259%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BentryX%3D0.5%3BentryY%3D1%3BentryDx%3D0%3BentryDy%3D0%3BexitX%3D0.56%3BexitY%3D-0.014%3BexitDx%3D0%3BexitDy%3D0%3BexitPerimeter%3D0%3B%22%20edge%3D%221%22%20source%3D%2255%22%20target%3D%2254%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%222170%22%20y%3D%22655%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%222220%22%20y%3D%22605%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2260%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BentryX%3D0.449%3BentryY%3D1%3BentryDx%3D0%3BentryDy%3D0%3BentryPerimeter%3D0%3BexitX%3D0.5%3BexitY%3D0%3BexitDx%3D0%3BexitDy%3D0%3B%22%20edge%3D%221%22%20source%3D%2257%22%20target%3D%2256%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%222270%22%20y%3D%22605%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%222320%22%20y%3D%22555%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2261%22%20value%3D%22print%20histogram%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%222500%22%20y%3D%22335%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2262%22%20value%3D%22calculate%20the%20count%20of%20midpoints%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%222500%22%20y%3D%22465%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2263%22%20value%3D%22print%20the%20histogram%20bar%22%20style%3D%22rounded%3D0%3BwhiteSpace%3Dwrap%3Bhtml%3D1%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%222500%22%20y%3D%22575%22%20width%3D%22120%22%20height%3D%2260%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2264%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BentryX%3D0.5%3BentryY%3D0%3BentryDx%3D0%3BentryDy%3D0%3B%22%20edge%3D%221%22%20target%3D%2262%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%222560%22%20y%3D%22395%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%222610%22%20y%3D%22345%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2265%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BentryX%3D0.558%3BentryY%3D-0.069%3BentryDx%3D0%3BentryDy%3D0%3BentryPerimeter%3D0%3B%22%20edge%3D%221%22%20target%3D%2263%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%222560%22%20y%3D%22525%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%222610%22%20y%3D%22475%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2266%22%20value%3D%22%22%20style%3D%22endArrow%3Dnone%3Bhtml%3D1%3Brounded%3D0%3BexitX%3D0.5%3BexitY%3D0%3BexitDx%3D0%3BexitDy%3D0%3BentryX%3D0.5%3BentryY%3D1%3BentryDx%3D0%3BentryDy%3D0%3B%22%20edge%3D%221%22%20source%3D%2261%22%20target%3D%222%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221860%22%20y%3D%22250%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221910%22%20y%3D%22200%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2267%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22-140%22%20y%3D%22450%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22-100%22%20y%3D%22420%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2268%22%20value%3D%22minimum%20of%20column%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22-190%22%20y%3D%22410%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2269%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%2230%22%20y%3D%22460%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22-10%22%20y%3D%22410%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2270%22%20value%3D%22minimum%20of%20row%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%2210%22%20y%3D%22410%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2271%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22220%22%20y%3D%22450%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22250%22%20y%3D%22420%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2272%22%20value%3D%22maximum%20of%20column%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22170%22%20y%3D%22410%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2273%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22390%22%20y%3D%22450%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22350%22%20y%3D%22410%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2274%22%20value%3D%22maximum%20of%20row%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22380%22%20y%3D%22410%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2275%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22540%22%20y%3D%22450%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22580%22%20y%3D%22410%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2276%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22710%22%20y%3D%22450%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22650%22%20y%3D%22410%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2277%22%20value%3D%22mean%20of%20row%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22690%22%20y%3D%22410%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2278%22%20value%3D%22mean%20of%20column%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22500%22%20y%3D%22410%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2279%22%20value%3D%22sum%20of%20column%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22460%22%20y%3D%22550%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2280%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22515%22%20y%3D%22600%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22530%22%20y%3D%22540%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2281%22%20value%3D%22sum%20of%20row%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22720%22%20y%3D%22550%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2282%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22720%22%20y%3D%22610%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22710%22%20y%3D%22540%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2283%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22690%22%20y%3D%22370%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22980%22%20y%3D%22370%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2284%22%20value%3D%22mean%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22740%22%20y%3D%22330%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2285%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22980%22%20y%3D%22410%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%22880%22%20y%3D%22460%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2286%22%20value%3D%22mean%20of%20column%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22880%22%20y%3D%22400%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2287%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221120%22%20y%3D%22400%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221230%22%20y%3D%22460%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2288%22%20value%3D%22mean%20of%20row%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221170%22%20y%3D%22400%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2289%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%22950%22%20y%3D%22460%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221040%22%20y%3D%22420%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2290%22%20value%3D%22variance%20of%20row%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221090%22%20y%3D%22450%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2291%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221170%22%20y%3D%22460%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221090%22%20y%3D%22420%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2292%22%20value%3D%22variance%20of%20column%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%22980%22%20y%3D%22450%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2293%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221130%22%20y%3D%22369.65999999999985%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221420%22%20y%3D%22369.65999999999985%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2294%22%20value%3D%22variance%26amp%3Bnbsp%3B%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221245%22%20y%3D%22335%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2295%22%20value%3D%22variance%20of%20column%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221350%22%20y%3D%22395%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2296%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221460%22%20y%3D%22395%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221380%22%20y%3D%22450%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2297%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221520%22%20y%3D%22390%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221600%22%20y%3D%22450%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2298%22%20value%3D%22variance%20of%20row%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221560%22%20y%3D%22395%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%2299%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221420%22%20y%3D%22465%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221490%22%20y%3D%22405%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22100%22%20value%3D%22stdv%20of%20column%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221450%22%20y%3D%22435%22%20width%3D%2240%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22101%22%20value%3D%22stdv%20of%20row%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221500%22%20y%3D%22435%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22102%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221580%22%20y%3D%22460%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221510%22%20y%3D%22400%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22103%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221610%22%20y%3D%22590%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221730%22%20y%3D%22530%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22104%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221780%22%20y%3D%22590%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221780%22%20y%3D%22530%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22105%22%20value%3D%22sum%20of%20square%20of%20column1%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221580%22%20y%3D%22535%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22106%22%20value%3D%22sum%20of%20square%20of%20column2%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221860%22%20y%3D%22550%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22107%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221925%22%20y%3D%22460%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221910%22%20y%3D%22400%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22108%22%20value%3D%22sum%20of%20column1%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221780%22%20y%3D%22545%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22109%22%20value%3D%22sum%20of%20column2%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%222030%22%20y%3D%22535%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22110%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%222050%22%20y%3D%22445%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221950%22%20y%3D%22395%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22111%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221770%22%20y%3D%22455%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221860%22%20y%3D%22395%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22112%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%222080%22%20y%3D%22590%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221980%22%20y%3D%22540%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22113%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%221925%22%20y%3D%22590%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%221915%22%20y%3D%22530%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22114%22%20value%3D%22sum%20of%20column2%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221860%22%20y%3D%22400%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22115%22%20value%3D%22sum%20of%20square%20of%20column2%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221860%22%20y%3D%22435%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22116%22%20value%3D%22mean%20of%20column1%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221750%22%20y%3D%22405%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22117%22%20value%3D%22sum%20of%20square%20of%20column1%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221760%22%20y%3D%22355%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22118%22%20value%3D%22sum%20of%20column1%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%221700%22%20y%3D%22380%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22119%22%20value%3D%22sum%20of%20column1*column2%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%222005%22%20y%3D%22385%22%20width%3D%2295%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22120%22%20value%3D%22%22%20style%3D%22endArrow%3Dclassic%3Bhtml%3D1%3Brounded%3D0%3B%22%20edge%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20width%3D%2250%22%20height%3D%2250%22%20relative%3D%221%22%20as%3D%22geometry%22%3E%3CmxPoint%20x%3D%222350%22%20y%3D%22545%22%20as%3D%22sourcePoint%22%2F%3E%3CmxPoint%20x%3D%222340%22%20y%3D%22600%22%20as%3D%22targetPoint%22%2F%3E%3C%2FmxGeometry%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22121%22%20value%3D%22number%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%222355%22%20y%3D%22535%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22122%22%20value%3D%22frequency%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%222355%22%20y%3D%22565%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3CmxCell%20id%3D%22123%22%20value%3D%22count%22%20style%3D%22text%3Bhtml%3D1%3BstrokeColor%3Dnone%3BfillColor%3Dnone%3Balign%3Dcenter%3BverticalAlign%3Dmiddle%3BwhiteSpace%3Dwrap%3Brounded%3D0%3B%22%20vertex%3D%221%22%20parent%3D%221%22%3E%3CmxGeometry%20x%3D%222560%22%20y%3D%22535%22%20width%3D%2260%22%20height%3D%2230%22%20as%3D%22geometry%22%2F%3E%3C%2FmxCell%3E%3C%2Froot%3E%3C%2FmxGraphModel%3E

// ----------------------------------Start of functions defination-------------------------------------------
void login();
int checkadmin(string,string);
void getchoice();
void adminmenu();
void usermenu();
void createuser();
void logout();
void changepass();
void deleteuser();
void loadfile();
void studentfile();
void databasenow(string,int[][5]);
void savefile();
void savereport(string,double,double);
void saveHTMLreport(string,double,double);
void clearActivity();
void logrecord(string);
void pressenter(int);
void viewfunc();
void loadmin();
void minrow(int);
void mincolumn(int,double&,int);
void loadmax();
void maxrow(int);
void maxcolumn(int,double&,int);
void loadmed();
void findrowmed();
void findcolmed();
void loadmean();
void findrowmean(int,int&, float&, double&, double&);
void findcolmean(int,int&, float&, double&, double&);
void loadvar();
void findrowvar(int,int& ,float& ,double& ,double,double&);
void findcolvar(int,int& ,float& ,double& ,double,double&);
void loadstdv();
void findrowstdv(int,int& ,float& ,double& ,double ,double&, double&);
void findcolstdv(int,int& ,float& ,double& ,double ,double&, double&);
void loadcorr();
void findcolsum12(int ,int ,double&);
void findcorrelation(int& ,float& ,double& ,double& ,double&);
void finddistinct();
void findhistogram();
void reportsmenu();


//------------------------------------------main function------------------------------------------------------
int main()
{   
    clearActivity();
    login();
    return 0;
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//----------------------------This functions login the user into the system-------------------------------------
void login()
{   
    int s;
    char n;
    cout<<"|-------------------------------------------------|\n"
        <<"|      Hello and Welcome to Our System            |\n"
        <<"|-------------------------------------------------|\n"
        <<"|ENTER 1 TO LOGIN                                 |\n"
        <<"|ENTER 0 TO EXIT                                  |\n"
        <<"|-------------------------------------------------|\n";
    cin>>n;
    cin.ignore(25,'\n');
    if(n=='1')
    { 
        cout<<"-----------------------------------------------------------\n"
            <<"Please enter the username-\n";
        cin>>username;
        cin.ignore(25,'\n');
        cout<<"Please enter the password-\n";
        cin>>password;
        cin.ignore(25,'\n');
        status=checkadmin(username,password);
        logrecord(" just logged in");
        getchoice();
    }
    else if(n=='0')
            exit(0);
    else
    {
        cout<<"Wrong choice\n"
            <<"Please enter from given choices only\n";
        login();
    }
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//---------------------------This functions checks if the user is admin or not----------------------------------
 int checkadmin(string name,string pass)
 {      
    vec users;
    users = loadfile();
     for (int i=0;i<users.size();i++)
    {   
        if(get<0>(users[i])==name && get<2>(users[i])==pass && get<1>(users[i])==1)
            return 1;
        else if(get<0>(users[i])==name && get<2>(users[i])==pass && get<1>(users[i])==0)   
            return 0;
    }
    return 2;
 }

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//----------------------This functions takes the input from the user and calls different functions---------------
void getchoice() 
{   
    if(status==1)
        adminmenu();
    else
    {   
        if(status==0)
        usermenu();
        else
        {
        cout<<"Either username or password was wrong\n";
        login();
        }
    }
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//----------------------------------This function shows the menu for the admin----------------------------------
void adminmenu()
{
    char ch;
    cout << "|--------------------------------------------------------|\n"
        << "       Hello admin "<<username<<"                         \n"
        << "|--------------------------------------------------------|\n"
        << "| Please Enter from the choice given below               |\n"
        << "| Enter 1 to Login as a User Account to view FUNCTION    |\n"
        << "| Enter 2 to Create a New User Account                   |\n"
        << "| Enter 3 to Logout from your User Account               |\n"
        << "| Enter 4 to Delete any User Account                     |\n"
        << "| Enter 5 To Change your Password                        |\n"
        << "| Enter O To Exit                                        |\n"
        << "|--------------------------------------------------------|\n";
    cin >> ch;
    cin.ignore(' ','\n');
    string str=" just choose menu option ";
    logrecord(str);
    loadfile();
    switch(ch)
    {
        case('1') : studentfile();
                    break;
        case('2') :  createuser();
                    break;
        case('3') : logout();
                    break;
        case('4') :  deleteuser();
                    break;
        case('5') :  changepass();
                    break;
        case('0') : exit(0);
                    break;
        default: cout<<"Wrong choice\n"
                     <<"Please try again\n";
                        adminmenu();
                        break;    
    }
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//--------------------------This function shows the menu for a regular user-------------------------------------
void usermenu()
{
    char ch;
    cout <<"|--------------------------------------------------------|\n"
        << "        Hello user "<< username<<"                        \n"
        << "|--------------------------------------------------------|\n"
        << "| Please Enter from the choice given below               |\n"
        << "| Enter 1 to view all the FUNCTION                       |\n"
        << "| Enter 2 to Logout from your User Account               |\n"
        << "| Enter 3 To Change your Password                        |\n"
        << "| Enter O To Exit                                        |\n"
        << "|--------------------------------------------------------|\n";
    cin >> ch;
    cin.ignore(' ','\n');
    string str=" just choose menu option "+ch;
    logrecord(str);
    loadfile();
    switch(ch)
    {   case('1') : studentfile(); 
                    break;
        case('2') : logout();
                    break;
        case('3') : changepass();
                    break;
        case('0') : exit(0);
                    break;

        default: cout<<"Wrong choice\n"
                    <<"Please try again\n";
                    usermenu();
                    break;
    }
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//----------------------------This functions creates the new user-----------------------------------------------
void createuser() 
{   
    string user,pass;
    int s, flag=0,f;
    cout <<"Enter a unique user name -\n";
    cin >> user;
    cout << "Enter your password -\n";
    cin >> pass;
    cout <<"Enter 1 to create new admin, 0 for reguler user-\n";
    cin>>s;
    for(int i=0; i<users.size(); i++)
    {if(get<0>(users[i])==user)
    {
        flag = 1;
        break;
    }}
    if(flag!=1)
    {ofstream outfile;
    outfile.open("Users.dat",ios::ate|ios::app);
    int activity=1;
    outfile << user << " " << s << " " << pass << " " << activity <<endl;
    outfile.close();
    cout << "-----------------------------------------------------\n"
         << "Username and password created successfully.\n"<<endl;
    string str=" just created another user as "+user;
    logrecord(str);}
    else 
    cout<<"The username already exists\n";
    pressenter(f==1);
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//----------------------------This functions logout the user from the system---------------------------------
void logout()
{   
    string str=" logged out from the system ";
    logrecord(str);
    system("cls");
    cout<<"Logout was successful.\n";
}

//---------------------------------------------Salah Fayeq------------------------------------------------------
//----------------------------This functions changes the password-------------------------------------
void changepass() 
{
    string newpass1,newpass2,oldpass;           
    cout << "Enter your old password to continue..." << endl;
    cin >> oldpass;       
    for (int i=0;i<users.size();i++)
    {
        if (oldpass == get<2>(users[i]) && username==get<0>(users[i]))
       {    
            cout << "Please enter the new password"<< endl;
            cin >> newpass1;
            cout << "Please re-enter your new password"<< endl;
            cin >> newpass2;
            if(newpass1==newpass2)
            {
                get<2>(users[i])=newpass1;
                cout << "Password changed you may procced to login"<< endl;
            }
                else
                cout <<"passwords don't match try again"<<endl;
            string str=" just changed his password ";
            logrecord(str);       
       }
         else
            cout <<"password is wrong"<<endl;
                break;  
    }
    ofstream outfile;
    outfile.open("Users.dat" , ios::out);
    for (int i=0;i<users.size();i++)
    { 
        outfile << get<0>(users[i]) << " " 
                << get<1>(users[i]) << " " 
                << get<2>(users[i]) << " " 
                << get<3>(users[i]) <<endl;
    }
    outfile.close();
    pressenter(status);
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
//----------------------------This functions deletes the user--------------------------------------
void deleteuser() 
{
    string name, pass;
                cout << "-----------------------------------------------------\n"
                    << "Enter the Username to delete-\n";
                cin >> name;
                cout << "-----------------------------------------------------\n"
                    << "Enter Password to confirm deletion-\n";
                cin >> pass;
     for (int i=0;i<users.size();i++)
    {   
        if (name==get<0>(users[i]) && pass==get<2>(users[i]) && get<3>(users[i])==1)
             { 
                cout << get<0>(users[i]) << ": "
                    << ((get<1>(users[i])==1)?"admin":"user")
                    << ": " <<get<2>(users[i]) << ": "
                    << ((get<3>(users[i])==1)?"Deleted":"Active")
                    << endl;
                get<3>(users[i])=0;
                    break;
             }       
    }
    ofstream outfile;
    outfile.open("Users.dat",ios::out);
    for (int i=0;i<users.size();i++)
    { 
        outfile << get<0>(users[i]) << " " 
                << get<1>(users[i]) << " " 
                << get<2>(users[i]) << " " 
                << get<3>(users[i]) <<endl;
    }
    outfile.close();
    cout << "---------------------------------------------------\n"
                    <<"Account deletion was successful.\n" << endl;
    string str=" deleted the user "+name;
    logrecord(str);
    pressenter(1);
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
// ---------------------------------This function loads Users.dat the file-----------------------------------------
void loadfile() 
{   
    tuple<string,int,string,int> userdata;
    ifstream file;
    file.open("Users.dat");
    while (file>>get<0>(userdata))
    {
        file >>get<1>(userdata);
        file >>get<2>(userdata);
        file >>get<3>(userdata);
        users.push_back(userdata);
    }
    file.close();
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
// ---------------------This function loads the student database file and clears the comma----------------------
void studentfile() 
{
    string arr1[100],filename;
    int arr2[100][5];
    int k=0;
    int i=0;
    ifstream data;
    cout<<"Before proceeding enter the name of the Student data base file\n";
    cin>>filename;
    data.open(filename+".dat");
    while (!data.eof()){
        string x;
        data >> x;
        arr1[i] = x;
        i++;
    }
    for (int i=0; i<100; i++){
        string s = arr1[i];
        stringstream string_stream(s);
        int i2 = 0;
        while(string_stream.good()){
            string y;
            getline(string_stream, y, ',' );
            stringstream string_stream2(y);
            string_stream2 >> k;
            arr2[i][i2]=k;
            i2++;
        }
    }
   databasenow(filename,arr2);
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
// -----------------------------This function stores the data base file in the vector------------------------------------
void databasenow(string filename, int ar[][5])
{
    array <int,5> a;
    for(int i=0;i<100;i++)
    {
        get<0>(a)=ar[i][0];
        get<1>(a)=ar[i][1];
        get<2>(a)=ar[i][2];
        get<3>(a)=ar[i][3];
        get<4>(a)=ar[i][4];
        student.push_back(a);
    }
    logrecord(" loaded the "+filename+" file.");
    viewfunc();
}
//---------------------------------------------omar------------------------------------------------------
// -------------------------------This function saves the new file----------------------------------------
void savefile()
{       
    string newfilename;
    cout << "Enter the new file name "<< endl;
    cin >> newfilename; 
    ofstream file(newfilename+".dat",ios::app);
    for(int i=0;i<100;i++)
    {
        file<<get<0>(student[i]) <<", "
            <<get<1>(student[i]) <<", "
            <<get<2>(student[i]) <<", "
            <<get<3>(student[i]) <<", "
            <<get<4>(student[i]) << endl;
    }
    string str=" Created and saved a newfile as "+newfilename+"\n";
    logrecord(str);
}

//---------------------------------------------Ahmad Ayaan/Salah Fayeq------------------------------------------------------
// -----------------This function clears the user activity in a file before function starts--------------------------
void clearActivity()
{
    ofstream file;
    file.open("Report.dat",ios::out|ios::trunc);
    file.close();
    ofstream outfile;
    outfile.open("Activity.dat",ios::out|ios::trunc);
    outfile.close();
    ofstream hfile;
    hfile.open("Report.html" ,ios::out|ios::trunc);
}

//---------------------------------------------Salah Fayeq------------------------------------------------------
// --------------------This function saves the report of the user choices in a file-------------------------
void savereport(string str, double col,double results)
{
    ofstream outFile;
    outFile.open("Report.dat",ios::out|ios::app);
    outFile << "you just"<<" " << str << " "<< col <<" and the result is: " << results<< endl;
    outFile.close();
    logrecord(" saved the report");
    reportsmenu();
}

//---------------------------------------------Salah Fayeq------------------------------------------------------
// -----------------This function saves the report in HTML of the user choices in a file---------------------
void saveHTMLreport(string str, double col,double results)
{      
    ofstream outFile;
    outFile.open("Report.html",ios::out|ios::app);
    outFile << "you just"<<" " << str << " "<< col <<" and the result is: " << results<< endl;
    outFile.close();
    logrecord(" saved the HTML report");
    reportsmenu();
}

//---------------------------------------------Ahmad Ayaan------------------------------------------------------
// -------------------------This function saves the user activity in a file-------------------------------------
void logrecord(string str)
{
    ofstream outfile;
    outfile.open("Activity.dat",ios::out|ios::app);
    outfile << "--> " << username << " " << str << endl;
    outfile.close();
}
//---------------------------------------------Liew ------------------------------------------------------
//----------------------This functions asks the user to press enter to continue---------------------------------
void pressenter(int flag)
{
    char temp = 'x';
    cout << "Press enter to continue...." << endl;
    cin.get(temp);
    cin.ignore(20,'\n');
    if(temp=='\n')
    {
        if(flag==0)
        usermenu();
        else if(flag==1)
        adminmenu();
        else if(flag==2)
        viewfunc();
    }
    else
    {
        cout<<"Wrong selection\n";
        pressenter(flag);
    }
}

//---------------------------------------------Salah Fayeq------------------------------------------------------
// --------------------This function shows different functions for user to perform------------------------------
void viewfunc()
{
    char ch;
    cout <<"|------------------------------------------------------------|\n"
        <<"              "<<username<<" ,Please enter a number to procced:\n"
        <<"|-------------------------------------------------------------|\n"
        <<"|  Enter 1 to find the minmum value:                          |\n"
        <<"|  Enter 2 to find the maximum value:                         |\n"
        <<"|  Enter 3 to find the median of the value:                   |\n"
        <<"|  Enter 4 to find the mean of the value:                     |\n"
        <<"|  Enter 5 to find the variance of the value:                 |\n"
        <<"|  Enter 6 to find the standard deviation of the value        |\n"   
        <<"|  Enter 7 to find the correlation between the values         |\n"   
        <<"|  Enter 8 to find the distinct data members                  |\n"
        <<"|  Enter 9 to plot a histogram                                |\n"
        <<"|  Enter R to proceed to the Reports menu                     |\n" 
        <<"|  Enter B to go back to User's menu                          |\n"
        <<"|  Enter S to save the StudentDatabase.dat file with a newname|\n"  
        <<"|  Enter 0 to exit                                            |\n"     
        <<"|-------------------------------------------------------------|\n"
        <<endl;
    cin>>ch;
    cin.ignore(' ','\n');
    string word= " just choose a menu option from all the functions ";
    logrecord(word);
    switch(ch)
    {
         case('1')    : loadmin();
                         break;
         case('2')    : loadmax();
                         break;
         case('3')    : loadmed();               
                         break;
         case('4')    : loadmean();
                         break;
         case('5')    : loadvar();
                         break;
         case('6')    : loadstdv();
                         break;                
         case('7')    : loadcorr();
                         break;     
         case('8')    : finddistinct();
                         break;
         case('9')    : findhistogram();
                         break;
         case('R')    : reportsmenu();
                         break;
         case('B')    : getchoice();
                         break;
         case('S')    : savefile();
                         break;
         case('0')    : exit(0);
                         break;               
         default: cout<<"Wrong choice\n"
                        <<"Please Enter from the choice given below\n";
                viewfunc();
                break;         
    }
}
//---------------------------------------------Omar ------------------------------------------------------
//------------------------------This functions loads the minimum function-------------------------------------
void loadmin()
{   
    int flag = 4,c=0;//****
    double value=0.0;
    char ch;
    cout <<"Please enter the 1 to find minimum for the specific row and 2 for the column"<<endl;
    cin>>ch;
    if(ch=='1')
        minrow(flag);
    else if(ch=='2')
        mincolumn(c,value,flag);
    pressenter(2);
}

//---------------------------------------------Omar ------------------------------------------------------
//------------------------------This function prints minimum from a row-------------------------------------
void minrow(int flag)
{   int choice;
    double min=0.0;
    cout<<"Enter the row number from 0 to 99 to find the minimum from 3 subjects"<<endl;
    cin>>choice;
    for(int i=0;i<student.size();i++)
    {   
        if(i==choice)
        {   
            min=get<1>(student[i]);
            if(get<2>(student[i])<get<1>(student[i]) && get<2>(student[i])<get<3>(student[i]) && get<2>(student[i])<get<4>(student[i]))
                min=get<2>(student[i]);
            else if(get<3>(student[i])<get<1>(student[i]) && get<3>(student[i])<get<2>(student[i]) && get<2>(student[i])<get<4>(student[i]))
                min=get<3>(student[i]);
            else if(get<4>(student[i])<get<1>(student[i]) && get<4>(student[i])<get<2>(student[i]) && get<4>(student[i])<get<3>(student[i]))
                min=get<4>(student[i]);
            if (flag==4){
                cout<<"The minimum value of the row "<<choice<<" is "<<min<<endl;
                logrecord(" calculated the minimum");
            }
            break;
        }
    }
}


//---------------------------------------------Omar ------------------------------------------------------
//------------------------------This function print the minimum from a column-------------------------------------
void mincolumn(int choice,double &min,int flag)
{   
    if(flag ==4){
        cout<<"Enter the column number from 1 to 4"<<endl;
        cin>>choice;    
    }
    if(choice==1)
    for(int i=0;i<student.size();i++)
    {  min=get<1>(student[0]);
       { 
        if(get<1>(student[i])<min)
            min=get<1>(student[i]);
        }
    }
    else if(choice==2)
    for(int i=0;i<student.size();i++)
    {  min=get<2>(student[0]);
       { 
        if(get<2>(student[i])<min)
            min=get<2>(student[i]);
        }
    }
    else if(choice==3)
    {min=get<3>(student[0]);
    for(int i=0;i<student.size();i++)
        { 
        if(get<3>(student[i])<min)
            min=get<3>(student[i]);
        }
    }
    else if(choice==4)
   { min=get<4>(student[0]);
    for(int i=0;i<student.size();i++)
        { 
        if(get<4>(student[i])<min)
            min=get<4>(student[i]);
        }
    }
    if (flag==4){
        cout<<"The minimum value of the column "<<choice<<" is "<<min<<endl;
        logrecord(" calculated the minimum");
    }
}

//---------------------------------------------Omar ------------------------------------------------------
//------------------------------This functions loads the maximum function-------------------------------------
void loadmax()
{   double value=0.0;
    int flag = 5,c=0;
    logrecord(" calculated the maximum");
    char ch;
    cout <<"Please enter the 1 to find maximum for the specific row and 2 for the column"<<endl;
    cin>>ch;
    if(ch=='1')
        maxrow(flag);
    else if(ch=='2')
        maxcolumn(c,value,flag);
    pressenter(2);

}
//---------------------------------------------Omar ------------------------------------------------------
//------------------------------This function print the maximum from a row-------------------------------------
void maxrow(int flag)
{
    double max=0.0;
    int choice;
    cout<<"Enter the row number from 0 to 99 to find the maximum from 3 subjects"<<endl;
    cin>>choice;
    for(int i=0;i<student.size();i++)
    {   
        if(i==choice)
        {   max=get<1>(student[i]);
            if(get<2>(student[i])>get<1>(student[i]) && get<2>(student[i])>get<3>(student[i]) && get<2>(student[i])>get<4>(student[i]))
            max=get<2>(student[i]);
            else if(get<3>(student[i])>get<1>(student[i]) && get<3>(student[i])>get<2>(student[i]) && get<3>(student[i])>get<4>(student[i]))
                max=get<3>(student[i]);
            else if(get<4>(student[i])>get<1>(student[i]) && get<4>(student[i])>get<2>(student[i]) && get<4>(student[i])>get<3>(student[i]))
                max=get<4>(student[i]);
            if (flag==5){
                cout<<"The maximum value of the row "<<choice<<" is "<<max<<endl;
                logrecord(" calculated the maximum");
            }
            break;
        }
    }
}

//---------------------------------------------Omar ------------------------------------------------------
//------------------------------This function prints maximum from a column-------------------------------------
void maxcolumn(int choice,double &max,int flag)
{
    max=0.0;
    if(flag ==5){
        cout<<"Enter the column number from 1 to 4"<<endl;
        cin>>choice;    
    }
    if(choice==1)
    for(int i=0;i<student.size();i++)
    {  max=get<1>(student[0]);
       { 
        if(get<1>(student[i])>max)
            max=get<1>(student[i]);
        }
    }
    if(choice==2)
    for(int i=0;i<student.size();i++)
    {  max=get<2>(student[0]);
       { 
        if(get<2>(student[i])>max)
            max=get<2>(student[i]);
        }
    }
    else if(choice==3)
    {max=get<3>(student[0]);
    for(int i=0;i<student.size();i++)
        { 
        if(get<3>(student[i])>max)
            max=get<3>(student[i]);
        }
    }
    else if(choice==4)
   { max=get<4>(student[0]);
    for(int i=0;i<student.size();i++)
        { 
        if(get<4>(student[i])>max)
            max=get<4>(student[i]);
        }
    }
    if (flag==5){
        cout<<"The maximum value of the row "<<choice<<" is "<<max<<endl;
        logrecord(" calculated the maximum");
    }
}
//---------------------------------------------Omar ------------------------------------------------------
//------------------------------This functions loads the median function-------------------------------------
void loadmed()
{   
    logrecord(" calculated the median");
    pressenter(2);
}

void findrowmed()
{

}

void findcolmean()
{
    
}
//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This functions loads the mean function-----------------------------------------
void loadmean()
{   
    int flag=0;
    int row = -1;
    int col = -1;
    int rc;
    float rowmean,colmean;
    double rowsum,colsum,rowsqsum,colsqsum;
    cout << endl << "Enter 1 to find mean of a row or 2 to find mean of a column:" << endl;
    cin >> rc;
    cin.ignore(' ','\n');
    if (rc==1)
    {
        findrowmean(flag,row,rowmean,rowsum,rowsqsum);
    } 
    else if(rc==2)
    {
        findcolmean(flag,col,colmean,colsum,colsqsum);
    }
    else
    {
        cout<<"Wrong choice\n"
             <<"Enter again\n";
        loadmean();
    }
    pressenter(2);
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This functions finds the mean of the row-----------------------------------------
void findrowmean(int flag,int &row,float &rowmean,double &rowsum,double &rowsqsum){
    rowsum = 0;
    rowsqsum = 0;
    rowmean = 0;
    if(row==-1){
        do{
            cout << endl << "Enter row from 1-100:" << endl;
            cin >> row;
            if (row <1 || row > 100)
            cout << "Invalid row" << endl;
        }while (row <1 || row > 100);
    }
    rowsum = rowsum + get<1>(student[row-1]);
    rowsum = rowsum + get<2>(student[row-1]);
    rowsum = rowsum + get<3>(student[row-1]);
    rowsum = rowsum + get<4>(student[row-1]);
    rowsqsum = rowsqsum + (get<1>(student[row-1])*get<1>(student[row-1]));
    rowsqsum = rowsqsum + (get<2>(student[row-1])*get<2>(student[row-1]));
    rowsqsum = rowsqsum + (get<3>(student[row-1])*get<3>(student[row-1]));
    rowsqsum = rowsqsum + (get<4>(student[row-1])*get<4>(student[row-1]));
    rowmean = rowsum/4;

    if(flag==0){
        cout << endl << "The mean of row " << row << " is " << rowmean << endl;
        logrecord(" calculated the mean of the row ");
        savereport("calculated the mean of the row",row,rowmean);
        saveHTMLreport("calculated the mean of the row:",row,rowmean);
    }
}


//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This functions finds the mean of the cloumn-----------------------------------------
void findcolmean(int flag,int &col,float &colmean,double &colsum,double &colsqsum)
{
    colsum = 0;
    colsqsum = 0;
    colmean = 0;
    if(col==-1){
        do{
            cout << endl << "Enter column from 2-5:" << endl;
            cin >> col;
            if (col <2 || col > 5)
            cout << "Invalid column" << endl;
        }while (col <2 || col > 5);
    }
    switch(col)
    {
        case (2): for(int i=0;i<100;i++){
            colsum = colsum + get<1>(student[i]);
            colsqsum = colsqsum + (get<1>(student[i])*get<1>(student[i]));}break;
        case (3): for(int i=0;i<100;i++){
            colsum = colsum + get<2>(student[i]);
            colsqsum = colsqsum + (get<2>(student[i])*get<2>(student[i]));}break;
        case (4): for(int i=0;i<100;i++){
            colsum = colsum + get<3>(student[i]);
            colsqsum = colsqsum + (get<3>(student[i])*get<3>(student[i]));}break;
        case (5): for(int i=0;i<100;i++){
            colsum = colsum + get<4>(student[i]);
            colsqsum = colsqsum + (get<4>(student[i])*get<4>(student[i]));}break;
    }
    colmean = colsum/100;
    if(flag==0)
    {
        cout << endl << "The mean of the column " << col << " is " << colmean << endl;
        logrecord(" calculated the mean of the column ");
        savereport("calculated the mean of the column:",col,colsqsum);
        saveHTMLreport("calculated the mean of the column:",col,colsqsum);
    }
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This function loads the variance function------------------------------------
void loadvar()
{
    int flag = 1;
    int row = -1;
    int col = -1;
    int rc;
    float rowmean,colmean;
    double rowsum,colsum,rowsqsum,colsqsum,rowvar,colvar;
    cout << endl << "Enter 1 to find variance of a row or 2 to find variance of a column:" << endl;
    cin >> rc;
    cin.ignore(' ','\n');
    if (rc==1){
        findrowvar(flag,row,rowmean,rowsum,rowsqsum,rowvar);
    } else if(rc==2)
    {
        findcolvar(flag,col,colmean,colsum,colsqsum,colvar);
    }
    else
    {
        cout<<"Wrong choice\n"
             <<"Enter again\n";
        loadvar();
    }
    pressenter(2);
}

//---------------------------------------------Liew ------------------------------------------------------
//--------------------------This functions finds the variance of the row-----------------------------------
void findrowvar(int flag,int &row,float &rowmean,double &rowsum,double rowsqsum,double &rowvar)
{   
    rowvar = 0;
    findrowmean(flag,row,rowmean,rowsum,rowsqsum);
    rowvar = ((rowsqsum)-((rowsum*rowsum)/4))/3;
    if (flag ==1){
        cout << endl << "The variance of row " << row << " is " << rowvar << endl;
        logrecord(" calculated the variance of the row ");
        savereport("calculated the variance of the row: ",row,rowvar);
        saveHTMLreport("calculated thevariance of the row:",row,rowvar);
    }
}

//---------------------------------------------Liew ------------------------------------------------------
//---------------------------This functions finds the variance of the column-----------------------------------
void findcolvar(int flag,int &col,float &colmean,double &colsum,double colsqsum,double &colvar)
{   
    colvar = 0;
    findcolmean(flag,col,colmean,colsum,colsqsum);
    colvar = ((colsqsum)-((colsum*colsum)/100))/99;
    if (flag ==1){
        cout << endl << "The variance of column " << col << " is " << colvar << endl;
        logrecord(" calculated the variance of the column");
        savereport("calculated the variance of the column",col,colvar);
    }
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------This functions loads the standard deviation function----------------------------------
void loadstdv()
{
    int flag =2;
    int row = -1;
    int col = -1;
    int rc;
    float rowmean,colmean;
    double rowsum,colsum,rowsqsum,colsqsum,rowvar,colvar,rowstdv,colstdv;
    cout << endl << "Enter 1 to find standard deviation of a row or 2 to find standard deviation of a column:" << endl;
    cin >> rc;
    cin.ignore(' ','\n');
    if (rc==1){
        findrowstdv(flag,row,rowmean,rowsum,rowsqsum,rowvar,rowstdv);
    } else if(rc==2){
        findcolstdv(flag,col,colmean,colsum,colsqsum,colvar,colstdv);
    }
    else
    {
        cout<<"Wrong choice\n"
             <<"Enter again\n";
        loadstdv();
    }
    pressenter(2);
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------This functions finds the standard deviation of row----------------------------------
void findrowstdv(int flag,int &row,float &rowmean,double &rowsum,double rowsqsum,double &rowvar,double &rowstdv)
{
    rowstdv=0;
    findrowvar(flag,row,rowmean,rowsum,rowsqsum,rowvar);
    rowstdv= sqrt(rowvar);
    cout << endl << "The standard deviation of row " << row << " is " << rowstdv << endl;
    logrecord(" calculated the standard deviation of the row ");
    savereport("calculated the standard deviation of the row ",row,rowstdv);
    saveHTMLreport("calculated the standard deviation of the row",row,rowstdv);
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This functions the standard deviation of column----------------------------------------
void findcolstdv(int flag,int &col,float &colmean,double &colsum,double colsqsum,double &colvar, double &colstdv)
{
    colstdv = 0;
    findcolvar(flag,col,colmean,colsum,colsqsum,colvar);
    colstdv = sqrt(colvar);
    cout << endl << "The standard deviation of column " << col << " is " << colstdv << endl;
    logrecord(" calculated the standard deviation of the column ");
    savereport("calculated the standard deviation of the column: ",col,colstdv);
    saveHTMLreport("calculated the standard deviation of the column",col,colstdv);
}

//---------------------------------------------Liew ------------------------------------------------------
//-------------------------This function loads the find correlation function--------------------------------
void loadcorr()
{
    int row = -1;
    int col = -1;
    float rowmean,colmean;
    double rowsum,colsum,rowsqsum,colsqsum,corr;
    findcorrelation(col,colmean,colsum,colsqsum,corr);
    pressenter(2);
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This functions finds the correlation----------------------------------------
void findcorrelation(int &col,float &colmean,double &colsum,double &colsqsum,double &corr)
{   
    int flag=3;
    int col2;
    float colmean2;
    double colsum2,colsqsum2,colsum12;
    do {   
        cout << endl << "Enter a column from 2-5:" << endl;
        cin >> col;
        if (col <2 || col> 5)
            cout << "Invalid column" << endl;
    }while(col <2 || col> 5);
    findcolmean(flag,col,colmean,colsum,colsqsum);
    do {   
        cout << endl << "Enter a different column from 2-5:" << endl;
        cin >> col2;
        if (col2 <2 || col2> 5 || col2 == col)
            cout << "Invalid column" << endl;
    }while(col2 <2 || col2> 5 || col2 == col);   
    findcolmean(flag,col2,colmean2,colsum2,colsqsum2);
    findcolsum12(col,col2,colsum12);
    corr = (colsum12-(100*colmean*colmean2))/(sqrt(colsqsum-(100*colmean*colmean))*sqrt(colsqsum2-(100*colmean2*colmean2)));
    cout << endl << "The correlation between column " << col << " and " << col2 << " is " << corr << endl;
    logrecord(" calculated the correlation between two columns ");
}

//---------------------------------------------Liew ------------------------------------------------------
//---------------------This functions finds multiples of 2 element in a same row----------------------------
void findcolsum12(int col,int col2,double &colsum12)
{
    colsum12 = 0;
    if((col==2 && col2==3)||(col==3 && col2==2)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<1>(student[i])*get<2>(student[i]));
    }
    if((col==2 && col2==4)||(col==4 && col2==2)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<1>(student[i])*get<3>(student[i]));
    }
    if((col==2 && col2==5)||(col==5 && col2==2)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<1>(student[i])*get<4>(student[i]));
    }
    if((col==3 && col2==4)||(col==4 && col2==3)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<2>(student[i])*get<3>(student[i]));
    }
    if((col==3 && col2==5)||(col==5 && col2==3)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<2>(student[i])*get<4>(student[i]));
    }
    if((col==4 && col2==5)||(col==5 && col2==4)){
        for(int i=0;i<100;i++)
        colsum12 = colsum12 + (get<3>(student[i])*get<4>(student[i]));
    }
}

//---------------------------------------------Liew ------------------------------------------------------
//------------------------------This functions finds distinct member-----------------------------------------
void finddistinct()
{   
    int flag=0;
   double mindata,maxdata,tempmax,tempmin;
    for (int i=2;i<=5;i++){
        maxcolumn(i,tempmax,flag);
        mincolumn(i,tempmin,flag);
        maxdata = (maxdata<tempmax) ? tempmax : maxdata;
        mindata = (mindata>tempmin) ? tempmin : mindata;
    }
    cout << "     Distinct Numbers Table    " << endl;
    cout << "---------------+---------------" << endl;//15-+15-
    cout << "|    Number    |   Frequency  |" << endl;
    cout << "---------------+---------------" << endl;
    for (int k=mindata;k<=maxdata;k++){
        int f = 0;
        for (int i=0;i<100;i++){
            if (k == get<1>(student[i]))
                f++;
            if (k == get<2>(student[i]))
                f++;
            if (k == get<3>(student[i]))
                f++;
            if (k == get<4>(student[i]))
                f++;
        }
        if (f!=0){
            cout << "|" << setw(7) << right << k;
            cout << setw(8) << right <<"|";
            cout << setw(8) <<right << f;
            cout << setw(7) << right <<"|" << endl;
            cout << "---------------+---------------" << endl;
        }
    }
    logrecord(" found out the distinct member ");
    pressenter(2);
}


//------------------------------------------Salah Fayeq---------------------------------------------------
//------------------------------This function finds the histogram-----------------------------------------
void findhistogram()
{
    //empty for now
}

//---------------------------------------------      ------------------------------------------------------
//------------------------------This functions shows the report menu-----------------------------------------
void reportsmenu()
{   
    string str1;
    double db=0;
    double ds=0;
    char ch;
    cout <<"--------------------------------------------------------\n"
        <<"          "<<username<<" ,Please enter a number to procced:\n"
        <<"--------------------------------------------------------\n"
        <<"|  Enter 1 to create a report as a text file           |\n"
        <<"|  Enter 2 to create a HTML report                     |\n"
        <<"|  Enter B to go back to perform more functions        |\n"
        <<"|  Enter U to go back to User's settings menu          |\n"
        <<"|  Enter 0 to exit                                     |\n"
        <<"--------------------------------------------------------\n";
    cin>>ch;
    cin.ignore(' ','\n');
    string str=" choose the report's menu option ";
    logrecord(str);
    switch(ch)
    {
         case('1')    : savereport(str1,db,ds);
                         break;
         case('2')    : saveHTMLreport(str1,db,ds);
                         break;
         case('B')    : viewfunc();
                         break;
         case('U')    : getchoice();
                         break;
         case('0')    : exit(0);
                         break;               
         default: cout<<"Wrong choice------------->\n"
                        <<"Please Enter from the choice given below\n";
                reportsmenu();
                break;         
    }
}
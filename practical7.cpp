#include<iostream> 
#include<map> 
#include<string> 
#include<utility> 
using namespace std; 
 
int main() 
{ 
    typedef map<string, int> maptype; 
    maptype populationmap; 

    populationmap.insert(pair<string, int>("China", 1339)); 
    populationmap.insert(pair<string, int>("India", 1187)); 
    populationmap.insert(maptype::value_type("US", 310)); 
    populationmap.insert(maptype::value_type("Indoneshia", 234)); 
    populationmap.insert(make_pair("Brazil", 193)); 

    cout << "Size of populationmap: " << populationmap.size() << "\n";

    // ERASE THE END ELEMENT USING THE ERASE FUNCTION
    // BECAUSE IT'S ORDERED MAP (BY KEY)
    // MAP ELEMENTS ARE NOT IN THE ORDER OF THE ENTRY
    // IN THIS MAP ITS US SINCE IT'S ORDERED ALPHABETICALLY
    maptype::iterator iter = --populationmap.end();
    populationmap.erase(iter); 

    // OUTPUT THE SIZE OF THE MAP
    cout << "Size of population map: " << populationmap.size() << "\n";

    // TO DISPLAY THE MAP CONTENT
    for(iter = populationmap.begin(); iter != populationmap.end(); ++iter) { 
        cout << iter->first << ":" << iter->second << " Million \n"; 
    }

    // FIND WILL RETURN AN ITERATOR TO THE MATCHING ELEMENT IF IT IS FOUND
    // OR TO THE END OF THE MAP IF THE KEY IS NOT FOUND
    string country = "Brazil"; 
    iter = populationmap.find(country); 
    if(iter != populationmap.end()) 
        cout << country << "'s population is " << iter->second << " Million\n";
    else 
        cout << "Key is not in populationmap" << "\n";

    // CLEAR THE ENTRIES IN THE MAP
    populationmap.clear();

    return 0;
}

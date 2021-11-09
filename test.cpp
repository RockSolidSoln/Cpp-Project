void findhistogram(struct datavalues d)
{
    
    srand(time(NULL));
    vector<int> v(100);
    set<int> s;

    for (auto item : v){
         item =  rand()%10;
    }
    for (auto item : v){

      cout << item << ":";
      cout << endl;
    }
    
    
    for (auto item : v)
        s.insert(item);
        
    vector<int> v2(s.begin(),s.end());
    vector<int> hist (v2.size(),0);

    for (int j=0; j<v.size(); j++){
        for (int i=0;i<v2.size(); i++){
            if(v[j] == v2[i])
                hist[i]++;
        }
    }
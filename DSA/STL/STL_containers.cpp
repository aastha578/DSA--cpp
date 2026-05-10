#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{

// =========================================================
// VECTOR
// =========================================================

    cout << "=========== VECTOR ===========" << endl;

    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v.emplace_back(40);

    v.insert(v.begin() + 1, 15);

    v.erase(v.begin() + 2);

    cout << "Front: " << v.front() << endl;
    cout << "Back: " << v.back() << endl;
    cout << "At index 1: " << v.at(1) << endl;
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Empty: " << v.empty() << endl;

    cout << "Traversal: ";
    for(auto val : v)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Reverse Traversal: ";
    for(auto it = v.rbegin(); it != v.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    v.pop_back();

    v.clear();



// =========================================================
// LIST
// =========================================================

    cout << "\n=========== LIST ===========" << endl;

    list<int> l;

    l.push_back(10);
    l.push_front(5);

    l.emplace_back(20);
    l.emplace_front(1);

    cout << "Front: " << l.front() << endl;
    cout << "Back: " << l.back() << endl;

    cout << "Traversal: ";
    for(auto val : l)
    {
        cout << val << " ";
    }
    cout << endl;

    auto listIt = l.begin();

    l.insert(listIt, 100);

    l.erase(l.begin());

    l.remove(10);

    l.reverse();

    l.sort();

    cout << "Size: " << l.size() << endl;

    l.pop_front();

    l.pop_back();

    l.clear();



// =========================================================
// QUEUE
// =========================================================

    cout << "\n=========== QUEUE ===========" << endl;

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    q.emplace(40);

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;

    queue<int> tq = q;

    cout << "Traversal: ";
    while(!tq.empty())
    {
        cout << tq.front() << " ";
        tq.pop();
    }
    cout << endl;

    q.pop();

    cout << "Empty: " << q.empty() << endl;



// =========================================================
// STACK
// =========================================================

    cout << "\n=========== STACK ===========" << endl;

    stack<int> st;

    st.push(100);
    st.push(200);

    st.emplace(300);

    cout << "Top: " << st.top() << endl;
    cout << "Size: " << st.size() << endl;

    stack<int> ts = st;

    cout << "Traversal: ";
    while(!ts.empty())
    {
        cout << ts.top() << " ";
        ts.pop();
    }
    cout << endl;

    st.pop();

    cout << "Empty: " << st.empty() << endl;



// =========================================================
// DEQUE
// =========================================================

    cout << "\n=========== DEQUE ===========" << endl;

    deque<int> dq;

    dq.push_front(10);
    dq.push_back(20);

    dq.emplace_front(5);
    dq.emplace_back(30);

    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;

    dq.insert(dq.begin() + 1, 15);

    dq.erase(dq.begin());

    cout << "Size: " << dq.size() << endl;

    cout << "Traversal: ";
    for(auto val : dq)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Reverse Traversal: ";
    for(auto it = dq.rbegin(); it != dq.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    dq.pop_front();

    dq.pop_back();

    dq.clear();



// =========================================================
// MAP
// =========================================================

    cout << "\n=========== MAP ===========" << endl;

    map<string, int> mp;

    mp["tv"] = 100;

    mp.insert({"ac", 200});

    mp.emplace("laptop", 300);

    cout << "Size: " << mp.size() << endl;

    cout << "Count of tv: " << mp.count("tv") << endl;

    if(mp.find("tv") != mp.end())
    {
        cout << "tv found" << endl;
    }

    cout << "Traversal:" << endl;

    for(auto p : mp)
    {
        cout << p.first << " -> " << p.second << endl;
    }

    cout << "Reverse Traversal:" << endl;

    for(auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        cout << it->first << " -> " << it->second << endl;
    }

    mp.erase("ac");

    cout << "Empty: " << mp.empty() << endl;

    mp.clear();



// =========================================================
// UNORDERED MAP
// =========================================================

    cout << "\n=========== UNORDERED MAP ===========" << endl;

    unordered_map<string, int> ump;

    ump["tv"] = 100;

    ump.insert({"ac", 200});

    ump.emplace("laptop", 300);

    ump.emplace("mobile", 400);

    cout << "Size: " << ump.size() << endl;

    cout << "Count of tv: " << ump.count("tv") << endl;

    if(ump.find("ac") != ump.end())
    {
        cout << "ac found" << endl;
    }

    cout << "Traversal:" << endl;

    for(auto p : ump)
    {
        cout << p.first << " -> " << p.second << endl;
    }

    ump.erase("mobile");

    cout << "Bucket Count: " << ump.bucket_count() << endl;

    cout << "Load Factor: " << ump.load_factor() << endl;

    ump.clear();



// =========================================================
// MULTIMAP
// =========================================================

    cout << "\n=========== MULTIMAP ===========" << endl;

    multimap<string, int> mm;

    mm.insert({"tv", 100});

    mm.emplace("tv", 150);

    mm.emplace("ac", 200);

    mm.emplace("laptop", 300);

    mm.emplace("tv", 500);

    cout << "Size: " << mm.size() << endl;

    cout << "Count of tv: " << mm.count("tv") << endl;

    cout << "Traversal:" << endl;

    for(auto p : mm)
    {
        cout << p.first << " -> " << p.second << endl;
    }

    auto mapIt = mm.find("tv");

    if(mapIt != mm.end())
    {
        cout << "First tv value: " << mapIt->second << endl;
    }

    mm.erase("ac");

    mm.clear();



// =========================================================
// SET
// =========================================================

    cout << "\n=========== SET ===========" << endl;

    set<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(30);

    s.emplace(40);

    cout << "Size: " << s.size() << endl;

    cout << "Count of 20: " << s.count(20) << endl;

    if(s.find(30) != s.end())
    {
        cout << "30 found" << endl;
    }

    cout << "Lower Bound of 25: "
         << *s.lower_bound(25) << endl;

    cout << "Upper Bound of 20: "
         << *s.upper_bound(20) << endl;

    cout << "Traversal: ";
    for(auto val : s)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Reverse Traversal: ";
    for(auto it = s.rbegin(); it != s.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    s.erase(20);

    s.clear();



// =========================================================
// MULTISET
// =========================================================

    cout << "\n=========== MULTISET ===========" << endl;

    multiset<int> ms;

    ms.insert(10);
    ms.insert(20);
    ms.insert(20);
    ms.insert(30);

    ms.emplace(20);

    cout << "Size: " << ms.size() << endl;

    cout << "Count of 20: " << ms.count(20) << endl;

    cout << "Traversal: ";
    for(auto val : ms)
    {
        cout << val << " ";
    }
    cout << endl;

    ms.erase(ms.find(20));

    ms.clear();



// =========================================================
// UNORDERED SET
// =========================================================

    cout << "\n=========== UNORDERED SET ===========" << endl;

    unordered_set<int> us;

    us.insert(100);
    us.insert(200);
    us.insert(300);

    us.emplace(400);

    cout << "Size: " << us.size() << endl;

    cout << "Count of 200: " << us.count(200) << endl;

    if(us.find(300) != us.end())
    {
        cout << "300 found" << endl;
    }

    cout << "Traversal: ";
    for(auto val : us)
    {
        cout << val << " ";
    }
    cout << endl;

    us.erase(200);

    cout << "Bucket Count: " << us.bucket_count() << endl;

    cout << "Load Factor: " << us.load_factor() << endl;

    us.clear();

    return 0;
}
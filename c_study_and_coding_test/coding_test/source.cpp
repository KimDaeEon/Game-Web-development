#pragma once
#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#pragma region hash(map)
// 해시 > 완주하지 못한 선수

string h_solution1(vector<string> participant, vector<string> completion) {
    // 아래는 모범 답안
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < completion.size(); i++) {
        if (participant[i] != completion[i])
            return participant[i];
    }

    return participant[participant.size() - 1];


    // 아래는 내가 처음에 풀었던 것
    //map<string, int> m;
    //for (auto it = completion.begin(); it != completion.end(); it++) {
    //    if (m.find(*it) == m.end())// 처음 나오는 요소면 삽입
    //        m.insert(pair<string, int>(*it, 1)); // 항목을 찾을 맵 생성
    //    else {  // 중복 요소인 경우 ++ 한다.
    //        ++m[*it];
    //    }
    //}
    //
    //for (auto it = participant.begin(); it != participant.end(); it++) {
    //    auto target = m.find(*it);

    //    if (target == m.end()) {
    //        return *it;
    //    }

    //    if (target->second == 0) {
    //        return *it;
    //    }
    //    else {
    //        target->second--;
    //    }
    //}


   
}

#pragma endregion




#pragma region vector_sort_vs_priority_queue_sort
//class my_type {
//public:
//    int a;
//    int b;
//
//};

//class my_func {
//public:
//    bool operator()(my_type& in1, my_type& in2) {
//        if (in1.a > in2.a) {
//            return true;
//        }
//        if (in1.a == in2.a) {
//            if (in1.b > in2.b) {
//                return true;
//            }
//            return false;
//        }
//
//        return false;
//    }
//};

//my_type a;
//my_type b;
//my_type c;
//
//a.a = 10;
//a.b = 20;
//
//b.a = 10;
//b.b = 30;
//
//c.a = 5;
//c.b = 50;
//
//priority_queue<my_type, vector<my_type>, my_func> mtpq;
//vector<my_type> mtv;
//mtpq.push(a);
//mtpq.push(b);
//mtpq.push(c);
//
//mtv.push_back(a);
//mtv.push_back(b);
//mtv.push_back(c);
//
//sort(mtv.begin(), mtv.end(), my_func());
//
//int size = mtpq.size();
//for (int i = 0; i < size; i++) {
//    my_type top = mtpq.top();
//    cout << top.a << top.b << endl;
//    mtpq.pop();
//}
//
//for (int i = 0; i < size; i++) {
//    cout << mtv[i].a << mtv[i].b << endl;
//}
#pragma endregion

int main()
{
  
    return 0;
}

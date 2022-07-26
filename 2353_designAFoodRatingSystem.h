//
// Created by 王柯 on 7/25/22.
//

#ifndef LEETCODE_2353_DESIGNAFOODRATINGSYSTEM_H
#define LEETCODE_2353_DESIGNAFOODRATINGSYSTEM_H

#include "solution.h"

class FoodRatings {
public:
    class ff {
    public:
        int rating;
        string food_name;
        string cuisine_name;

        ff() {}

        ff(int r, string f, string c) : rating(r), food_name(f), cuisine_name(c) {}
    };

    struct cmp{
        bool operator() (const pair<int, string> &p1, const pair<int, string> &p2) const{
            if (p1.first != p2.first){
                return p1.first > p2.first;  // sort acc to decreasing rating
            }
            else {
                return p1.second < p2.second;  //sort acc to lexicographically shortest letter
            }
        }
    };

    map<string, ff> foodToFf;
    map<string, set<pair<int, string>, cmp> > cuisineDb;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            ff tmp = ff(ratings[i], foods[i], cuisines[i]);
            foodToFf.insert(make_pair(foods[i], tmp));
            cuisineDb[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        ff tmp = foodToFf[food];
        string cuisine = tmp.cuisine_name;
        //change cuisineDb
        cuisineDb[cuisine].erase({tmp.rating, tmp.food_name});
        foodToFf[food].rating = newRating;
        cuisineDb[cuisine].insert({newRating, tmp.food_name});
    }

    string highestRated(string cuisine) {
        return cuisineDb[cuisine].begin()->second;
    }
};

#endif //LEETCODE_2353_DESIGNAFOODRATINGSYSTEM_H

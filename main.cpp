#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1152;

/*
Input: username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"],
timestamp = [1,2,3,4,5,6,7,8,9,10],
website = ["home","about","career","home","cart","maps","home","home","about","career"]
Output: ["home","about","career"]
*/
tuple<vector<string>, vector<int>, vector<string>, vector<string>>
testFixture1()
{
  auto users = vector<string>{
      "joe", "joe", "joe", "james",
      "james", "james", "james",
      "mary", "mary", "mary"};
  auto ts = vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto webs = vector<string>{"home", "about", "career",
                             "home", "cart", "maps", "home",
                             "home", "about", "career"};

  auto output = vector<string>{
      "home", "about", "career"};

  return make_tuple(users, ts, webs, output);
}

string toString(vector<string> input)
{
  string result = "[";
  for (auto e : input)
  {
    result += e;
    result += ",";
  }
  /* remove the last comma */
  if (result.size() > 1)
    result.pop_back();
  result += "]";
  return result;
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see: "
       << toString(get<3>(f)) << endl;
  Solution sol;
  auto result = sol.findPattern(get<0>(f), get<1>(f), get<2>(f));
  cout << "result: " << toString(result) << endl;
}

main()
{
  test1();
  return 0;
}
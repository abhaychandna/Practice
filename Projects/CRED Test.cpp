#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;
int main()
{
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;
    std::cout << "H";
    std::for_each(
        in(cin), in(), cout << (_1 * 3) << " ");
}
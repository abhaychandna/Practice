#include <iostream>
#include <random>
using namespace std;



void pi_monte_carlo()
{


    int N = 100000;
    int K = 8;

    constexpr int FLOAT_MIN = 0;
    constexpr int FLOAT_MAX = 1;

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> distr(FLOAT_MIN, FLOAT_MAX);
    srand(1);

    double x, y;
    double d;

    int c_cnt = 0;
    int s_cnt = 0;
    int i = 0;

    {       
        for (i = 0; i < N; i++)
        {
            x = distr(eng);
            y = distr(eng);
            d = ((x * x) + (y * y));
            if (d <= 1)
                c_cnt++;
        }
    }

    double pi = 4.0 * ((double)c_cnt / (double)N);
    cout << "Pi = " << pi;
}

int main()
{
    pi_monte_carlo();
}

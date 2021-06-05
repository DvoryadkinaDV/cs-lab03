#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
// ввод массива чисел
vector<double>
input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

// поиск максимума и минимума
void
find_minmax(const vector<double>& numbers, double& min, double& max)
{
    min = numbers[0];
    for (double x : numbers)
    {
    if (x < min)
    {
    min = x;
    }
    else if (x > max)
    {
    max = x;
    }
    }

}

//расчет количества чисел в столбцах гистограммы

vector<size_t>
make_histogram(const vector<double>& numbers, size_t bin_count)
{

    double min, max;
    size_t number_count = numbers.size();
    find_minmax(numbers,min,max);
    vector<size_t> bins(bin_count);
    double bin_size = (max - min) / bin_count;
    for (size_t i = 0; i < number_count; i++) {
        bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++) {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi)) {
                bins[j]++;
                found = true;
            }
        }
        if (!found) {
            bins[bin_count - 1]++;
        }
    }
    return bins;
}


// show histogram text
void show_histogram_text(const vector<size_t>& bins)
{
    size_t bin_count = bins.size();
    double max_count = bins[0];
    double s = 0;
    for (size_t i = 1; i < bin_count; i++)

    {

    if (bins[i] > max_count) max_count = bins[i];

    s = s + bins [i];

    }

    double coef;

    if (max_count > MAX_ASTERISK)

    coef = static_cast<double>(MAX_ASTERISK) / max_count;

    else coef = 1;

    s = s / bin_count;

    size_t j;

    for (size_t i = 0; i < bin_count; i++)

    {

    if (bins[i]<100)

    {

    cout<<" ";

    if (bins[i]<10) cout<<" ";

    }

    cout << bins[i];

    cout << "|";

    if (bins[i] > s)

    {

    for (j = 0; j < s *coef ; j++)
    cout<<"*" ;

    float p = (bins[i] - s)*coef;

    for (j = 1; j < p ; j++)
    cout<<"+" ;

    }

    else

    {

    for (j = 0; j < bins[i]*coef ; j++)
        cout<<"*" ;

    float p = (s - bins[i])*coef;

    for (j = 0; j < p ; j++)
        cout <<"-" ;

    }
        cout << endl;
    }
}
    int main()
    {
        size_t number_count;
        cerr << "Enter number count: ";
        cin >> number_count;
        cerr << "Enter numbers: ";
        const auto numbers = input_numbers(number_count);
        size_t bin_count;
        cerr << "Enter number bins: ";
        cin >> bin_count;
        const auto bins = make_histogram(numbers, bin_count);
        show_histogram_text(bins);
        return 0;
        
    }



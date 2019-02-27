#include <iostream>
#include <vector>
#include <assert.h>
#include <cmath>
using namespace std;

/*
ref1: https://blog.csdn.net/qll125596718/article/details/8248249 一元线性回归模型与最小二乘法及其C++实现


*/
pair<double, double> LeastSquare(const vector<double>& X, const vector<double>& Y){
    /* y = ax + b */
    assert(X.size() == Y.size() && X.size() != 0);
    double A = 0, B = 0, C = 0, D = 0;
    int n = X.size();
    for(int i = 0; i < n; ++i){
        A += X[i] * X[i];
        B += X[i];
        C += X[i] * Y[i];
        D += Y[i];
    }
    double denominator = n*A - B*B;
    assert(denominator != 0);
    double a = (n*C - B*D)/denominator, b = (A*D - B*C)/denominator;
    return make_pair(a, b);
}

pair<double, double> LeastSquare_v2(const vector<double>& X, const vector<double>& Y){
    /* y = ax + b
    使用的是先求EX, EY, DX, 再求最小二乘的方法 */
    assert(X.size() == Y.size() && X.size() != 0);
    int n = X.size();
    double X_mean = 0, Y_mean = 0;
    for(int i = 0; i < n; ++i){
        X_mean += X[i];
        Y_mean += Y[i];
    } X_mean /= n;
    Y_mean /= n;
    double X_variance = 0, numerator = 0;
    for(int i = 0; i < n; ++i){
        double tmp = X[i]-X_mean;
        X_variance += tmp*tmp;
        numerator += tmp*(Y[i]-Y_mean);
    }
    assert(X_variance != 0);
    double a = numerator/X_variance, b = Y_mean - a*X_mean;
    return make_pair(a, b);
}

int main(){
    /* 数据来源：https://blog.csdn.net/pl20140910/article/details/51926886 */
    float pY[25] = { 10.98, 11.13, 12.51, 8.40, 9.27,
                      8.73, 6.36, 8.50, 7.82, 9.14,
                      8.24, 12.19, 11.88, 9.57, 10.94,
                      9.58, 10.09, 8.11, 6.83, 8.88,
                      7.68, 8.47, 8.86, 10.38, 11.08 };
    float pX[25] = { 35.3, 29.7, 30.8, 58.8, 61.4,
                      71.3, 74.4, 76.6, 70.7, 57.5,
                      46.4, 28.9, 28.1, 39.1, 46.8,
                      48.5, 59.3, 70.0, 70.0, 74.5,
                      72.1, 58.1, 44.6, 33.4, 28.6 };
    vector<double> X(pX, pX+25), Y(pY, pY+25);
    pair<double, double> res = LeastSquare(X, Y);
    double a = res.first, b = res.second;
    cout << a << " " << b << endl;  // y = -0.079*x + 13.62
    res = LeastSquare_v2(X, Y);
    a = res.first, b = res.second;
    cout << a << " " << b << endl;  // y = -0.079*x + 13.62
}

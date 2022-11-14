/*
描述
假设你有一个数组prices，长度为n，其中prices[i]是股票在第i天的价格，请根据这个价格数组，返回买卖股票能获得的最大收益
1.你可以买入一次股票和卖出一次股票，并非每天都可以买入或卖出一次，总共只能买入和卖出一次，且买入必须在卖出的前面的某一天
2.如果不能获取到任何利润，请返回0
3.假设买入卖出均无手续费
 
要求：空间复杂度 O(1)，时间复杂度 O(n)
*/

import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param prices int整型一维数组 
     * @return int整型
     */
    public int maxProfit (int[] arr) {
        // 本方法 空间复杂度 O(n)，时间复杂度 O(n)
        int n = arr.length;
        if(n == 0) return 0;
        int [] left = new int [n];
        int [] right = new int [n];
        Arrays.fill(left,0);
        Arrays.fill(right,0);
        left[0] = arr[0];
        for(int i = 1; i < n; ++i){
            left[i] = Math.min(left[i-1], arr[i]);
        }
        right[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; --i){
            right[i] = Math.max(arr[i], right[i+1]);
        }
        int res = 0;
        for(int i = 1; i < n; ++i){
            res = Math.max(res, right[i]-left[i]);
        } return res;
    }
    
    public int maxProfit2 (int[] arr) {
        // 本方法 空间复杂度 O(1)，时间复杂度 O(n)
        int n = arr.length;
        if(n == 0) return 0;
        int res = 0;
        int min = arr[0];
        for(int i = 1; i < n; ++i){
            min = Math.min(min, arr[i]);
            res = Math.max(res, arr[i]-min);
        } return res;
    }
}

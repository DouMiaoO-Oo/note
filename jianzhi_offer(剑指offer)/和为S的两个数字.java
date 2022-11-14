/ *
描述：
输入一个升序数组 array 和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，返回任意一组即可，如果无法找出这样的数字，返回一个空数组即可。
示例1：
    输入：
        [1,2,4,7,11,15],15
    返回值：
        [4,11]
    说明：
        返回[4,11]或者[11,4]都是可以的       
示例2
    输入：
        [1,5,11],10
    返回值：
        []
    说明：
        不存在，返回空数组     
*/
import java.util.ArrayList;
public class Solution {
    public ArrayList<Integer> FindNumbersWithSum(int [] arr,int sum) {
        int l = 0;
        int r = arr.length-1;
        ArrayList<Integer> res = new ArrayList<Integer>();
        while(l < r){
            if(arr[l] + arr[r] == sum){
                res.add(arr[l]);
                res.add(arr[r]);
                break;
            }
            if(arr[l] + arr[r] < sum) ++l;
            else --r;
        } return res;
    }
}

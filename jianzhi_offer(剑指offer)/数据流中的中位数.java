import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class Solution {
    private Queue<Integer> minH = new PriorityQueue<Integer>();
    private Queue<Integer> maxH = new PriorityQueue<Integer>(
        new Comparator<Integer>(){
            @Override
            public int compare(Integer x, Integer y){
                return y-x;
            }
        });
    public void Insert(Integer num) {
        if(maxH.isEmpty() || num <= maxH.peek()){
            maxH.add(num);
        } else{
            minH.add(num);
        }
        if(minH.size()+2 == maxH.size()){
            minH.offer(maxH.poll());
        }
        else if(maxH.size() < minH.size()){
            maxH.offer(minH.poll());
        }
    }

    public Double GetMedian() {
        if(minH.size() == maxH.size()){
            return (minH.peek()+maxH.peek())/2.0;
        } return maxH.peek()*1.0;
    }
}

class Reach{
//You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.
    // X and Y co-ordinates of the points in order.
    // Each point is represented by (X.get(i), Y.get(i))
    public int coverPoints(ArrayList<Integer> X, ArrayList<Integer> Y) {
        int sum=0;
        for(int i=1;i<=X.size()-1;++i)
        {
            sum=sum + Math.max(Math.abs(X.get(i)-X.get(i-1)),Math.abs(Y.get(i)-Y.get(i-1))); 
        }
        return sum;
    }
}





class MovingAverage {
    int size = 0; 
    List queue = new ArrayList<Integer>(); 
    public MovingAverage(int size) {
        this.size = size; 
    }
    
   public double next(int val) {
        
        queue.add(val); 
        
        int windowSum =0; 
        
        for(int i = Math.max(0, queue.size() - size); i < queue.size(); i++)
        {
            windowSum += (int)queue.get(i);
        }
        
        return windowSum*1.0/Math.min(queue.size(), size); 
   }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
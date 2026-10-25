package ExAandExB;

import java.util.ArrayList;

public class MyVector <E extends Number & Comparable<E>>{
    private ArrayList<Item<E>> storageM;
    private Sorter<E> sorter;

    public MyVector(int n){
        this.storageM = new ArrayList<>(n);
    }

    public MyVector(ArrayList<Item<E>> arr){
        this.storageM = new ArrayList<>(arr);
    }

    public void add(Item<E> value){
        this.storageM.add(value);
    }

    public void setSortStrategy(Sorter<E> s){
        this.sorter = s;
    }

    public void performSort(){
        if (this.sorter != null) this.sorter.sort(this.storageM);
    }

    public void display(){
        for (Item<E> item : this.storageM){
            System.out.print(item.getItem() + " ");
        }
        System.out.println();
    }
}

package ExC;

import java.util.ArrayList;

public class DoubleArrayListSubject implements Subject {
    private ArrayList<Double> data;
    private ArrayList<Observer> observers;

    public DoubleArrayListSubject() {
        this.data = new ArrayList<>();
        this.observers = new ArrayList<>();
    }

    @Override
    public void addObserver(Observer o) {
        this.observers.add(o);
        o.update(data);
    }

    @Override
    public void remove(Observer o) {
        this.observers.remove(o);
        o.update(data);
    }

    @Override
    public void notifyObservers() {
        for (Observer o : this.observers)
            o.update(data);
    }

    public void addData(double value) {
        this.data.add(value);
    }

    public void setData(double value, int index) {
        if (index >= 0 && index < data.size()) {
            data.set(index, value);
            notifyObservers();
        }
        else{
            System.out.println("Error: Invalid index");
        }
    }

    public void populate(double [] values) {
        data.clear();
        for (double d : values) data.add(d);
        notifyObservers();
    }

    public void display() {
        if (data.isEmpty()) {
            System.out.println("Empty List ...");
            return;
        }
        for (Double d : data){
            System.out.print(d + " ");
        }
        System.out.println();
    }
}
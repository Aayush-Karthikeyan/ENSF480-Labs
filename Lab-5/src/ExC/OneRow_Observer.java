package ExC;

import java.util.ArrayList;

public class OneRow_Observer implements Observer {
    private ArrayList<Double> data;

    public OneRow_Observer(DoubleArrayListSubject subject) {
        data = new ArrayList<Double>();
        subject.addObserver(this);
    }

    @Override
    public void update(ArrayList<Double> newData) {
        data = new ArrayList<Double>(newData);
        display();
    }

    public void display() {
        System.out.println("Notification to One-Row Observer: Data Changed:");
        if (data.isEmpty()) {
            System.out.println("Empty List ...");
            return;
        }
        for (Double d : data) {
            System.out.print(d + " ");
        }
        System.out.println();
    }
}
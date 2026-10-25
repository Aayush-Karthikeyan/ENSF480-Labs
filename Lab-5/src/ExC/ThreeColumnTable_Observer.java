package ExC;

import java.util.ArrayList;
import java.util.Arrays;

public class ThreeColumnTable_Observer implements Observer {
    private ArrayList<Double> data;

    public ThreeColumnTable_Observer(DoubleArrayListSubject subject) {
        this.data = new ArrayList<>();
        subject.addObserver(this);
    }

    @Override
    public void update(ArrayList<Double> newData) {
        this.data = new ArrayList<>(newData);
        display();
    }

    public void display() {
        System.out.println("Notification to Three-Column Table Observer: Data Changed:");
        if (data.isEmpty()) {
            System.out.println("Empty List ...");
            return;
        }

        for (int i = 0; i < data.size(); i+= 3) {
            for (int j = i; j < i + 3 && j < data.size(); j++){
                System.out.print(data.get(j) + " ");
            }
            System.out.println();
        }
    }
}

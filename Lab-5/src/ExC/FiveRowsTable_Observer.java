package ExC;

import java.util.ArrayList;

public class FiveRowsTable_Observer implements Observer {
    private ArrayList<Double> data;

    public FiveRowsTable_Observer(DoubleArrayListSubject subject) {
        data = new ArrayList<Double>();
        subject.addObserver(this);
    }

    @Override
    public void update(ArrayList<Double> newData) {
        data = new ArrayList<Double>(newData);
        display();
    }

    public void display() {
        System.out.println("Notification to Five-Rows Table Observer: Data Changed:");
        if (data.isEmpty()) {
            System.out.println("Empty List ...");
            return;
        }

        for (int i = 0; i < 5 && i < data.size(); i++) {
            for (int j = i; j < data.size(); j+= 5){
                System.out.print(data.get(j) + " ");
            }
            System.out.println();
        }
    }
}

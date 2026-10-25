package ExAandExB;

import java.util.ArrayList;
import java.util.Collections;

public class BubbleSorter <E extends Number & Comparable<E>> implements Sorter<E> {
    @Override
    public void sort(ArrayList<Item<E>> list){
        int n = list.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (list.get(j).getItem().compareTo(list.get(j + 1).getItem()) > 0)
                    Collections.swap(list, j, j + 1);
            }
        }
    }
}
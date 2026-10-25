package ExAandExB;

import java.util.ArrayList;
import java.util.Collections;

public class SelectionSorter <E extends Number & Comparable<E>> implements Sorter<E> {
    @Override
    public void sort(ArrayList<Item<E>> list){
        for (int i = 0; i < list.size() - 1; i++) {
            int min = i;
            for (int j = i + 1; j < list.size(); j++) {
                if (list.get(j).getItem().compareTo(list.get(min).getItem()) < 0)
                    min = j;
            }
            if (min != i)
                Collections.swap(list, i, min);
        }
    }
}
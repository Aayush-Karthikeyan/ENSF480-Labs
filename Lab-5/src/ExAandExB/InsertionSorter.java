package ExAandExB;

import java.util.ArrayList;

public class InsertionSorter <E extends Number & Comparable<E>> implements Sorter<E> {
    @Override
    public void sort(ArrayList<Item<E>> list){
        for (int i = 1; i < list.size(); i++) {
            Item<E> key = list.get(i);
            int j = i - 1;
            while (j >= 0 && list.get(j).getItem().compareTo(key.getItem()) > 0) {
                list.set(j + 1, list.get(j));
                j--;
            }
            list.set(j + 1, key);
        }
    }
}
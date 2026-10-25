package ExC;

public interface Subject {
    void addObserver(Observer o);
    void remove(Observer o);
    void notifyObservers();
}
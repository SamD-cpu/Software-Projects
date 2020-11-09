/**
 * @author Samuel Debesai
 * @date 6/1/2018
 */
import java.util.*;
public abstract class ReservableItem{

    private String id; 
    private Reservation[] res = new Reservation[10];//constant of 10
    /**
     * needed for derived classes
     */
    public ReservableItem(Scanner fileIn)
    {
        this.id = fileIn.nextLine();
    }

    /**
     * gets the id
     * @return id
     */
    public String getId()
    { 
        return this.id;
    }

    /**
     * abstract method for fitness method
     */
    public abstract int getFitnessValue(Reservation res);

    /**
     * gets reservations
     * @return res
     */
    public Reservation[] getReservations()
    {
        return res;
    }

}

/**
 * @author Samuel Debesai
 * @date 6/1/2018
 */
import java.util.*;
public class Table extends ReservableItem
{
    private int seats;

    /**
     * Constructor for objects of class Table
     */
    public Table(Scanner fileIn) 
    {
        super(fileIn);
        seats = Integer.parseInt(getId().substring(getId().indexOf(" ")+1));

    }

    /**
     * gets the fitness value of the reservation from 0-100
     * fitness based around seats
     * @return 0,100,fitnessValue
     */
    public int getFitnessValue(Reservation res) 
    {

        int fitnessValue =0;
        if(!(res instanceof RestaurantReservation))//not a instance of the restaurant class, not worth
        //evaluation
        {
            System.out.println("Wrong Reservation Type");
            return 0;
        }

        RestaurantReservation newRes = (RestaurantReservation) res;
        if(seats<newRes.getSeats() || getReservations()[newRes.getTime()] != null)//if the seats are
        //less then what you need return 0
        {
            return 0;
        }

        if (seats == newRes.getSeats()){//return if a full match
            return 100;
        }

        fitnessValue = (this.seats - newRes.getSeats() * 100);//builds a fitness value of the 
        //difference of seats and lesser of seats needed
        return fitnessValue;
    }
}

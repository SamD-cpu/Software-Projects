/**
 * @author Samuel Debesai
 * @date 6/1/2018
 */
public class RestaurantReservation extends Reservation
{
    private int seats;
    /**
     * reservations in the case of a restaurant 
     */
    public RestaurantReservation(int seats ,int timeslot, String customerName) 
    {
        super(customerName, timeslot);
        this.seats = seats;
    }

    /**
     * getter for seats
     * @return seats
     */
    public int getSeats()
    {
        return this.seats;
    }

    /**
     * toString for Restaurant
     * @return seats
     */
    public String toString()
    {
        return super.toString() + " "+ "seats: "+ this.seats+ " \n";
    }

}

/**
 * @author Samuel Debesai
 * @date 6/1/2018
 */
import java.util.*;
public class Boat extends ReservableItem
{
    /**
     * takes input, taken from reserableItem
     */
    public Boat(Scanner fileIn) 
    {
        super(fileIn);

    }

    /**
     * fitness of reservation of boats
     * @param res
     */
    public int getFitnessValue(Reservation res)
    {

        int fitnessValue =0;
        if(!(res instanceof BoatReservation))//same type
        {
            System.out.println("Wrong Reservation Type");
            return 0;//no fit
        }

        BoatReservation newRes = (BoatReservation) res;
        ArrayList<String> arr = newRes.getPreferences();//array of preferences
        if(getReservations()[newRes.getTime()] != null)//times of reservation is not open

        {
            return 0;// no fit
        }

        for(int i=0; i<arr.size();i++)
        {
            if(super.getId().equals(arr.get(i)))//checks what the best match is from the list
            //of boats preferences
            {
                fitnessValue = 100-i;
                return fitnessValue;
            }
        }
        return fitnessValue;
    }

}

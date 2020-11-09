/**
 * @author Samuel Debesai
 * @date 6/1/2018
 */
import java.util.*;
public class BoatReservation extends Reservation
{
    private ArrayList<String> list= new ArrayList<String>();
    /**
     *Boat version, call to super
     */
    public BoatReservation(String customerName, int timeslot)
    {
        super(customerName,timeslot);

    }

    /**
     * accounts for boats preferences to the list
     * @param boatName
     */
    public void addBoatPreference(String boatName)
    {
        list.add(boatName);

    }

    /**
     * prefrences to AL
     * @return list
     * 
     */
    public ArrayList<String> getPreferences()
    {
        return this.list;
    }

}

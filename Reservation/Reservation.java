/**
 * @author Samuel Debesai
 * @date 6/1/2018
 */
import java.util.*;
public class Reservation implements Comparable{
    //instance
    private String customerName;
    private int timeslot;
    private String id;
    /**
     * constructor that takes in the instances of the name and time
     */
    public Reservation(String customerName, int timeslot)
    {
        this.customerName = customerName;
        this.timeslot = timeslot;
    }

    /*
     * getters for the class
     */
    public String getCustomer()
    {
        return this.customerName;
    }

    public int getTime()
    {
        return this.timeslot;
    }

    /**
     * toString method for res
     * @return str
     */
    public String toString()
    {
        String str = "";
        str += "Name: " + getCustomer() +" Time: " + getTime() + " ID: " + this.id;
        return str;
    }

    /**
     * sets the ID 
     * @param id
     */
    public void setResourceId(String id)
    {
        this.id = id;
    }

    /**
     * compares the two objects
     * 1) -1 is this is less than obj
     * 2) 1 if this is greater than obj
     * 3) 0 is equal
     */
    @Override
    public int compareTo(Object other)
    {
        Reservation obj = (Reservation) other;
        if(this.customerName.compareTo(obj.getCustomer()) < 0){ 
            return -1;
        }
        if(this.customerName.compareTo(obj.getCustomer()) > 0){ 
            return 1;
        }
        return 0; 
    }

}
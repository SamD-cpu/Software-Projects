/**
 * @author Samuel Debesai
 * @date 6/1/2018
 */
import java.util.*;
public class ResManager<ItemType extends ReservableItem,ResType extends Reservation>{
    ArrayList<ItemType> itemList; 
    ArrayList<ResType> resList; 
    /**
     * no arg constructor
     */
    public ResManager()
    {
        //instantiate the arraylists 
        itemList = new ArrayList<ItemType>();
        resList = new ArrayList<ResType>();

    }

    /**
     * makes a reservation based on if the trialReservation fits
     * @param trialRes
     */
    public Reservation makeReservation(ResType trialRes)
    {
        //sets the max and index for potential reservation
        int max = 0;
        int index = 0;

        for (int i = 0; i < itemList.size(); i++)//traverses the item list
        {
            if (itemList.get(i).getFitnessValue(trialRes) > max)//checks if the fitness value if greater
            //then the max
            {
                max = itemList.get(i).getFitnessValue(trialRes);//sets new max if so
                index = i;//index @ i
                if (max == 100)
                    break;
            }
        }
        if(max != 0)
        {
            resList.add(trialRes);//adds to offical list of reservations
            itemList.get(index).getReservations()[trialRes.getTime()] = trialRes;//new reservation
            trialRes.setResourceId(itemList.get(index).getId());//sets a new resource ID
            return trialRes;
        }
        System.out.println("Unable to reserve: "+ trialRes.toString());
        return null;
    }

    /**
     * add trial reservation to itemList
     * @param trialRes
     */
    public void addReservable(ItemType trialRes)
    {
        itemList.add(trialRes);
    }

    /**
     * sorts resevation using the bubble sort algo
     */
    public void sortReservations()
    {
        int n = resList.size();
        for (int i = 0; i < n-1; i++)
            for (int j = 0; j < n-i-1; j++)
                if (resList.get(j).getCustomer().compareTo(resList.get(j+1).getCustomer())> 0)
                {
                    //swap method using arraylist
                    ResType temp = resList.get(j);
                    resList.set(j,resList.get(j+1));
                    resList.set(j+1,temp);
                }
    }

    /**
     * toString method
     * @return str
     */
    public String toString()
    {
        String str = "";
        for(int i =0; i < resList.size(); i++)
        {
            str+= resList.get(i).toString();
            str+= " \n ";
        }
        return str;
    }

}

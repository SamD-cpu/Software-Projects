//package ReservationSystem;
/*
 * Reservation System homework
 * CSS143
 * Lesley Kalmin
 */

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

/*
 * Driver for Restaurant Reservations
 */
public class RestaurantDriver {

    public static void main(String[] args) {
        ResManager<Table, Reservation> manager = new ResManager<Table, Reservation>();
        try {

            Scanner scanner = new Scanner(new FileInputStream("tableFile.txt"));

            while (scanner.hasNext())
            {				
                manager.addReservable(new Table(scanner));				
            }
        } catch (FileNotFoundException e) {
            System.out.println("file not found");
            System.exit(0);
        }
        //manager.printItems();  // debugging code, prints list of Tables

        RestaurantReservation r1 = new RestaurantReservation(2, 3, "Chen family");
        manager.makeReservation(r1);
        RestaurantReservation r2 = new RestaurantReservation(8, 4, "Singh party");
        manager.makeReservation(r2);
        r2 = new RestaurantReservation(8, 4, "Kal");
        manager.makeReservation(r2);
        r2 = new RestaurantReservation(8, 4, "business1");
        manager.makeReservation(r2);
        RestaurantReservation r3 = new RestaurantReservation(2, 2, "Newmans");
        manager.makeReservation(r3);

        r2 = new RestaurantReservation(11, 4, "TooBig");
        manager.makeReservation(r2);
        r2 = new RestaurantReservation(10, 4, "party5");
        manager.makeReservation(r2);
        r3 = new RestaurantReservation(10, 4, "party6");
        manager.makeReservation(r3);
        r3 = new RestaurantReservation(10, 4, "overflow");
        manager.makeReservation(r3);

        System.out.println("Listing of reservations:");
        System.out.println(manager);

        System.out.println("\nSorted reservations");
        manager.sortReservations();
        System.out.println(manager);
    }

}

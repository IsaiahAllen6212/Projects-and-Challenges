package learn.foraging;

import learn.foraging.ui.Controller;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class App {
    public static void main(String[] args) {
        /*
        ConsoleIO io = new ConsoleIO();
        View view = new View(io);

        ForageFileRepository forageFileRepository = new ForageFileRepository("./data/forage_data");
        ForagerFileRepository foragerFileRepository = new ForagerFileRepository("./data/foragers.csv");
        ItemFileRepository itemFileRepository = new ItemFileRepository("./data/items.txt");

        ForagerService foragerService = new ForagerService(foragerFileRepository);
        ForageService forageService = new ForageService(forageFileRepository, foragerFileRepository, itemFileRepository);
        ItemService itemService = new ItemService(itemFileRepository);

        Controller controller = new Controller(foragerService, forageService, itemService, view);
        controller.run()
         */

        ApplicationContext context = new ClassPathXmlApplicationContext("dependency-configuration.xml");

        Controller controller = context.getBean(Controller.class);
        controller.run();
    }
}

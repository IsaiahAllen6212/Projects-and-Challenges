package learn.foraging.domain;

import learn.foraging.data.DataException;
import learn.foraging.data.ForagerRepositoryDouble;
import learn.foraging.models.Forager;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ForagerServiceTest {

    ForagerService service = new ForagerService(new ForagerRepositoryDouble());

    @Test
    void shouldAdd() throws DataException {
        Result actual = service.add(new Forager("Test", "McTest", "MN"));

        assertTrue(actual.isSuccess());
    }

    @Test
    void shouldNotAddNull() throws DataException {
        Result actual = service.add(new Forager());

        assertFalse(actual.isSuccess());
    }

    @Test
    void shouldNotAddNullState() throws DataException{
        Forager forager = new Forager();
        forager.setFirstName("Test");
        forager.setLastName("McTest");
        forager.setState("");
        Result actual = service.add(forager);

        System.out.print("Error message for 'shouldNotAddNullState' test: ");
        System.out.println(actual.getErrorMessages().get(0));
        assertFalse(actual.isSuccess());
    }

    @Test
    void shouldNotAddNullFirstName() throws DataException{
        Forager forager = new Forager();
        forager.setFirstName("");
        forager.setLastName("McTest");
        forager.setState("MN");
        Result actual = service.add(forager);

        System.out.print("Error message for 'shouldNotAddNullFirstName' test: ");
        System.out.println(actual.getErrorMessages().get(0));
        assertFalse(actual.isSuccess());
    }

    @Test
    void shouldNotAddNullLastName() throws DataException{
        Forager forager = new Forager();
        forager.setFirstName("Test");
        forager.setLastName("");
        forager.setState("MN");
        Result actual = service.add(forager);

        System.out.print("Error message for 'shouldNotAddNullLastName' test: ");
        System.out.println(actual.getErrorMessages().get(0));
        assertFalse(actual.isSuccess());
    }

    @Test
    void shouldNotAddNullDuplicate() throws DataException{
        service.add(new Forager("Test", "McTest", "MN"));
        Result actual = service.add(new Forager("Test", "McTest", "MN"));

        System.out.print("Error message for 'shouldNotAddDuplicate' test: ");
        System.out.println(actual.getErrorMessages().get(0));
        assertFalse(actual.isSuccess());
    }
}
package learn.foraging.data;

import learn.foraging.models.Forager;
import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class ForagerFileRepositoryTest {
    ForagerFileRepository repo = new ForagerFileRepository("./data/foragers.csv");

    @Test
    void shouldFindAll() throws IOException {
        repo = new ForagerFileRepository("./data/foragers.csv");
        List<Forager> all = repo.findAll();

        long lineCount = Files.lines(Paths.get("./data/foragers.csv")).count() - 1;
        assertEquals(lineCount, all.size());
    }

    @Test
    void FindAllShouldNotBeEmpty(){
        repo = new ForagerFileRepository("./data/foragers.csv");
        List<Forager> all = repo.findAll();
        assertFalse(all.isEmpty());
    }

    @Test
    void shouldAdd() throws DataException{
        Forager forager = new Forager("Test", "McTest", "MN");
        Forager actual = repo.add(forager);

        assertEquals("Test", actual.getFirstName());
    }
}
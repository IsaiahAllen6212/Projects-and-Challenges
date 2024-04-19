package learn.foraging.domain;

import learn.foraging.data.DataException;
import learn.foraging.data.ForagerRepository;
import learn.foraging.models.Category;
import learn.foraging.models.Forage;
import learn.foraging.models.Forager;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public class ForagerService {

    private final ForagerRepository repository;

    public ForagerService(ForagerRepository repository) {
        this.repository = repository;
    }

    public List<Forager> findByState(String stateAbbr) {
        return repository.findByState(stateAbbr);
    }

    public List<Forager> findByLastName(String prefix) {
        return repository.findAll().stream()
                .filter(i -> i.getLastName().startsWith(prefix))
                .collect(Collectors.toList());
    }


    public Result add(Forager forager) throws DataException {
        Result result = validate(forager);
        if(result.getErrorMessages().size() > 0){
            return result;
        }
        repository.add(forager);
        return result;
    }

    public Result validate(Forager forager) {
        Result result = new Result();
        List<Forager> all = repository.findAll();


        if(forager == null){
            result.addErrorMessage("Forger cannot be null.");
            return result;
        }

        if(all.isEmpty()){
            result.addErrorMessage("Forger file is corrupted.");
            return result;
        }

        if(forager.getState() == null|| forager.getState().isEmpty()){
            result.addErrorMessage("State required.");
            return result;
        }

        if(forager.getFirstName() == null|| forager.getFirstName().isEmpty()){
            result.addErrorMessage("First Name required.");
            return result;
        }

        if(forager.getLastName() == null|| forager.getLastName().isEmpty()){
            result.addErrorMessage("Last Name required.");
            return result;
        }

        Set<Character> specialCharacters = getSpecialCharactersSet();

        if (specialCharacters.stream().anyMatch(ch -> forager.getFirstName().contains(String.valueOf(ch)))) {
            result.addErrorMessage("First name cannot contain any special characters");
        }

        if (specialCharacters.stream().anyMatch(ch -> forager.getLastName().contains(String.valueOf(ch)))){
            result.addErrorMessage("Last name cannot contain any special characters");
        }

        for (Forager f : all){
            if (f.getFirstName().equals(forager.getFirstName())
                    && f.getLastName().equals(forager.getLastName())
                    && f.getState().equals(forager.getState())){
                result.addErrorMessage("Forager cannot be a duplicate.");
                return result;
            }
        }

        return result;
    }

    public void itemCategoryValue(List<Forage> forages){

        if (forages == null || forages.isEmpty()){
            System.out.println("No forages found.");
            return;
        }

        Map<Category, BigDecimal> categoryValueMap = forages.stream()
                .collect(Collectors.groupingBy(forage -> forage.getItem().getCategory(),
                        Collectors.reducing(BigDecimal.ZERO, Forage::getValue, BigDecimal::add)));

        List<Map.Entry<Category, BigDecimal>> sortedEntries = categoryValueMap.entrySet().stream()
                .sorted(Map.Entry.<Category, BigDecimal>comparingByValue().reversed())
                .collect(Collectors.toList());

        sortedEntries.forEach(entry -> {
            String formattedValueSum = entry.getValue().setScale(2, RoundingMode.HALF_UP).toString();
            System.out.println(entry.getKey() + ": $" + formattedValueSum);
        });
    }

    public static Set<Character> getSpecialCharactersSet() {
        Set<Character> specialCharacters = new HashSet<>();

        specialCharacters.add('!');
        specialCharacters.add('@');
        specialCharacters.add('#');
        specialCharacters.add('$');
        specialCharacters.add('%');
        specialCharacters.add('^');
        specialCharacters.add('&');
        specialCharacters.add('*');
        specialCharacters.add('(');
        specialCharacters.add(')');
        specialCharacters.add('-');
        specialCharacters.add('_');
        specialCharacters.add('=');
        specialCharacters.add('+');
        specialCharacters.add('[');
        specialCharacters.add(']');
        specialCharacters.add('{');
        specialCharacters.add('}');
        specialCharacters.add('\\');
        specialCharacters.add('|');
        specialCharacters.add(';');
        specialCharacters.add(':');
        specialCharacters.add('\'');
        specialCharacters.add('"');
        specialCharacters.add(',');
        specialCharacters.add('.');
        specialCharacters.add('/');
        specialCharacters.add('<');
        specialCharacters.add('>');
        specialCharacters.add('?');

        return specialCharacters;
    }

}

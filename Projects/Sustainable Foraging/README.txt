Foraging Application

Overview
- The Foraging Application is a Java program designed to manage foragers, items, and foraging activities. 
- It provides functionality to add, retrieve, and manipulate data related to foragers and foraging activities, as well as items that can be foraged. 
- The application is structured using a layered architecture, with separate components for domain logic and data access.


Features
- Forager Management: Add new foragers, retrieve foragers by state or last name, and validate forager data.
- Item Management: Add new items, retrieve items by category, and validate item data.
- Foraging Activity Management: Add new foraging activities, retrieve activities by date, and generate random foraging data within a specified date range.
- Data Persistence: Forager, item, and foraging activity data is stored in CSV files using a file-based repository implementation.
- Error Handling: Custom exceptions (DataException) are used for handling data-related errors.


Architecture
- The application follows a layered architecture, with the following components:
- Domain Layer: Contains business logic and domain entities:
- Forager: Represents a forager with attributes like first name, last name, and state.
- Item: Represents an item that can be foraged with attributes like name, category, and dollar per kilogram.
- Forage: Represents a foraging activity with attributes like date, forager, item, and kilograms.
- Service Layer: Provides services for manipulating domain entities and performing business logic:
- ForagerService: Provides services related to foragers, such as adding, retrieving, and validating foragers.
- ItemService: Provides services related to items, such as adding, retrieving, and validating items.
- ForageService: Provides services related to foraging activities, such as adding, retrieving, and generating foraging activities.
- Data Access Layer: Provides interfaces and implementations for data access:
- ForagerRepository: Interface for accessing forager data.
- ItemRepository: Interface for accessing item data.
- ForageRepository: Interface for accessing foraging activity data.
- ForagerFileRepository, ItemFileRepository, ForageFileRepository: File-based implementations of the repository interfaces.
- Utilities: Contains utility classes like Result and Response for handling operation results and error messages.


Usage
Building the Application:
- Ensure you have Java installed on your system.
- Clone the repository or download the source code.
- Build the application using your preferred Java development environment or command-line tools.

Running the Application:
- Execute the main program or run the application using your Java IDE.
- Follow the prompts to interact with the application, such as adding foragers, items, or foraging activities.

Customization:
- Customize the file paths in the repository implementations (ForagerFileRepository, ItemFileRepository, ForageFileRepository) to specify where the data files are stored.
- Modify or extend the domain entities, services, or repositories to meet specific requirements.


Dependencies
The application has no external dependencies beyond the core Java libraries.

Contributing
Contributions to the Foraging Application are welcome! If you find any bugs, have feature requests, or want to contribute improvements, feel free to open an issue or submit a pull request on GitHub.

License
This project is licensed under the MIT License. See the LICENSE file for details.
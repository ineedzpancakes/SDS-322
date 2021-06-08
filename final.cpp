#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::to_string;
using std::vector;
using std::cout;
using std::endl;

class Person {
  public:
    static const int SUSCEPTIBLE = 0;
    static const int RECOVERED = -1;
    static const int VACCINATED = -2;
    int healthStatus = 0;

    // Returns an integer value of a person's health status. 
    int getHealthStatus() {
      return healthStatus;
    }

    // Returns the description of the person’s state as a string.
    string status_string() {
      string status;
      if (healthStatus == SUSCEPTIBLE) {
        status = "susceptible";
      }
      if (healthStatus == RECOVERED) {
        status = "recovered";
      }
      if (healthStatus == VACCINATED) {
        status = "vaccinated";
      }
      else {
        status = "sick (" + to_string(healthStatus) + ")";
      }
      return status;
    }

    // Indicates whether the person is sick or has recovered. 
    bool is_stable() {
      return healthStatus <= SUSCEPTIBLE;
    }

    // Indicates whether the person is susceptible or not.
    bool is_susceptible() {
      return healthStatus == SUSCEPTIBLE;
    }

    // Updates the person’s status for the next day. 
    void update() {
      if (!(is_stable())) {
        healthStatus--;
        if (is_susceptible()) {
          healthStatus = -1;
        }
      }
    }

    // Infect a person, with the disease to run for n days.
    void infect(int n) {
      healthStatus = is_susceptible() ? n : healthStatus;
    }

    // Vaccinates a person. 
    void vaccinate() {
      healthStatus = is_susceptible() ? VACCINATED : healthStatus;
    }
};

class Population {
  public:
    int populationSize;
    int nDays;
    int maxInteractions;
    vector<Person> population;
    float probability_of_transfer;
    float chance;
    float vaccinated_percentage;
    int nVaccinated;

    Population(int npeople) {
      populationSize = npeople;

      for (int i = 0; i < populationSize; i++) {
        Person person;
        population.push_back(person);
      }
    }

    // Sets the max amount of interactions.
    void set_max_interactions(int interactions) {
      maxInteractions = interactions;
    }

    // Sets the number of days. 
    void set_n_days(int n) {
      nDays = n;
    }

    // Infects a random person.
    void random_infection() {
      int infected = rand() % populationSize;
      population.at(infected).infect(nDays);
    }

    // Counts the total number of infected people.
    int count_infected() {
      int count = 0;
      for (int i = 0; i < population.size(); i++) {
        if (!(population.at(i).is_stable())) {
          count++;
        }
      }
      return count;
    }

    // Updates all the persons in the population.
    void update() {
      int nInfected = count_infected();
      for (int i = 0; i < population.size(); i++) {
        population.at(i).update();
      }

      if (maxInteractions != 0) {
        for (int j = 0; j < nInfected; j++) {
          int interaction = rand() % maxInteractions + 1;
          for (int k = 0; k < interaction; k++) {
            chance = (float) rand()/(float)RAND_MAX;
            if (chance <= probability_of_transfer) {
              random_infection();
            }
          }
        }
      }
    }

    // Vaccinates a random person.
    void vaccinate(float vaccine_percentage) {
      nVaccinated = vaccine_percentage * populationSize;
      for (int k = 0; k < nVaccinated; k++) {
        int vaccinated = rand() % populationSize;
        population.at(vaccinated).vaccinate();
      }
      // int k = 0;
      // while (k < nVaccinated) {
      //   int vaccinated = rand() % populationSize;
      //   if (population.at(vaccinated).getHealthStatus() != -2) {
      //     population.at(vaccinated).vaccinate();
      //     k++;
      //   }
      // }
    }

    // Sets the probabilty of a transfer. 
    void set_probability_of_transfer(float probability) {
      probability_of_transfer = probability;
    }
};

int main() {
  srand((unsigned)time(0));
  
  // Using a for loop, these values can be incremented daily.
  // For example, one parameter can be (in/de)cremented 
  // while all the others are fixed.
  // The percentage of the population vaccinated can increased daily
  // or the maximum amount of interactions can be decreased daily. 
  int step = 0;
  int population_size = 30000;
  int time_period = 7;
  int max_interactions = 12;
  float probability = 0.1;
  float percent_vaccinated = 0;

  Population society = Population(population_size);
  society.set_n_days(time_period);
  society.set_max_interactions(max_interactions);
  society.random_infection();
  society.set_probability_of_transfer(probability);
  society.vaccinate(percent_vaccinated);

  cout << "Day , Total Infected" << endl;
  while (true) {
    step++;
    cout << step << ", " << society.count_infected() << endl;
    society.update();
    if (society.count_infected() == 0) {
      step++;
      cout << step << ", " << society.count_infected() << endl;
      break;
    }
  }
  return 0;
}

#include <iostream>
#include <list>

using namespace std;

// Whom to be notified
class Observer {
   public: 
      virtual void update (
         double temperature,
         double humidity,
         double pressure
      ) = 0;
};

// What to be notified
class Subject {
   public:
      virtual void registerObserver(Observer *o) = 0;
      virtual void removeObserver(Observer *o) = 0;
      virtual void notifyObservers() = 0;
};


// Not part of the observer pattern.
// * Defined for our convenience in show in how obverser pattern is working
class DisplayElement {
   public:
      virtual void display() = 0;
};

class WeatherData : public Subject {
   private:
      list<Observer*> observers;
      double         temperature;
      double         humidity;
      double         pressure;

   public:
      WeatherData() { }
      void registerObserver(Observer *o) {
         observers.push_back(o);
      }

      void removeObserver(Observer *o) {
         observers.remove(o);
      }

      void notifyObservers() {
         list<Observer*>::iterator itr;
         for (itr=observers.begin(); itr!=observers.end(); ++itr) {
            // calling update(temperature, humidity, pressure); to each o
            (*itr)->update(temperature, humidity, pressure);
         }
      }
/*   
      void measurementsChanged() {
         notifyObservers();
      }
*/

      void setMeasurements(double t, double h, double p) {
         temperature = t;
         humidity = h;
         pressure = p;
//         measurementsChanged();
         notifyObservers();
      }

/*
      double getTemperature() {
         return temperature;
      }

      double getHumidity() {
         return humidity;
      }

      double getPressure() {
         return pressure;
      }
*/
};

// 1st Observer
class CurrentConditionsDisplay : public Observer, DisplayElement {
   private:
      double   temperature;
      double   humidity;
      Subject *weatherData;
//      WeatherData *weatherData;

   public:
      CurrentConditionsDisplay(Subject *weatherDataObj) {
//      CurrentConditionsDisplay(WeatherData *weatherDataObj) {
         weatherData = weatherDataObj;
         weatherData->registerObserver(this);
      }

      void update(double t, double h, double p) {
         temperature = t;
         humidity = h;

         display();
      }

      void display() {
         cout << "CurrentConditionDisplay:" << endl;
         cout << "   Current conditions: " << temperature
              << "F degrees and " << humidity << "% humidity" << endl;
      }
};

// 2nd Observer
class StatisticsDisplay : public Observer, DisplayElement {
   private:
      double   maxTemp; // = 0;
      double   minTemp; // = 200;
      double   tempSum; // = 0;
      int      numReadings;
      Subject *weatherData;
//      WeatherData *weatherData;

   public:
      StatisticsDisplay(Subject *wd) :
         maxTemp(0), minTemp(200), tempSum(0), numReadings(0) {

         weatherData = wd;
         weatherData->registerObserver(this);
      }

      void update(double t, double h, double p) {
         tempSum += t;
         numReadings++;

         if (t > maxTemp) {
            maxTemp = t;
         }

         if (t < minTemp) {
            minTemp = t;
         }

         display();
      }

      void display() {
         cout << "StatisticsDisplay:" << endl;
         cout << "   Avg/Max/Min temperature = " << (tempSum/numReadings)
              << "/" << maxTemp << "/" <<  minTemp << endl;
      }
};

class ForecastDisplay : public Observer, DisplayElement {
   private:
      double currentPressure;
      double lastPressure;
      Subject *weatherData;

   public:
      ForecastDisplay(Subject *wd) : currentPressure(29.92) {
         
         weatherData = wd;
         weatherData->registerObserver(this);
      }

      void update(double t, double h, double p) {
         lastPressure = currentPressure;
         currentPressure = p;

         display();
      }

      void display() {
         cout << "ForecaseDisplay: " << endl;
         
         if (currentPressure > lastPressure) {
            cout << "   Improving weather on the way!" << endl;
         } else if (currentPressure == lastPressure) {
            cout << "   More of the same" << endl;
         } else if (currentPressure < lastPressure) {
            cout << "   Watch out for cooler, rainy weather" << endl;
         }
      }
};

int main() {
   WeatherData wd; //*wd = new WeatherData();

   CurrentConditionsDisplay cd(&wd);
   StatisticsDisplay sd(&wd);
   ForecastDisplay fd(&wd);

   cout << endl << "1st update: " << endl;
   wd.setMeasurements(80, 65, 30.4f);

   cout << endl << "2nd update: " << endl;
   wd.setMeasurements(82, 70, 29.2f);

   cout << endl << "3rd update: " << endl;
   wd.setMeasurements(78, 90, 29.2f);
}

#include <iostream>
#include <string>

using namespace std;

class GumballMachine;

// Interface Class : State
class State {
   public:
      virtual void InsertQuarter() { }// = 0;
      virtual void EjectQuarter() { };// = 0;
      virtual void TurnCrank() { };// = 0;
      virtual void Dispense() { };// = 0;
   
      virtual string toString() { return ""; };
};

class NoQuarterState : public State {
   private:
      GumballMachine *_gbmInstance;

   public:
      NoQuarterState(GumballMachine *gbm) {
         _gbmInstance = gbm;
      }

      void InsertQuarter();

      void EjectQuarter() {
         cout << "You haven't inserted a quarter" << endl;
      }

      void TurnCrank() {
         cout << "You turned, but there is no quarter" << endl;
      }

      void Dispense() {
         cout << "You need to pay first" << endl;
      }

      string toString() {
         return "waiting for quarter";
      }
}; 

class HasQuarterState : public State {
   private:
      GumballMachine *_gbmInstance;

   public:
      HasQuarterState(GumballMachine *gbm) {
         _gbmInstance = gbm;
      }

      void InsertQuarter() {
         cout << "You can't insert another quarter" << endl;
      }

      void EjectQuarter(); 
      void TurnCrank(); 
      void Dispense() {
         cout << "No gumball dispensed" << endl;
      }

      string toString() {
         return "waiting for turn of crank";
      }
}; 

class SoldState : public State {
   private:
      GumballMachine *_gbmInstance;

   public:
      SoldState(GumballMachine *gbm) {
         _gbmInstance = gbm;
      }

      void InsertQuarter() {
         cout << "Please wait, we're already giving you a gumball" << endl;
      }

      void EjectQuarter() {
         cout << "Sorry, you already turned the crank" << endl;
      }

      void TurnCrank() {
         cout << "Turning twice doesn't get you another gumball" << endl;
      }

      void Dispense();

      string toString() {
         return "dispensing a gumball";
      }
}; 

class SoldOutState : public State {
   private:
      GumballMachine *_gbmInstance;

   public:
      SoldOutState(GumballMachine *gbm) {
         _gbmInstance = gbm;
      }

      void InsertQuarter() {
         cout << "You can't insert a quarter, the machine is sold out" << endl;
      }

      void EjectQuarter() {
         cout << "You can't eject, you haven't inserted a quarter yet" << endl;
      }

      void TurnCrank() {
         cout << "You turned, but there are no gumballs" << endl;
      }

      void Dispense() {
         cout << "No gumball dispensed" << endl;
      }

      string toString() {
         return "Sold out!";
      }
};

class GumballMachine {
   private:
      State *soldOutState;
      State *noQuarterState;
      State *hasQuarterState;
      State *soldState;

      State *currentState;
      int   gumballCounter;

   public:
      GumballMachine(int numberOfGumballs) {
         soldOutState = new SoldOutState(this);
         noQuarterState = new NoQuarterState(this);
         hasQuarterState = new HasQuarterState(this);
         soldState = new SoldState(this);

         gumballCounter = numberOfGumballs;

         if (gumballCounter > 0) {
            currentState = noQuarterState;
         } else {
            currentState = soldOutState;
         }
      }

      ~GumballMachine() {
         delete soldOutState;
         delete noQuarterState;
         delete hasQuarterState;
         delete soldState;
      }

      int GetCount() {
         return gumballCounter;
      }

      void ReleaseBall() {
         cout << "A gumball comes rolling out the slot ..." << endl;
         if (gumballCounter > 0) {
            gumballCounter--;
         }
      }

      void SetState(State *st) {
         currentState = st;
      }

      State* GetSoldOutState() {
         return soldOutState;
      }

      State* GetNoQuarterState() {
         return noQuarterState;
      }

      State* GetHasQuarterState() {
         return hasQuarterState;
      }

      State* GetSoldState() {
         return soldState;
      }

      void InsertQuarter() {
         currentState->InsertQuarter();
      } 

      void EjectQuarter() {
         currentState->EjectQuarter();
      }

      void TurnCrank() {
         currentState->TurnCrank();
         currentState->Dispense();
      }

      void Refill(int count) {
         gumballCounter = count;
         currentState = noQuarterState;
      }

      void PrintStatus() {
         cout << "\n\nMighty Gumball, Inc.\n";
         cout << "C++ coded by Thawee Techathamnukool 2016\n";
         cout << "Inventory: " << gumballCounter << " gumball";
         if (gumballCounter > 1)
            cout << "s";
         cout << endl;
         cout << "Machine state: " << currentState->toString() << endl;
      }
};

void NoQuarterState::InsertQuarter() {
   cout << "You inserted a quarter" << endl;
   _gbmInstance->SetState(_gbmInstance->GetHasQuarterState());
}

void HasQuarterState::EjectQuarter() {
   cout << "Quarter returned" << endl;
   _gbmInstance->SetState(_gbmInstance->GetNoQuarterState());
}

void HasQuarterState::TurnCrank() {
   cout << "You turned ..." << endl;
   _gbmInstance->SetState(_gbmInstance->GetSoldState());
}

void SoldState::Dispense() {
   _gbmInstance->ReleaseBall();
   if (_gbmInstance->GetCount() > 0) {
      _gbmInstance->SetState(_gbmInstance->GetNoQuarterState());
   } else {
      cout << "Oops, out of gumballs!" << endl;
      _gbmInstance->SetState(_gbmInstance->GetSoldOutState());
   }
}

/*
GumballMachine::GumballMachine(int numberOfGumballs) {
   soldOutState = new SoldOutState(this);
   noQuarterState = new NoQuarterState(this);
   hasQuarterState = new HasQuarterState(this);
   soldState = new SoldState(this);

   gumballCounter = numberOfGumballs;

   if (gumballCounter > 0) {
      currentState = noQuarterState;
   } else {
      currentState = soldOutState;
   }
}
*/

int main() {
   GumballMachine *gbm = new GumballMachine(1);
   gbm->PrintStatus();

   cout << endl << "INPUT: put a quarter\n";
   gbm->InsertQuarter();
   cout << endl << "INPUT: turn crank\n";
   gbm->TurnCrank();

   cout << endl << "INPUT: put a quarter\n";
   gbm->InsertQuarter();
   cout << endl << "INPUT: turn crank\n";
   gbm->TurnCrank();

   cout << endl << "INPUT: refill 3 gumballs to the machine\n";
   gbm->Refill(3);

   cout << endl << "INPUT: put a quarter\n";
   gbm->InsertQuarter();
   cout << endl << "INPUT: turn crank\n";
   gbm->TurnCrank();

   gbm->PrintStatus();

   delete gbm;
}


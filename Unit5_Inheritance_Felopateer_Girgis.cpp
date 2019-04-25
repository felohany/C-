
//UTA Assignment
//begin include
#include "clock_time.cpp"
#define MAX_CLOCK_NAME
#include<vector>
#include<string>
#include<string.h>
#define RUN_TIME 604800  //seconds in one week

//end include


enum CLOCK_TYPE
{
	Sundial, Atomic, Cuckoo, Grandfather, Wrist
};

//begin class

class Clock
{
	public:
		Clock(CLOCK_TYPE const type, ClockTime const& initialTime, double const driftPerSecond, char const * const name)
		{
			type_ = Sundial;
			driftPerSecond_ = driftPerSecond;
			strcpy(name_ , name); 
			clockTime_.setTime(initialTime);
		}
	protected:
		ClockTime clockTime_;
		
	private:
		CLOCK_TYPE type_;
		double driftPerSecond_;
		char name_[MAX_CLOCK_NAME];
		
		public:
			virtual void reset() = 0; // pure virtual function
			virtual void tick() = 0 ; // pure virtual fn
			virtual void displayTime() const = 0;
			char const * const name() const {return name_;}
			double const driftPerSecond() const { return driftPerSecond_;}
			
};
//end class
//begin class2

class NaturalClock : public Clock //inheritance
{
	public: 
        NaturalClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : Clock(type, initialTime, driftPerSecond, name) { } //empty constructor { }
			   
        virtual void reset() = 0; //pure virtual function
        virtual void tick() = 0;  //pure virtual fn
        virtual void displayTime() const = 0;

};

//end class2
//begin class3

class MechancialClock : public Clock //inheritance 
{
    public: 
        MechancialClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : Clock(type, initialTime, driftPerSecond, name) { } //empty constructor { }
			   
        virtual void reset() = 0; //pure virtual function
        virtual void tick() = 0;  //pure virtual fn
        virtual void displayTime() const = 0;  
};
 
 //end class3
 //begin class 4
 
class DigitalClock : public Clock //inheritance 
{
    public: 
        DigitalClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : Clock(type, initialTime, driftPerSecond, name) { }  //empty constructor { }
        virtual void reset() = 0; //pure virtual function
        virtual void tick() = 0;  //pure virtual function
        virtual void displayTime() const = 0;  
};
 
//end class 4
//begin class 5

class QuantumClock : public Clock //inheritance 
{
    public: 
        QuantumClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : Clock(type, initialTime, driftPerSecond, name) { }  //empty constructor { }
        virtual void reset() = 0; //pure virtual function
        virtual void tick() = 0;  //pure virtual function
        virtual void displayTime() const = 0;  
};

//end class5
//begin class 6

class SundialClock : public NaturalClock //inheritance 
{
    public: 
        SundialClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : NaturalClock(type, initialTime, driftPerSecond, name) { }  //empty constructor { }
         void reset()   //virtual overload the child can overload the fn of the parent
        {
        	clockTime_.reset();
		}
         void tick()
        {
        	clockTime_.increment();
		}
		 void displayTime() const
		{
			
			//string typeName = " ";
			cout << "Sundial clock \t time [" ;
			clockTime_.display();
			cout << "] - total drift = " ;
			//seconds 
			cout << (clockTime_.deltaTime() * driftPerSecond());
			cout << " second  " << endl;
			
			//clockTime_.display();
		}
		
		
		};

//end class 6
//begin class 7

class CuckooClock : public NaturalClock //inheritance 
{
    public: 
        CuckooClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : NaturalClock(type, initialTime, driftPerSecond, name) { }  //empty constructor { }
         void reset()   //virtual overload the child can overload the fn of the parent
        {
        	clockTime_.reset();
		}
         void tick()
        {
        	clockTime_.increment();
		}
		 void displayTime() const
		{
			//clockTime_.display();
			
			cout << name() <<"clock \t time [" ;
			clockTime_.display();
			cout << "] - total drift = " ;
			//seconds 
			cout << (clockTime_.deltaTime() * driftPerSecond());
			cout << " second  " << endl;
			
			
		}
		
		
		};
		
//end class 7
//begin class 8

class GrandfatherClock : public Clock //inheritance 
{
    public: 
        GrandfatherClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : Clock(type, initialTime, driftPerSecond, name) { }  //empty constructor { }
         void reset()   //virtual overload the child can overload the fn of the parent
        {
        	clockTime_.reset();
		}
         void tick()
        {
        	clockTime_.increment();
		}
	 void displayTime() const
		{
			//clockTime_.display();
		
		cout << "Grandfather clock \t time [" ;
			clockTime_.display();
			cout << "] - total drift = " ;
			//seconds 
			cout << (clockTime_.deltaTime() * driftPerSecond());
			cout << " second  "<< endl ;
			
		
		}
		
		
		};
//end class 8
//begin class 9

class WristClock : public DigitalClock //inheritance 
{
    public: 
        WristClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : DigitalClock(type, initialTime, driftPerSecond, name) { } //empty constructor
        virtual void reset()  //vitual overload the  child can overload the functions of the parent
        {
            clockTime_.reset(); 
        }
        void tick()     
        {
            clockTime_.increment(); 
        }
        void displayTime() const
        {
           // clockTime_.display(); 
        	cout << "Wrist clock \t time [" ;
			clockTime_.display();
			cout << "] - total drift = " ;
			//seconds 
			cout << (clockTime_.deltaTime() * driftPerSecond());
			cout << " second  " << endl;
			
		}
};
//end class 9
//begin class 10 
class AtomicClock : public QuantumClock //inheritance 
{
    public: 
        AtomicClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : QuantumClock(type, initialTime, driftPerSecond, name) { } //empty constructor
      void reset()  //vitual overload the  child can overload the functions of the parent
        {
            clockTime_.reset(); 
        }
      void tick()     
        {
            clockTime_.increment(); 
        }
        void displayTime() const
        {
            clockTime_.display(); 
        }
};
//end class 10

//begin int main
int main()
{
	vector<Clock*> clocks_;
	ClockTime ct;
	ct.setTime(0,0,0,1);
	

	//sd.displayTime();
	
	
	cout << "Reported clock times after resetting: " << endl;
	cout << "=====================================" << endl;
	SundialClock sd(Sundial, ct, 0, "sundial" );
	sd.displayTime();
		for (int i=0; i<604800;i++)
	{
		sd.tick();
	}
	sd.displayTime();
	
	CuckooClock cd(Cuckoo, ct, 0.000694444, "Cuckoo");
	cd.displayTime();
	for (int i=0; i<604800;i++)
	{
		cd.tick();
	}
	cd.displayTime();
	
	
	/*
	GrandfatherClock gf(Grandfather, ct, 6, "test");
	cd.displayTime();
	
	WristClock wr(Wrist, ct, 6, "test");
	cd.displayTime();
	*/
	//system("pause");
	return 0;
}

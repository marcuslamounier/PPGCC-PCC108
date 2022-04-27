#ifndef SYSTEM_H
#define SYSTEM_H

class InterfaceSystem {
  public:
    virtual double getValue() const = 0;
    virtual void setValue(double v) = 0;
};

class System: public InterfaceSystem {
  protected:
    double value;

  public:
    System();
    System(double v = 0);
    System (const System& sys);
    virtual ~System();

    System& operator=(const System& sys);

    double getValue() const;
    void setValue(double v);
};

#endif

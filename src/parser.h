#ifndef parser_h
#define parser_h

#include "names.h"
#include "scanner.h"
#include "network.h"
#include "devices.h"
#include "monitor.h"
#include "error.h"

using namespace std;

class parser {
 private:
  void error ();
  void deviceList();
  void connectionList();
  void monitorList();
  void newDevice(int deviceType);
  void newConnection();
  void newMonitor();
  network* netz; // instantiations of various classes for parser to use.
  devices* dmz; 
  monitor* mmz;
  scanner* smz;
  int curint;
  symbol cursym;
  name curname;
  bool ok;
  int badname;
  name monitorName;
  name connectionInName;
  name connectionOutName;

  /* put other stuff that the class uses internally here */
  /* also declare internal functions                     */

 public:
  bool readin (); /* returns true if definitions file parsed ok */
    /* Reads the definition of the logic system and builds the             */
    /* corresponding internal representation via calls to the 'Network'    */
    /* module and the 'Devices' module.                                    */

  parser (network* network_mod,
	  devices* devices_mod,
	  monitor* monitor_mod,
	  scanner* scanner_mod);
    /* the constructor takes pointers to various other classes as parameters */
};

#endif /* parser_h */


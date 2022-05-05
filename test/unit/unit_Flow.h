#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

void unit_Flow_constructor();
void unit_Flow_destructor();

void unit_Flow_getSource();
void unit_Flow_getTarget();
void unit_Flow_getLastValue();

void unit_Flow_setSource();
void unit_Flow_setTarget();
void unit_Flow_setLastValue();

void unit_Flow_clearSource();
void unit_Flow_clearTarget();
void unit_Flow_execute();

void run_unit_tests_Flow();

#endif
/**************************************************************************/
/*                                                                        */
/*                                 OCaml                                  */
/*                                                                        */
/*          Xavier Leroy and Damien Doligez, INRIA Rocquencourt           */
/*                                                                        */
/*   Copyright 1996 Institut National de Recherche en Informatique et     */
/*     en Automatique.                                                    */
/*                                                                        */
/*   All rights reserved.  This file is distributed under the terms of    */
/*   the GNU Lesser General Public License version 2.1, with the          */
/*   special exception on linking described in the file LICENSE.          */
/*                                                                        */
/**************************************************************************/

#ifndef CAML_SIGNALS_H
#define CAML_SIGNALS_H

#if defined(CAML_INTERNALS) && defined(POSIX_SIGNALS)
#include<signal.h>
#endif

#ifndef CAML_NAME_SPACE
#include "compatibility.h"
#endif
#include "misc.h"
#include "mlvalues.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CAML_INTERNALS
CAMLextern intnat volatile caml_pending_signals[];
CAMLextern int volatile caml_something_to_do;
extern int volatile caml_requested_major_slice;
extern int volatile caml_requested_minor_gc;

void caml_update_young_limit(void);
void caml_request_major_slice (void);
void caml_request_minor_gc (void);
CAMLextern int caml_convert_signal_number (int);
CAMLextern int caml_rev_convert_signal_number (int);
void caml_execute_signal(int signal_number, int in_signal_handler);
void caml_record_signal(int signal_number);
void caml_set_something_to_do (void);
void caml_raise_in_async_callback (value exc);
void caml_process_event(void);
int caml_set_signal_action(int signo, int action);

CAMLextern void (*caml_enter_blocking_section_hook)(void);
CAMLextern void (*caml_leave_blocking_section_hook)(void);
CAMLextern int (*caml_try_leave_blocking_section_hook)(void);
CAMLextern void (* volatile caml_async_action_hook)(void);
#ifdef POSIX_SIGNALS
CAMLextern int (*caml_sigmask_hook)(int, const sigset_t *, sigset_t *);
#endif
#endif /* CAML_INTERNALS */

CAMLextern void caml_enter_blocking_section (void);
CAMLextern void caml_leave_blocking_section (void);

#ifdef __cplusplus
}
#endif

#endif /* CAML_SIGNALS_H */

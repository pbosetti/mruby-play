#include <stdlib.h>
#include <stdbool.h>
#include <mruby.h>
#include <mruby/data.h>
#include <mruby/array.h>
#include <mruby/variable.h>
#include <mruby/string.h>
#include <mruby/numeric.h>
#include <errno.h>
#include "simple.h"

#ifdef __cplusplus
extern "C" {
#endif

#define IV_GET(name) mrb_iv_get(mrb, self, mrb_intern_cstr(mrb, (name)))
#define IV_SET(name, value)                                                    \
  mrb_iv_set(mrb, self, mrb_intern_cstr(mrb, (name)), value)

static void simple_free(mrb_state *mrb, void *p) {
  if (p != NULL) {
    free(p);
  }
}

static struct mrb_data_type mrb_simple_ctx_type = {"SimpleContext",
                                                      simple_free};

mrb_value mrb_simple_init(mrb_state *mrb, mrb_value self) {
  mrb_int val_i;
  mrb_float val_f;
  simple_context *simple;
  simple = calloc(1, sizeof(simple));
  
  mrb_get_args(mrb, "if", &val_i, &val_f);
  simple->i = (int)val_i;  
  simple->f = val_f;

  mrb_data_init(self, simple, &mrb_simple_ctx_type);
  return self;
}

mrb_value mrb_simple_f(mrb_state *mrb, mrb_value self) {
  simple_context *simple;
  simple = DATA_GET_PTR(mrb, self, &mrb_simple_ctx_type, simple_context);
  
  return mrb_float_value(mrb, simple->f);
}

mrb_value mrb_simple_i(mrb_state *mrb, mrb_value self) {
  simple_context *simple;
  simple = DATA_GET_PTR(mrb, self, &mrb_simple_ctx_type, simple_context);
  
  return mrb_fixnum_value(simple->i);
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#ifdef __cplusplus
extern "C" {
#endif
  
typedef struct {
  int i;
  float f;
} simple_context;

mrb_value mrb_simple_init(mrb_state *mrb, mrb_value self);
mrb_value mrb_simple_f(mrb_state *mrb, mrb_value self);
mrb_value mrb_simple_i(mrb_state *mrb, mrb_value self);

#ifdef __cplusplus
} /* extern "C" */
#endif
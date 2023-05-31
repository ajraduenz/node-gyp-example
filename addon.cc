#include <node_api.h>

napi_value HelloWorld(napi_env env, napi_callback_info info) {
  napi_value greeting;
  napi_create_string_utf8(env, "Example", NAPI_AUTO_LENGTH, &greeting);
  return greeting;
}

napi_value Init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, nullptr, 0, HelloWorld, nullptr, &fn);
  if (status != napi_ok) {
    napi_throw_error(env, nullptr, "Failed to create function");
  }

  status = napi_set_named_property(env, exports, "helloWorld", fn);
  if (status != napi_ok) {
    napi_throw_error(env, nullptr, "Failed to set named property");
  }

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
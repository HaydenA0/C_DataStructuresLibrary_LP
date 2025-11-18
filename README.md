


* Use the pattern `ds_Type_action()` for all functions
* Example: `ds_list_create()`, `ds_hashmap_get()`
* Every data structure should have a `new` and a `destroy` method
* The `destroy` function should be safe to call with `NULL`
* If a data structure contains another, it has full ownership by default
  * The parent creates and destroys its children
  * All memory is internally managed
  * No external caller responsibility
* Every data structure should have an initial state and an error state that can be distinguished


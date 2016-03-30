

```sh
make						# use the default BUILD_MODE
make BUILD_MODE=pf			# builds src_pf/*, creates libpf.a
make BUILD_MODE=rm			# builds src_rm/*, creates librm.a
make BUILD_MODE=pf_test1	# calls pf, builds src_pf_test1/*, creates pf_test1
make BUILD_MODE=pf_test2	# calls pf, builds src_pf_test2/*, creates pf_test2
make BUILD_MODE=pf_test3	# calls pf, builds src_pf_test3/*, creates pf_test3
```
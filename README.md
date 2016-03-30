

```sh
make						# use the default BUILD_MODE

make BUILD_MODE=pf			# builds src/pf/*, creates ./libpf.a
make BUILD_MODE=rm			# calls libft -m32, builds src/rm/*, creates ./librm.a
make BUILD_MODE=pf_test1	# calls pf, builds src/pf_test1/*, creates ./pf_test1
make BUILD_MODE=pf_test2	# calls pf, builds src/pf_test2/*, creates ./pf_test2
make BUILD_MODE=pf_test3	# calls pf, builds src/pf_test3/*, creates ./pf_test3
make BUILD_MODE=sandbox		# calls pf && rm, buils src/sandbox/*, creates ./sandbox
```
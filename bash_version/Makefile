all: test-init test clean

test-init:
	git clone https://github.com/bats-core/bats-core.git test/bats
	git clone https://github.com/bats-core/bats-support.git test/test_helper/bats-support
	git clone https://github.com/bats-core/bats-assert.git test/test_helper/bats-assert

test:
	./test/bats/bin/bats test/timer_tests.bats

clean:
	rm -Rf test/bats
	rm -Rf test/test_helper

.PHONY: test test-init clean

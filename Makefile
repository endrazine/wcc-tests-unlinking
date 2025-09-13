all::
	docker build . -t wcc-unlinking:latest --no-cache

run::
	docker run --user 0 -it wcc-unlinking:latest bash

test::
	docker run --user 0 -it wcc-unlinking:latest bash -c "make test"

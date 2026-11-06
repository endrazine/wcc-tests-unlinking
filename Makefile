all::
	docker buildx build --load . -f Dockerfile-24.04 -t wcc-unlinking:24.04 --build-arg VERSION=24.04
	docker buildx build --load . -f Dockerfile-26.04 -t wcc-unlinking:26.04 --build-arg VERSION=26.04
	docker buildx build --load . -f Dockerfile-26.10 -t wcc-unlinking:26.10 --build-arg VERSION=26.10

rebuild::
	docker buildx build --load . -f Dockerfile-24.04 -t wcc-unlinking:24.04 --build-arg VERSION=24.04 --no-cache
	docker buildx build --load . -f Dockerfile-26.04 -t wcc-unlinking:26.04 --build-arg VERSION=26.04 --no-cache
	docker buildx build --load . -f Dockerfile-26.10 -t wcc-unlinking:26.10 --build-arg VERSION=26.10 --no-cache

shell::
	docker run --user 0 -it wcc-unlinking:24.04 bash
	docker run --user 0 -it wcc-unlinking:26.04 bash
	docker run --user 0 -it wcc-unlinking:26.10 bash

run::
test::
#	docker run --user 0 -it wcc-unlinking:22.04 bash -c "make test"
	docker run --user 0 -it wcc-unlinking:24.04 bash -c "make test"
	docker run --user 0 -it wcc-unlinking:26.04 bash -c "make test -i"
	docker run --user 0 -it wcc-unlinking:26.10 bash -c "make test -i"

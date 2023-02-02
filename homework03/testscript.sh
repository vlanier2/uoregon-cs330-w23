#! /bin/bash

./spmv test1/A.mtx test1/x.mtx test1out.mtx > /dev/null

./spmv test2/A.mtx test2/x.mtx test2out.mtx > /dev/null

echo "CHECKING DIFFS"

diff test1/ans.mtx test1out.mtx

diff test2/ans.mtx test2out.mtx
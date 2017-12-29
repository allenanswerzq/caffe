#!/usr/bin/env sh
set -e

TOOLS=./build/tools
echo $@
$TOOLS/caffe test \
  --model=examples/cifar10/cifar10_quick_train_test.prototxt \
  --weights=examples/cifar10/snapshot/_iter_4000.caffemodel $@

# reduce learning rate by factor of 10 after 8 epochs
#$TOOLS/caffe train \
#  --solver=examples/cifar10/cifar10_quick_solver_lr1.prototxt \
#  --snapshot=examples/cifar10/cifar10_quick_iter_4000.solverstate $@

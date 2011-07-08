// Copyright (c) 2011 Cloudera, Inc. All rights reserved.

#ifndef IMPALA_RUNTIME_RUNTIME_STATE_H
#define IMPALA_RUNTIME_RUNTIME_STATE_H

namespace impala {

class DescriptorTbl;
class ObjectPool;

// A collection of items that are part of the global state of a 
// query and potentially shared across execution nodes.
class RuntimeState {
 public:
  RuntimeState(const DescriptorTbl& descs);

  ObjectPool* obj_pool() const { return obj_pool_; }
  const DescriptorTbl& descs() const { return descs_; }
  int batch_size() const { return batch_size_; }

 private:
  const DescriptorTbl& descs_;
  ObjectPool* obj_pool_;
  int batch_size_;

  static const int DEFAULT_BATCH_SIZE = 1024;
};

}

#endif
